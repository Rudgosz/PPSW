#include "string.h"

#define Null '\0'

void CopyString(char pcSource[], char pcDestination[]){
    unsigned char ucLoopCounter;
    for(ucLoopCounter = 0; pcSource[ucLoopCounter] != Null; ucLoopCounter++){
        pcDestination[ucLoopCounter] = pcSource[ucLoopCounter];
    }
    pcDestination[ucLoopCounter] = Null;
}





enum CompResult eCompareString(char pcStr1[], char pcStr2[]){
    unsigned char ucLoopCounter;
    for(ucLoopCounter = 0; pcStr1[ucLoopCounter] != Null; ucLoopCounter++){
        if(pcStr1[ucLoopCounter] != pcStr2[ucLoopCounter]){
            return DIFFERENT;
        }
    }

    if(pcStr1[ucLoopCounter] == pcStr2[ucLoopCounter]){
        return EQUAL;
    } else {
        return DIFFERENT;
    }
}


void AppendString(char pcSourceStr[], char pcDestinationStr[]){
    unsigned char ucLoopCounter;
    for(ucLoopCounter = 0; pcDestinationStr[ucLoopCounter] != Null; ucLoopCounter++){};
    CopyString(pcSourceStr, pcDestinationStr + ucLoopCounter);

}


void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar){
    unsigned char ucLoopCounter;
    for(ucLoopCounter = 0; pcString[ucLoopCounter] != Null; ucLoopCounter++){
        if(pcString[ucLoopCounter] == cOldChar){
            pcString[ucLoopCounter] = cNewChar;
        }
    }
}
