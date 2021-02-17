#include "ads1115.h"
int ads1115(ads1115_t *val){
	FILE* dataFromLDR = popen("gpio -x ads1115:120:0x49 aread 121","r");
	int iLDR = 0;
	fscanf(dataFromLDR, "%d",  &iLDR);
	printf("LDR Output: %d\n",iLDR);
	
	FILE* dataFromNTC = popen("gpio -x ads1115:120:0x49 aread 122","r");
	int iNTC = 0;
	fscanf(dataFromNTC, "%d", &iNTC);
	float fNTCTemperatur = (float)iNTC/1000;
	printf("Temperatur: %.2f\n",fNTCTemperatur);
	val->ldr= iLDR;
	val->ntc=iNTC;

	return 0;
}
