#ifndef Light_h
#define Light_h

class Light
{
public:
  Light(int pin = 2);

  void begin();

  void set(bool state);
  void on();
  void off();

private:
  int _pin;
};

#endif
