#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_FILE "/sys/bus/w1/devices/28-01144fe3b8aa/w1_slave"

int read_ds18b20()
{
  FILE *fp;
  char con[1000];
  char *pch;
  float temp=0;
  
  fp = fopen(BASE_FILE, "r");
  if(!fp)
  	return 1;

  while(fgets(con, 1000, fp)!=NULL){
  		
  		pch=strstr(con,"t=");
  		if(pch!=NULL){

			pch+=2;
  			temp = (float) strtod(pch,NULL);
  			temp /= 1000;

  			printf("DS18B20 Temperature: %.2f °C\n", temp);
  		}
  }

  fclose(fp);
  return 0;

}
 
int main( void )
{
    read_ds18b20();
    return(0);
}
