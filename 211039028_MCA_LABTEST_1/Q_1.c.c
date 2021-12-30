#include<lpc214x.h>

void delay(unsigned int z);        
void pll();
int main(void)
{
    IO0DIR|= (1 << 9)|(1 << 10); //connecting two LEDs for P0.9 and P0.10
	  IO1DIR |=0X0;
    pll();                  
    while(1) {
			
			if ((IO1PIN & (1<<16)) == 0)
			{
        IO0SET=(1 << 10); // making P0.10 high
        delay(1000);      // delay of 1 sec for LED 1
        IO0CLR=(1 << 10); // making P0.10 low
        delay(1000);  
			}	 
				if ((IO1PIN & (1<<20)) == 0)
			{
        IO0SET=(1 << 9); // making P0.10 high
        delay(500);  // delay of 500ms for LED 2
        IO0CLR=(1 << 9); // making P0.10 low
        delay(500);    
			}
}
}
void pll()                  
{
    PLL0CON=0x01;
    PLL0CFG=0x24;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    while(!(PLL0STAT&(1<<10)));
    PLL0CON=0x03;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    VPBDIV=0x01;
}
void delay(unsigned int z)
{
    T0CTCR=0x0;                                
    T0TCR=0x00;                 
    T0PR=59999; // prescalar value                
    T0TCR=0x02;                 
    T0TCR=0x01;                 
    while(T0TC<z);           
    T0TCR=0x00;                 
    T0TC=0;                     
}