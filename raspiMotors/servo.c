#include "servo.h"

void moveSensor(int pin, int grad){

	if(grad>180||grad<0){
	return ;
	}
        grad=grad+60+190.0/180.0;

        char c[64];
        sprintf(c,"echo P1-%d=%d > /dev/servoblaster",pin,grad);
        system(c);
}