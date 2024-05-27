#include <LPC21xx.H>
#define LED0_bm 1<<16
#define LED1_bm 1<<17
#define LED2_bm 1<<18
#define LED3_bm 1<<19

enum ButtonState {RELASED, PRESSED};

void Delay(int iDelayTime){
	int iLoopCtr;
	for(iLoopCtr = 0; iLoopCtr < iDelayTime; iLoopCtr++){}
}

void LedInit(){
	IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks){
	IO1SET = 1<<(ucLedIndeks + 16);
}

enum ButtonState ReadButton1(){
	if((IO0PIN = 1<<4) == 0){
		return PRESSED;
	}else{
		return RELASED;
	}
}


int main(){
	

	
	while(1){
		LedInit();
		Delay(3000000);
		IO1CLR = LED0_bm;
		LedOn(1);
		Delay(3000000);
		IO1CLR = LED1_bm;
		LedOn(2);
		Delay(3000000);
		IO1CLR = LED2_bm;
		LedOn(3);
		Delay(3000000);
		IO1CLR = LED3_bm;
	}
}
