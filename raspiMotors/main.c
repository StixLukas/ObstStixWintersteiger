#include "dcmotor.h"
#include "stepper.h"

int main (int argc, char **argv)
{ 
	
	dcmotor(38, 40, 36, 300, 1);
	
	//stepper(pin1, 2, 3, 4, speed, steps);

	//servo(pin, grad);
}