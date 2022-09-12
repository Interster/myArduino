/* The following code will turn a servo motor 
to 0 degrees, wait 1 second, then turn it to 90, 
wait one more second, turn it to 180, and then 
go back.

Die servo moet gekoppel wees aan digitale pin 3
op die Arduino.
*/

// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
}
void loop(){ 
   // Make servo go to 0 degrees 
   Servo1.write(160); 
   delay(1000); 
   // Make servo go to 90 degrees 
   //Servo1.write(110); 
   //delay(1000); 
   // Make servo go to 180 degrees 
   Servo1.write(30); 
   delay(1000); 
}
