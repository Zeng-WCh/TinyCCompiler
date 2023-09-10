# TinyCCompiler

## Grammar

This project use a subset of C language, which is called SysY(tiny C), the grammar is shown below.

```text
CompuUnit -> [CompUnit] (Decl | FuncDef)
Decl -> ConstDecl | VarDecl
ConstDecl -> 'const' BType ConstDef {',' ConstDef} ';'
BType -> 'int'
ConstDef -> Ident {'[' ConstExp ']'} '=' ConstInitVal
ConstInitVal -> ConstExp
                | '{' [ConstInitVal {',' ConstInitVal}] '}'
VarDecl -> BType VarDef {',' VarDef} ';'
VarDef -> Ident {'[' ConstExp ']'}
          | Ident {'[' ConstExp ']'} '=' InitVal
InitVal -> Exp
           | '{' [InitVal {',' InitVal}] '}'
FuncDef -> FuncType Ident '(' [FuncFParams] ')'
FuncType -> 'void'
            | 'int'
FuncFParams -> FuncFParam {',' FuncFParam}
FuncFParam -> BType Ident ['[' ']' {'[' Exp ']'}]
Block -> '{' {BlockItem} '}'
BlockItem -> Decl 
             | Stmt
Stmt -> LVal '=' Exp ';'
        | [Exp] ';'
        | Block
        | 'if' '(' Cond ')' Stmt ['else' Stmt]
        | 'while' '(' Cond ')' Stmt
        | 'break' ';'
        | 'continue' ';'
        | 'return' [Exp] ';'
Exp -> AddExp
Cond -> LOrExp
LVal -> Ident {'[' Exp ']'}
PrimaryExp -> '(' Exp ')'
              | LVal
              | Number
UnaryExp -> PrimaryExp
            | Ident '(' [FuncRParams] ')'
            | UnaryOp UnaryExp
UnaryOp -> '+' | '-' | '!'
FuncRParams -> Exp {',' Exp}
MulExp -> UnaryExp {MulOp UnaryExp}
MulOp -> '*' | '/' | '%'
AddExp -> MulExp {AddOp MulExp}
AddOp -> '+' | '-'
RelExp -> {RelExp RelOp} AddExp
RelOp -> '<' | '>' | '<=' | '>='
EqExp -> RelExp {EqOp RelExp}
EqOp -> '==' | '!='
LAndExp -> EqExp {LAndOp EqExp}
LAndOp -> '&&'
LOrExp -> LAndExp {LOrOp LAndExp}
LOrOp -> '||'
ConstExp -> AddExp
Ident -> [a-zA-Z_][a-zA-Z0-9_]*
Number -> [0-9]+
```