#include "Light.h"
#include <SimpleTimer.h>

#ifndef BasicLights_h
#define BasicLights_h

class BasicLights
{
public:
  BasicLights(int frontPin, int backPin, int blinkRate = 500);

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
  };

private:
  int _mode;
  bool _blinkState;
  bool _brakeState;

  SimpleTimer _timer;

  Light _front;
  Light _back;
};

#endif
