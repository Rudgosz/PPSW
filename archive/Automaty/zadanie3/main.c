#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

void Delay(int iDelayTime){
    int iLoopCtr;
    for(iLoopCtr = 0; iLoopCtr < iDelayTime*5460; iLoopCtr++){}
}

int main(){
	unsigned char ucStepCounter = 1;
	enum LedState{LED_LEFT, LED_RIGHT};
	enum LedState eLedState = LED_LEFT;
	LedInit();
	while(1){
		switch(eLedState){
			case LED_LEFT:
				LedStepLeft();
				if(ucStepCounter == 3){
					eLedState = LED_RIGHT;
					ucStepCounter = 0;
				}
				break;
				
			case LED_RIGHT:
				LedStepRight();
				if(ucStepCounter == 3){
					eLedState = LED_LEFT;
					ucStepCounter = 0;
				}
				break;
			
		}
		ucStepCounter = ucStepCounter + 1;
		Delay(500);
	}
}


