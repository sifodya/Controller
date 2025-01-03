#ifndef HANDELMIDI_H
#define HANDELMIDI_H
#include <USB-MIDI.h>
// #include <MIDI.h>
//Creates default instance for midi
extern usbMidi::usbMidiTransport __usbMIDI;
extern midi::MidiInterface<usbMidi::usbMidiTransport> MIDI;
#endif