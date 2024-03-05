#include "Light.h"
#include <SimpleTimer.h>

#ifndef LightControl_h
#define LightControl_h

#include "Arduino.h"

class LightControl
{
public:
  LightControl(int leftPin, int rightPin, int frontPin, int backPin, int spotPin);
  void begin();

  void on();
  void off();

  int getMode();
  void setMode(int mode);

  void setBrakes(bool brakes);
  void setSpots(bool spots);

  void update();
  void updateAmbers();

private:
  int _mode;
  bool _blink;
  bool _brakes;
  bool _spots;

  SimpleTimer _timer;

  Light _left;
  Light _right;
  Light _front;
  Light _back;
  Light _spot;
};

#endif