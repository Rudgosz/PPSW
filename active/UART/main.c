#include "uart.h"
#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"
#include "serwo.h"
    
int main (){
  unsigned int uiMainCounter = 0;
  UART_InitWithInt(9600);
	while(1){
		uiMainCounter++;
	}
	
}

