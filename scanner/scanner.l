%{
    #include <cstdio>
    #include "token/token.h"

    int yynum;
%}

%option noyywrap
%option outfile="scanner.c" header-file="scanner.h"

ZERO 0
OCTAL 0[0-7]+
HEX 0x[0-9a-fA-F]+
BIN 0b[01]+
DECIMAL [1-9][0-9]*
SPACE [\f\r\t\n\r ]+
STRING_LITERAL \"([^\\\"]|\\.)*\"
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%

{SPACE} { /* ignore */ }

{ZERO} {
    yynum = 0;
    return tok_number;
}

{OCTAL} {
    yynum = strtol(yytext, NULL, 8);
    return tok_number;
}

{HEX} {
    yynum = strtol(yytext, NULL, 16);
    return tok_number;
}

{BIN} {
    yynum = strtol(yytext, NULL, 2);
    return tok_number;
}

{DECIMAL} {
    yynum = strtol(yytext, NULL, 10);
    return tok_number;
}

"int" {
    return tok_int;
}

"void" {
    return tok_void;
}

"char" {
    return tok_char;
}

"const" {
    return tok_const;
}

"," {
    return tok_comma;
}

";" {
    return tok_semicolon;
}

"=" {
    return tok_assign;
}

"+" {
    return tok_plus;
}

"-" {
    return tok_minus;
}

"*" {
    return tok_star;
}

"/" {
    return tok_slash;
}

"%" {
    return tok_mod;
}

"(" { 
    return tok_lparen; 
}

")" { 
    return tok_rparen; 
}

"[" {
    return tok_lbracket;
}

"]" {
    return tok_rbracket;
}

"{" {
    return tok_lbrace;
}

"}" {
    return tok_rbrace;
}

"<" {
    return tok_lt;
}

"<=" {
    return tok_le;
}

">" {
    return tok_gt;
}

">=" {
    return tok_ge;
}

"==" {
    return tok_eq;
}

"!=" {
    return tok_ne;
}

"&&" {
    return tok_and;
}

"||" {
    return tok_or;
}

"!" {
    return tok_not;
}

"if" {
    return tok_if;
}

"else" {
    return tok_else;
}

"while" {
    return tok_while;
}

"break" {
    return tok_break;
}

"continue" {
    return tok_continue;
}

"return" {
    return tok_return;
}

{STRING_LITERAL} {
    return tok_string_literal;
}

{IDENTIFIER} {
    return tok_identifier;
}

<<EOF>> { 
    return tok_eof; 
}

. {
    fprintf(stderr, "unknown %s\n", yytext);
    return tok_unknown;
}

%%