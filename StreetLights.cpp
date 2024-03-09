#include <SimpleTimer.h>
#include "StreetLights.h"

StreetLights::StreetLights(int frontPin, int backPin, int leftPin, int rightPin, int blinkRate = 500, bool amberDefault = false)
    : BasicLights(frontPin, backPin, blinkRate)
{
  _left = Light(leftPin);   // init the left Light with its pin
  _right = Light(rightPin); // init the right Light with its pin

  _amberDefault = amberDefault; // The amberDefault controls if the signal lights blink "ON" or blink "OFF"
}

void StreetLights::begin() // Set all the pinModes to output
{
  BasicLights::begin(); // Call the inherited virtual

  _left.begin();  // begin our left light
  _right.begin(); // begin our right light

  _left.set(_amberDefault); // Set our ambers to their default state right away
  _right.set(_amberDefault);
}

void StreetLights::set(bool state) // Set all the lights to the same state
{
  BasicLights::set(state); // Set the old lights to the same state

  _left.set(state); // Set the new lights to the same state
  _right.set(state);
}

void StreetLights::update() // Our new update function
{
  if (_mode == LightMode::OFF)
    return this->off();

  if (_mode != LightMode::DISABLED)
  {
    _front.on();
    _back.set(_brakeState);
  }

  this->updateBlinkers();
}

void StreetLights::updateBlinkers() // Our new updateBlinkers function
{
  if (_mode == LightMode::RUNNING) // If running, just set ambers
  {
    _left.set(_amberDefault);
    _right.set(_amberDefault);
    return;
  }

  if (!_timer.isReady()) // If timer not ready, return out
    return;

  _timer.reset();      // Reset the timer to be ready for the next cycle
  _blinkState ^= true; // Invert the timer state

  switch (_mode) // Depending on the mode...
  {
  case LightMode::L_BLINK: // Left blink blinks the left light
    _left.set(_blinkState);
    break;
  case LightMode::R_BLINK: // Right blink blinks the right light
    _right.set(_blinkState);
    break;
  case LightMode::HAZARDS: // Hazards blinks both signal lights
    _left.set(_blinkState);
    _right.set(_blinkState);
    break;
  default: // DISABLED or invalid  blinks all lights
    this->set(_blinkState);
    break;
  }
}
