#include <Arduino.h>

#include "test_procedure.h"

TestProcedure::TestProcedure(int pin){
  _pin = pin;
  _is_test = false;
  pinMode(_pin, INPUT);
}

bool TestProcedure::digitalReadWithDebounce(long delay_ms) {
  if(digitalRead(_pin) == LOW) {
    delay(delay_ms);
    if(digitalRead(_pin) == LOW) {
      return false;
    }
  }
  return true;
}

bool TestProcedure::isTesting() {
  return _is_test;
}

void TestProcedure::run() {
  if(!isTesting()) {
    if(digitalReadWithDebounce() == LOW) {
      _is_test = true;
      _last_test_time = millis();
    } else {
      _is_test = false;
    }
  }

  if(isTesting()) {
    if(_test_delay > 0) {
      if((millis() - _last_test_time) >= _test_delay) {
        _is_test = false;
      }
    } else if(digitalReadWithDebounce() == HIGH) {
      _is_test = false;
    }
  }
}