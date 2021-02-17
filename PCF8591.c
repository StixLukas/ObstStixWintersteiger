
#include "pcf8591.h"

int[] pcf8591(){
	int valueLDR;
	int valueNTC;
	wiringPiSetup();
	
	pcf8591Setup(PCF, 0x48);

	valueLDR = analogRead(PCF+1);
	valueNTC = analogRead(PCF+2);
	
	printf("%d\n%d\n",valueLDR,valueNTC);
	analogWrite(PCF+1,valueLDR);
	analogWrite(PCF+2,valueNTC);


	return int[valueLDR,valueNTC];
}
