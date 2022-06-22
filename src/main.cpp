
#if true

#include <Arduino.h>
#include <QSerial.h>

void onData(String key, String value) {
  if(key == "led") digitalWrite(13, value.toInt());
  else QSerial.send("received." + key, value);
}

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  QSerial.init(&Serial, onData);
}

void loop() {
  QSerial.loop();
}

#endif
