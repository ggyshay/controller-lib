#define POT_RESOLUTION 4
#define POT_TIMEOUT 300
#include "arduino.h"

class Potentiometer {
  public:
    Potentiometer(byte control);
    Potentiometer();
    void setReading(byte value, unsigned long now);
    unsigned long potTime;
    bool moving;
    byte _value;
    byte _control;
    bool isMidiEnabled = false;
  private:
};


Potentiometer::Potentiometer(byte control)
{
  _control = control;
  _value = 0;
  isMidiEnabled = true;
}

Potentiometer::Potentiometer()
{
  isMidiEnabled = false;
  _control = 100;
  _value = 0x7F;
}

void Potentiometer::setReading(byte value, unsigned long now)
{
  if (_value - value > POT_RESOLUTION || _value - value < -POT_RESOLUTION)
  {
    potTime = now;
  }

  if (potTime + POT_TIMEOUT > now)
  {
    moving = true;
  }
  else
  {
    moving = false;
  }

  if (moving)
  {
    _value = value;
    if (isMidiEnabled){
      writeMIDI(0xB0, _control, _value);
    }
  }
}
