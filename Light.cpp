#include "Arduino.h"
#include "Light.h"

Light::Light(int pin) // Constructor, requires the pin that controls the light
{
  _pin = pin;
}

void Light::begin() // Sets the light's pinMode to output
{
  pinMode(_pin, OUTPUT);
}

void Light::set(bool state) // Sets the light to be on if true or off if false
{
  digitalWrite(_pin, state);
}

void Light::on() // Turns the light on
{
  this->set(HIGH);
}

void Light::off() // Turns the light off
{
  this->set(LOW);
}
