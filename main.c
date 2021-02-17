#include <stdio.h>
#include "dht11.h"
#include "DS18B20.h"

int main( void )
{
	float[2] dht = read_dht_data();;
	float ds18b20 = read_ds18b20();

	printf( "Humidity = %.1f %% Temperature = %.1f *C\n", dht[0], dht[1] );

	printf( "Temperature = %.2f *C\n", ds18b20);


	return(0);
}