#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"


void Automat() {
  enum LedState{STOP, LEFT, RIGHT};
  enum LedState eLedState = STOP;

  switch(eLedState) {
    
    case STOP:
      if(eKeyboardRead() == BUTTON_0) {
        eLedState = LEFT;
      } else if(eKeyboardRead() == BUTTON_2) {
        eLedState = RIGHT;
      } else {
      eLedState = STOP;
      }
      break;
      
    case LEFT:
      if(eKeyboardRead() == BUTTON_1) {
          eLedState = STOP;
      } else {
        eLedState = LEFT;
      }
      LedStepLeft();
      break;
      
    case RIGHT:
      if(eKeyboardRead() == BUTTON_1) {
        eLedState = STOP;
      }else {
        eLedState = RIGHT;
      }
      LedStepRight();
      break;
  }
}



int main (){
  unsigned int iMainLoopCtr;
  Timer0Interrupts_Init(250000, &Automat);
  KeyboardInit();
  LedInit();

  while(1){
    iMainLoopCtr++;
  }
}
