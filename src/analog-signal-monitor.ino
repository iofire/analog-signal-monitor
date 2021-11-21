#include "config.h"
#include "analog-reader.h"
#include "relay-commander.h"
#include "alarm_supervisor.h"
#include "fault_supervisor.h"
#include "test_procedure.h"

AnalogReader faultInput(FAULT_INPUT_PIN, ANALOG_GAIN);
AnalogReader alarmInput(ALARM_INPUT_PIN, ANALOG_GAIN);

RelayCommander alarmRelay(ALARM_RELAY_PIN, ALARM_ACTIVE_POLARITY);
RelayCommander faultRelay(FAULT_RELAY_PIN, FAULT_ACTIVE_POLARITY);

AlarmSupervisor alarmSupervisor(&alarmRelay, &alarmInput);
FaultSupervisor faultSupervisor(&faultRelay, &alarmInput);

TestProcedure testButton(TEST_BUTTON_PIN);

void setup() {
  alarmInput.setVoltageReference(5.5);
  alarmSupervisor.setReferenceValue(0.0075*165);
  alarmSupervisor.setHysteresis(0.08);
  delay(SENSOR_WARMUP_TIME);
}

void loop() {
  alarmSupervisor.run();
  faultSupervisor.run();
  testButton.run();

  faultSupervisor.forceCondition(testButton.isTesting());
  digitalWrite(FAULT_LED_PIN, faultSupervisor.isFaultCondition());
}
