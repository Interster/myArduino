/*
Program: Send Integers to Raspberry Pi
File: send_ints_to_raspberrypi.ino
Description: Send integers from Arduino to a Raspberry Pi
Author: Addison Sears-Collins
Website: https://automaticaddison.com
Date: July 5, 2020
*/
 
// Initialize the variables with some randomly-chosen integers
// that could represent servo motor angles, for example.
int servo_0_angle = 90;
int servo_1_angle = 7;
int servo_2_angle = 63;
int servo_3_angle = 85;
int servo_4_angle = 162;
int servo_5_angle = 45;
 
void setup(){
   
  // Set the baud rate  
  Serial.begin(9600);
   
}
 
void loop(){
   
  // Print integers every 500 milliseconds
  // We do println to add a new line character '\n' at the end
  // of the comma-separated stream of integers
  Serial.print(servo_0_angle); Serial.print(",");
  Serial.print(servo_1_angle); Serial.print(",");
  Serial.print(servo_2_angle); Serial.print(",");
  Serial.print(servo_3_angle); Serial.print(",");
  Serial.print(servo_4_angle); Serial.print(",");
  Serial.println(servo_5_angle); 
  delay(500);
}
