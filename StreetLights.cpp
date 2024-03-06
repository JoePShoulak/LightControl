#include "StreetLights.h"
#include <SimpleTimer.h>

StreetLights::StreetLights(int frontPin, int backPin, int leftPin, int rightPin, int blinkRate = 500)
{
  _front = Light(frontPin);
  _back = Light(backPin);
  _left = Light(leftPin);
  _right = Light(rightPin);

  _timer = SimpleTimer(blinkRate);
}

void StreetLights::begin()
{
  _front.begin();
  _back.begin();
  _left.begin();
  _right.begin();
}

void StreetLights::set(bool state)
{
  _front.set(state);
  _back.set(state);
  _left.set(state);
  _right.set(state);
}

void StreetLights::off()
{
  this->set(LOW);
}

void StreetLights::setMode(int mode)
{
  _mode = mode;
}

void StreetLights::setBrakes(bool state)
{
  _brakeState = state;
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
    _left.off();
    _right.off();
    return;
  }

  if (!_timer.isReady())
    return;

  _timer.reset();
  _blinkState = !_blinkState;

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
