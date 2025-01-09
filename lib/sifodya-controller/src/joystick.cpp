#include <joystick.h>
#include <Display.h>
#include <handelMidi.h>
#include <main.h>

void Joystick::updatedDisplay(int joystickValueX, int joystickValueY)
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 2);
  display.print("Joystick X: ");
  display.print(joystickValueX);
  // display.setCursor(100, 2);
  // display.println(*joystickScaledValue[2]);
  display.setCursor(0, 12);
  display.print("Joystick Y: ");
  display.print(joystickValueY);
  // display.setCursor(100, 12);
  // display.println(*joystickScaledValue[3]);
  display.display();
  elapsedTime = millis();
  screenReseted = false;
}
void Joystick::joystickUpdate()
{
    valueX = analogRead(analogPins[0]);
    valueY = analogRead(analogPins[1]);
    smoothedX = ALPHA * valueX + (1 - ALPHA) * smoothedX;
    smoothedY = ALPHA * valueY + (1 - ALPHA) * smoothedY;

    //calculate delta of X
    deltaX = abs(smoothedX - oldValueX);
    deltaY = abs(smoothedY - oldValueY);
    //map X to Midi range
    if (deltaX > DELTA_THRESHOLD)
    {
    scaleValueX = map(smoothedX, 0, MAX_ADC, 0, 128);
    MIDI.sendControlChange(21, scaleValueX, 3);
    Joystick::updatedDisplay(scaleValueX, scaleValueY);
    }
    //update old Value
    oldValueX = smoothedX;

    //calculate delta of Y


    //map Y to Midi range
    if (deltaY > DELTA_THRESHOLD)
    {
        scaleValueY = map(smoothedY, 0, MAX_ADC, 0, 128);
        MIDI.sendControlChange(20, scaleValueY, 3);
        Joystick::updatedDisplay(scaleValueX, scaleValueY);
    }
    //update old Value
    oldValueY = smoothedY;

}