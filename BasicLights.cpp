#include <SimpleTimer.h>
#include "BasicLights.h"

BasicLights::BasicLights(int frontPin, int backPin, int blinkRate = 500)
{
  _front = Light(frontPin);
  _back = Light(backPin);

  _timer = SimpleTimer(blinkRate);
}

void BasicLights::begin()
{
  _front.begin();
  _back.begin();
}

void BasicLights::set(bool state)
{
  _front.set(state);
  _back.set(state);
}

void BasicLights::off()
{
  this->set(LOW);
}

void BasicLights::setMode(int mode)
{
  _mode = mode;
}

void BasicLights::setBrakes(bool state)
{
  _brakeState = state;
}

void BasicLights::update()
{
  if (_mode == MODE::OFF)
    return this->off();

  if (_mode == MODE::RUNNING)
  {
    _front.on();
    _back.set(_brakeState);
    return;
  }

  this->updateBlinkers();
}

void BasicLights::updateBlinkers()
{
  if (!_timer.isReady())
    return;

  _timer.reset();
  _blinkState ^= true;

  switch (_mode)
  {
  case MODE::HAZARDS:
    _front.on();
    _back.set(_blinkState);
    break;
  default: // DISABLED or invalid
    this->set(_blinkState);
    break;
  }
}
