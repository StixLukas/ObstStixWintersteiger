#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);	
DallasTemperature sensors(&oneWire);

void read_ds18b20()
{
  // Send the command to get temperatures
  sensors.requestTemperatures(); 

  //print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print((char)176);//shows degrees character
  Serial.print("C  |  ");
  
  //print the temperature in Fahrenheit
  Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  Serial.print((char)176);//shows degrees character
  Serial.println("F");
  
  delay(500);
}
 
int main( void )
{
    printf( "Raspberry Pi wiringPi DS18B20 Temperature\n" );
 
    if ( wiringPiSetup() == -1 )
        exit( 1 );
 
    while ( 1 )
    {
        read_ds18b20();
        delay( 1000 ); 
    }
 
    return(0);
}