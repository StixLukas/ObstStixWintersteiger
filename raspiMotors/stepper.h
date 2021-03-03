#ifndef __STEPPER__
#define __STEPPER__

#include <stdio.h>
#include <wiringPi.h>

void stepper(int pin1, int pin2, int pin3, int pin4, int speed, int steps);
void initPins(const int index);
void halfStep(int &index, bool dir);
void debugPrint(void);

#endif