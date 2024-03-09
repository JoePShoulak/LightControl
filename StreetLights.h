#ifndef StreetLights_h
#define StreetLights_h

/*
  A class for controlling multiple LEDs in an RC car
  Includes front, back, and left/right signal lights
*/

#include "BasicLights.h"

class StreetLights : public BasicLights
{
public:
  StreetLights(int frontPin, int backPin, int leftPin, int rightPin,
               int blinkRate = 500, bool amberDefault = false); // Constructor, 4 pins for light control
                                                                // blinkRate in ms (default 500)
                                                                // amberDefault state (default false)

  virtual void begin() override;         // More lights, more pins, more begin functionality
  virtual void set(bool state) override; // More lights, must also update the set function

  virtual void update() override;         // Different behavior, different update function
  virtual void updateBlinkers() override; // Blinkers function differently now too

protected:
  bool _amberDefault; // The default state of the left/right signaling lights

  Light _left;  // Left light
  Light _right; // Right light
};

#endif
