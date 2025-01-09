#include "Arduino.h"
#include <Wire.h>
#include <handelDisplay.h>
#include <handelMidi.h>
#include <rotary.h>
#include <joystick.h>
#include <main.h>

RotaryEncoder rotaryEncoder;
Joystick joystick;

USBMIDI_CREATE_DEFAULT_INSTANCE();

int valueX, valueY = 0;
int oldValueX, oldValueY = 0;
int deltaX, deltaY = 0;
int smoothedX, smoothedY = 0;
int scaleValueX, scaleValueY = 0;
int rotaryValue1, rotaryValue2, rotaryValue3, rotaryValue4, rotaryValue5, rotaryValue6, rotaryValue7, rotaryValue8 = 0;
bool screenReseted = true;
int buttonPageState = 0;
int buttonPage = 1;

int digitalPagePins[1] = {20};
int analogPins[2] = {A0, A1};
int digitalEncoderPins[2] = {0, 1};
unsigned long startTime = 0;

// void runButtons()
// {
//   for (unsigned int i=0; i<sizeof(buttonNumbers); i++)
//   {
//     *buttonStates[i] = digitalRead(digitalButtonPins[i]);

//     if(oldButtonStates[i] != buttonStates[i])
//     {
//       if(buttonStates[i] == LOW)
//       {
//         // Serial.println("Drück!");
//         MIDI.sendControlChange(buttonControlerChannel[buttonPage][i], 127, MIDI_CHANNEL);
//       }

//     oldButtonStates[i] = buttonStates[i];
//     }
//  }
// }

void setPinMode()
{
  for (unsigned int i = 0; i < sizeof(analogPins); i++)
  {
    pinMode(analogPins[i], INPUT);
  }
  for (unsigned int z = 0; z < sizeof(digitalPagePins); z++)
  {
    pinMode(digitalPagePins[z], INPUT);
  }
  for (unsigned int z = 0; z < sizeof(digitalEncoderPins); z++)
  {
    pinMode(digitalEncoderPins[z], INPUT);
  }
}
void buttonPageTurn()
{
  buttonState = digitalRead(20);

  if (oldButtonState != buttonState)
  {
    if (buttonState == LOW)
    {
      buttonPageState = 1;
      buttonPage++;

      if (buttonPage > 4)
      {
        buttonPage = 1;
      }
      displayButtonPageTurn(buttonPage);
    }
    else
    {
      buttonPageState = 0;
    }

    oldButtonState = buttonState;
  }
}

void setup()
{
  delay(500);
  // Serial.begin(9600);
  setPinMode();
  MIDI.begin(MIDI_CHANNEL_OMNI);
  delay(100);
  initialiseScreen();
  startTime = millis();
}

void loop()
{
  // runJoystick();
  // runButtons();
  /// buttonPageTurn();
  rotaryEncoder.encoderPage();
  // todo for loop over all rotaries
  rotaryEncoder.updateEncoder();
  joystick.joystickUpdate();
  blackScreen(SCREEN_TIMEOUT);
}
