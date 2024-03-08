#include <SimpleTimer.h>
#include "OffroadLights.h"

OffroadLights::OffroadLights(int frontPin, int backPin, int leftPin, int rightPin, int spotPin, int blinkRate = 500, bool amberDefault = false)
{
  _front = Light(frontPin);
  _back = Light(backPin);
  _left = Light(leftPin);
  _right = Light(rightPin);
  _spot = Light(spotPin);

  _timer = SimpleTimer(blinkRate);
  _amberDefault = amberDefault;
}

void OffroadLights::begin()
{
  _front.begin();
  _back.begin();
  _left.begin();
  _right.begin();
  _spot.begin();

  _left.set(_amberDefault);
  _right.set(_amberDefault);
}

void OffroadLights::set(bool state)
{
  _front.set(state);
  _back.set(state);
  _left.set(state);
  _right.set(state);
  _spot.set(state);
}

void OffroadLights::off()
{
  this->set(LOW);
}

void OffroadLights::setMode(int mode)
{
  _mode = mode;
}

void OffroadLights::setBrakes(bool state)
{
  _brakeState = state;
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

void OffroadLights::updateBlinkers()
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
