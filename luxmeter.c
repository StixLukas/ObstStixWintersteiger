#include <wiringPiI2C.h>
#include <stdio.h>
int luxmeter(){
	int handle = wiringPiI2CSetup(0x5C);
	wiringPiI2CWrite(handle,0x01);
	wiringPiI2CWrite(handle,0x21);
	int word = wiringPiI2CReadReg16(handle,0x00);
	int lux=((word & 0xff00)>>8) | ((word & 0x00ff)<<8);
	printf("Aktuelle Beleuchtungsstärke in Lux: %d\n",lux);
	return 0;
}
