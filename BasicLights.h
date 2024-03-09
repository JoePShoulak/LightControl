#ifndef BasicLights_h
#define BasicLights_h

/*
  A class for controlling multiple LEDs in an RC car
  Only including front lights and back lights
*/

#include <SimpleTimer.h> // We need this to blink the lights
#include "Light.h"       // This lets us control each light more simply

enum LightMode // The major modes the lights can be in
{
  OFF,
  RUNNING,
  HAZARDS,
  DISABLED,
  L_BLINK,
  R_BLINK
};

class BasicLights
{
public:
  BasicLights(int frontPin, int backPin, int blinkRate = 500); // Constructor, front lights, back lights,
                                                               // and a blinkRate in ms (defaults to 500)
  virtual void begin();                                        // Sets each Light's pinMode to output
  virtual void set(bool state);                                // Set all LEDs to the same state
  void off();                                                  // Turn off all LEDs

  void setMode(int mode);     // Change the mode of the car
  void setBrakes(bool state); // Change the brake status on the car

  virtual void update();         // Update all the LEDs of the car
  virtual void updateBlinkers(); // Update the blinkers (subroutine of update)

protected:
  int _mode;        // The major mode of the car
  bool _blinkState; // The state of the blinking lights
  bool _brakeState; // The state of the brakes

  SimpleTimer _timer; // The timer for blinking the lights

  Light _front; // The front light of the car (head lights)
  Light _back;  // The back lights of the car (brake lights)
};

#endif
