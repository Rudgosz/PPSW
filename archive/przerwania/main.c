#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"


void Automat(){
	
	enum LedState{LED_LEFT,LED_RIGHT,LED_STOP};
	static enum  LedState  eLedState = LED_LEFT;

	 switch(eLedState){
		case LED_RIGHT: 	
			if(eKeyboardRead()==BUTTON_2){
				eLedState = LED_STOP;
			}else{
				eLedState = LED_RIGHT;
				LedStepRight();
			}
			break;
		case LED_LEFT: 
			if(eKeyboardRead()==BUTTON_2){
				eLedState = LED_STOP;
			}else{
				eLedState = LED_LEFT;
				LedStepLeft();
			}
			break;
		case LED_STOP: 
			if(eKeyboardRead()==BUTTON_1){
				eLedState = LED_LEFT;
			}else if(eKeyboardRead()==BUTTON_3){
				eLedState = LED_RIGHT;
			}else{
				eLedState = LED_STOP;	
			}
			break;
	 }
}







int main (){
	unsigned int iMainLoopCtr;
	//Timer0Interrupts_Init(250000,&Automat);
	Timer0Interrupts_Init(1000,&Automat);
	//Timer1Interrupts_Init(10000,&Automat);
	LedInit();
	KeyboardInit();

	while(1){
	 	iMainLoopCtr++;
	}
}
