/* Rolbeheer

Rolbeheer van 'n sweeftuig.
Meet die rolhoek met 'n ADXL335 versnellingsmeter
Beheer dan servos om rolroere te deflekteer om die rolhoek
na 0 setpunt te beheer.

Die servo moet gekoppel wees aan digitale pin 3
op die Arduino.

*/

// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 
// Create a servo object 
Servo Servo1; 


//Analog read pins
const int xPin = 0;
const int yPin = 1;
const int zPin = 2;

//The minimum and maximum values that came from
//the accelerometer while standing still
//You very well may need to change these
int minVal = 265;
int maxVal = 402;

//to hold the caculated values
double x;
double y;
double z;

void setup(){
  Serial.begin(9600); 

  // We need to attach the servo to the used pin number 
  Servo1.attach(servoPin); 
}

void loop(){

  //read the analog values from the accelerometer
  int xRead = analogRead(xPin);
  int yRead = analogRead(yPin);
  int zRead = analogRead(zPin);

  //convert read values to degrees -90 to 90 - Needed for atan2
  int xAng = map(xRead, minVal, maxVal, -90, 90);
  int yAng = map(yRead, minVal, maxVal, -90, 90);
  int zAng = map(zRead, minVal, maxVal, -90, 90);

  //Caculate 360deg values like so: atan2(-yAng, -zAng)
  //atan2 outputs the value of -π to π (radians)
  //We are then converting the radians to degrees
  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);

  //Output the caculations
  Serial.print("x: ");
  Serial.print(x);
  Serial.print(" | y: ");
  Serial.print(y);
  Serial.print(" | z: ");
  Serial.print(z);

  // Stel servo tot die hoek rondom x-as 
  // mits dit -180 grade tot +180 grade is
  if (x > 180) {
    Servo1.write(360 - x);
    Serial.print(" | servo: ");
    Serial.print(360 - x);} 
  if (x < 180) {
    Servo1.write(x);
    Serial.print(" | servo: ");
    Serial.print(x);
    }

  Serial.println(" ");
  
  delay(100);//just here to slow down the serial output - Easier to read
}
