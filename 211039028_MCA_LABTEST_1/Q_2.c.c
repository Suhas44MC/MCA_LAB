 # include<lpc214x.h>
 
 unsigned char test [] ={0x3f,0x06,0x5b,0x4f,0x66,0x7d,0x07,0x7f,0x6f};
 void delay()
 {
	 int k;
	 for(k =0;k<1000;k++);
 }
 void main()
 {
	 int j, j1;
	 IO0DIR = 0xff;
	 IO1DIR = 0x30000;
	 while(1)
	 {
		 for(j =0;j<100;j++){
			  for(j1 =0;j<500;j1++){
					IO0CLR = 0XFF;
					IO1CLR = 0X30000;
					IO1SET = 0x20000;
			 IO0SET = test[j/10];
			 delay();
						IO0CLR = 0XFF;
					IO1CLR = 0X30000;
					IO1SET = 0x10000;
				IO0SET = test[j&10];
			 delay();
			 
			 
	 }
 }}}