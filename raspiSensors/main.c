#include <stdio.h>
#include "dht11.h"
#include "DS18B20.h"
#include "ads1115.h"
#include "luxmeter.h"
#include "pcf8591.h"
#include "ObstGyro.h"
#include "ObstHCSR.h"
#include "bme280.h"

int main( void )
{
	mpu6050_t mpu;
	bme280_t bme;
	bme280_t bme;
	dht11_t dht11_val;
	ads1115_t ads1115_val;
	int luxmeter_val;
	pcf8591_t pcf8591_val;

	read_dht_data(&dht11_val);
	float ds18b20 = read_ds18b20();
	ads1115(&ads1115_val);
	luxmeter_val= luxmeter();
	pcf8591(&pcf8591_val);

	printf( "Humidity = %.1f Temperature = %.1f C (%.1f F)\n", dht11_val->h, dht11_val->c, dht11_val->f);

	printf( "Temperature = %.2f *C\n", ds18b20);

	readGyro(mpu6050_t &mpu);
	printf("X rotation: %f\n", mpu->x);
	printf("Y rotation: %f\n", mpu->y);
	
	printf("Distance: %f ",readHCSR());

	readBME280(bme280_t &bme);
	printf("{\"sensor\":\"bme280\", \"humidity\":%.2f, \"pressure\":%.2f,"
    	" \"temperature\":%.2f, \"altitude\":%.2f}\n",
    	bme->humidity, bme->pressure, bme->temperature, bme->altitude);

	return(0);
}