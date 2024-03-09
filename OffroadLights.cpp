#include "OffroadLights.h"

OffroadLights::OffroadLights(int frontPin, int backPin, int leftPin, int rightPin, int spotPin, int blinkRate = 500, bool amberDefault = false)
    : StreetLights(frontPin, backPin, leftPin, rightPin, blinkRate, amberDefault)
{
  _spot = Light(spotPin);
}

void OffroadLights::begin()
{
  StreetLights::begin();

  _spot.begin();
}

void OffroadLights::set(bool state)
{
  StreetLights::set(state);

  _spot.set(state);
}

void OffroadLights::setSpot(bool state)
{
  _spotState = state;
}

void OffroadLights::update()
{
  if (_mode == MODE::OFF)
    return this->off();

  if (_mode != MODE::DISABLED)
  {
    _front.on();
    _back.set(_brakeState);
    _spot.set(_spotState);
  }

  this->updateBlinkers();
}
