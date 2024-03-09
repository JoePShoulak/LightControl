#include "StreetLights.h"

#ifndef OffroadLights_h
#define OffroadLights_h

class OffroadLights : public StreetLights
{
public:
  OffroadLights(int frontPin, int backPin, int leftPin, int rightPin, int spotPin, int blinkRate = 500, bool amberDefault = false);

  virtual void begin() override;
  virtual void set(bool state) override;

  void setSpot(bool state);

  virtual void update() override;

protected:
  bool _spotState;

  Light _spot;
};

#endif
