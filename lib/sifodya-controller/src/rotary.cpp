#include <rotary.h>
#include <Display.h>
#include <handelMidi.h>
#include <main.h>

void RotaryEncoder::encoderPage()
{
 buttonState = digitalRead(digitalPagePins[0]);

    if(oldButtonState != buttonState)
    {
      if(buttonState == LOW)
      { 
        indexEncoderPage++;

        if(indexEncoderPage > 4)
        indexEncoderPage=1;

        display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.print("Encoder Page ");
  display.println(indexEncoderPage);
  display.display();
  elapsedTime = millis();
  screenReseted = false;
      }

    oldButtonState = buttonState;
    
  }   
}

void RotaryEncoder::updateEncoder()
{
  // Pin A, Pin B, Button Pin
  //todo Pins abreifen mit Multi Arra und encoder indes
  SimpleRotary simpleRotary(digitalEncoderPins[0], digitalEncoderPins[1], NULL);

    byte i;

    // 0 = not turning, 1 = CW, 2 = CCW
    i = simpleRotary.rotate();

    switch (i)
    {
    case 0:
      break;
    
    case 1:
      rotaryValue1++;
      rotaryValue1 = rotaryValueCheck(rotaryValue1);
      MIDI.sendControlChange(encoderControlerChannel[indexEncoderPage][encoderIndex], rotaryValue1, MIDI_CHANNEL);

      rotaryDisplayUpdate(rotaryValue1, encoderIndex);
      break;
      
    case 2:
      rotaryValue1--;
      rotaryValue1 = rotaryValueCheck(rotaryValue1);
      MIDI.sendControlChange(encoderControlerChannel[indexEncoderPage][encoderIndex], rotaryValue1, MIDI_CHANNEL);
      rotaryDisplayUpdate(rotaryValue1, encoderIndex);
      break;

    default:
      break;
    }
}

int RotaryEncoder::rotaryValueCheck(int rotaryValue)
{
    if(rotaryValue > 127)
    {
      rotaryValue = 0;
    }
    if (rotaryValue<0)
    {
      rotaryValue = 127;
    }
    return rotaryValue;
}
void RotaryEncoder::rotaryDisplayUpdate(int rotaryValue, int index)
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print("Rotary: ");
  display.print(index);
  display.setCursor(80, 10);
  display.println(rotaryValue);
  display.display();
  elapsedTime = millis();
  screenReseted = false;
}
