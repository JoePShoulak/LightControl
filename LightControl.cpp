#include "LightControl.h"
#include <SimpleTimer.h>

// LightControl::LightControl(int leftPin, int rightPin, int frontPin, int backPin, int spotPin)
LightControl::LightControl(int leftPin, int rightPin, int frontPin, int backPin)
{
  _leftLight = Light(leftPin);
  _rightLight = Light(rightPin);
  _frontLight = Light(frontPin);
  _backLight = Light(backPin);
  // _spotLight = Light(spotPin);

  _timer = SimpleTimer(BLINKRATE);
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

void LightControl::setBrakes(bool brakes)
{
  _brake_status = brakes;
}

// void LightControl::setSpots(bool spots)
// {
//   _spots_status = spots;
// }

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
  _blink_status = !_blink_status;

  switch (_mode)
  {
  case MODE::L_BLINK:
    _leftLight.set(_blink_status);
    break;
  case MODE::R_BLINK:
    _rightLight.set(_blink_status);
    break;
  case MODE::HAZARDS:
    _leftLight.set(_blink_status);
    _rightLight.set(_blink_status);
    break;
  }
}

void LightControl::update()
{
  if (_mode == MODE::OFF)
    return this->off();

  _frontLight.on();
  _backLight.set(_brake_status);
  // _spotLight.set(_spots_status);

  this->updateAmbers();
}
