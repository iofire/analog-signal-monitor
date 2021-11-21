#ifndef __ALARM_SUPERVISOR_H__
#define __ALARM_SUPERVISOR_H__

#include "relay-commander.h"
#include "analog-reader.h"

class AlarmSupervisor {
  public: 
  AlarmSupervisor(RelayCommander *alarmRelay, AnalogReader *alarmReader);
  
  void setReferenceValue(double ref);
  double getReferenceValue();

  void setHysteresis(double hyst);
  double getHysteresis();

  bool isAlarmCondition();

  void run();

  private:
  double _ref;
  double _hyst_upper_limit, _hyst_lower_limit;
  bool _alarm_condition;
  RelayCommander *_alarmRelay;
  AnalogReader *_alarmReader;
};

#endif //__ALARM_SUPERVISOR_H__