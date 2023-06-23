#include "ast.h"
#include "SymbolTable.h"
#include <map>
#include <stack>
#include <cstdio>
#include <cassert>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>

using namespace llvm;

class Hole
{
private:
    std::map<std::string, Value *> _hole;

public:
    Hole() = default;
    ~Hole()
    {
    }
    void insert(std::string name, Value *value)
    {
        _hole.insert(std::pair<std::string, Value *>(name, value));
    }
};

extern LLVMContext *TheContext;
extern IRBuilder<> *Builder;
extern Module *TheModule;

namespace
{
    SymbolTable sym_table;
}

void AST::print_space(int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf(" ");
    }
}

void CompUnit::print(int dep)
{
    print_space(dep);
    printf("`-CompUnit\n");
    for (auto comp_unit : _comp_units)
    {
        comp_unit->print(dep + 2);
    }
}

void Decl::print(int dep)
{
    print_space(dep);
    printf("`-Decl\n");
    if (_const != nullptr)
    {
        _const->print(dep + 2);
    }
    if (_var != nullptr)
    {
        _var->print(dep + 2);
    }
}

Value *CompUnit::eval()
{
    IRBuilder<> builder();
}

void FuncDef::print(int dep)
{
    print_space(dep);
    printf("`-FuncDef\n");
    print_space(dep + 2);
    printf("`-FuncType\n");
    type->print(dep + 4);
    print_space(dep + 2);
    printf("`-Ident: %s\n", ident.c_str());
    if (params != nullptr)
    {
        params->print(dep + 2);
    }
    block->print(dep + 2);
}

void ConstDecl::print(int dep)
{
    print_space(dep);
    printf("`-ConstDecl\n");
    for (auto const_def : _const_defs)
    {
        const_def->print(dep + 2);
    }
}

void VarDecl::print(int dep)
{
    print_space(dep);
    printf("`-VarDecl\n");
    for (AST *var_def : _var_defs)
    {
        var_def->print(dep + 2);
    }
}

void VarDecls::print(int)
{
    fprintf(stderr, "Called from VarDecls, This should not be called\n");
}

void ConstDecls::print(int)
{
    fprintf(stderr, "Called from ConstDecls, This should not be called\n");
}

void ConstDef::print(int dep)
{
    print_space(dep);
    printf("`-ConstDef\n");
    print_space(dep + 2);
    printf("`-Ident: %s\n", ident.c_str());
    if (s != nullptr)
    {
        s->print(dep + 2);
    }
    iv->print(dep + 2);
}

void ConstSelector::print(int dep)
{
    print_space(dep);
    printf("`-ConstInitVal\n");
    for (auto init_val : selects)
    {
        init_val->print(dep + 2);
    }
}

void ConstInitVal::print(int dep)
{
    print_space(dep);
    printf("`-ConstInitVal\n");
    for (auto init_val : _init_vals)
    {
        init_val->print(dep + 2);
    }
}

void ConstExp::print(int dep)
{
    print_space(dep);
    printf("`-ConstExp\n");
    add->print(dep + 2);
}

Value *ConstExp::eval()
{
    return this->add->eval();
}

void ConstInits::print(int)
{
    fprintf(stderr, "Called from ConstInits, This should not be called\n");
}

void VarDef::print(int dep)
{
    print_space(dep);
    printf("`-VarDef\n");
    print_space(dep + 2);
    printf("`-Ident: %s\n", ident.c_str());
    if (s != nullptr)
    {
        s->print(dep + 2);
    }
    if (iv != nullptr)
    {
        iv->print(dep + 2);
    }
}

void InitVal::print(int dep)
{
    print_space(dep);
    printf("`-InitVal\n");
    for (auto init_val : _init_vals)
    {
        init_val->print(dep + 2);
    }
}

void InitVals::print(int)
{
    fprintf(stderr, "Called from InitVals, This should not be called\n");
}

void FuncType::print(int dep)
{
    print_space(dep);
    printf("`-FuncType\n");
    print_space(dep + 2);
    printf("`-Type: %s\n", type == 1 ? "int" : "void");
}

void FuncFParam::print(int dep)
{
    print_space(dep);
    printf("`-FuncFParam\n");
    print_space(dep + 2);
    printf("`-Ident: %s\n", ident.c_str());
    for (auto dim : _dims)
    {
        if (dim != nullptr)
        {
            dim->print(dep + 2);
        }
        else
        {
            print_space(dep + 2);
            printf("`-Dim: unspecified\n");
        }
    }
}

void Dim::print(int)
{
    fprintf(stderr, "Called from Dim, This should not be called\n");
}

void FuncFParamList::print(int)
{
    fprintf(stderr, "Called from FuncFParamList, This should not be called\n");
}

void FuncFParams::print(int dep)
{
    print_space(dep);
    printf("`-FuncFParams\n");
    for (auto param : _params)
    {
        param->print(dep + 2);
    }
}

void BlockItem::print(int dep)
{
    print_space(dep);
    printf("`-BlockItem\n");
    if (_stmt)
    {
        _stmt->print(dep + 2);
    }
    if (_decl)
    {
        _decl->print(dep + 2);
    }
}

void Block::print(int dep)
{
    print_space(dep);
    printf("`-Block\n");
    for (auto item : _block_items)
    {
        item->print(dep + 2);
    }
}

void Assignment::print(int dep)
{
    print_space(dep);
    printf("`-Assignment\n");
    _lval->print(dep + 2);
    _exp->print(dep + 2);
}

void IfStmt::print(int dep)
{
    print_space(dep);
    printf("`-IfStmt\n");
    condition->print(dep + 2);
    true_part->print(dep + 2);
    if (false_part)
    {
        false_part->print(dep + 2);
    }
}

void WhileStmt::print(int dep)
{
    print_space(dep);
    printf("`-WhileStmt\n");
    condition->print(dep + 2);
    body->print(dep + 2);
}

Value *WhileStmt::eval()
{
    Value *cond = this->condition->eval();
    Function *TheFunction = Builder->GetInsertBlock()->getParent();
    // true part
    BasicBlock *trueBB = BasicBlock::Create(*TheContext, "trueBB", TheFunction);
    BasicBlock *falseBB = BasicBlock::Create(*TheContext, "falseBB", TheFunction);
}

void Stmt::print(int dep)
{
    print_space(dep);
    printf("`-Stmt\n");
    if (asg)
    {
        asg->print(dep + 2);
    }
    else if (exp)
    {
        if (type == 0)
        {
            print_space(dep + 2);
            printf("`-ReturnStmt\n");
            dep += 2;
        }
        exp->print(dep + 2);
    }
    else if (block)
    {
        block->print(dep + 2);
    }
    else if (ifs)
    {
        ifs->print(dep + 2);
    }
    else if (whiles)
    {
        whiles->print(dep + 2);
    }
    else
    {
        if (type == 0)
        {
            print_space(dep + 2);
            printf("`-ReturnStmt\n");
        }
        else if (type == 1)
        {
            print_space(dep + 2);
            printf("`-BreakStmt\n");
        }
        else if (type == 2)
        {
            print_space(dep + 2);
            printf("`-ContinueStmt\n");
        }
        else
        {
            printf("`-EmptyStmt\n");
        }
    }
}

Value *Stmt::eval()
{
    if (asg)
    {
        return asg->eval();
    }
    else if (exp)
    {
        if (type == 0)
        {
            // return stmt
            return Builder->CreateRet(exp->eval());
        }
        else
        {
            return exp->eval();
        }
    }
    else if (block)
    {
        return block->eval();
    }
    else if (ifs)
    {
        return ifs->eval();
    }
    else if (whiles)
    {
        return whiles->eval();
    }
    else
    {
        if (type == 0)
        {
            // return stmt
            return Builder->CreateRetVoid();
        }
        else if (type == 1)
        {
            // break stmt
            // so we need to find the loop block
            BasicBlock *curBlock = Builder->GetInsertBlock();
            // create a new block
            BasicBlock *newBlock = BasicBlock::Create(*TheContext, "breakBlock", curBlock->getParent());
            // jump to the new block
            return Builder->CreateBr(newBlock);
        }
        else if (type == 2)
        {
            // continue stmt
            // so we need to find the loop block
            BasicBlock *curBlock = Builder->GetInsertBlock();
            // jump to the loop block
            return Builder->CreateBr(curBlock);
        }
        else
        {
            // empty stmt
            return nullptr;
        }
    }
}

void AddExp::print(int dep)
{
    print_space(dep);
    printf("`-AddExp\n");
    if (add_exp && mul_exp)
    {
        add_exp->print(dep + 2);
        print_space(dep + 2);
        printf("`-%c\n", op);
        mul_exp->print(dep + 2);
    }
    else
    {
        mul_exp->print(dep + 2);
    }
}

Value *AddExp::eval()
{
    if (add_exp && mul_exp)
    {
        Value *left = add_exp->eval();
        Value *right = mul_exp->eval();
        switch (op)
        {
        case '+':
            return Builder->CreateAdd(left, right);
        case '-':
            return Builder->CreateSub(left, right);
        default:
            return nullptr;
        }
    }
    else
    {
        return mul_exp->eval();
    }
}

void Exp::print(int dep)
{
    print_space(dep);
    printf("`-Exp\n");
    add_exp->print(dep + 2);
}

Value *Exp::eval()
{
    return add_exp->eval();
}

void Cond::print(int dep)
{
    print_space(dep);
    printf("`-Cond\n");
    lor_exp->print(dep + 2);
}

Value *Cond::eval()
{
    return lor_exp->eval();
}

void LVal::print(int dep)
{
    print_space(dep);
    printf("`-LVal\n");
    print_space(dep + 2);
    printf("`-%s\n", ident.c_str());
    for (auto selector : selectors)
    {
        selector->print(dep + 2);
    }
}

Value *LVal::eval()
{
    Value *val = TheModule->getNamedGlobal(ident);
    if (val == nullptr)
    {
        // try local
        val = sym_table.lookup(ident);
        if (val == nullptr)
        {
            // not found
            fprintf(stderr, "Error: variable %s not found\n", ident.c_str());
            return nullptr;
        }
    }
    else
    {
        // TODO TYPE CHECK
        if (this->selectors.empty())
        {
            // just a variable
            return val;
        }
        else
        {
            // array
            Type *t = val->getType();
            // Type Check
            if (t->isArrayTy())
            {
                // ok
            }
            else
            {
                fprintf(stderr, "Error: %s is not an array\n", ident.c_str());
                return nullptr;
            }
            for (auto selector : selectors)
            {
                if (t->isArrayTy())
                {
                    // ok
                }
                else
                {
                    fprintf(stderr, "Error: %s is not an array\n", ident.c_str());
                    return nullptr;
                }
                Value *idx = selector->eval();
                if (idx == nullptr)
                {
                    return nullptr;
                }
                if (idx->getType() != Type::getInt32Ty(*TheContext))
                {
                    fprintf(stderr, "Error: array index must be int\n");
                    return nullptr;
                }
                val = Builder->CreateGEP(t, val, idx);
                t = t->getArrayElementType();
            }
            return val;
        }
    }
    return val;
}

void PrimaryExp::print(int dep)
{
    print_space(dep);
    printf("`-PrimaryExp\n");
    if (exp)
    {
        exp->print(dep + 2);
    }
    else if (lval)
    {
        lval->print(dep + 2);
    }
    else
    {
        print_space(dep + 2);
        printf("`-%d\n", num);
    }
}

Value *PrimaryExp::eval()
{
    if (exp)
    {
        return exp->eval();
    }
    else if (lval)
    {
        return lval->eval();
    }
    else
    {
        return ConstantInt::get(Type::getInt32Ty(*TheContext), num);
    }
}

void UnaryExp::print(int dep)
{
    print_space(dep);
    printf("`-UnaryExp\n");
    if (primary_exp)
    {
        primary_exp->print(dep + 2);
    }
    else if (unary_exp)
    {
        print_space(dep + 2);
        printf("`-%c\n", op);
        unary_exp->print(dep + 2);
    }
    else
    {
        print_space(dep + 2);
        printf("`-%s\n", callee.c_str());
        for (auto rparam : rparams)
        {
            rparam->print(dep + 2);
        }
    }
}

Value *UnaryExp::eval()
{
    if (primary_exp)
    {
        return primary_exp->eval();
    }
    else if (unary_exp)
    {
        auto val = unary_exp->eval();
        if (op == '+')
        {
            return val;
        }
        else if (op == '-')
        {
            return Builder->CreateNeg(val);
        }
        else if (op == '!')
        {
            // TODO : check
            return Builder->CreateNot(val);
        }
        return val;
    }
    else
    {
        // Func Call
        Function *func = TheModule->getFunction(callee);
        if (func == nullptr)
        {
            fprintf(stderr, "Function %s not found\n", callee.c_str());
            return nullptr;
        }
        std::vector<Value *> args;
        for (int i = 0; i < this->rparams.size(); i++)
        {
            args.push_back(rparams[i]->eval());
        }
        return Builder->CreateCall(func, args);
    }
}

void MulExp::print(int dep)
{
    print_space(dep);
    printf("`-MulExp\n");
    if (mul_exp && unary_exp)
    {
        mul_exp->print(dep + 2);
        print_space(dep + 2);
        printf("`-%c\n", op);
        unary_exp->print(dep + 2);
    }
    else
    {
        unary_exp->print(dep + 2);
    }
}

Value *MulExp::eval()
{
    if (mul_exp)
    {
        auto left = mul_exp->eval();
        auto right = unary_exp->eval();
        if (op == '*')
        {
            return Builder->CreateMul(left, right);
        }
        else if (op == '/')
        {
            return Builder->CreateSDiv(left, right);
        }
        else if (op == '%')
        {
            return Builder->CreateSRem(left, right);
        }
    }
    else
    {
        return unary_exp->eval();
    }
}

void RelExp::print(int dep)
{
    print_space(dep);
    printf("`-RelExp\n");
    if (rel)
    {
        rel->print(dep + 2);
        print_space(dep + 2);
        printf("`-%s\n", op.c_str());
        add->print(dep + 2);
    }
    else
    {
        add->print(dep + 2);
    }
}

Value *RelExp::eval()
{
    if (rel)
    {
        auto left = rel->eval();
        auto right = add->eval();
        if (op == "<")
        {
            return Builder->CreateICmpSLT(left, right);
        }
        else if (op == ">")
        {
            return Builder->CreateICmpSGT(left, right);
        }
        else if (op == "<=")
        {
            return Builder->CreateICmpSLE(left, right);
        }
        else
        {
            return Builder->CreateICmpSGE(left, right);
        }
    }
    else
    {
        return add->eval();
    }
}

void EqExp::print(int dep)
{
    print_space(dep);
    printf("`-EqExp\n");
    if (eq)
    {
        eq->print(dep + 2);
        print_space(dep + 2);
        printf("`-%s\n", op.c_str());
        rel->print(dep + 2);
    }
    else
    {
        rel->print(dep + 2);
    }
}

Value *EqExp::eval()
{
    if (eq)
    {
        auto left = eq->eval();
        auto right = rel->eval();
        if (op == "==")
        {
            return Builder->CreateICmpEQ(left, right);
        }
        else
        {
            return Builder->CreateICmpNE(left, right);
        }
    }
    else
    {
        return rel->eval();
    }
}

void LAndExp::print(int dep)
{
    print_space(dep);
    printf("`-LAndExp\n");
    if (land)
    {
        land->print(dep + 2);
        eq->print(dep + 2);
    }
    else
    {
        eq->print(dep + 2);
    }
}

Value *LAndExp::eval()
{
    if (land)
    {
        auto left = eq->eval();
        auto right = land->eval();
        return Builder->CreateAnd(left, right);
    }
    else
    {
        return this->eq->eval();
    }
}

void LOrExp::print(int dep)
{
    print_space(dep);
    printf("`-LOrExp\n");
    if (lor)
    {
        lor->print(dep + 2);
        land->print(dep + 2);
    }
    else
    {
        land->print(dep + 2);
    }
}

Value *LOrExp::eval()
{
    if (lor)
    {
        auto left = lor->eval();
        auto right = land->eval();
        return Builder->CreateOr(left, right);
    }
    else
    {
        return this->land->eval();
    }
}

void LValSelector::print(int)
{
    fprintf(stderr, "Called from LValSelector, This should not be called\n");
}

Value *LValSelector::eval()
{
    fprintf(stderr, "Called from LValSelector, This should not be called\n");
    return nullptr;
}

void FuncRParams::print(int)
{
    fprintf(stderr, "Called from FuncRParams, This should not be called\n");
}

Value *FuncRParams::eval()
{
    fprintf(stderr, "Called from FuncRParams, This should not be called\n");
    return nullptr;
}