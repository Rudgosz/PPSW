#include <LPC21xx.H>
#include "timer.h"

#define CounterEnable_bm (1<<0)
#define CounterReset_bm (1<<1)

void InitTimer0(void){
  T0TCR = CounterEnable_bm;
}

void WaitOnTimer0(unsigned int uiTime){
  T0TCR = T0TCR|CounterReset_bm;
  T0TCR = T0TCR&(~CounterReset_bm);
  while(T0TC <= ((uiTime)*15)){}
}
