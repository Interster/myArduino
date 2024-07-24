import math
import socket
import struct
import sys
import time

import cv2
import numpy as np
import pandas as pd

print ()
print("Python Ver: "+ str(sys.version_info.major) + '.' + str(sys.version_info.minor))
print("Pygame Ver: " + cv2.__version__)
print("Numpy Ver:  " + np.__version__)

GREEN = (0, 255, 0)
RED   = (0, 0, 255)
BLUE  = (255, 0, 0)
WHITE = (255, 255, 255)
TEAL  = (255, 255, 0)

WDT, HGT = 640, 480

points = [0, 1, 2, 3, 4, 5, 6, 7]
cube_size = .8 #.1 to 1

points[0] = [[-cube_size], [-cube_size], [cube_size]]
points[1] = [[cube_size], [-cube_size], [cube_size]]
points[2] = [[cube_size], [cube_size], [cube_size]]
points[3] = [[-cube_size], [cube_size], [ cube_size]]
points[4] = [[-cube_size], [-cube_size], [-cube_size]]
points[5] = [[cube_size], [-cube_size], [-cube_size]]
points[6] = [[cube_size], [cube_size], [-cube_size]]
points[7] = [[-cube_size], [cube_size], [-cube_size]]

def draw_line(i, j, k, color):
    a = k[i]
    b = k[j]
    cv2.line(img, (a[0], a[1]), (b[0], b[1]), color, 2)

black = np.zeros(shape=[480, 640, 3], dtype=np.uint8) # Blank Image when video input runs o

x_angle = 0.
y_angle = 0.
z_angle = 0
angle_speed = 100
scale = 600

delta_radian = .015707963267948966 # 1/100th of a radian




print("Starting")
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# s.connect(("localhost", 1234))
print("Connecting")
s.connect(("172.16.16.215", 1234))

print("Sending")
s.send("Start".encode())

gyro_rate = 1/104
calibrate_count = 0
roll_bias, pitch_bias, yaw_bias = 0.0, 0.0, 0.0

try:
    df = pd.DataFrame(columns=["Counter", "Roll (degrees/second)", "Pitch (degrees/second)", "Yaw (degrees/second)"])
    print("Receiving")
    while True:
        data = s.recv(16)
        if data != b'':
            try:
                packet_counter, = struct.unpack('B', data[:1])
                roll, pitch, yaw = struct.unpack('fff', data[1:])

                if calibrate_count < 100:
                    calibrate_count += 1
                    roll_bias += roll
                    pitch_bias += pitch
                    yaw_bias += yaw
                else:
                    if calibrate_count == 100:
                        print("Done calibrating")
                        roll_bias = roll_bias / calibrate_count
                        pitch_bias = pitch_bias  / calibrate_count
                        yaw_bias = yaw_bias / calibrate_count
                    corrected_roll = roll - roll_bias
                    corrected_pitch = pitch - pitch_bias
                    corrected_yaw = yaw - yaw_bias

                    df.loc[len(df)] = [packet_counter, corrected_roll, corrected_pitch, corrected_yaw]
                    img = np.copy(black)

                    projected_points = [j for j in range(len(points))]

                    z_angle = z_angle + math.radians(corrected_roll) * gyro_rate
                    x_angle = x_angle - math.radians(corrected_pitch) * gyro_rate
                    y_angle = y_angle + math.radians(corrected_yaw ) * gyro_rate
                    
                    calibrate_count = calibrate_count + 1
                    if calibrate_count % 10 == 0:
                        print(f"x_angle = {math.degrees(x_angle):.2f}, y_angle = {math.degrees(y_angle):.2f}, z_angle = {math.degrees(z_angle):.2f}")
                        pass
                    else:
                        continue

                    angle = int(math.degrees(x_angle))

                    if x_angle > math.pi*1.99: x_angle = 0
                    if y_angle > math.pi*1.99: y_angle = 0
                    if z_angle > math.pi*1.99: z_angle = 0

                    rotation_x = [[1,                 0,                  0],
                                  [0, math.cos(x_angle), -math.sin(x_angle)],
                                  [0, math.sin(x_angle), math.cos(x_angle)]]
                    rotation_y = [[math.cos(y_angle), 0, -math.sin(y_angle)],
                                  [0,                 1,                  0],
                                  [math.sin(y_angle), 0, math.cos(y_angle)]]

                    rotation_z = [[math.cos(z_angle), -math.sin(z_angle), 0],
                                  [math.sin(z_angle), math.cos(z_angle),  0],
                                  [0,                 0,                  1]]

                    index = 0

                    for point in points: # Draw points
                        rotated_2d = np.matmul(rotation_y, point)
                        rotated_2d = np.matmul(rotation_x, rotated_2d)
                        rotated_2d = np.matmul(rotation_z, rotated_2d)

                        distance = 5 # view point distance
                        z = 1/(distance - rotated_2d[2][0])
                        projection_matrix = [[z, 0, 0], [0, z, 0]]
                        projected_2d = np.matmul(projection_matrix, rotated_2d)

                        x = int(projected_2d[0][0] * scale) + WDT // 2
                        y = int(projected_2d[1][0] * scale) + HGT // 2

                        projected_points[index] = [x, y]

                        cv2.circle(img, (x, y), 5, WHITE, 2)
                        cv2.circle(img, (WDT // 2, HGT // 2), 4, TEAL, cv2.FILLED)

                        index += 1

                    for m in range(4): # Draw Lines to connect dots
                        draw_line(m, (m + 1) % 4, projected_points, GREEN)
                        draw_line(m + 4, (m +1) % 4 + 4, projected_points, RED)
                        draw_line(m, m + 4, projected_points, BLUE)

                    cv2.putText(img, str(angle) + ' Degrees', (15,25), cv2.FONT_HERSHEY_PLAIN, 1.5, GREEN, 1)
                    cv2.imshow("", img)

                    # time.sleep(1/angle_speed)

                    if cv2.waitKey(1) == 27:
                        cv2.destroyAllWindows ()
                        break
            except struct.error:
                print(f"Error {data}" )
        else:
            print("Nothing")
except KeyboardInterrupt:
    print("User stopped")

try:
    s.close()
    print("closed successfully")
    df.to_excel("data.xlsx", index=False)
except OSError:
    pass


