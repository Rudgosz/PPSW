#include "uart.h"
#include "konwersje.h"
#include "string.h"
#include "timer_interrupts.h"
#include "command_decoder.h"

extern unsigned char ucTokenNr;
extern struct Token asToken[MAX_TOKEN_NR];

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
    
    char cTextSend[TRANSMITER_SIZE];
    char cTextReceive[RECEIVER_SIZE];
    
    unsigned char fCalcRequested = 0;
    unsigned int uiCalcResult = 0;
    
    UART_InitWithInt(9600);
    Timer0Interrupts_Init(1000000, WatchUpdate); 
    
    while(1) {
        
        if(eReceiver_GetStatus() == READY){
            Receiver_GetStringCopy(cTextReceive);
            DecodeMsg(cTextReceive);

            if((ucTokenNr == 2) && (asToken[0].eType == KEYWORD) && (asToken[1].eType == NUMBER)) {
                if(asToken[0].uValue.eKeyword == CALC){
                    uiCalcResult = asToken[1].uValue.uiNumber * 2;
                    fCalcRequested = 1; 
                }
            }
        }
        
        if(Transmiter_GetStatus() == FREE){
            
            if(fCalcRequested){
                CopyString("calc ", cTextSend);
                UIntToHexStr(uiCalcResult, cTextSend + 5);
                Transmiter_SendString(cTextSend);
                fCalcRequested = 0;
            }
            else if(sWatch.fMinutesValueChanged){
                CopyString("min ", cTextSend);
                UIntToHexStr(sWatch.ucMinutes, cTextSend + 4);
                Transmiter_SendString(cTextSend);
                sWatch.fMinutesValueChanged = 0; 
            }
            else if(sWatch.fSecondsValueChanged){
                CopyString("sec ", cTextSend);
                UIntToHexStr(sWatch.ucSeconds, cTextSend + 4);
                Transmiter_SendString(cTextSend);
                sWatch.fSecondsValueChanged = 0;
            }
        }
    }
}
