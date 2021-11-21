#include <Arduino.h>
#include "relay-commander.h" 

RelayCommander::RelayCommander(int pin) {
  RelayCommander(pin, LOW);
}

RelayCommander::RelayCommander(int pin, int ac_pol) {
  _pin = pin;
  _active_pol = ac_pol;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, !_active_pol); // Default OFF state;
}

void RelayCommander::setActivePolarity(int ac_pol) {
  _active_pol = ac_pol;
}

void RelayCommander::on() {
  digitalWrite(_pin, _active_pol);
}

void RelayCommander::off() {
  digitalWrite(_pin, !_active_pol);
}
