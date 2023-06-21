%{
    #include "ast.hpp"
    #include "parser.h"  
    #include <cstdio>  
%}

%output "parser.c"
%defines "token.h"

%union {
    int intVal;
    char *strVal;
    AST *ast;
}

%token tok_int, tok_void, tok_char, tok_number, tok_string_literal
%token tok_identifier, tok_const, tok_comma, tok_semicolon, tok_assign
%token tok_plus, tok_minus, tok_star, tok_slash, tok_mod
%token tok_lparen, tok_rparen, tok_lbrace, tok_rbrace, tok_lbracket, tok_rbracket
%token tok_lt, tok_gt, tok_le, tok_ge, tok_eq, tok_ne
%token tok_and, tok_or, tok_not
%token tok_if, tok_else, tok_while, tok_break, tok_continue, tok_return
%token tok_unknown

%type <ast> program

%start CompUnits

%%

CompUnits: CompUnits CompUnit {}
         | CompUnit {}
        ;

CompUnit: Decl {}
        | FuncDef {}
        ;

Decl: ConstDecl {}
    | VarDecl {}
    ;

ConstDecl: tok_const BTYPE ConstDecls tok_semicolon{};

ConstDecls: ConstDefs tok_comma ConstDef {}
          | ConstDef {}
          ;

ConstDef: tok_identifier tok_assign ConstInitVal {}
        | tok_identifier ConstSelector tok_assign ConstInitVal {}
        ;

ConstSelector: tok_lbracket ConstExp tok_rbracket {}
             | ConstSelector tok_lbracket ConstExp tok_rbracket {}
             ;

ConstInitVal: ConstExp {}
            | tok_lbrace tok_rbrace
            | tok_lbrace ConstInits tok_rbrace
            ;

ConstInits: ConstInitVal {}
          | ConstInits tok_comma ConstInitVal {}
          ;

VarDecl: BTYPE VarDecls tok_semicolon{};

VarDecls: VarDef 

%%