/*#include <stdio.h>

#include <pigpio.h>

#define STEP_DELAY 2000

/*
2000  7 RPM
1500  9 RPM
1000 13 RPM
 900 15 RPM
*/

#define Pin1 32
#define Pin2 33
#define Pin3 16
#define Pin4 18

int step = 0; 

void loop() 
{ 
   switch(step)
   { 
   case 0: 
     gpioWrite(Pin1, PI_LOW);  
     gpioWrite(Pin2, PI_LOW); 
     gpioWrite(Pin3, PI_LOW); 
     gpioWrite(Pin4, PI_HIGH); 
   break;  
   case 1: 
     gpioWrite(Pin1, PI_LOW);  
     gpioWrite(Pin2, PI_LOW); 
     gpioWrite(Pin3, PI_HIGH); 
     gpioWrite(Pin4, PI_HIGH); 
   break;  
   case 2: 
     gpioWrite(Pin1, PI_LOW);  
     gpioWrite(Pin2, PI_LOW); 
     gpioWrite(Pin3, PI_HIGH); 
     gpioWrite(Pin4, PI_LOW); 
   break;  
   case 3: 
     gpioWrite(Pin1, PI_LOW);  
     gpioWrite(Pin2, PI_HIGH); 
     gpioWrite(Pin3, PI_HIGH); 
     gpioWrite(Pin4, PI_LOW); 
   break;  
   case 4: 
     gpioWrite(Pin1, PI_LOW);  
     gpioWrite(Pin2, PI_HIGH); 
     gpioWrite(Pin3, PI_LOW); 
     gpioWrite(Pin4, PI_LOW); 
   break;  
   case 5: 
     gpioWrite(Pin1, PI_HIGH);  
     gpioWrite(Pin2, PI_HIGH); 
     gpioWrite(Pin3, PI_LOW); 
     gpioWrite(Pin4, PI_LOW); 
   break;  
     case 6: 
     gpioWrite(Pin1, PI_HIGH);  
     gpioWrite(Pin2, PI_LOW); 
     gpioWrite(Pin3, PI_LOW); 
     gpioWrite(Pin4, PI_LOW); 
   break;  
   case 7: 
     gpioWrite(Pin1, PI_HIGH);  
     gpioWrite(Pin2, PI_LOW); 
     gpioWrite(Pin3, PI_LOW); 
     gpioWrite(Pin4, PI_HIGH); 
   break;  
   default: 
     gpioWrite(Pin1, PI_LOW);  
     gpioWrite(Pin2, PI_LOW); 
     gpioWrite(Pin3, PI_LOW); 
     gpioWrite(Pin4, PI_LOW); 
   break;  
   }
} 

int main(int argc, char * argv[])
{
   int i;
   int step_delay = STEP_DELAY;

   if (argc > 1) step_delay = atoi(argv[1]);

   if ((step_delay < 800) || (step_delay>1000000)) step_delay = STEP_DELAY;

   if (gpioInitialise()<0) return 1;

   gpioSetMode(Pin1, PI_OUTPUT);  
   gpioSetMode(Pin2, PI_OUTPUT);  
   gpioSetMode(Pin3, PI_OUTPUT);  
   gpioSetMode(Pin4, PI_OUTPUT);  

   for (i=0; i<9000000; i++)
   {
      loop();
      step++;
      if (step>7) step = 0;
      gpioDelay(step_delay);
   }

   gpioTerminate();
}

 /*
 CodeNova
 stepper motor test, for BaconStorm
 3/13/2019
 
 Notes to self:
 sudo gpio readall
 g++ -Wall -o steptest steptest.cpp -lwiringPi
*/
/*
#include <stdio.h>
#include <wiringPi.h>

#define FORWARD		1
#define BACKWARD	0

const int SPEED = 500;
const int PINS[4] = {22,23,24,25};
const bool STEPS[8][4] = {
	{HIGH, LOW, HIGH, LOW},	//0
	{HIGH, LOW, LOW, LOW},	//1
	{HIGH, LOW, LOW, HIGH},	//2
	{LOW, LOW, LOW, HIGH},	//3
	{LOW, HIGH, LOW, HIGH},	//4
	{LOW, HIGH, LOW, LOW},	//5
	{LOW, HIGH, HIGH, LOW},	//6
	{LOW, LOW, HIGH, LOW},	//7
	};

void initPins(const int index);
void halfStep(int &index, bool dir);
void debugPrint(void);

int main(void)
{
	printf("CodeNova, Stepper Test\n");
	int index = 0;		//step index counter
	
	wiringPiSetup(); 	//setup wireing pi
	initPins(index);	//init pins, start at 0

	//forward 10 halfsteps
	printf("* Forward Test *\n");
	for(int i = 0; i < 10; i++)
	{	
		halfStep(index, FORWARD);
		delay(SPEED);
		printf("index: %d\n", index);	//debug index counter
	}
	
	//backward 10 halfsteps
	printf("* Backward Test *\n");
	for(int i = 0; i < 10; i++)
	{
		halfStep(index, BACKWARD);
		delay(SPEED);
		printf("index: %d\n", index);	//debug index counter
	}	
	
	printf("Test FIN\n");
	return 0;
}

void initPins(const int index)
{
	for(int i = 0; i < 4; i++)
	{
		printf("init-ing pin %d, OUTPUT\n", PINS[i]);	//debug output
		pinMode(PINS[i], OUTPUT);						//set IO to output
		digitalWrite(PINS[i], STEPS[index][i]);			//write to IO
	}
	debugPrint();										//print IO state, debug
	printf("index: %d\n", index);						//print index number, debug
}

void halfStep(int &index, bool dir)
{
	index = dir ? ((index+1)%8) : ((index+7)%8);	//add|sub index based on direction
	
	for(int i = 0; i < 4; i++)
		digitalWrite(PINS[i], STEPS[index][i]);		//write to IO	
	
	debugPrint();									//print IO state, debug
}

void debugPrint(void)
{
	for(int i = 0; i < 4; i++)
		printf("%d", digitalRead(PINS[i])); //read the new io state
	printf("\n");
}
*/
