/*
Log in op WiFi en stuur mqtt boodskappe

Van hierdie voorbeeld:

https://www.emqx.com/en/blog/esp32-connects-to-the-free-public-mqtt-broker

N. Agenbag
2026-02-08

*/

#include <WiFi.h>
#include <PubSubClient.h>
#include "arduino_secrets.h"

// WiFi
int status = WL_IDLE_STATUS;
char ssid[] = SECRET_SSID;      // Wifi SSID
char password[] = SECRET_PASS;      // Wifi password
int keyIndex = 0;            // your network key Index number (needed only for WEP)

// MQTT Broker
const char *mqtt_broker = SECRET_HASS_IP;
const char *topic = "homeassistant/esp32/tank";
const char *mqtt_username = SECRET_MQTTUSER;
const char *mqtt_password = SECRET_MQTTPASSWORD;
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    for (int i = 0; i < length; i++) {
        Serial.print((char) payload[i]);
    }
    Serial.println();
    Serial.println("-----------------------");
}

void setup() {
    // Set software serial baud to 115200;
    Serial.begin(115200);
    // Connecting to a WiFi network
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the Wi-Fi network");
    //connecting to a mqtt broker
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(callback);

    while (!client.connected()) {
        String client_id = "esp32-client-";
        client_id += WiFi.macAddress();
        Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
        if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
            Serial.println("Public EMQX MQTT broker connected");
        } else {
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
        }
    }
    // Publish and subscribe
    client.publish(topic, "Hi, I'm ESP32 ^^");
    client.subscribe(topic);
}



void loop() {
    client.loop();
}