/*  Arduino DC Motor Control - PWM | H-Bridge | L298N

    Beheer die motor met 'n enkele reostaat
*/

#define enA 9
#define in1 6
#define in2 7


void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {
  int potValue = analogRead(A0); // Read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  analogWrite(enA, pwmOutput); // Send PWM signal to L298N Enable pin

  Serial.println(pwmOutput);
}