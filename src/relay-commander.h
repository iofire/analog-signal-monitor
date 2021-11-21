#ifndef __RELAY_COMMANDER_H__
#define __RELAY_COMMANDER_H__

class RelayCommander {
  public: 
  RelayCommander();
  RelayCommander(int pin);
  RelayCommander(int pin, int ac_pol);
  void setActivePolarity(int ac_pol);
  void on();
  void off(); 

  private: 
  int _pin;
  int _active_pol;
};

#endif// __RELAY_COMMANDER_H__
