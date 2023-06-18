%{
    #include <cstdio>
    #include "token/token.h"

    #define YYEOF 0
%}
%option noyywrap

OCTAL 0[0-7]+
HEX 0x[0-9a-fA-F]+
DECIMAL [1-9][0-9]*
NUMBER {OCTAL}|{HEX}|{DECIMAL}

%%

NUMBER {
    yylval.num = atoi(yytext);
    return tok_number;
}

"(" { return tok_lparen; }


<<EOF>> { return YYEOF; }

. {
    fprintf(stderr, "unknown %s\n", yytext);
    return ~YYEOF;
}

%%

int main() {
    int tok;
    while ((tok = yylex()) != YYEOF) {
        printf("%d, %s\n", tok, yytext);
    }
    return 0;
}