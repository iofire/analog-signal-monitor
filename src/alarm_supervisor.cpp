#include "alarm_supervisor.h"

AlarmSupervisor::AlarmSupervisor(RelayCommander *alarmRelay, AnalogReader *alarmReader) {
  _alarmReader = alarmReader;
  _alarmRelay = alarmRelay;
  _alarm_condition = false;
}
void AlarmSupervisor::setReferenceValue(double ref) {
  _ref = ref;
}
double AlarmSupervisor::getReferenceValue() {
  return _ref;
}
void AlarmSupervisor::setHysteresis(double hyst) {
  _hyst_upper_limit = _ref + hyst;
  _hyst_lower_limit = _ref - hyst;
}
double AlarmSupervisor::getHysteresis() {
  return _hyst_upper_limit - _hyst_lower_limit;
}

bool AlarmSupervisor::isAlarmCondition() {
  return _alarm_condition;
}

void AlarmSupervisor::run() {
  if(_alarmReader->compare(_hyst_lower_limit) <= 0 ) {
    _alarm_condition = false;
  } else if (_alarmReader->compare(_hyst_upper_limit) >= 0) {
    _alarm_condition = true;
  }

  if(isAlarmCondition()) {
    _alarmRelay->on();
  } else {
    _alarmRelay->off();
  }
}