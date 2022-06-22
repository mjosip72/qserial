
#include "QSerial.h"

void qserial_t::init(HardwareSerial* serial, on_qserial_data_func onData) {
  _serial = serial;
  _onData = onData;
}

void qserial_t::loop() {

  if(_serial == nullptr) return;
  if(_serial->available() == 0) return;

  String data = _serial->readStringUntil('\n');

  int keyValueSeparator = data.indexOf('=');
  if(keyValueSeparator == -1) return;

  String key = data.substring(0, keyValueSeparator);
  String value = data.substring(keyValueSeparator + 1);
  
  _onData(key, value);

}

void qserial_t::send(String key, String value) {
  String message = key + '=' + value + '\n';
  _serial->print(message);
}

qserial_t QSerial;
