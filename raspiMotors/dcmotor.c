#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DELAY 100

int main (void)
{ 
	dcmotor(38, 40, 36, 300, 1); // forward	
	dcmotor(38, 40, 36, 500, 0); // backwards
}


void dcmotor(int powerPin, int fwdPin, int bwdPin, int power, int isforward){
	
	if (wiringPiSetupPhys () == -1)
		exit (1) ;

	pinMode (powerPin, PWM_OUTPUT) ;
	pinMode(bwdPin, OUTPUT);
	pinMode(fwdPin, OUTPUT);


	if(isforward==1){
		digitalWrite(bwdPin, LOW);
		digitalWrite(fwdPin,HIGH);
	}
	else if(isforward==0){
		digitalWrite(fwdPin, LOW);
		digitalWrite(bwdPin, HIGH);
	}

	pwmWrite(powerPin, power);	//powe should be between 230 - 512

}