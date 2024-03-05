#include "Light.h"
#include <SimpleTimer.h>

#ifndef LightControl_h
#define LightControl_h

class LightControl
{
  int BLINKRATE = 500;

public:
  // LightControl(int leftPin, int rightPin, int frontPin, int backPin, int spotPin);
  LightControl(int leftPin, int rightPin, int frontPin, int backPin);

  virtual void begin();
  virtual void off();

  void setMode(int mode);
  void setBrakes(bool brakes);
  // void setSpots(bool spots);

  virtual void update();
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
  bool _blink_status;
  bool _brake_status;
  // bool _spots_status;

  SimpleTimer _timer;

  Light _leftLight;
  Light _rightLight;
  Light _frontLight;
  Light _backLight;
  // Light _spotLight;
};

#endif
