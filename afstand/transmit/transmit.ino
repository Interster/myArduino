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

const byte address[6] = "00001";

// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package {
  byte j1Potx;
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
}

void loop() {
  // const char text[] = "Hello World";
  // radio.write(&text, sizeof(text));

  data.j1Potx - map(analogRead(A0), 0, 1023, 0, 255); // Convert the analog read value from 0 to 1023 into a BYTE value from 0 to 255
  radio.write(&data, sizeof(Data_Package));
  
  Serial.println("Sent message");
  delay(1000);
}
