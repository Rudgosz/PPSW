#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

void Delay(int iDelayTime){
    int iLoopCtr;
    for(iLoopCtr = 0; iLoopCtr < iDelayTime*12000; iLoopCtr++){}
}

int main(){
    LedInit();
    KeyboardInit();
    while(1){
			
			switch(eKeyboardRead()){
				case BUTTON_1:
					LedStepRight();
          break;
        case BUTTON_2:
          LedStepLeft();
          break;
				default:
          break;
			}
			
    Delay(45);
			
  }
}
