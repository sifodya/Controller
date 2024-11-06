#include "Arduino.h"
#include "MIDI.h"
#include "USB-MIDI.h"
#include "Wire.h"
#include <handelDisplay.cpp>
#include <SimpleRotary.h>
#include <rotary.cpp>
#include <pins.h>
#include <main.h>
#include <joystick.cpp>
#include <pins.h>

RotaryEncoder rotaryEncoder;
Joystick joystick;

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
  //runJoystick();
  //runButtons();
  ///buttonPageTurn();
  rotaryEncoder.encoderPage();
  //todo for loop over all rotaries
  rotaryEncoder.updateEncoder();
  joystick.joystickUpdate();
  blackScreen(SCREEN_TIMEOUT);

}

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
  for(unsigned int i=0; i<sizeof(analogPins); i++)
  {
    pinMode(analogPins[i], INPUT);
  }
  for(unsigned int z=0; z<sizeof(digitalPagePins); z++)
  {
    pinMode(digitalPagePins[z], INPUT);
  }
   for(unsigned int z=0; z<sizeof(digitalEncoderPins); z++)
  {
    pinMode(digitalEncoderPins[z], INPUT);
  }
}
void buttonPageTurn()
{
    buttonState = digitalRead(20);

    if(oldButtonState != buttonState)
    {
      if(buttonState == LOW)
      { 
        buttonPageState = 1;
        buttonPage++;

        if(buttonPage > 4)
        buttonPage=1;

        displayButtonPageTurn(buttonPage);
      }
      else
      {
        buttonPageState = 0;
      }

    oldButtonState = buttonState;
    
  }
}

