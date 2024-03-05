#include "Arduino.h"
#include "Light.h"

Light::Light(int pin)
{
  _pin = pin;
}

void Light::begin()
{
  pinMode(_pin, OUTPUT);
}

void Light::set(bool state)
{
  _state = state;
  digitalWrite(_pin, _state);
}

void Light::on()
{
  this->set(HIGH);
}

void Light::off()
{
  this->set(LOW);
}
