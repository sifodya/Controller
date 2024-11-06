#ifndef MAIN_H
#define MAIN_H
#define MAX_ADC 1023 //max value read by adc
#define DELTA_THRESHOLD 3 //threshold to output midi data
#define ALPHA 0.9 // smoothing factor (0.0 to 1.0)
#define SCREEN_TIMEOUT 5000 //Screen return to black time in ms
#define MIDI_CHANNEL 3 //midi output channel


int valueX, valueY = 0;
int oldValueX, oldValueY = 0;
int deltaX, deltaY = 0;
int smoothedX, smoothedY = 0;
int scaleValueX, scaleValueY = 0;
int Index = 0;
int buttonPageState = 0;
int buttonPage = 1;
int encoderPage = 1;
int oldRotaryValue = 0;
int valueX1, valueX2, valueY1, valueY2;
int *joystickValue[4] = {&valueX1, &valueY1, &valueX2, &valueY2};
int smoothedValueX1, smoothedValueX2, smoothedValueY1, smoothedValueY2;
int *joystickSmoothedValue[4] = {&smoothedValueX1, &smoothedValueY1, &smoothedValueX2, &smoothedValueY2};
int oldValueX1, oldValueX2, oldValueY1, oldValueY2 = 0;
int *joystickOldValue [4] = {&oldValueX1, &oldValueY1, &oldValueX2, &oldValueY2};
int scaledValueX1, scaledValueX2, scaledValueY1, scaledValueY2;
int *joystickScaledValue [4] = {&scaledValueX1, &scaledValueY1, &scaledValueX2, &scaledValueY2};

bool buttonState1, buttonState2, buttonState3, buttonState4, buttonState5, buttonState6, buttonState7, buttonState8 = 0;
bool *buttonStates[8] = {&buttonState1, &buttonState2, &buttonState3, &buttonState4, &buttonState5, &buttonState6, &buttonState7, &buttonState8};
bool oldButtonState1, oldButtonState2, oldButtonState3, oldButtonState4, oldButtonState5, oldButtonState6, oldButtonState7, oldButtonState8 = 1;
bool *oldButtonStates[8] = {&oldButtonState1, &oldButtonState2, &oldButtonState3, &oldButtonState4, &oldButtonState5, &oldButtonState6, &oldButtonState7, &oldButtonState8};
int deltaX1, deltaX2, deltaY1, deltaY2 = 0;
int *deltaJoystickValues[4] = {&deltaX1, &deltaY1, &deltaX2, &deltaY2};
int rotaryValue1, rotaryValue2, rotaryValue3, rotaryValue4, rotaryValue5, rotaryValue6, rotaryValue7, rotaryValue8 = 0;
int *rotaryValues[8] = {&rotaryValue1, &rotaryValue2, &rotaryValue3, &rotaryValue4, &rotaryValue5, &rotaryValue6, &rotaryValue7, &rotaryValue8};


int buttonControlerChannel [4] [8] = {
  {0, 1, 2, 3, 4, 5, 6, 7},
  {8, 9, 10, 11, 12, 13, 14, 15},
  {16, 17, 18, 19, 20, 21, 22, 23},
  {24, 25, 26, 27, 28, 29, 30, 31}
};
int joystickControlerChannel [4] = {
  32, 33, 34, 35
};
int rotaryNumbers [8] = {1, 2, 3, 4, 5, 6, 7, 8};
int buttonNumbers [8] = {1, 2, 3, 4, 5, 6, 7, 8};

bool buttonState =0;
bool oldButtonState = 1;
bool screenReseted = true;

unsigned long startTime;
unsigned long currentTime;
unsigned long elapsedTime;

unsigned long *ptr_elapsedTime = &elapsedTime;
bool *ptr_screenReseted = &screenReseted;

void setPinMode();


#endif