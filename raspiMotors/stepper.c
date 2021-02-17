/*
2000  7 RPM
1500  9 RPM
1000 13 RPM
 900 15 RPM
*/

#define Pin1 14
#define Pin2 15
#define Pin3 17
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