#ifndef Light_h
#define Light_h

#include "Arduino.h"

class Light
{
public:
  Light(int pin = 2);
  void begin();
  void on();
  void off();
  void toggle();
  void set(bool state);

private:
  int _pin;
  bool _state;
};

#endif