#include<lpc21xx.h>
void delay(){
	int a;
	for(a=0;a<100;a++);
}
int main(){
	PINSEL0 = 0X00000000;
	IO0DIR = 0XFFFFFFFF;
	IOPIN0 = 0X00000000;
	while(1){
		/*IO0SET = (1<<0); // TO runs clock wise
		IO0CLR = (1<<1);
		delay();
		IO0CLR = (1<<0)|(1<<1); // TURNS OFF
		delay();*/
		
		IO0SET = (1<<1); // TO runs anticlock wise
		IO0CLR = (1<<0);
		delay();
		IO0CLR = (1<<0)|(1<<1); // TURNS OFF
		
	
	}

}