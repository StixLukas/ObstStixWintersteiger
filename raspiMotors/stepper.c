 /*
 CodeNova
 stepper motor test, for BaconStorm
 3/13/2019
 
 Notes to self:
 sudo gpio readall
 g++ -Wall -o steptest steptest.cpp -lwiringPi
*/

#include <stdio.h>
#include <wiringPi.h>
#define FORWARD   1
#define BACKWARD  0
const int SPEED = 1000;
const int PINS[4] = {32,33,16,18};
const bool STEPS[8][4] = {
  {HIGH, LOW, HIGH, LOW}, //0
  {HIGH, LOW, LOW, LOW},  //1
  {HIGH, LOW, LOW, HIGH}, //2
  {LOW, LOW, LOW, HIGH},  //3
  {LOW, HIGH, LOW, HIGH}, //4
  {LOW, HIGH, LOW, LOW},  //5
  {LOW, HIGH, HIGH, LOW}, //6
  {LOW, LOW, HIGH, LOW},  //7
  };
void initPins(const int index);
void halfStep(int &index, bool dir);
void debugPrint(void);
int main(void)
{
  printf("CodeNova, Stepper Test\n");
  int index = 0;    //step index counter
  
  wiringPiSetupPhys();  //setup wireing pi
  initPins(index);  //init pins, start at 0
  //forward 10 halfsteps
  printf("* Forward Test *\n");
  for(int i = 0; i < 10; i++)
  { 
    halfStep(index, FORWARD);
    delay(SPEED);
    printf("index: %d\n", index); //debug index counter
  }
  
  //backward 10 halfsteps
  printf("* Backward Test *\n");
  for(int i = 0; i < 10; i++)
  {
    halfStep(index, BACKWARD);
    delay(SPEED);
    printf("index: %d\n", index); //debug index counter
  } 
  
  printf("Test FIN\n");
  return 0;
}
void initPins(const int index)
{
  for(int i = 0; i < 4; i++)
  {
    printf("init-ing pin %d, OUTPUT\n", PINS[i]); //debug output
    pinMode(PINS[i], OUTPUT);           //set IO to output
    digitalWrite(PINS[i], STEPS[index][i]);     //write to IO
  }
  debugPrint();                   //print IO state, debug
  printf("index: %d\n", index);           //print index number, debug
}
void halfStep(int &index, bool dir)
{
  printf("index before calc: %d",index);
  index = dir ? ((index+1)%8) : ((index+7)%8);  //add|sub index based on direction 
  printf("index(halfStep): %d",index);  
  for(int i = 0; i < 4; i++)
    digitalWrite(PINS[i], STEPS[index][i]);   //write to IO 
  	
  debugPrint();                 //print IO state, debug
}
void debugPrint(void)
{
  for(int i = 0; i < 4; i++)
    printf("\n%d", digitalRead(PINS[i])); //read the new io state
  printf("\n");
}

