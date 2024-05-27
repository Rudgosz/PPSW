#include <LPC21xx.H>

#define LED0_bm 1<<16
#define LED1_bm 1<<17
#define LED2_bm 1<<18
#define LED3_bm 1<<19

void Delay(int iDelayTime){
	int iLoopCtr;
	for(iLoopCtr = 0; iLoopCtr < iDelayTime; iLoopCtr++){}
}

int main(){
	IO1DIR = LED0_bm;
	while(1){
		IO1SET = LED0_bm;
		Delay(600000);
		IO1CLR = LED0_bm;
		Delay(600000);
	}
}
