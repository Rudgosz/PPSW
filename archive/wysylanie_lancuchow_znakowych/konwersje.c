#define Null '\0'

enum Result {OK, ERROR};


void UIntToHexStr(unsigned int uiValue, char pcStr[]) {
    unsigned char ucNibbleCounter;
    unsigned char ucCurrentNibble;

    pcStr[0] = '0';
    pcStr[1] = 'x';

    for (ucNibbleCounter = 0; ucNibbleCounter < 8; ucNibbleCounter++) {
        ucCurrentNibble = ((uiValue >> 4*ucNibbleCounter) & 0xF);
            if(ucCurrentNibble <= 9){
                pcStr[9-ucNibbleCounter] = '0' + ucCurrentNibble;
            }
            else{
                pcStr[9-ucNibbleCounter] = 'A'+(ucCurrentNibble-10);
            }
   }
   pcStr[10] = Null;
}




enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue) {

unsigned char ucCharCounter;
unsigned char ucCurrentChar;

*puiValue = 0;

if(pcStr[0] != '0' || pcStr[1] != 'x' || pcStr[2] == Null) {
    return ERROR;
}
for(ucCharCounter = 2; ucCharCounter <= 6; ucCharCounter++) {
    ucCurrentChar = pcStr[ucCharCounter];

if(ucCurrentChar == Null) {
    return OK;
} else if(ucCharCounter == 6) {
    return ERROR;
}

*puiValue = *puiValue << 4;

if((ucCurrentChar <= '9') && (ucCurrentChar >= '0')) {
    ucCurrentChar = ucCurrentChar - '0';
} else if(ucCurrentChar <= 'F' && ucCurrentChar >= 'A') {
    ucCurrentChar = ucCurrentChar - 'A' + 10;
} else {
    return ERROR;
}
    *puiValue = *puiValue | ucCurrentChar;
}
    return OK;
}




void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]){
    unsigned char ucCharCounter;
    for(ucCharCounter=0; pcDestinationStr[ucCharCounter]!=Null; ucCharCounter++){}
    UIntToHexStr(uiValue, pcDestinationStr + ucCharCounter);
}
