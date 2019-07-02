#include "arduino.h"

class PushButton
{
public:
    void setReading(bool reading)
    {
        if (reading != lastButtonState)
            lastDebounceTime = millis();

        if ((millis() - lastDebounceTime) > debounceDelay)
        {
            if (reading != buttonState)
            {
                buttonState = reading;
                *value = buttonState;
            }
        }
        lastButtonState = reading;
    }

    PushButton(byte _note)
    {
        note = _note;
    }

private:
    byte note = 0;
    bool buttonState = false;
    bool lastButtonState = false;
    unsigned long lastDebounceTime = 0;
};

class Switch
{
    void setReading(bool reading)
    {
        if (reading != lastButtonState)
            lastDebounceTime = millis();

        if ((millis() - lastDebounceTime) > debounceDelay)
        {
            if (reading != buttonState)
            {
                buttonState = reading;
                if (buttonState == HIGH)
                    *value = !*value;
            }
        }
        lastButtonState = reading;
    }
}