#include "ast.h"
#include <cstdio>
#include <cassert>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>

using namespace llvm;

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

Value* CompUnit::eval() {
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
        if (type == 0) {
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
    else {
        if (type == 0) {
            print_space(dep + 2);
            printf("`-ReturnStmt\n");
        }
        else if (type == 1) {
            print_space(dep + 2);
            printf("`-BreakStmt\n");
        }
        else if (type == 2) {
            print_space(dep + 2);
            printf("`-ContinueStmt\n");
        }
        else {
            printf("`-EmptyStmt\n");
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

void Exp::print(int dep)
{
    print_space(dep);
    printf("`-Exp\n");
    add_exp->print(dep + 2);
}

void Cond::print(int dep)
{
    print_space(dep);
    printf("`-Cond\n");
    lor_exp->print(dep + 2);
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

void LValSelector::print(int)
{
    fprintf(stderr, "Called from LValSelector, This should not be called\n");
}

void FuncRParams::print(int)
{
    fprintf(stderr, "Called from FuncRParams, This should not be called\n");
}
