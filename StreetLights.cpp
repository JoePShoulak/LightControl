#include <SimpleTimer.h>
#include "StreetLights.h"

StreetLights::StreetLights(int frontPin, int backPin, int leftPin, int rightPin, int blinkRate = 500, bool amberDefault = false)
    : BasicLights(frontPin, backPin, blinkRate)
{
  _left = Light(leftPin);
  _right = Light(rightPin);

  _amberDefault = amberDefault;
}

void StreetLights::begin()
{
  BasicLights::begin();

  _left.begin();
  _right.begin();

  _left.set(_amberDefault);
  _right.set(_amberDefault);
}

void StreetLights::set(bool state)
{
  BasicLights::set(state);

  _left.set(state);
  _right.set(state);
}

void StreetLights::update()
{
  if (_mode == MODE::OFF)
    return this->off();

  if (_mode != MODE::DISABLED)
  {
    _front.on();
    _back.set(_brakeState);
  }

  this->updateBlinkers();
}

void StreetLights::updateBlinkers()
{
  if (_mode == MODE::RUNNING)
  {
    _left.set(_amberDefault);
    _right.set(_amberDefault);
    return;
  }

  if (!_timer.isReady())
    return;

  _timer.reset();
  _blinkState ^= true;

  switch (_mode)
  {
  case MODE::L_BLINK:
    _left.set(_blinkState);
    break;
  case MODE::R_BLINK:
    _right.set(_blinkState);
    break;
  case MODE::HAZARDS:
    _left.set(_blinkState);
    _right.set(_blinkState);
    break;
  default: // DISABLED or invalid
    this->set(_blinkState);
    break;
  }
}
