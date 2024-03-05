#include "Light.h"
#include <SimpleTimer.h>

#ifndef LightControl_h
#define LightControl_h

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

  enum MODE
  {
    OFF = -1,
    READY = 0,
    L_BLINK = 1,
    R_BLINK = 2,
    HAZARDS = 3
  };

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
