#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

void Delay(int iDelayTime){
    int iLoopCtr;
    for(iLoopCtr = 0; iLoopCtr < iDelayTime*5460; iLoopCtr++){}
}

int main(){
	
	enum LedState{LED_LEFT, LED_RIGHT};
	enum LedState eLedState = LED_LEFT;
	LedInit();
	while(1){
		switch(eLedState){
			case LED_LEFT:
				LedStepLeft();
				eLedState = LED_RIGHT;
				break;
			case LED_RIGHT:
				LedStepRight();
				eLedState = LED_LEFT;
				break;
		}
		Delay(500);
	}
}


