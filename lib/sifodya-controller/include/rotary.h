#ifndef ROTARY_H
#define ROTARY_H
#include <SimpleRotary.h>

class RotaryEncoder
{
    private:
    int encoderControlerChannel [4] [8] = {
    {40, 41, 42, 43, 44, 45, 46, 47},
    {48, 49, 50, 51, 52, 53, 54, 55},
    {56, 57, 58, 59, 60, 61, 62, 63},
    {64, 65, 66, 67, 68, 69, 70, 71},
    };
    int indexEncoderPage = 1;
    int encoderIndex = 1;
    int buttonState = 0;
    int oldButtonState = 1;

public:
    RotaryEncoder()
    {
    }
    void updateEncoder();
    void encoderPage();
    void rotaryDisplayUpdate(int rotaryValue, int index);
    int rotaryValueCheck(int rotaryValue);

    ~RotaryEncoder()
    {}
};
#endif