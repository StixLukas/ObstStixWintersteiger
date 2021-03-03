#include "dcmotor.h"
#include "stepper.h"
#include "servo.h"

int main (int argc, char **argv)
{ 
	
	dcmotor(38, 40, 36, 300, 1);

	moveServo(12,180);
	
	//stepper(pin1, 2, 3, 4, speed, steps);
}