#include <LPC213X.h>

void delay();
int i;
unsigned char dir_fl;

int main()
{
IODIR0 = 0XFFFFFFFF;
dir_fl = 0;//for 0 it runs in anticlock wise direction , for 1 in clock wise direction

while(1)
{
if(dir_fl == 0)
{
IOSET0 = 0x3;
delay();
IOCLR0 = 0x3;

IOSET0 = 0x6;
delay();
IOCLR0 = 0x6;

IOSET0 = 0xC;
delay();
IOCLR0 = 0xC;

IOSET0 = 0x9;
delay();
IOCLR0 = 0x9;
}

else if(dir_fl == 1)
{
IOSET0 = 0x9;
delay();
IOCLR0 = 0x9;



IOSET0 = 0xC;
delay();
IOCLR0 = 0xC;



IOSET0 = 0x6;
delay();
IOCLR0 = 0x6;



IOSET0 = 0x3;
delay();
IOCLR0 = 0x3;
}
}
}

void delay()
{
for(i=0; i<=5000;i++)
for(i=0; i<=150000; i++);

}