#include "LightControl.h"
#include <SimpleTimer.h>

#define BLINKRATE 500

LightControl::LightControl(int leftPin, int rightPin, int frontPin, int backPin, int spotPin)
{
  _left = Light(leftPin);
  _right = Light(rightPin);
  _front = Light(frontPin);
  _back = Light(backPin);
  _spot = Light(spotPin);

  _timer = SimpleTimer(BLINKRATE);
}

void LightControl::begin()
{
  _left.begin();
  _right.begin();
  _front.begin();
  _back.begin();
  _spot.begin();
}

void LightControl::on()
{
  _left.on();
  _right.on();
  _front.on();
  _back.on();
  _spot.on();
}

void LightControl::off()
{
  _left.off();
  _right.off();
  _front.off();
  _back.off();
  _spot.off();
}

void LightControl::setMode(int mode)
{
  _mode = mode;
}

void LightControl::setBrakes(bool brakes)
{
  _brakes = brakes;
}

void LightControl::setSpots(bool spots)
{
  _spots = spots;
}

void LightControl::updateAmbers()
{
  _timer.reset();
  _blink = !_blink;

  switch (_mode)
  {
  case MODE::L_BLINK:
    _left.set(_blink);
    break;
  case MODE::R_BLINK:
    _right.set(_blink);
    break;
  case MODE::HAZARDS:
    _left.set(_blink);
    _right.set(_blink);
    break;
  default:
    _left.off();
    _right.off();
    break;
  }
}

void LightControl::update()
{
  if (_mode == MODE::OFF)
    return this->off();

  _front.on();
  _back.set(_brakes);
  _spot.set(_spots);

  if (!_timer.isReady())
    return;

  this->updateAmbers();
}
