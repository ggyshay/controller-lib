#include "arduino.h"

struct MidiMessage
{
    byte type = 0;
    byte velocity = 0;
    byte note = 0;
    byte channel = 0;
    byte value = 0;
};


class MIDIInterface {
    void sendNoteOn(){

    }
    void sendNoteOff() {

    }
    void sendControlChange(){

    }
    MidiMessage getMessage() {
        Serial.read();
        MidiMessage m;
        m.type = 
    }
}