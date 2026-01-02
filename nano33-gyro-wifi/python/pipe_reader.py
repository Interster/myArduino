import socket
import struct
import time

import pandas as pd

print("Starting")
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# s.connect(("localhost", 1234))
print("Connecting")
s.connect(("192.168.8.119", 1234))

print("Sending")
s.send("Start".encode())
start = None

try:
    df = pd.DataFrame(columns=["Counter", "Roll (degrees/second)", "Pitch (degrees/second)", "Yaw (degrees/second)"])
    print("Receiving")
    while True:
        data = s.recv(17)
        if start is None:
            start = time.time()
        if data != b'':
            try:
                packet_counter, = struct.unpack('B', data[:1])
                roll, pitch, yaw = struct.unpack('fff', data[1:])
                df.loc[len(df)] = [packet_counter, roll, pitch, yaw]
            except struct.error:
                print(f"Error {data}" )
        else:
            print("Nothing")
        if time.time() - start > 120:
            break
except KeyboardInterrupt:
    print("User stopped")

try:
    s.close()
    print("closed successfully")
    #df.to_excel("data.xlsx", index=False)
    df.to_csv("data.csv", index=False)
except OSError:
    pass


