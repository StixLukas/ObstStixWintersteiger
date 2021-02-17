#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <math.h>

typedef struct mpu6050{
	double x;
	double y;
}mpu6050_t;

void readGyro(mpu6050_t);
