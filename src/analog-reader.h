#ifndef __ANALOG_READER_H__
#define __ANALOG_READER_H__

#define DEFAULT_TOLERANCE 0.00001F
#define ADC_RESOLUTION 1023.0F

class AnalogReader {
  public:
  AnalogReader(int pin, double upper_r, double lower_r);
  AnalogReader(int pin, double gain);

  double read();
  unsigned int readRaw();
  int compare(double ref);
  void setVoltageReference(double volt_ref);

  private: 
  int _pin;
  double _gain;
  double _tolerance;
  double _voltage_ref;
};

#endif //__ANALOG_READER_H__