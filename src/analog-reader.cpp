#include <Arduino.h>
#include "analog-reader.h"

AnalogReader::AnalogReader(int pin, double upper_r, double lower_r) {
  if(lower_r != 0) {
    _gain = (upper_r + lower_r) / lower_r;
  } else {
    _gain = lower_r;
  }
  _pin = pin;
  _tolerance = DEFAULT_TOLERANCE;
  _gain = ((upper_r + lower_r) == 0) ? 1 :(lower_r / (upper_r + lower_r));
}

AnalogReader::AnalogReader(int pin, double gain) {
  _pin = pin;
  _gain = gain;
}

double AnalogReader::read() {
  double voltage = readRaw() * (_voltage_ref / ADC_RESOLUTION);
  return(_gain * voltage);
}

unsigned int AnalogReader::readRaw() {
  return(analogRead(_pin));
}

int AnalogReader::compare(double ref) {
  double diff = read() - ref;
  
  if(diff >= _tolerance) {
    return 1;
  } else {
    
  }
  if(diff == 0) {
    return 0;
  } else if (diff > _tolerance) {
    return 1;
  } else {
    return -1;
  }
}

void AnalogReader::setVoltageReference(double volt_ref) {
  _voltage_ref = volt_ref;
}
