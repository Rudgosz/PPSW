#include "uart.h"
#include "string.h"
#include "konwersje.h"

int main() {
    unsigned int uiNumCounter = 0;
    char cTextToSend[TRANSMITER_SIZE];

    UART_InitWithInt(9600);

    while(1) {

        if(Transmiter_GetStatus() == FREE) {
            
            CopyString("licznik 0x", cTextToSend);
            UIntToHexStr(uiNumCounter, cTextToSend + 10);
            Transmiter_SendString(cTextToSend);
            uiNumCounter++;
        }
    }
}
