#include "ObstGyro.h"

int fd;
int acclX, acclY, acclZ;
int gyroX, gyroY, gyroZ;
double acclX_scaled, acclY_scaled, acclZ_scaled;
 
int read_word_2c(int addr)
{
int val;
val = wiringPiI2CReadReg8(fd, addr);
val = val << 8; //bits werden um 8 nach links verschoben
val += wiringPiI2CReadReg8(fd, addr+1);
if (val >= 0x8000)
val = -(65536 - val);
 
return val;
}
 
double dist(double a, double b)
{
return sqrt((a*a) + (b*b));
}
 
double get_y_rotation(double x, double y, double z)
{
double radians;
radians = atan2(x, dist(y, z));
return -(radians * (180.0 / M_PI));
}
 
double get_x_rotation(double x, double y, double z)
{
double radians;
radians = atan2(y, dist(x, z));
return (radians * (180.0 / M_PI));
}
 
void readGyro(mpu6050_t *mpu)
{
fd = wiringPiI2CSetup (0x69);
wiringPiI2CWriteReg8 (fd,0x6B,0x00);//disable sleep mode
 
acclX = read_word_2c(0x3B);
acclY = read_word_2c(0x3D);
acclZ = read_word_2c(0x3F);
 
acclX_scaled = acclX / 16384.0;
acclY_scaled = acclY / 16384.0;
acclZ_scaled = acclZ / 16384.0;

mpu->x=get_x_rotation(acclX_scaled, acclY_scaled, acclZ_scaled);
mpu->y=get_y_rotation(acclX_scaled, acclY_scaled, acclZ_scaled);

}
