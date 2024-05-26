#include <LPC21xx.H>
#include "timer.h" //git test

#define COUNTER_ENABLE_bm (1<<0)
#define COUNTER_RESET_bm (1<<1)
#define INTERRUPT_FLAG_MR0_bm (1<<0)
#define INTERRUPT_MATCH_MR0_bm (1<<0)
#define INTERRUPT_RESET_MR0_bm (1<<1)


void InitTimer0(void){
  T0TCR=COUNTER_ENABLE_bm; //wlaczenie timera
}


void WaitOnTimer0(unsigned int uiTime){

  T0TCR |= (COUNTER_RESET_bm); //wlaczenie resetowania
  T0TCR &= (~COUNTER_RESET_bm); //wylaczenie resetowania
  while((uiTime*15) > T0TC){}

}


void InitTimer0Match0(unsigned int uiDelayTime){

  T0TCR = COUNTER_ENABLE_bm; //wlaczenie timera
  T0TCR |= (COUNTER_RESET_bm); //wlaczenie resetowania
  T0TCR &= (~COUNTER_RESET_bm); // wylaczenie resetowania

  T0MR0 = uiDelayTime*15; //ustawienie flagi do resetu
  T0MCR |= INTERRUPT_MATCH_MR0_bm | INTERRUPT_RESET_MR0_bm; //wlaczenie funkcji interrupt i reset

}


void WaitOnTimer0Match0(void){

  while(T0IR != INTERRUPT_FLAG_MR0_bm){} //czekanie az pojawi sie przerwanie
  T0IR = INTERRUPT_FLAG_MR0_bm; //zerowanie flagi

}
