#include "Light.h"
#include <SimpleTimer.h>

#ifndef StreetLights_h
#define StreetLights_h

class StreetLights
{
public:
  StreetLights(int frontPin, int backPin, int leftPin, int rightPin, int blinkRate = 500, bool amberDefault = false);

  virtual void begin();
  virtual void set(bool state);
  virtual void off();

  void setMode(int mode);
  void setBrakes(bool state);

  virtual void update();
  virtual void updateBlinkers();

  enum MODE
  {
    OFF,
    RUNNING,
    HAZARDS,
    DISABLED,
    L_BLINK,
    R_BLINK
  };

private:
  int _mode;
  bool _blinkState;
  bool _brakeState;
  bool _amberDefault;

  SimpleTimer _timer;

  Light _front;
  Light _back;
  Light _left;
  Light _right;
};

#endif
