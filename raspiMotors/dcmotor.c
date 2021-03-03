#include "dcmotor.h"

#define DELAY 100

int main (int argc, char **argv)
{ 
	if(argc==6){
		int powerpin= atoi(argv[1]);
		int forward= atoi(argv[2]);
		int backward= atoi(argv[3]);
		int power= atoi(argv[4]);
		int isforward= atoi(argv[5]);

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