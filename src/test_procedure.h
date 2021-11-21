#ifndef __TEST_PROCEDURE_H__
#define __TEST_PROCEDURE_H__ 

#define DEFAULT_TEST_DELAY 0 //Retentive

class TestProcedure {
  public:
  TestProcedure(int pin);

  bool digitalReadWithDebounce(long delay_ms = 50);
  
  bool isTesting();

  void run(); 

  private:
  long _test_delay;
  long _last_test_time; 
  bool _is_test;
  int _pin;

};

#endif