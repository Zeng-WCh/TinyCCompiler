%{
    #include "ast.hpp"
    #include "token.h"  
    #include <cstdio> 

    int yylex();

    #define yyerror(x) \
    do {\
        fprintf(stderr, "error: %s\n", x); \
    } while(0)
%}

%output "parser.cpp"
%defines "token.h"

%union {
    int intVal;
    char *strVal;
    AST *ast;
}

%token tok_int tok_void tok_char tok_number tok_string_literal
%token tok_identifier tok_const tok_comma tok_semicolon tok_assign
%token tok_plus tok_minus tok_star tok_slash tok_mod
%token tok_lparen tok_rparen tok_lbrace tok_rbrace tok_lbracket tok_rbracket
%token tok_lt tok_gt tok_le tok_ge tok_eq tok_ne
%token tok_and tok_or tok_not
%token tok_if tok_else tok_while tok_break tok_continue tok_return
%token tok_unknown

%type <ast> CompUnits

%start CompUnits

%%

CompUnits: tok_int {};
%%