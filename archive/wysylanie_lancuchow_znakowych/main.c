#include "uart.h"
#include "konwersje.h"
#include "string.h"
#include "timer_interrupts.h"

struct Watch{
    unsigned char ucMinutes;
    unsigned char ucSeconds;
    unsigned char fSecondsValueChanged;
    unsigned char fMinutesValueChanged;
};

struct Watch sWatch;

void WatchUpdate(void) {
    sWatch.ucSeconds++;
    sWatch.fSecondsValueChanged = 1;

    if (sWatch.ucSeconds >= 60) {
        sWatch.ucSeconds = 0;
        sWatch.ucMinutes++;
        sWatch.fMinutesValueChanged = 1;
        
        if (sWatch.ucMinutes >= 60) {
            sWatch.ucMinutes = 0;
        }
    }
}

int main() {
    
    char cText[TRANSMITER_SIZE];
    UART_InitWithInt(9600);
    Timer0Interrupts_Init(1000000, WatchUpdate); 

    while(1) {
        if (Transmiter_GetStatus() == FREE) {
            
            if (sWatch.fMinutesValueChanged) {
                CopyString("min 0x", cText);
                UIntToHexStr(sWatch.ucMinutes, cText + 6);
                Transmiter_SendString(cText);
                sWatch.fMinutesValueChanged = 0; 
            }

            else if (sWatch.fSecondsValueChanged) {
                CopyString("sec 0x", cText);
                UIntToHexStr(sWatch.ucSeconds, cText + 6);
                Transmiter_SendString(cText);
                sWatch.fSecondsValueChanged = 0;
            }
        }
    }
}
