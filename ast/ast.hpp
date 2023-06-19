#ifndef __AST__
#define __AST__

class AST {
    public:
        virtual ~AST() = default;
};

class CompUnit : AST {

};

class Decl : AST {

};

class FuncDef : AST {

};

class ConstDecl : AST {

};

class VarDecl : AST {

};

class BType : AST {

};

class ConstDef : AST {

};

class ConstInitVal : AST {

};

class ConstExp : AST {

};

class VarDef : AST {

};

class InitVal : AST {

};

class FuncType : AST {

};

class FuncFParams : AST {

};

class FuncFParam : AST {

};

class Block : AST {

};

class BlockItem : AST {

};

class Stmt : AST {

};

class Exp : AST {

};

class Cond : AST {

};

class LVal : AST {

};

class PrimaryExp : AST {

};

class Number : AST {

};

class UnaryExp : AST {

};

class UnaryOp : AST {

};

class FuncRParams : AST {

};

class MulExp : AST {

};

class AddExp : AST {

};

class RelExp : AST {

};

class EqExp : AST {

};

class LAndExp : AST {

};

class LOrExp : AST {

};

class ConstExp : AST {

};

#endif