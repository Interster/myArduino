#%%
import pygame
import serial # Module needed for serial communication
import time # Module needed to add delays in the code




#%%
#Stel op die seriepoort kommunikasie

# Set the port name and the baud rate. This baud rate should match the
# baud rate set on the Arduino.
# Timeout parameter makes sure that program doesn't get stuck if data isn't
# being received. After 1 second, the function will return with whatever data
# it has. The readline() function will only wait 1 second for a complete line 
# of input.
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
 
# Inisialiseer die heelgetal waardes wat na Arduino gestuur gaan word 
servo_0_angle = 0
servo_1_angle = 0
servo_2_angle = 0
servo_3_angle = 0
servo_4_angle = 0
servo_5_angle = 0
 
# Get rid of garbage/incomplete data
ser.flush()


#%%
pygame.init()

# %%
# Hoof lus vir die beheer van die servos

#Loop until the user clicks the close button.
done = False

# Used to manage how fast the screen updates
clock = pygame.time.Clock()

# Initialize the joysticks
pygame.joystick.init()
# Get count of joysticks
joystick_count = pygame.joystick.get_count()
print("Number of joysticks: {}".format(joystick_count))

joystick = pygame.joystick.Joystick(0)
joystick.init()
axis = joystick.get_axis( 1 )
print("Axis {} value: {:>6.2f}".format(1, axis))

while done==False:

    # EVENT PROCESSING STEP
    for event in pygame.event.get(): # User did something
        if event.type == pygame.QUIT: # If user clicked close
            done=True # Flag that we are done so we exit this loop
        
        # Possible joystick actions: JOYAXISMOTION JOYBALLMOTION JOYBUTTONDOWN JOYBUTTONUP JOYHATMOTION
        if event.type == pygame.JOYBUTTONDOWN:
            print("Joystick button pressed.")
            button = joystick.get_button( 0 )
            print("Button {:>2} value: {}".format(0,button) )

            # As die masjien geweer gedruk word, stop die meting
            if button == 1:
                done=True # Flag that we are done so we exit this loop
        if event.type == pygame.JOYBUTTONUP:
            print("Joystick button released.")
     
    # Limit to 20 frames per second
    clock.tick(20)
    axis = joystick.get_axis( 1 )
    # Skakel die beheerstok as oor na 'n servo hoek
    servo_0_angle = int(axis*90 + 90)
    print("Axis {} value: {:>6.2f}".format(1, servo_0_angle))

    

    # Convert the integers to a comma-separated string
    angle_value_list = [str(servo_0_angle),str(servo_1_angle),str(
    servo_2_angle),str(servo_3_angle),str(servo_4_angle),str(servo_5_angle)]    
    send_string = ','.join(angle_value_list)
    send_string += "\n"
 
    # Send the string. Make sure you encode it before you send it to the Arduino.
    ser.write(send_string.encode('utf-8'))
    
# Close the window and quit.
# If you forget this line, the program will 'hang'
# on exit if running from IDLE.
pygame.quit ()
# %%
