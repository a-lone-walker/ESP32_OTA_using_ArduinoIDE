#include <ArduinoOTA.h>
#include <WiFi.h>

#include "credentials.h"

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Connecting to WiFi...");
  if(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi connected!");
  Serial.println(WiFi.localIP());

  ArduinoOTA.begin();
}

void loop() {
  ArduinoOTA.handle();
}