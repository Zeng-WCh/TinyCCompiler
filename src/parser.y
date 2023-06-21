%{
    #include "ast.h"
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
%left tok_lbrace

%union {
    int intVal;
    char *strVal;
    void *ast;
}

%token tok_int tok_void tok_char tok_number tok_string_literal
%token tok_identifier tok_const tok_comma tok_semicolon tok_assign
%token tok_plus tok_minus tok_star tok_slash tok_mod
%token tok_lparen tok_rparen tok_lbrace tok_rbrace tok_lbracket tok_rbracket
%token tok_lt tok_gt tok_le tok_ge tok_eq tok_ne
%token tok_and tok_or tok_not
%token tok_if tok_else tok_while tok_break tok_continue tok_return
%token tok_unknown

%type <ast> CompUnits CompUnit Decl FuncDef ConstDecl VarDecl ConstDecls ConstDef ConstSelector ConstInitVal ConstInits VarDecls VarDef InitVal Inits Params Param Block BlockItems BlockItem Stmt Exp Cond LVal LVals PrimaryExp UnaryExp Args MulExp AddExp RelExp EqExp LAndExp LOrExp ConstExp

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

ConstDecl: tok_const tok_int ConstDecls tok_semicolon{};

ConstDecls: ConstDecls tok_comma ConstDef {}
          | ConstDef {}
          ;

ConstDef: tok_identifier tok_assign ConstInitVal {}
        | tok_identifier ConstSelector tok_assign ConstInitVal {}
        ;

ConstSelector: tok_lbracket ConstExp tok_rbracket {}
             | ConstSelector tok_lbracket ConstExp tok_rbracket {}
             ;

ConstInitVal: ConstExp {}
            | tok_lbrace tok_rbrace {}
            | tok_lbrace ConstInits tok_rbrace {}
            ;

ConstInits: ConstInitVal {}
          | ConstInits tok_comma ConstInitVal {}
          ;

VarDecl: tok_int VarDecls tok_semicolon{};

VarDecls: VarDef {}
        | VarDecls tok_comma VarDef {}
        ;

VarDefs: tok_lbracket ConstExp tok_rbracket {}
        | VarDecls tok_lbracket ConstExp tok_rbracket {}
        ;

VarDef: tok_identifier {}
      | tok_identifier tok_assign InitVal {}
      | tok_identifier VarDefs {}
      | tok_identifier VarDefs tok_assign InitVal {}
      ;
    
InitVal: Exp {}
       | tok_lbrace tok_rbrace {}
       | tok_lbrace Inits tok_rbrace {}
       ;

Inits: InitVal {}
     | Inits tok_comma InitVal {}
     ;

FuncDef: tok_int tok_identifier tok_lparen tok_rparen Block {}
       | tok_int tok_identifier tok_lparen Params tok_rparen Block {}
       | tok_void tok_identifier tok_lparen tok_rparen Block {}
       | tok_void tok_identifier tok_lparen Params tok_rparen Block {}
       ;

Params: Param {}
      | Params tok_comma Param {}
      ;

Param: tok_int tok_identifier {}
     | tok_int tok_identifier tok_lbracket tok_rbracket {}
     | tok_int tok_identifier tok_lbracket tok_rbracket LVals {}
     ;

Block: tok_lbrace tok_rbrace {}
     | tok_lbrace BlockItems tok_rbrace {}
     ;

BlockItems: BlockItem {}
          | BlockItems BlockItem {}
          ;

BlockItem: Decl {}
         | Stmt {}
         ;

Stmt: LVal tok_assign Exp tok_semicolon {}
    | Exp tok_semicolon {}
    | tok_semicolon {}
    | Block {}
    | tok_if tok_lparen Cond tok_rparen Stmt {}
    | tok_if tok_lparen Cond tok_rparen Stmt tok_else Stmt {}
    | tok_while tok_lparen Cond tok_rparen Stmt {}
    | tok_break tok_semicolon {}
    | tok_continue tok_semicolon {}
    | tok_return Exp tok_semicolon {}
    | tok_return tok_semicolon {}
    ;

Exp: AddExp {};

Cond: LOrExp {};

LVal: tok_identifier {} {}
    | tok_identifier LVals {};

LVals: tok_lbracket Exp tok_rbracket {}
     | LVals tok_lbracket Exp tok_rbracket {}
     ;

PrimaryExp: tok_lparen Exp tok_rparen {}
          | LVal {}
          | tok_number {}

UnaryExp: PrimaryExp {}
        | tok_identifier tok_lparen tok_rparen {}
        | tok_identifier tok_lparen Args tok_rparen {}
        | tok_plus UnaryExp {}
        | tok_minus UnaryExp {}
        | tok_not UnaryExp {}
        ;

Args: Exp {}
    | Args tok_comma Exp {}
    ;

MulExp: UnaryExp {}
      | MulExp tok_star UnaryExp {}
      | MulExp tok_slash UnaryExp {}
      | MulExp tok_mod UnaryExp {}
      ;

AddExp: MulExp {}
      | AddExp tok_plus MulExp {}
      | AddExp tok_minus MulExp {}
      ;

RelExp: AddExp {}
      | RelExp tok_lt AddExp {}
      | RelExp tok_gt AddExp {}
      | RelExp tok_le AddExp {}
      | RelExp tok_ge AddExp {}
      ;

EqExp: RelExp {}
     | EqExp tok_eq RelExp {}
     | EqExp tok_ne RelExp {}
     ;

LAndExp: EqExp {}
       | LAndExp tok_and EqExp {}
       ;

LOrExp: LAndExp {}
      | LOrExp tok_or LAndExp {}
      ;

ConstExp: AddExp {};

%%