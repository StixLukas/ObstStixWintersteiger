#include <stdio.h>
#include "dht11.h"
#include "DS18B20.h"

int main( void )
{
	dht11_t dht11_val; 
	read_dht_data(&dht11_val);
	float ds18b20 = read_ds18b20();

	printf( "Humidity = %.1f Temperature = %.1f C (%.1f F)\n", dht11_val->h, dht11_val->c, dht11_val->f);

	printf( "Temperature = %.2f *C\n", ds18b20);


	return(0);
}