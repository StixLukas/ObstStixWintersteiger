#ifndef __DHT11_H__
#define __DHT11_H__

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
	
	typedef struct dht11{
		float h;
		float c;
		float f;
	}dht11_t;

	void read_dht_data(dht11_t);

#endif