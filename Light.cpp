#include "Arduino.h"
#include "Light.h"

Light::Light(int pin)
{
  _pin = pin;
  _state = false;
}

void Light::begin()
{
  pinMode(_pin, OUTPUT);
}

void Light::on()
{
  _state = HIGH;
  digitalWrite(_pin, _state);
}

void Light::off()
{
  _state = LOW;
  digitalWrite(_pin, _state);
}

void Light::toggle()
{
  _state = !_state;
  digitalWrite(_pin, _state);
}

void Light::set(bool state)
{
  _state = state;
  digitalWrite(_pin, _state);
}