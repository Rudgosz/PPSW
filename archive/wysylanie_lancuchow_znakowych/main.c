#include "uart.h"
#include "konwersje.h"
#include "string.h"
#include "timer_interrupts.h"
#include "command_decoder.h"
#include "serwo.h"
#include "keyboard.h"

#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define WHITE   "\x1B[0m"


extern unsigned char ucTokenNr;
extern struct Token asToken[MAX_TOKEN_NR];
extern char cOdebranyZnak;

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
    
    
    unsigned char fCalcReq = 0;
    unsigned int uiCalcResult = 0;
    
    ServoInit(20);
    UART_InitWithInt(9600);
    Timer1Interrupts_Init(1000000, WatchUpdate); 
    
    while(1) {
        
        switch (eKeyboardRead()) {

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

         default:
            break;
         }
        
        
        if(eReceiver_GetStatus() == READY){
            Receiver_GetStringCopy(cTextReceive);
            DecodeMsg(cTextReceive);

            if((ucTokenNr > 0) && (asToken[0].eType == KEYWORD)){
                switch(asToken[0].uValue.eKeyword) {
                    case CALLIB:
                        ServoCallib();
                        break;
                    case GOTO:
                        if((ucTokenNr >= 2) && (asToken[1].eType == NUMBER)) {
                            ServoGoTo(asToken[1].uValue.uiNumber);
                        }
                        break;
                    case CALC:
                        if((ucTokenNr >= 2) && (asToken[1].eType == NUMBER)) {
                            uiCalcResult = asToken[1].uValue.uiNumber * 2;
                            fCalcReq = 1; 
                        }
                        break;

                }
            }
        }
        
        if(Transmiter_GetStatus() == FREE){
            
            if(fCalcReq){
                CopyString(WHITE, cTextSend);
                AppendString("calc ", cTextSend);
                UIntToHexStr(uiCalcResult, cTextSend + 9);
                Transmiter_SendString(cTextSend);
                fCalcReq = 0;
            }
            else if(sWatch.fMinutesValueChanged){
                CopyString(GREEN, cTextSend);
                AppendString("min ", cTextSend);
                UIntToHexStr(sWatch.ucMinutes, cTextSend + 9);
                Transmiter_SendString(cTextSend);
                sWatch.fMinutesValueChanged = 0; 
            }
            else if(sWatch.fSecondsValueChanged){
                CopyString(YELLOW, cTextSend);
                AppendString("sec ", cTextSend);
                UIntToHexStr(sWatch.ucSeconds, cTextSend + 9);
                Transmiter_SendString(cTextSend);
                sWatch.fSecondsValueChanged = 0;
            }
        }
    }
}
