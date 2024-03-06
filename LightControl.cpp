#include "LightControl.h"
#include <SimpleTimer.h>

// LightControl::LightControl(int leftPin, int rightPin, int frontPin, int backPin, int spotPin, int blinkRate = 500)
LightControl::LightControl(int leftPin, int rightPin, int frontPin, int backPin, int blinkRate = 500)
{
  _left = Light(leftPin);
  _right = Light(rightPin);
  _front = Light(frontPin);
  _back = Light(backPin);
  // _spot = Light(spotPin);

  _timer = SimpleTimer(blinkRate);
}

void LightControl::begin()
{
  _left.begin();
  _right.begin();
  _front.begin();
  _back.begin();
  // _spot.begin();
}

void LightControl::set(bool state)
{
  _left.set(state);
  _right.set(state);
  _front.set(state);
  _back.set(state);
  // _spot.set(state);
}

void LightControl::off()
{
  this->set(LOW);
}

void LightControl::setMode(int mode)
{
  _mode = mode;
}

void LightControl::setBrakes(bool state)
{
  _brakeState = state;
}

// void LightControl::setSpot(bool state)
// {
//   _spotState = state;
// }

void LightControl::update()
{
  if (_mode == MODE::OFF)
    return this->off();

  if (_mode != MODE::DISABLED)
  {
    _front.on();
    _back.set(_brakeState);
    // _spot.set(_spotState);
  }

  this->updateBlinkers();
}

void LightControl::updateBlinkers()
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
