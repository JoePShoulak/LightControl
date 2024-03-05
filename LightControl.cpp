#include "LightControl.h"
#include <SimpleTimer.h>

// LightControl::LightControl(int leftPin, int rightPin, int frontPin, int backPin, int spotPin, int blinkRate = 500)
LightControl::LightControl(int leftPin, int rightPin, int frontPin, int backPin, int blinkRate = 500)
{
  _leftLight = Light(leftPin);
  _rightLight = Light(rightPin);
  _frontLight = Light(frontPin);
  _backLight = Light(backPin);
  // _spotLight = Light(spotPin);

  _timer = SimpleTimer(blinkRate);
}

void LightControl::begin()
{
  _leftLight.begin();
  _rightLight.begin();
  _frontLight.begin();
  _backLight.begin();
  // _spotLight.begin();
}

void LightControl::set(bool state)
{
  _leftLight.set(state);
  _rightLight.set(state);
  _frontLight.set(state);
  _backLight.set(state);
  // _spotLight.set(state);
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

// void LightControl::setSpots(bool state)
// {
//   _spotState = state;
// }

void LightControl::update()
{
  if (_mode == MODE::OFF)
    return this->off();

  if (_mode != MODE::DISABLED)
  {
    _frontLight.on();
    _backLight.set(_brakeState);
    // _spotLight.set(_spotState);
  }

  this->updateBlinkers();
}

void LightControl::updateBlinkers()
{
  if (_mode == MODE::RUNNING)
  {
    _leftLight.off();
    _rightLight.off();
    return;
  }

  if (!_timer.isReady())
    return;

  _timer.reset();
  _blinkState = !_blinkState;

  switch (_mode)
  {
  case MODE::L_BLINK:
    _leftLight.set(_blinkState);
    break;
  case MODE::R_BLINK:
    _rightLight.set(_blinkState);
    break;
  case MODE::HAZARDS:
    _leftLight.set(_blinkState);
    _rightLight.set(_blinkState);
    break;
  case MODE::DISABLED:
    this->set(_blinkState);
    break;
  }
}
