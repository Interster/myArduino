/*

  WiFi UDP Send and Receive String

 This sketch wait an UDP packet on localPort using a WiFi shield.

 When a packet is received an Acknowledge packet is sent to the client on port remotePort

 Circuit:

 * WiFi shield attached

 created 30 December 2012

 by dlf (Metodo2 srl)

 */

#include <SPI.h>
#include <WiFiNINA.h> 
#include <WiFiUdp.h>
#include "arduino_secrets.h"
#include "Arduino_LSM6DS3.h"
// #include "Arduino_LSM9DS1.h"


int status = WL_IDLE_STATUS;
char ssid[] = SECRET_SSID;      // Wifi SSID
char pass[] = SECRET_PASS;      // Wifi password
int keyIndex = 0;            // your network key Index number (needed only for WEP)

unsigned int localPort = 1234;      // local port to listen on

char packetBuffer[255]; //buffer to hold incoming packet
char  ReplyBuffer[] = "acknowledged";       // a string to send back

WiFiUDP Udp;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  //Initialize serial and wait for port to open:

  Serial.begin(9600);

  while (!Serial) {

    ; // wait for serial port to connect. Needed for native USB port only

  }

  // check for the presence of the shield:

  if (WiFi.status() == WL_NO_SHIELD) {

    Serial.println("WiFi shield not present");

    // don't continue:

    while (true);

  }

  String fv = WiFi.firmwareVersion();

  if (fv != "1.1.0") {

    Serial.println("Please upgrade the firmware");

  }

  // attempt to connect to Wifi network:

  while (status != WL_CONNECTED) {

    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    

    // wait 10 seconds for connection:
    int counter = 0;
    while (counter++ < 10)
    {
      delay(1000);
      if (WiFi.status() == WL_CONNECTED)
      { 
        Serial.print("Connected ");
        break;
      }
    }
  }
  WiFi.config(IPAddress(172, 16, 16, 215));

  Serial.println("Connected to wifi");

  printWifiStatus();

  Serial.println("\nStarting connection to server...");

  // if you get a connection, report back via serial:

  Udp.begin(localPort);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }

  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");

}

float x, y, z;
bool start_sending = false;
int led_status = 0;
uint8_t packet_counter = 0;

void loop() {
  if (start_sending) {
    if (IMU.gyroscopeAvailable()) {
      IMU.readGyroscope(x, y, z);
      
      Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());

      Udp.write(&packet_counter, 1);
      Udp.write((const uint8_t *)&x, sizeof(x));
      Udp.write((const uint8_t *)&y, sizeof(y));
      Udp.write((const uint8_t *)&z, sizeof(z));

      packet_counter += 1;

      Udp.endPacket();

      // Serial.print(x);
      // Serial.print('\t');
      // Serial.print(y);
      // Serial.print('\t');
      // Serial.println(z);
    }
  }
  else { 
    int packetSize = Udp.parsePacket();
    Serial.print(".");
    
    digitalWrite(LED_BUILTIN, led_status);
    led_status = !led_status;
    // Serial.print(packetSize);

    if (packetSize) {
      start_sending = true;
      digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
      Serial.println("\nNow Sending Gyro Data");
    }
    delay(1000);
  }
}

void printWifiStatus() {

  // print the SSID of the network you're attached to:

  Serial.print("SSID: ");

  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:

  IPAddress ip = WiFi.localIP();

  Serial.print("IP Address: ");

  Serial.println(ip);

  // print the received signal strength:

  long rssi = WiFi.RSSI();

  Serial.print("signal strength (RSSI):");

  Serial.print(rssi);

  Serial.println(" dBm");
}