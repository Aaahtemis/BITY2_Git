#include <ArduinoJson.h>
#include <ArduinoJson.hpp>

/**
 * BasicHTTPClient.ino
 *
 *  Created on: 24.05.2015
 *
 */

#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

WiFiMulti wifiMulti;
String api_key = "api_key=XVMOXMYW4OPDJZUX";
String update_url = "https://api.thingspeak.com/update?";

HTTPClient http;

const int analogPin = 34;


void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %u...\n", t);
    Serial.flush();
    delay(1000);
  }

  wifiMulti.addAP("D_Block_Lab", "P@ssw0rd");

  JsonDocument filter;
  filter["text"] = true;

}

void loop() {
  // wait for WiFi connection
  if ((wifiMulti.run() == WL_CONNECTED)) {

    HTTPClient http;
    int pos = analogRead(analogPin);
    String field1 = "field1=" + pos;
    String url = "https://api.thingspeak.com/update?api_key=XVMOXMYW4OPDJZUX&field1=" + String(pos);

    http.begin(url);  //HTTP
    int code = http.GET();
    Serial.println(code);
    //Serial.println(field1);
    Serial.println(url);
    Serial.println(pos);
    delay(15000); 
  }

}
