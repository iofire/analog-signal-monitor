#ifndef __FAULT_SUPERVISOR_H__
#define __FAULT_SUPERVISOR_H__

#include "relay-commander.h"
#include "analog-reader.h"
#include "config.h"

#define FAULT_SIGNAL_VALUE 0.05F

class FaultSupervisor {
  public: 
  FaultSupervisor(RelayCommander *faultRelay, AnalogReader *alarmReader, AnalogReader *powerStatus);
  FaultSupervisor(RelayCommander *faultRelay, AnalogReader *alarmReader);
  
  void setRefereceValue(double ref);
  void run();
  bool isFaultCondition();
  void forceCondition(bool cond);

  private:
  double _ref_value; 
  bool _fault_condition;
  bool _forced_condition;
  RelayCommander *_faultRelay;
  AnalogReader *_alarmReader;
  AnalogReader *_powerStatus;
};

#endif //__FAULT_SUPERVISOR_H__