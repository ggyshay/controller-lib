#include "arduino.h"

class Multiplexer
{
public:
    Multiplexer(bool _is16, byte _initialPort, byte _inputPort, bool _isAnalog)
    {
        mask = _is16 ? 0B1111 : 0B111;
        initialPort = _initialPort;
        inputPort = _inputPort;
        isAnalog = _isAnalog;
    }
    int readOutput(byte n)
    {
        sendBits(n);
        if (isAnalog)
            return analogRead(inputPort);

        return digitalRead(inputPort) ? 1024 : 0;
    }
    void writeToOutput(byte n, int value)
    {
        sendBits(n);
        if (isAnalog)
        {
            analogWrite(inputPort, value);
        }
        else
        {
            digitalWrite(intputPort, value > 512);
        }
    }

private:
    byte mask;
    byte initialPort;
    byte inputPort;
    bool isAnalog;
    void sendBits(byte i)
    {
        PORTD &= ~(mask << initialPort);
        PORTB &= ~(mask >> (8 - initialPort));
        PORTD |= (i << initialPort);
        PORTB |= (i >> (8 - initialPort));
    }
}