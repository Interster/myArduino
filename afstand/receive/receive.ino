/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "printf.h"

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
  // initialize the transceiver on the SPI bus
  if (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
    while (1) {} // hold in infinite loop
  }
  radio.openReadingPipe(0, address);
  radio.setAutoAck(false);
  radio.setChannel(0); //select a channel (in which there is no noise!) 0 ... 125
  radio.setDataRate(RF24_250KBPS); // Lowest datarate
  radio.setPALevel(RF24_PA_MAX); // Maximum power
  radio.startListening();

  // For debugging info
  printf_begin();             // needed only once for printing details
  // radio.printDetails();       // (smaller) function that prints raw register values
  radio.printPrettyDetails(); // (larger) function that prints human readable data

}

void loop() {
  
    if(radio.available()) {
      radio.read(&data, sizeof(Data_Package));
    }
    
    Serial.print("j1PotX: ");
    Serial.println(data.j1Potx);

}
