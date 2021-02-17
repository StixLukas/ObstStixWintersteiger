#include <stdio.h> include <stdlib.h> include <unistd.h> include <assert.h>

#include <wiringPi.h>

int D=1000;

unsigned m[]={18,16,32,33};

int b[8]={0b0001, 0b011, 0b0010, 0b0110, 0b0100, 0b1100, 0b1000, 0b1001};

void gpiosWrite(unsigned *p, unsigned v)
{
  for(int i=0; i<4; ++i)
    digitalWrite( p[i], (v&(1<<i)) ? HIGH : LOW );
}

void hstep(unsigned v)
{
  gpiosWrite(m, b[v & 0x7]);
}

void hstep2(int x)
{
  hstep(x); usleep(D);
}

int main(int argc, char *argv[])
{
  int i,x=0,dx;
 
  wiringPiSetupPhys();
  dx = atoi(argv[1]);
  if (argc==3) {
    D = atoi(argv[2]);
    D = (D<1000) ? 1000 : D;
  }

  for(i=0; i<4; ++i)
    {
      
      digitalWrite(m[i], LOW);
    }

  hstep2(x);

  for(i=0; i<dx; ++i) hstep2(++x);
  for(i=0; i>dx; --i) hstep2(--x);
}
