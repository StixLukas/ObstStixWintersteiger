#include "ObstHCSR.h"

double timedelay;
clock_t start, end;
double result;

double readHCSR(){
  wiringPiSetupPhys();
  pinMode(15,OUTPUT);

  start=clock();
  digitalWrite(15,HIGH);
  pinMode(15,INPUT);
  while(digitalRead(15)!=1);
  end=clock();
  timedelay=((double) (end-start));

  result=17150*timedelay;

  return result;
}
