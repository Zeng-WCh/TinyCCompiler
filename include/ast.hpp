#ifndef __AST__
#define __AST__

class AST {
    public:
        virtual ~AST() = default;
};

class CompUnit : public AST {

};

class Decl : public AST {

};

class FuncDef : public AST {

};

class ConstDecl : public AST {

};

class VarDecl : public AST {

};

class BType : public AST {

};

class ConstDef : public AST {

};

class ConstInitVal : public AST {

};

class ConstExp : public AST {

};

class VarDef : public AST {

};

class InitVal : public AST {

};

class FuncType : public AST {

};

class FuncFParams : public AST {

};

class FuncFParam : public AST {

};

class Block : public AST {

};

class BlockItem : public AST {

};

class Stmt : public AST {

};

class Exp : public AST {

};

class Cond : public AST {

};

class LVal : public AST {

};

class PrimaryExp : public AST {

};

class Number : public AST {

};

class UnaryExp : public AST {

};

class UnaryOp : public AST {

};

class FuncRParams : public AST {

};

class MulExp : public AST {

};

class AddExp : public AST {

};

class RelExp : public AST {

};

class EqExp : public AST {

};

class LAndExp : public AST {

};

class LOrExp : public AST {

};

#endif