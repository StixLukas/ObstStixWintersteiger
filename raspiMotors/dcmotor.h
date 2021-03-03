#ifndef __DC_MOTOR__
#define __DC_MOTOR__

#include <wiringPi.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


void dcmotor(int powerPin, int fwdPin, int bwdPin, int power, int isforward);

#endif