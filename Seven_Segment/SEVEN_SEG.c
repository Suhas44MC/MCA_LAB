    #include<LPC21XX.H>  // header file for lpc2148
 
void delay();  // delay function
 
unsigned int i,j,k;  // globle variable
unsigned int ar[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; // array data  
int main()
{
PINSEL0=0X00000000;  // select port0 as gpio mode
IO0DIR =0X000000FF; // make starting 8 pin as output and other as input of port0
while(1){
if(IO1PIN & (1<<16)) 
	{	//Checking 16th pin of Port 1
	for(i=0;i<10;i++){
            IOSET0 = ar[i];   //Port 0's all pins are high now (LED is glowing)
        delay();
            IOCLR0 = ar[i];
}
}
else {
	for(i=10;i>=0;i--){
            IOSET0 = ar[i];   //Port 0's all pins are high now (LED is glowing)
        delay();
            IOCLR0 = ar[i];
	}
}
}

return 0;
}
   
void delay()
{
for(j=0;j<100000;j++);

}