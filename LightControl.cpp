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

void LightControl::off()
{
  _leftLight.off();
  _rightLight.off();
  _frontLight.off();
  _backLight.off();
  // _spotLight.off();
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

  _frontLight.on();
  _backLight.set(_brakeState);
  // _spotLight.set(_spotState);

  this->updateAmbers();
}

void LightControl::updateAmbers()
{
  if (_mode == MODE::READY)
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
  }
}
