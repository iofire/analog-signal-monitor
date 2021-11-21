#include "fault_supervisor.h"

FaultSupervisor::FaultSupervisor(RelayCommander *faultRelay, AnalogReader *alarmReader, AnalogReader *powerStatus) {
  _faultRelay = faultRelay;
  _alarmReader = alarmReader;
  _powerStatus = powerStatus;
  _fault_condition = false;
  _forced_condition = false;
}

FaultSupervisor::FaultSupervisor(RelayCommander *faultRelay, AnalogReader *alarmReader) {
  _faultRelay = faultRelay;
  _alarmReader = alarmReader;
  _powerStatus = alarmReader;
  _fault_condition = false;
  _forced_condition = false;
}

bool FaultSupervisor::isFaultCondition() {
  return _fault_condition;
}
void FaultSupervisor::forceCondition(bool cond) {
  _forced_condition = cond;
}

void FaultSupervisor::run() {
  if((_alarmReader->compare(FAULT_SIGNAL_VALUE) <= 0) || (_powerStatus->compare(FAULT_SIGNAL_VALUE) <= 0) || _forced_condition) {
    _fault_condition = true;
  } else {
    _fault_condition = false;
  }

  if(isFaultCondition()) {
    _faultRelay->on();
  } else {
    _faultRelay->off();
  }
}
