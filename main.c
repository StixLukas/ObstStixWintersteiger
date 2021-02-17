#include <stdio.h>
#include "dht11.h"
#include "DS18B20.h"
#include "ads1115.h"
#include "luxmeter.h"
#include "pcf8591.h"

int main( void )
{
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


	return(0);
}