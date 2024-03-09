#include <SimpleTimer.h>
#include "Light.h"

#ifndef BasicLights_h
#define BasicLights_h

enum MODE
{
  OFF,
  RUNNING,
  HAZARDS,
  DISABLED,
  L_BLINK,
  R_BLINK
};

class BasicLights
{
public:
  BasicLights(int frontPin, int backPin, int blinkRate = 500);

  virtual void begin();
  virtual void set(bool state);
  void off();

  void setMode(int mode);
  void setBrakes(bool state);

  virtual void update();
  virtual void updateBlinkers();

protected:
  int _mode;
  bool _blinkState;
  bool _brakeState;

  SimpleTimer _timer;

  Light _front;
  Light _back;
};

#endif
