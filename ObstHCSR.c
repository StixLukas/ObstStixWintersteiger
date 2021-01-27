#include <wiringPi.h>
#include <time.h>
#include <stdio.h>

double timedelay;
clock_t start, end;
double result;

int main(){
  read();
}

int read(){
while(1){
  pinMode(15,OUTPUT);

  start=clock();
  digitalWrite(15,HIGH);
  pinMode(15,INPUT);
  while(digitalRead(15)!=1);
  end=clock();
  timedelay=((double) (end-start));

  result=17150*timedelay;

  printf("Distance: %f ",result);
}
}
