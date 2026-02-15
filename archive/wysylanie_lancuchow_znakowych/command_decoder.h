#define MAX_TOKEN_NR 3
#define MAX_KEYWORD_STRING_LTH 10
#define MAX_KEYWORD_NR 3

typedef enum KeywordCode {CALLIB, GOTO, CALC} KeywordCode;
typedef enum TokenType {KEYWORD, NUMBER, STRING} TokenType;

typedef union TokenValue {
	enum KeywordCode eKeyword;
	unsigned int uiNumber;
	char *pcString;
}TokenValue;


typedef struct Token {
	enum TokenType eType;
	union TokenValue uValue;
}Token;

unsigned char ucFindTokensInString (char *pcString);
enum Result eStringToKeyword (char pcStr[], enum KeywordCode *peKeywordCode);
void DecodeTokens(void);
void DecodeMsg(char *pcString);
