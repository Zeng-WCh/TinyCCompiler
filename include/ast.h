#ifndef __AST__
#define __AST__

#include <vector>
#include <string>

class ConstDecl;
class VarDecl;
class ConstDefs;
class ConstInitVal;
class ConstSelector;

class AST {
    public:
        virtual ~AST() = default;
};

class CompUnit : public AST {
    private:
        std::vector<AST*> _comp_units;
    public:
        CompUnit() = default;
        ~CompUnit() {
            if (!_comp_units.empty()) {
                for (auto comp_unit : _comp_units) {
                    delete comp_unit;
                }
            }
            _comp_units.clear();
        }
        void add_comp_unit(AST* comp_unit) {
            _comp_units.push_back(comp_unit);
        }

};

class Decl : public AST {
    private:
        ConstDecl* _const;
        VarDecl* _var;
    public:
        Decl(ConstDecl* const_decl) : _const(const_decl), _var(nullptr) {}
        Decl(VarDecl* var) : _var(var), _const(nullptr) {}
        ~Decl() {
            if (_const != nullptr) {
                delete _const;
            }
            if (_var != nullptr) {
                delete _var;
            }
        }
};

class FuncDef : public AST {

};

class ConstDecl : public AST {
    private:
        ConstDefs* _const_defs;
    public:
        ConstDecl(ConstDefs* const_defs) : _const_defs(const_defs) {}
        ~ConstDecl() {
            if (_const_defs != nullptr) {
                delete _const_defs;
            }
        }
};

class VarDecl : public AST {
    private:
        std::vector<AST*> _var_defs;
    public:
        VarDecl() = default;
        ~VarDecl() {
            for (auto var_def : _var_defs) {
                delete var_def;
            }
        }
};

class BType : public AST {

};

class ConstDefs : public AST {
    private:
        std::vector<AST*> _const_defs;
    public:
        ConstDefs() = default;
        ~ConstDefs() {
            for (auto ast : _const_defs) {
                delete ast;
            }
        }
        void add_const(AST *const_def) {
            _const_defs.push_back(const_def);
        }
};

class ConstDef : public AST {
    private:
        std::string ident;
        ConstInitVal* iv;
        ConstSelector* s;
    public:
        ConstDef(const std::string& name, ConstInitVal* init_val, ConstSelector* selector) : ident(name), iv(init_val), s(selector) {}
        ~ConstDef() {
            if (this->iv) {
                delete this->iv;
            }
            if (this->s) {
                delete this->s;
            }
        }
};

class ConstSelector: public AST {
    private:
        std::vector<AST*> selects;
    public:
        ConstSelector() = default;
        ~ConstSelector() {
            for(auto select : selects) {
                delete select;
            }
        }
        void add_selector(AST* expr) {
            selects.push_back(expr);
        }
};

class ConstInitVal : public AST {
    private:
        std::vector<AST*> _init_vals;
    public:
        ConstInitVal() = default;
        ~ConstInitVal() {
            for (auto init_val : _init_vals) {
                delete init_val;
            }
        }

        void add_const_val(AST* val) {
            _init_vals.push_back(val);
        }
};

class ConstExp : public AST {

};

class ConstInits : public AST {
    private:
        std::vector<AST*> _const_inits;
    public:
        ConstInits() = default;
        ~ConstInits() {
            for (auto const_init : _const_inits) {
                delete const_init;
            }
        }
        void add_const_init(AST* const_init) {
            _const_inits.push_back(const_init);
        }
        std::vector<AST*>& get_const_inits() {
            return _const_inits;
        }
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