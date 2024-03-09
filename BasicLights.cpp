#include <SimpleTimer.h> // We need this to blink the lights
#include "BasicLights.h"

BasicLights::BasicLights(int frontPin, int backPin, int blinkRate = 500) // Constructor, front lights, back lights,
                                                                         // and a blinkRate in ms (defaults to 500)
{
  _front = Light(frontPin); // init the front Light by giving it the pin
  _back = Light(backPin);   // init the back Light by giving it the pin

  _timer = SimpleTimer(blinkRate); // init the timer by giving it a blinkRate
}

void BasicLights::begin() // Begin each light
{
  _front.begin();
  _back.begin();
}

void BasicLights::set(bool state) // Set all lights to one state
{
  _front.set(state);
  _back.set(state);
}

void BasicLights::off() // Set all lights off
{
  this->set(LOW);
}

void BasicLights::setMode(int mode) // Set the mode
{
  _mode = mode;
}

void BasicLights::setBrakes(bool state) // Set the brake state
{
  _brakeState = state;
}

void BasicLights::update() // Update all the lights
{
  if (_mode == LightMode::OFF) // If the mode is off, shut off all lights and return
    return this->off();

  if (_mode == LightMode::RUNNING) // If we're in the running mode (default)...
  {
    _front.on();            // Always on
    _back.set(_brakeState); // Matches the brake state
    return;
  }

  this->updateBlinkers(); // Update blinkers
}

void BasicLights::updateBlinkers()
{
  if (!_timer.isReady()) // If timer is not ready, nothing to update, return
    return;

  _timer.reset();      // Reset the timer so it can trigger again
  _blinkState ^= true; // Invert the blinkState

  switch (_mode) // Based on the mode...
  {
  case LightMode::HAZARDS:  // If Hazards...
    _front.on();            // Front stays on,
    _back.set(_blinkState); // Back blinks
    break;
  default:                  // If Disabled or invalid...
    this->set(_blinkState); // All blink
    break;
  }
}
