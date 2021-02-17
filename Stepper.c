#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include <pigpio.h>

int D=1000;

unsigned m[][4]={
  {14,15,17,18},
  {27,22,23,24}
};

int b[8]={0b0001, 0b011, 0b0010, 0b0110, 0b0100, 0b1100, 0b1000, 0b1001};

int M=sizeof(m)/sizeof(m[0]);
int N=sizeof(m[0])/sizeof(m[0][0]);

void gpiosWrite(unsigned *p, unsigned v)
{
  for(int i=0; i<N; ++i)
    gpioWrite( p[i], (v&(1<<i)) ? 1 : 0 );
}

void hstep(int mn, unsigned v)
{
  gpiosWrite(m[mn], b[v & 0x7]);
}

void hstep2(int x, int y)
{
  hstep(0,x); hstep(1,y); usleep(D);
}

int main(int argc, char *argv[])
{
  int i,j,x=0,y=0,dx,dy;

  assert(((argc+1)/2==2) || !"Format: sudo ./move dx dy [D]");
 
  assert(gpioInitialise()>=0);

  dx = atoi(argv[1]);
  dy = atoi(argv[2]);
  if (argc==4) {
    D = atoi(argv[3]);
    D = (D<1000) ? 1000 : D;
  }

  for(i=0; i<M; ++i)
    for(j=0; j<N; ++j)
    {
      gpioSetMode(m[i][j], PI_OUTPUT);
      gpioWrite(m[i][j], 0);
    }

  hstep2(x,y);

  for(i=0; i<dx; ++i) hstep2(++x,y);
  for(i=0; i>dx; --i) hstep2(--x,y);
  for(i=0; i<dy; ++i) hstep2(x,++y);
  for(i=0; i>dy; --i) hstep2(x,--y);
     
  gpioTerminate();
}