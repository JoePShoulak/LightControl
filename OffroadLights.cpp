#include "OffroadLights.h"

OffroadLights::OffroadLights(int frontPin, int backPin, int leftPin, int rightPin, int spotPin, int blinkRate = 500, bool amberDefault = false)
    : StreetLights(frontPin, backPin, leftPin, rightPin, blinkRate, amberDefault) // Constructor
{
  _spot = Light(spotPin); // Init the new light with it's pin number
}

void OffroadLights::begin() // begin all the lights
{
  StreetLights::begin(); // begin the old lights

  _spot.begin(); // begin the new light
}

void OffroadLights::set(bool state) // set all the states
{
  StreetLights::set(state); // set the old states

  _spot.set(state); // set the new state
}

void OffroadLights::setSpot(bool state) // set the state of the spotlight
{
  _spotState = state;
}

void OffroadLights::update() // new update function to update the new pins
{
  if (_mode == LightMode::OFF)
    return this->off();

  if (_mode != LightMode::DISABLED)
  {
    _front.on();
    _back.set(_brakeState);
    _spot.set(_spotState);
  }

  this->updateBlinkers();
}
