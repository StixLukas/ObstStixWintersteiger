#include <stdlib.h>
#include <stdio.h>
int ads1115(){
	FILE* dataFromLDR = popen("gpio -x ads1115:120:0x49 aread 121","r");
	int iLDR = 0;
	fscanf(dataFromLDR, "%d",  &iLDR);
	printf("LDR Output: %d\n",iLDR);
	
	FILE* dataFromNTC = popen("gpio -x ads1115:120:0x49 aread 122","r");
	int iNTC = 0;
	fscanf(dataFromNTC, "%d", &iNTC);
	float fNTCTemperatur = (float)iNTC/1000;
	printf("Temperatur: %.2f\n",fNTCTemperatur);

	return 0;
}
