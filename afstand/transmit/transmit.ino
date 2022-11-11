/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

// Define the digital inputs
#define jgierLinks 1  // Joystick gier gelykvlug knop links
#define jgierRegs 0  // Joystick gier gelykvlug knop links

const byte address[6] = "00001";

// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package {
  byte jhei;
  byte jgier;
  byte jmotor;
  byte jgierGelykLinks;
  byte jgierGelykRegs;
};

Data_Package data; // Create a variable with the above struct

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setChannel(0); //select a channel (in which there is no noise!) 0 ... 125
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS); // Lowest datarate
  radio.setPALevel(RF24_PA_MAX); // Maximum power
  radio.stopListening();

  // Activate the Arduino internal pull-up resistors
  pinMode(jgierLinks, INPUT_PULLUP);
  pinMode(jgierRegs, INPUT_PULLUP);

  // Set beginwaardes van middel van stuurstok
  data.jhei = 127; // Values from 0 to 255. When Joystick is in resting position, the value is in the middle, or 127. We actually map the pot value from 0 to 1023 to 0 to 255 because that's one BYTE value
  data.jgier = 127;
  data.jmotor = 127;
  data.jgierGelykLinks = 1;
  data.jgierGelykRegs = 1;
}

void loop() {
  // const char text[] = "Hello World";
  // radio.write(&text, sizeof(text));

  // Lees alle analoog insette
  // Convert the analog read value from 0 to 1023 into a BYTE value from 0 to 255
  data.jhei = map(analogRead(A1), 0, 1023, 0, 255); 
  data.jgier = map(analogRead(A2), 0, 1023, 0, 255); 
  data.jmotor = map(analogRead(A2), 0, 1023, 0, 255); 

  // Lees alle digitale insette
  data.jgierGelykLinks = digitalRead(jgierLinks);
  data.jgierGelykRegs = digitalRead(jgierRegs);

  radio.write(&data, sizeof(Data_Package));

  // Ontfouting uitdruk in serie monitor
  Serial.print("jhei: ");
  Serial.print(data.jhei);
  Serial.print(" jgier: ");
  Serial.print(data.jgier);
  Serial.print(" jmotor: ");
  Serial.print(data.jmotor);
  Serial.print(" Links: ");
  Serial.print(data.jgierGelykLinks);
  Serial.print(" Regs: ");
  Serial.print(data.jgierGelykRegs);
  Serial.println(" Sent message");
  //delay(1000);
}
