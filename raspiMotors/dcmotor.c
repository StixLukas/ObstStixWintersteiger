#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DELAY 100

void dcmotor(int powerPin, int fwdPin, int bwdPin, int power, int isforward);

int main (int argc, char **argv)
{ 
	if(argc==6){
		puts(argv[1]);
		int powerpin= (int) argv[1];
		puts(argv[2]);
		int forward= (int) argv[2];
		puts(argv[3]);
		int backward= (int) argv[3];
		puts(argv[4]);
		int power= (int) argv[4];
		puts(argv[5]);
		int isforward= (int) argv[5];

		dcmotor(powerpin, forward, backward, power, isforward); // dcmotor(38, 40, 36, 300, 1);
	}
	else{
		printf("Please enter 5 arguments");
	}
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