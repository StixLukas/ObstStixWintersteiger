#ifndef ADS1115_H
#define ADS1115_H

#include <stdlib.h>
#include <stdio.h>

int ads1115(ads1115_t);

typedef struct ads1115{
    int ldr;
    int ntc;
} ads1115_t;
#endif