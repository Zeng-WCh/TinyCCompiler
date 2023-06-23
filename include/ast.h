#ifndef __AST__
#define __AST__

#include <vector>
#include <string>
#include <llvm/IR/Value.h>

class ConstDecl;
class VarDecl;
class ConstDefs;
class ConstInitVal;
class ConstSelector;
class InitVal;
class LVal;
class Exp;
class FuncFParams;
class FuncType;
class Block;
class Cond;
class AddExp;
class MulExp;
class Stmt;
class LOrExp;

class AST
{
public:
    virtual ~AST() = 0;
    virtual void print(int dep) = 0;
    virtual llvm::Value* eval() = 0;
    virtual bool isConst();
    virtual int getConstValue();
    void print_space(int n);
};

AST::~AST() {}

class CompUnit : public AST
{
private:
    // AST shoule be decl or func_def
    std::vector<AST *> _comp_units;

public:
    CompUnit() = default;
    ~CompUnit()
    {
        if (!_comp_units.empty())
        {
            for (auto comp_unit : _comp_units)
            {
                delete comp_unit;
            }
        }
        _comp_units.clear();
    }
    void add_comp_unit(AST *comp_unit)
    {
        _comp_units.push_back(comp_unit);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class Decl : public AST
{
private:
    ConstDecl *_const;
    VarDecl *_var;

public:
    Decl(ConstDecl *const_decl) : _const(const_decl), _var(nullptr) {}
    Decl(VarDecl *var) : _var(var), _const(nullptr) {}
    ~Decl()
    {
        if (_const != nullptr)
        {
            delete _const;
        }
        if (_var != nullptr)
        {
            delete _var;
        }
    }

    void print(int) override;
    llvm::Value* eval() override;
};

class FuncDef : public AST
{
private:
    std::string ident;
    FuncType *type;
    FuncFParams *params;
    Block *block;

public:
    FuncDef(FuncType *type, const std::string &ident, FuncFParams *params, Block *block) : type(type), ident(ident), params(params), block(block) {}
    ~FuncDef()
    {
        if (this->type)
        {
            delete this->type;
        }
        if (this->params)
        {
            delete this->params;
        }
        if (this->block)
        {
            delete this->block;
        }
    }

    void print(int) override;
    llvm::Value* eval() override;
};

class ConstDecl : public AST
{
private:
    // AST should be const_def
    std::vector<AST *> _const_defs;

public:
    ConstDecl() = default;
    ConstDecl(const std::vector<AST *> &const_defs) : _const_defs(const_defs) {}
    ~ConstDecl()
    {
        for (auto const_def : _const_defs)
        {
            delete const_def;
        }
    }
    void add_const_decl(AST *const_def)
    {
        _const_defs.push_back(const_def);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class VarDecl : public AST
{
private:
    std::vector<AST *> _var_defs;

public:
    VarDecl() = default;
    VarDecl(const std::vector<AST *> &var_defs)
    {
        for (auto var_def : var_defs)
        {
            _var_defs.push_back(var_def);
        }
    }
    ~VarDecl()
    {
        for (auto var_def : _var_defs)
        {
            delete var_def;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class VarDecls : public AST
{
public:
    // AST should be var_def
    std::vector<AST *> _var_decls;
    VarDecls()
    {
    }
    ~VarDecls()
    {
    }
    void add_var_decl(AST *var_decl)
    {
        _var_decls.push_back(var_decl);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class ConstDecls : public AST
{
public:
    std::vector<AST *> _const_decls;
    ConstDecls() = default;
    ~ConstDecls()
    {
    }
    void add_const_decl(AST *const_decl)
    {
        _const_decls.push_back(const_decl);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class ConstDef : public AST
{
private:
    std::string ident;
    // should return a Constant*
    ConstInitVal *iv;
    // should return a Type*
    ConstSelector *s;

public:
    ConstDef(const std::string &name, ConstSelector *selector, ConstInitVal *init_val) : ident(name), iv(init_val), s(selector) {}
    ~ConstDef()
    {
        if (this->iv)
        {
            delete this->iv;
        }
        if (this->s)
        {
            delete this->s;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class ConstSelector : public AST
{
public:
    // AST should be const exp
    std::vector<AST *> selects;
    ConstSelector() = default;
    ~ConstSelector()
    {
        for (auto select : selects)
        {
            delete select;
        }
    }
    void add_selector(AST *expr)
    {
        selects.push_back(expr);
    }

    void print(int dep) override;
    // this should return a Type*
    llvm::Value* eval() override;
};

class ConstInitVal : public AST
{
private:
    // AST should be const exp
    std::vector<AST *> _init_vals;

public:
    ConstInitVal() = default;
    ConstInitVal(const std::vector<AST *> &init_vals) : _init_vals(init_vals) {}
    ~ConstInitVal()
    {
        for (auto init_val : _init_vals)
        {
            delete init_val;
        }
    }

    void add_const_val(AST *val)
    {
        _init_vals.push_back(val);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class ConstExp : public AST
{
private:
    AddExp *add;

public:
    ConstExp(AddExp *add) : add(add) {}
    ~ConstExp()
    {
        if (this->add)
        {
            delete this->add;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
    bool isConst() override;
    int getConstValue() override;
};

class ConstInits : public AST
{
public:
    std::vector<AST *> _const_inits;
    ConstInits() = default;
    ~ConstInits()
    {
    }
    void add_const_init(AST *const_init)
    {
        _const_inits.push_back(const_init);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class VarDef : public AST
{
private:
    std::string ident;
    // should return a Type*
    ConstSelector *s;
    // should return a Value*/Constant*
    InitVal *iv;

public:
    VarDef(const std::string &name, ConstSelector *selector, InitVal *init_val) : ident(name), s(selector), iv(init_val) {}
    ~VarDef()
    {
        if (this->s)
        {
            delete this->s;
        }
        if (this->iv)
        {
            delete this->iv;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class InitVal : public AST
{
private:
    // AST should be exp
    std::vector<AST *> _init_vals;

public:
    InitVal() = default;
    InitVal(const std::vector<AST *> &init_vals) : _init_vals(init_vals) {}
    ~InitVal()
    {
        for (auto init_val : _init_vals)
        {
            delete init_val;
        }
    }
    void add_init_val(AST *init_val)
    {
        _init_vals.push_back(init_val);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
    bool isConst() override;
    int getConstValue() override;
};

class InitVals : public AST
{
public:
    std::vector<AST *> _init_vals;
    InitVals() = default;
    ~InitVals()
    {
    }
    void add_init_val(AST *init_val)
    {
        _init_vals.push_back(init_val);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class FuncType : public AST
{
public:
    // 1 for int, 0 for void
    int type;
    FuncType(int type) : type(type) {}
    ~FuncType() = default;

    void print(int dep) override;
    llvm::Value* eval() override;
};

class FuncFParam : public AST
{
public:
    std::string ident;
    // nullptr means unspecified,
    // only 0 index can be nullptr, others must be positive
    std::vector<AST *> _dims;

    FuncFParam(const std::string &name) : ident(name) {}
    FuncFParam(const std::string &name, const std::vector<AST *> &_dim) : ident(name), _dims(_dim) {}
    ~FuncFParam()
    {
        for (auto dim : _dims)
        {
            if (dim != nullptr)
            {
                delete dim;
            }
        }
    }
    void add_dim(AST *dim)
    {
        _dims.push_back(dim);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class Dim : public AST
{
public:
    std::vector<AST *> _dim;
    Dim() = default;
    ~Dim()
    {
    }
    void add_dim(AST *dim)
    {
        _dim.push_back(dim);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class FuncFParamList : public AST
{
public:
    // AST should be like func_fparam
    std::vector<AST *> _params;
    FuncFParamList() = default;
    ~FuncFParamList()
    {
    }
    void add_param(AST *param)
    {
        _params.push_back(param);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class FuncFParams : public AST
{
public:
    // AST should be like func_fparam
    std::vector<AST *> _params;
    FuncFParams() = default;
    FuncFParams(const std::vector<AST *> &params) : _params(params) {}
    ~FuncFParams()
    {
        for (auto param : _params)
        {
            delete param;
        }
    }
    void add_param(AST *param)
    {
        _params.push_back(param);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class BlockItem : public AST
{
private:
    Stmt *_stmt;
    Decl *_decl;

public:
    BlockItem(Stmt *stmt) : _stmt(stmt) {}
    BlockItem(Decl *decl) : _decl(decl) {}
    ~BlockItem()
    {
        if (_stmt)
        {
            delete _stmt;
        }
        if (_decl)
        {
            delete _decl;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class BlockItems : public AST
{
public:
    std::vector<AST *> _block_items;
    BlockItems() = default;
    ~BlockItems()
    {
    }
    void add_block_item(AST *item)
    {
        _block_items.push_back(item);
    }

    void print(int dep) override
    {
        fprintf(stderr, "This should not be called\n");
    }
    llvm::Value* eval() override;
};

class Block : public AST
{
private:
    std::vector<AST *> _block_items;

public:
    Block() = default;
    Block(const std::vector<AST *> &block_items) : _block_items(block_items) {}
    ~Block()
    {
        for (auto item : _block_items)
        {
            delete item;
        }
    }
    void add_block_item(AST *item)
    {
        _block_items.push_back(item);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class Assignment : public AST
{
private:
    LVal *_lval;
    Exp *_exp;

public:
    Assignment(LVal *lval, Exp *exp) : _lval(lval), _exp(exp) {}
    ~Assignment()
    {
        if (_lval)
        {
            delete _lval;
        }
        if (_exp)
        {
            delete _exp;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class IfStmt : public AST
{
private:
    Cond *condition;
    Stmt *true_part;
    Stmt *false_part;

public:
    IfStmt(Cond *condition, Stmt *true_part, Stmt *false_part) : condition(condition), true_part(true_part), false_part(false_part) {}
    IfStmt(Cond *condition, Stmt *true_part) : condition(condition), true_part(true_part), false_part(nullptr) {}
    ~IfStmt()
    {
        if (condition)
        {
            delete condition;
        }
        if (true_part)
        {
            delete true_part;
        }
        if (false_part)
        {
            delete false_part;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class WhileStmt : public AST
{
private:
    Cond *condition;
    Stmt *body;

public:
    WhileStmt(Cond *condition, Stmt *body) : condition(condition), body(body) {}
    ~WhileStmt()
    {
        if (condition)
        {
            delete condition;
        }
        if (body)
        {
            delete body;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class Stmt : public AST
{
private:
    Assignment *asg = nullptr;
    Exp *exp = nullptr;
    Block *block = nullptr;
    IfStmt *ifs = nullptr;
    WhileStmt *whiles = nullptr;
    // 0 for return, 1 for break, 2 for continue
    int type = -1;
    bool filled = false;
    Stmt* next = nullptr;

public:
    Stmt() = default;
    Stmt(Assignment *asg) : asg(asg) {}
    Stmt(Exp *exp) : exp(exp) {}
    Stmt(Block *block) : block(block) {}
    Stmt(IfStmt *ifs) : ifs(ifs) {}
    Stmt(WhileStmt *whiles) : whiles(whiles) {}
    Stmt(int type, Exp *exp = nullptr) : type(type), exp(exp) {
        if (type == 1 || type == 2) {
            filled = true;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;

    bool isFilled()
    {
        return filled;
    }
};

class AddExp : public AST
{
private:
    char op = 0;
    AddExp *add_exp = nullptr;
    MulExp *mul_exp = nullptr;

public:
    AddExp(MulExp *mul_exp) : mul_exp(mul_exp) {}
    AddExp(AddExp *add_exp, char op, MulExp *mul_exp) : add_exp(add_exp), op(op), mul_exp(mul_exp) {}
    ~AddExp()
    {
        if (add_exp)
        {
            delete add_exp;
        }
        if (mul_exp)
        {
            delete mul_exp;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
    bool isConst() override;
    int getConstValue() override;
};

class Exp : public AST
{
private:
    AddExp *add_exp;

public:
    Exp(AddExp *add_exp) : add_exp(add_exp) {}
    ~Exp()
    {
        if (add_exp)
        {
            delete add_exp;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
    bool isConst() override;
    int getConstValue() override;
};

class Cond : public AST
{
private:
    LOrExp *lor_exp = nullptr;

public:
    Cond(LOrExp *lor_exp) : lor_exp(lor_exp) {}
    ~Cond()
    {
        if (lor_exp)
        {
            delete lor_exp;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class LVal : public AST
{
private:
    std::string ident;
    std::vector<AST *> selectors;

public:
    LVal(const std::string &ident, const std::vector<AST *> &selectors) : ident(ident), selectors(selectors) {}
    ~LVal()
    {
        for (auto selector : selectors)
        {
            delete selector;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
    bool isConst() override;
    int getConstValue() override;
};

class PrimaryExp : public AST
{
private:
    int num = 0;
    Exp *exp = nullptr;
    LVal *lval = nullptr;

public:
    PrimaryExp(int num) : num(num) {}
    PrimaryExp(Exp *exp) : exp(exp) {}
    PrimaryExp(LVal *lval) : lval(lval) {}
    ~PrimaryExp()
    {
        if (exp)
        {
            delete exp;
        }
        if (lval)
        {
            delete lval;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
    bool isConst() override;
    int getConstValue() override;
};

class UnaryExp : public AST
{
private:
    PrimaryExp *primary_exp = nullptr;
    std::string callee;
    std::vector<AST *> rparams;
    char op = 0;
    UnaryExp *unary_exp = nullptr;

public:
    UnaryExp(PrimaryExp *primary_exp) : primary_exp(primary_exp) {}
    UnaryExp(const std::string &callee, const std::vector<AST *> &rparams) : callee(callee), rparams(rparams) {}
    UnaryExp(char op, UnaryExp *unary_exp) : op(op), unary_exp(unary_exp) {}
    ~UnaryExp()
    {
        if (primary_exp)
        {
            delete primary_exp;
        }
        if (unary_exp)
        {
            delete unary_exp;
        }
        for (auto rparam : rparams)
        {
            delete rparam;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
    bool isConst() override;
    int getConstValue() override;
};

class MulExp : public AST
{
private:
    UnaryExp *unary_exp = nullptr;
    MulExp *mul_exp = nullptr;
    char op = 0;

public:
    MulExp(UnaryExp *unary_exp) : unary_exp(unary_exp) {}
    MulExp(MulExp *mul_exp, char op, UnaryExp *unary_exp) : mul_exp(mul_exp), op(op), unary_exp(unary_exp) {}
    ~MulExp()
    {
        if (unary_exp)
        {
            delete unary_exp;
        }
        if (mul_exp)
        {
            delete mul_exp;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
    bool isConst() override;
    int getConstValue() override;
};

class RelExp : public AST
{
private:
    AddExp *add = nullptr;
    std::string op;
    RelExp *rel = nullptr;

public:
    RelExp(AddExp *add) : add(add) {}
    RelExp(RelExp *rel, const std::string &op, AddExp *add) : add(add), op(op), rel(rel) {}
    ~RelExp()
    {
        if (add)
        {
            delete add;
        }
        if (rel)
        {
            delete rel;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class EqExp : public AST
{
private:
    RelExp *rel = nullptr;
    std::string op;
    EqExp *eq = nullptr;

public:
    EqExp(RelExp *re) : rel(re) {}
    EqExp(EqExp *eq, const std::string &op, RelExp *rel) : eq(eq), op(op), rel(rel) {}
    ~EqExp()
    {
        if (rel)
        {
            delete rel;
        }
        if (eq)
        {
            delete eq;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class LAndExp : public AST
{
private:
    EqExp *eq = nullptr;
    LAndExp *land = nullptr;

public:
    LAndExp(EqExp *eq) : eq(eq) {}
    LAndExp(LAndExp *land, EqExp *eq) : land(land), eq(eq) {}
    ~LAndExp()
    {
        if (eq)
        {
            delete eq;
        }
        if (land)
        {
            delete land;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class LOrExp : public AST
{
private:
    LAndExp *land = nullptr;
    LOrExp *lor = nullptr;

public:
    LOrExp(LAndExp *land) : land(land) {}
    LOrExp(LOrExp *lor, LAndExp *land) : lor(lor), land(land) {}
    ~LOrExp()
    {
        if (land)
        {
            delete land;
        }
        if (lor)
        {
            delete lor;
        }
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class LValSelector : public AST
{
public:
    std::vector<AST *> _selectors;
    LValSelector() = default;
    ~LValSelector()
    {
    }
    void add_selector(AST *selector)
    {
        _selectors.push_back(selector);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

class FuncRParams : public AST
{
public:
    std::vector<AST *> _params;
    FuncRParams() = default;
    FuncRParams(const std::vector<AST *> &params) : _params(params) {}
    ~FuncRParams()
    {
    }
    void add_param(AST *param)
    {
        _params.push_back(param);
    }

    void print(int dep) override;
    llvm::Value* eval() override;
};

#endif