
#pragma once

#include <Arduino.h>

typedef void (*on_qserial_data_func)(String, String);

class qserial_t {

  private:
  HardwareSerial* _serial;
  on_qserial_data_func _onData;

  public:

  void init(HardwareSerial*, on_qserial_data_func);
  void loop();
  void send(String, String);

};

extern qserial_t QSerial;
