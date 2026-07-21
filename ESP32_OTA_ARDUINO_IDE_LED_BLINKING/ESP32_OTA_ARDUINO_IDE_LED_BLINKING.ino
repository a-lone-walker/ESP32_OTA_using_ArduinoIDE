#include <ArduinoOTA.h>
#include <WiFi.h>

#include "credentials.h"

const int led_pin = 2;

void setup() {
  pinMode(led_pin, OUTPUT);
  WiFi.begin(SSID, PASSWORD);
  if(WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  ArduinoOTA.begin();
}

void loop() {
  ArduinoOTA.handle();

  digitalWrite(led_pin, HIGH);
  delay(1000);
  digitalWrite(led_pin, LOW);
  delay(1000);
}