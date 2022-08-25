/*
Program: Receive Integers From Raspberry Pi
File: receive_ints_from_raspberrypi.ino
Description: Receive integers from a Raspberry Pi
Author: Addison Sears-Collins
Website: https://automaticaddison.com
Date: July 5, 2020
*/
 
// Initialize the integer variables
int servo_0_angle = 90;
int servo_1_angle = 90;
int servo_2_angle = 90;
int servo_3_angle = 90;
int servo_4_angle = 90;
int servo_5_angle = 90;
 
int sum = 0;
 
void setup(){
   
  // Set the baud rate  
  Serial.begin(9600);
   
}
 
void loop(){
 
  if(Serial.available() > 0) {
    servo_0_angle = Serial.parseInt();
    servo_1_angle = Serial.parseInt();
    servo_2_angle = Serial.parseInt();
    servo_3_angle = Serial.parseInt();
    servo_4_angle = Serial.parseInt();
    servo_5_angle = Serial.parseInt(); 
 
    // Compute a sum to prove we have integers
    sum = servo_0_angle + servo_1_angle;
 
    // We do println to add a new line character '\n' at the end
    // of the comma-separated stream of integers
    Serial.print(servo_0_angle); Serial.print(",");
    Serial.print(servo_1_angle); Serial.print(",");
    Serial.print(servo_2_angle); Serial.print(",");
    Serial.print(servo_3_angle); Serial.print(",");
    Serial.print(servo_4_angle); Serial.print(",");
    Serial.print(servo_5_angle); Serial.print(",");
    Serial.println(sum); 
  }
}
