//========zadanie 1================
/*
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
*/


//========zadanie 2==================
/*

#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

void Delay(int iDelayTime){
    int iLoopCtr;
    for(iLoopCtr = 0; iLoopCtr < iDelayTime*5460; iLoopCtr++){}
}

int main(){
	
	enum LedState{STATE0, STATE1, STATE2, STATE3, STATE4, STATE5};
	enum LedState eLedState = STATE0;
	LedInit();
	while(1){
		switch(eLedState){
			case STATE0:
				LedStepLeft();
				eLedState = STATE1;
				break;
			case STATE1:
				LedStepLeft();
				eLedState = STATE2;
				break;
			case STATE2:
				LedStepLeft();
				eLedState = STATE3;
				break;
			case STATE3:
				LedStepRight();
				eLedState = STATE4;
				break;
			case STATE4:
				LedStepRight();
				eLedState = STATE5;
				break;
			case STATE5:
				LedStepRight();
				eLedState = STATE0;
				break;
		}
		Delay(500);
	}
}

*/



//=========zadanie 3============================

/*
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

*/



//======zadanie 4================
/*

#include "led.h"
#include "keyboard.h"

void Delay(int iDelayTime){
    int iLoopCtr;
    for(iLoopCtr = 0; iLoopCtr < iDelayTime*5460; iLoopCtr++){}
}

int main(){

	enum LedState{LED_STATE_RIGHT, LED_STATE_STOP};
	enum LedState eLedState = LED_STATE_RIGHT;
	LedInit();
	KeyboardInit();
	while(1){
		unsigned int uiStateCounter;
		switch(eLedState){
			
			case LED_STATE_RIGHT:
				LedStepRight();
				uiStateCounter++;
				if(uiStateCounter == 3){
					eLedState = LED_STATE_STOP;
					uiStateCounter = 0;
				}
				
				break;
				
			case LED_STATE_STOP:
				if(eKeyboardRead() == BUTTON_0){
					eLedState = LED_STATE_RIGHT;
				}
				break;

		}
		Delay(500);
	}
}
*/




//==============zadanie 5======================

/*
#include "led.h"
#include "keyboard.h"

void Delay(int iDelayTime){
    int iLoopCtr;
    for(iLoopCtr = 0; iLoopCtr < iDelayTime*5460; iLoopCtr++){}
}

int main(){

	enum LedState{LED_STATE_RIGHT, LED_STATE_STOP};
	enum LedState eLedState = LED_STATE_RIGHT;
	LedInit();
	KeyboardInit();
	while(1){
		switch(eLedState){

			case LED_STATE_RIGHT:
				LedStepRight();
				if(eKeyboardRead() == BUTTON_0){
					eLedState = LED_STATE_STOP;
				}
				break;

			case LED_STATE_STOP:
				if(eKeyboardRead() == BUTTON_1){
					eLedState = LED_STATE_RIGHT;
				}
				break;

		}
		Delay(500);
	}
}

*/



//===================zadanie 6====================


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