#MIDI Controller Library
This library was designed in order to facilitate the creation of MIDI controllers.
## Push Button
Push Button is a momentary button, when pressed it can trigger a MIDI envent or call a callback function.

## Switch
This type of button has a fixed state, when the physical button is pressed this class inverts its value (it changes from 0 to 1 or from 1 to 0).

## Potentiometer
Represents a physical potentiometer. Use set reading in every loop. When changes are detected it can send MIDI mensages.

## Multiplexer
This is the abstraction of a multiplexer. On the constructor are defined: is16 (if your multiplexer has 16 channels instead of only 8), initial port (the arduino port that the selectors are connected, for example, if your mux is connected from 8 to 10 the number here is 8), inputPort (the port through which data is sent or received from the multiplexer) and isAnalog (is youf multiplexer is analog instead of digital).

## MIDIInterface
This is the interface to receive and send MIDI messages. 
### noteOn
sends a noteOn midi message, specify the note number, velociy and channel(TODO)

### noteOff
sends a noteOff MIDI message, specify the note number.

### ControlChanged
sends a CC message, specify the controller number and its new value.

### Get message
Gets the received message.

### MIDI messages
Midi messages are composed of:
- type: (noteOn, noteOff, CC ... )
- velocity: (the note velocity, not defined for messages other than noteOn)
- note: (the note number or controller number)
- channel: (the midi channel)
- value: (the controller new value, not defined for messages other than controllerChange)

## TODO
- update MIDI
- adapt potentiometer
- test
- create examples