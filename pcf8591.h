

#ifndef PCF8591_H
#define PCF8591_H

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <pcf8591.h>

#define PCF 120
int pcf8591(pcf8591_t);


typedef struct pcf8591{
    int ldr;
    int ntc;
} pcf8591_t;

#endif