/* 

Skets wat 'n servo beheer om dieselfde hoek relatief
tot die aarde te hou.  Dit is vir 'n stabiele loop toepassing.

Gebruik saam met 'n Arduino Nano 33IOT.

N. Agenbag 2026-01-18
*/

#include <Servo.h>
#include <Arduino_LSM6DS3.h>


Servo myservo;  // create servo object to control a servo

// Veranderlikes wat die aanvangshoek bepaal
float x, y, z, setpunt, meet, beginhoek;

void setup() {
  Serial.begin(9600);  // Begin seriepoort uit vir ontfouting

  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }

  // Toets uitlesing van die versnellingsmeter
  Serial.print("Versnellingsmeter monsterfrekwensie = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Versnelling in g");
  Serial.println("X\tY\tZ");

  // Druk die aanvangswaarde van die versnellingsmeter
  // om die hoek te bepaal
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    // setpunt in grade
    setpunt = atan2(y, x) * (180 / PI);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
    Serial.print('Setpunt ');
    Serial.print(setpunt);
    Serial.println(' degrees');
  }

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  beginhoek = 45;  // waarde tussen 0 en 180 grade.  Stel dit in met loop opstelling
  myservo.write(beginhoek); 
}

void loop() {
  // Lees die versnellingsmeterwaarde en bereken die nuwe hoek
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    meet = atan2(y, x) * (180 / PI);
  }

  // Stel die servo na die nuwe posisie, indien dit verander het tot naaste graad
  myservo.write(beginhoek + round(setpunt - meet));
  delay(15);                           // waits for the servo to get there
}
