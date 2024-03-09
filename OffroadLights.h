#include "StreetLights.h"

#ifndef OffroadLights_h
#define OffroadLights_h

class OffroadLights : public StreetLights
{
public:
  OffroadLights(int frontPin, int backPin, int leftPin, int rightPin, int spotPin, // Constructor
                int blinkRate = 500, bool amberDefault = false);

  virtual void begin() override;         // New begin function for new lights
  virtual void set(bool state) override; // Same with set

  void setSpot(bool state); // New function for a new state

  virtual void update() override; // New update (updateBlinkers stays the same this time)

protected:
  bool _spotState; // New state for the spotlight

  Light _spot; // New Light object for the spotlight
};

#endif
