#include <Arduino.h>
#ifndef JOYSTICK_H
#define JOYSTICK_H
class Joystick
{
    private:
    #define DELTA_THRESHOLD 3 //threshold to output midi data
    #define MAX_ADC 1023 //max value read by adc
    #define ALPHA 0.9 // smoothing factor (0.0 to 1.0)
    int valueX, valueY = 0;
    int smoothedX, smoothedY = 0;
    int deltaX, deltaY = 0;
    //int scaleValueX, scaleValueY = 0;
    public:
    void updatedDisplay(int joystickvalueX, int joystickValueY);
    void joystickUpdate ();
};
#endif