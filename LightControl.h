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
  virtual void off();

  void setMode(int mode);
  void setBrakes(bool state);
  // void setSpots(bool state);

  virtual void update();
  void updateAmbers();

  enum MODE
  {
    OFF,
    READY,
    L_BLINK,
    R_BLINK,
    HAZARDS
  };

private:
  int _mode;
  bool _blinkState;
  bool _brakeState;
  // bool _spotState;

  SimpleTimer _timer;

  Light _leftLight;
  Light _rightLight;
  Light _frontLight;
  Light _backLight;
  // Light _spotLight;
};

#endif
