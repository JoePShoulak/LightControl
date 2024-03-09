#ifndef Light_h
#define Light_h

/*
  A class for controlling an LED via Arduino digital pins,
  especially when in strings or other high-current applications
  where relays or transistors are needed
*/

class Light
{
public:
  Light(int pin = 2); // Constructor, requires the pin that controls the light

  void begin(); // Sets the light's pinMode to output

  void set(bool state); // Sets the light to be on if true or off if false
  void on();            // Turns the light on
  void off();           // Turns the light off

private:
  int _pin; // The pin that controls the LED
};

#endif
