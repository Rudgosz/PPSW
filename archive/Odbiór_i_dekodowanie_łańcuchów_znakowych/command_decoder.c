#include "string.h"
#include "command_decoder.h"
#include "konwersje.h"


#define MAX_TOKEN_NR 3
#define Null '\0'
#define MAX_KEYWORD_NR 3
#define MAX_KEYWORD_STRING_LTH 10


typedef struct Keyword {
	enum KeywordCode eCode;
	char cString[MAX_KEYWORD_STRING_LTH + 1];
} Keyword;



struct Keyword asKeywordList[MAX_KEYWORD_NR] = {
	{CALLIB, "callib"},
	{GOTO, "goto"}
};


struct Token asToken[MAX_TOKEN_NR];
unsigned char ucTokenNr;

enum eFunctionState {TOKEN, DELIMITER};

unsigned char ucFindTokensInString(char *pcString){

  enum eFunctionState eState = DELIMITER;
  unsigned char ucCharacterCounter;
  unsigned char ucCurrentChar;
  ucTokenNr = 0;

  for(ucCharacterCounter = 0;;ucCharacterCounter++){
		
    ucCurrentChar = pcString[ucCharacterCounter];

    switch(eState){
      case TOKEN:
        if(ucCurrentChar == Null){
          return ucTokenNr;
        }
        else if(ucTokenNr == MAX_TOKEN_NR){
          return ucTokenNr;
        }
        else if(ucCurrentChar == ' '){
          eState = DELIMITER;
        }
        break;

      case DELIMITER:
        if(ucCurrentChar == Null){
          return ucTokenNr;
        }
        else if(ucCurrentChar != ' '){
          eState = TOKEN;
					asToken[ucTokenNr].uValue.pcString = pcString + ucCharacterCounter;
          ucTokenNr++;
        }
        else{
            break;
        }
        

    }
  }
}


enum Result eStringToKeyword (char pcStr[], enum KeywordCode *peKeywordCode){
	
  unsigned char ucKeywordCounter;
	
  for(ucKeywordCounter = 0; ucKeywordCounter < MAX_KEYWORD_NR; ucKeywordCounter++){
		
    if(eCompareString(asKeywordList[ucKeywordCounter].cString, pcStr) == EQUAL){
      *peKeywordCode = asKeywordList[ucKeywordCounter].eCode;
      return OK;
    }
		
  }
  return ERROR;
}


void DecodeTokens(void){
	
	unsigned char ucTokenCounter;
	struct Token *psCurrentToken;
	unsigned int uiTokenValue;
	enum KeywordCode eTokenCode;
	
	for(ucTokenCounter = 0; ucTokenCounter < ucTokenNr; ucTokenCounter++){
		
		psCurrentToken= &asToken[ucTokenCounter];
		
			if(eStringToKeyword(psCurrentToken->uValue.pcString, &eTokenCode) == OK){
				psCurrentToken->eType = KEYWORD;
				psCurrentToken->uValue.eKeyword = eTokenCode;
			}
			else if(eHexStringToUInt(psCurrentToken->uValue.pcString, &uiTokenValue) == OK){
				psCurrentToken->eType = NUMBER;
				psCurrentToken->uValue.uiNumber = uiTokenValue;
			}	
			else{
				psCurrentToken->eType = STRING;
			}
	}
}



void DecodeMsg(char *pcString) {
	ucFindTokensInString(pcString);
	ReplaceCharactersInString(pcString, ' ', Null);
	DecodeTokens();
}
