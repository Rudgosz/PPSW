#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "serwo.h"
#include "uart.h"


int main (){
  
  extern char cOdebranyZnak;
  unsigned int uiServoPosition = 12;
  KeyboardInit();  
  LedInit();
  ServoInit(50);
  UART_InitWithInt(9600);
  
while(1){
  

    switch(cOdebranyZnak){
      
      case '1':
        ServoGoTo(uiServoPosition);
        uiServoPosition += 12;
        break;
      /*
      case '2':
        ServoGoTo(24);
        break;
      
      case '3':
        ServoGoTo(36);
        break;
      
      case '4':
        break;
      */
      case 'c':
        ServoCallib();
        break;
      
      default:
        break;
    }
    
    cOdebranyZnak = 0;
    /*
    switch(eKeyboardRead()){
      
      case BUTTON_0:
        ServoCallib();
        break;      
      
      case BUTTON_1:
        ServoGoTo(12);
        break;
      
      case BUTTON_2:
        ServoGoTo(24);
        break;
     
      case BUTTON_3:
        ServoGoTo(36);
        break;
      
      case RELASED:
        break;
      
      default:
        break;
    }
    */
  }
}




