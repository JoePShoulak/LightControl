#ifndef Light_h
#define Light_h

class Light
{
public:
  Light(int pin = 2);

  void begin();
  void on();
  void off();

  void set(bool state);

private:
  int _pin;
  bool _state;
};

#endif
