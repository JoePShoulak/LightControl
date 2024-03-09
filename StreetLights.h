#include "BasicLights.h"

#ifndef StreetLights_h
#define StreetLights_h

class StreetLights : public BasicLights
{
public:
  StreetLights(int frontPin, int backPin, int leftPin, int rightPin, int blinkRate = 500, bool amberDefault = false);

  virtual void begin() override;
  virtual void set(bool state) override;

  virtual void update() override;
  virtual void updateBlinkers() override;

protected:
  bool _amberDefault;

  Light _left;
  Light _right;
};

#endif
