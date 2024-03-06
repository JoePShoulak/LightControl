#include "Light.h"
#include <SimpleTimer.h>

#ifndef LightControl_h
#define LightControl_h

class LightControl
{
public:
  // LightControl(int leftPin, int rightPin, int frontPin, int backPin, int spotPin, int blinkRate = 500);
  LightControl(int leftPin, int rightPin, int frontPin, int backPin, int blinkRate = 500);

  virtual void begin();
  virtual void set(bool state);
  virtual void off();

  void setMode(int mode);
  void setBrakes(bool state);
  // void setSpot(bool state);

  virtual void update();
  void updateBlinkers();

  enum MODE
  {
    OFF,
    RUNNING,
    L_BLINK,
    R_BLINK,
    HAZARDS,
    DISABLED
  };

private:
  int _mode;
  bool _blinkState;
  bool _brakeState;
  // bool _spotState;

  SimpleTimer _timer;

  Light _left;
  Light _right;
  Light _front;
  Light _back;
  // Light _spot;
};

#endif
