/*
* Arduino radiobeheer vir Old Fogey
* 
* N. Agenbag 2022-11-14
* 
* Radiobeheer ontvanger van die Old Fogey
* 
* Die Old Fogey het net gier en heivlak asook
* motorkrag beheer.
* 
* Die heivlak servo word gekoppel op D2 of 
* digitale pen 2.
* Die gier servo word gekoppel op D3 of 
* digitale pen 3.
* Die motor word gekoppel op D4 of digitale pen 4.
* 
* Die RF24 radio gebruik digitale pen 7 en 8.
* 
* Die radio ontvanger word met 'n Arduino Nano
* implementeer omdat dit kompak is en lae massa
* het.
*/

// Volgende word gebruik vir radio:
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "printf.h"


// Volgende word gebruik vir servos en motor:
#include <Servo.h> 

// Definieer die radio:
RF24 radio(7, 8); // CE, CSN
// Radio se adres:
const byte address[6] = "00001";


// Definieer die beheervlak servos:
int heiServoPen = 2; 
int gierServoPen = 3; 
int ESCmotorPen = 4;
// Definieer die uitskryf veranderlikes
int heiWaarde;
int gierWaarde;
int motorWaarde;
// Skep heivlak, gier en motor servo objekte 
Servo HeiServo2; 
Servo GierServo3; 
Servo ESCmotor4;

// Definieer die data pakket wat die radio stuur/ontvang.
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

  // Maak servos vas aan die digitale pen nommers.
  HeiServo2.attach(heiServoPen); 
  GierServo3.attach(gierServoPen);
  ESCmotor4.attach(ESCmotorPen, 1000, 2000); // (pen, min pulswydte, maks pulswydte in mikrosekondes) 
}

void loop() {
  
  // Indien radio beskikbaar is, lees data:
  if(radio.available()) {
    radio.read(&data, sizeof(Data_Package));

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
    Serial.println("   Boodskap ontvang");
  
    Serial.println("------------------------------");
    // Skryf servo opdragte:  90 grade is die middel van bereik.
    heiWaarde = map(data.jhei, 0, 255, 0, 180); 
    Serial.print("hei Servo "); Serial.print(heiWaarde);
    HeiServo2.write(90); // Skryf net na middelwaarde vir toets.
  
    gierWaarde = map(data.jgier, 0, 255, 0, 180); 
    Serial.print(" gier Servo "); Serial.print(gierWaarde);
    GierServo3.write(90); // Skryf net na middelwaarde vir toets.
  
    motorWaarde = map(data.jmotor, 0, 255, 0, 180); 
    Serial.print(" motor "); Serial.println(motorWaarde);
    // Stuur sein na die elektroniese spoedbeheer van motor (ESC)
    // 0 is stilstaande en 180 is maksimum spoed
    ESCmotor4.write(0);  
    Serial.println("------------------------------");
  
  }
    


  // Moet herstel roetine bysit vir as kommunikasie onderbreek word.
}
