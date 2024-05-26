#include "led.h"
#include "keyboard.h"

void Delay(int iDelayTime){
    int iLoopCtr;
    for(iLoopCtr = 0; iLoopCtr < iDelayTime*5460; iLoopCtr++){}
}

int main(){

  enum LedState{LED_STATE_LEFT, LED_STATE_RIGHT, LED_STATE_STOP};
  enum LedState eLedState = LED_STATE_LEFT;
  LedInit();
  KeyboardInit();
  while(1){
    switch(eLedState){

      case LED_STATE_RIGHT:
        LedStepRight();
        if(eKeyboardRead() == BUTTON_1){
          eLedState = LED_STATE_STOP;
        }
        break;

      case LED_STATE_LEFT:
        LedStepLeft();
          if(eKeyboardRead() == BUTTON_1){
            eLedState = LED_STATE_STOP;
          }
          break;

      case LED_STATE_STOP:
        if(eKeyboardRead() == BUTTON_2){
          eLedState = LED_STATE_RIGHT;
        }
        else if(eKeyboardRead() == BUTTON_0){
          eLedState = LED_STATE_LEFT;
        }
        break;

  }
  
 Delay(500);

 }

}
