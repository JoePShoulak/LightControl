#include <SimpleTimer.h>
#include "Light.h"

#ifndef OffroadLights_h
#define OffroadLights_h

class OffroadLights
{
public:
  OffroadLights(int frontPin, int backPin, int leftPin, int rightPin, int spotPin, int blinkRate = 500, bool amberDefault = false);

  virtual void begin();
  virtual void set(bool state);
  void off();

  void setMode(int mode);
  void setBrakes(bool state);
  void setSpot(bool state);

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
  bool _spotState;
  bool _amberDefault;

  SimpleTimer _timer;

  Light _front;
  Light _back;
  Light _left;
  Light _right;
  Light _spot;
};

#endif
