#include <LPC21xx.H>
#include "timer.h"

#define COUNTER_ENABLE_bm (1<<0)
#define COUNTER_RESET_bm (1<<1)
#define INTERRUPT_FLAG_MR0_bm (1<<0)
#define INTERRUPT_MATCH_MR0_bm (1<<0)
#define INTERRUPT_RESET_MR0_bm (1<<1)


void InitTimer0(void){
  T0TCR=COUNTER_ENABLE_bm;
}


void WaitOnTimer0(unsigned int uiTime){

  T0TCR |= (COUNTER_RESET_bm);
  T0TCR &= (~COUNTER_RESET_bm);
  while((uiTime*15) >= T0TC){}

}


void InitTimer0Match0(unsigned int uiDelayTime){

  T0TCR = COUNTER_ENABLE_bm;
  T0TCR |= (COUNTER_RESET_bm);
  T0TCR &= (~COUNTER_RESET_bm);
  
  T0MR0 = uiDelayTime*15;
  T0MCR |= INTERRUPT_MATCH_MR0_bm | INTERRUPT_RESET_MR0_bm;

}


void WaitOnTimer0Match0(void){

  while(T0IR != INTERRUPT_FLAG_MR0_bm){}
  T0IR = INTERRUPT_FLAG_MR0_bm;

}
