#include "ast.h"
#include "SymbolTable.h"
#include <map>
#include <stack>
#include <cstdio>
#include <cassert>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>

using namespace llvm;

extern LLVMContext *TheContext;
extern IRBuilder<> *Builder;
extern Module *TheModule;

namespace
{
    SymbolTable sym_table;
    std::stack<std::pair<BasicBlock *, BasicBlock *>> holeStack;
    std::map<std::string, Type *> globalMap;
    int constEval = -1;
    bool iv_const = false;
    Value *local_var;
    Type *local_type;

    bool isAssign = true;
    bool isRet = false;
    bool isBranch = false;
    bool genConst = false;
    Type *arr_type = nullptr;
}

bool AST::isConst()
{
    return false;
}

void AST::print_space(int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf(" ");
    }
}

int AST::getConstValue()
{
    return -114514;
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

Value *CompUnit::eval()
{
    for (auto comp_unit : _comp_units)
    {
        comp_unit->eval();
    }
    return nullptr;
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

Value *Decl::eval()
{
    if (_const != nullptr)
    {
        return _const->eval();
    }
    if (_var != nullptr)
    {
        return _var->eval();
    }
    return nullptr;
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

Value *ConstDecl::eval()
{
    for (auto const_def : _const_defs)
    {
        const_def->eval();
    }
    return nullptr;
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

Value *VarDecl::eval()
{
    for (auto var_def : _var_defs)
    {
        var_def->eval();
    }
    return nullptr;
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

Value *ConstDef::eval()
{
    bool isGlobal = (sym_table.isempty());

    Value *val = nullptr;
    Type *t = nullptr;

    if (s == nullptr)
    {
        t = llvm::Type::getInt32Ty(*TheContext);
    }
    else
    {
        t = (Type *)s->eval();
    }

    if (iv != nullptr)
    {
        val = iv->eval();
    }
    else
    {
        if (t->isArrayTy())
        {
            val = ConstantAggregateZero::get(t);
        }
        else
        {
            val = ConstantInt::get(t, 0);
        }
    }

    if (isGlobal)
    {
        TheModule->getOrInsertGlobal(ident, t);
        GlobalVariable *gVar = TheModule->getNamedGlobal(ident);
        gVar->setLinkage(GlobalValue::ExternalLinkage);
        gVar->setInitializer((Constant *)val);
        globalMap[ident] = t;
    }
    else
    {
        auto it = sym_table.lookup(ident);
        if (it != nullptr)
        {
            fprintf(stderr, "Error: %s has been defined\n", ident.c_str());
            return nullptr;
        }
        Value *v = Builder->CreateAlloca(t, nullptr, ident);
        Builder->CreateStore(val, v);
        sym_table.insert(ident, v, t, true);
    }

    return nullptr;
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

Value *ConstInitVal::eval()
{
    if (_init_vals.size() > 1)
    {
        // array
        int size = _init_vals.size();
        std::vector<Constant *> vals;
        for (auto init_val : _init_vals)
        {
            vals.push_back((Constant *)init_val->eval());
        }
        Constant *retVal = ConstantArray::get(ArrayType::get(Type::getInt32Ty(*TheContext), size), vals);
    }
    else
    {
        // single
        return _init_vals[0]->eval();
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
    if (!this->add->isConst())
    {
        fprintf(stderr, "Error: ConstExp is not const\n");
        return nullptr;
    }
    int val = this->add->getConstValue();
    return ConstantInt::get(Type::getInt32Ty(*TheContext), val, true);
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

Value *VarDef::eval()
{
    if (sym_table.isempty())
    {
        // global
        auto it = TheModule->getNamedGlobal(ident);
        if (it != nullptr)
        {
            fprintf(stderr, "Error: %s has been defined\n", ident.c_str());
            return nullptr;
        }
        Type *t = nullptr;
        if (s == nullptr)
        {
            t = Type::getInt32Ty(*TheContext);
        }
        else
        {
            t = (Type *)s->eval();
            arr_type = t;
        }
        if (iv == nullptr)
        {
            TheModule->getOrInsertGlobal(ident, t);
            GlobalVariable *gVar = TheModule->getNamedGlobal(ident);
            gVar->setLinkage(GlobalValue::ExternalLinkage);
            gVar->setInitializer(ConstantInt::get(t, 0));
        }
        else
        {
            iv_const = true;
            TheModule->getOrInsertGlobal(ident, t);
            GlobalVariable *gVar = TheModule->getNamedGlobal(ident);
            gVar->setLinkage(GlobalValue::ExternalLinkage);
            auto val = iv->eval();
            gVar->setInitializer((Constant *)val);
            iv_const = false;
        }
        globalMap[ident] = t;
    }
    else
    {
        auto it = sym_table.lookup(ident);
        if (it != nullptr)
        {
            fprintf(stderr, "Error: %s has been defined\n", ident.c_str());
            return nullptr;
        }
        Type *t = nullptr;
        if (s == nullptr)
        {
            t = Type::getInt32Ty(*TheContext);
        }
        else
        {
            t = (Type *)s->eval();
        }
        Value *v = Builder->CreateAlloca(t, nullptr, ident);
        local_var = v;
        local_type = t;
        sym_table.insert(ident, v, t, false);
        if (iv != nullptr)
        {
            bool t = isAssign;
            isAssign = true;
            iv->eval();
            isAssign = false;
            isAssign = t;
        }
    }
    return nullptr;
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

Value *InitVal::eval()
{
    if (iv_const)
    {
        // global var must be constant
        std::vector<Constant *> vals;
        for (auto init_val : _init_vals)
        {
            // if (!init_val->isConst())
            // {
            //     fprintf(stderr, "Error: InitVal should be constant at this\n");
            //     return nullptr;
            // }
            // int val = init_val->getConstValue();
            // auto t_bak = arr_type;
            // arr_type->print(llvm::errs());
            Type *bak = arr_type;
            if (arr_type != Type::getInt32Ty(*TheContext)) {
                arr_type = arr_type->getArrayElementType();
            }
            Constant* val = (Constant*) init_val->eval();
            arr_type = bak;
            bool tmp = genConst;
            genConst = true;
            vals.push_back(val);
            genConst = tmp;
        }
        if (!this->is_array)
        {
            return vals[0];
        }
        else
        {
            // arr_type->print(llvm::errs());
            Constant *retVal = ConstantArray::get(ArrayType::get(arr_type->getArrayElementType(), vals.size()), vals);
            return retVal;
        }
    }
    // local array
    if (_init_vals.size() > 1)
    {
        for (int i = 0; i < _init_vals.size(); i++)
        {
            Value *v = _init_vals[i]->eval();
            Builder->CreateStore(v, Builder->CreateConstGEP2_32(local_type, local_var, 0, i));
        }
    }
    else
    {
        Builder->CreateStore(_init_vals[0]->eval(), local_var);
    }
    return nullptr;
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

Value *VarDecls::eval()
{
    fprintf(stderr, "Called from VarDecls, This should not be called\n");
    return nullptr;
}

Value *ConstSelector::eval()
{
    Type *ret = nullptr;
    for (int i = (int)selects.size() - 1; i >= 0; --i)
    {
        if (!selects[i]->isConst())
        {
            fprintf(stderr, "Error: ConstSelector should be constant at this\n");
            return nullptr;
        }
        int val = selects[i]->getConstValue();
        if (ret == nullptr)
        {
            ret = ArrayType::get(Type::getInt32Ty(*TheContext), val);
        }
        else
        {
            ret = ArrayType::get(ret, val);
        }
    }
    return (Value *)ret;
}

Value *FuncFParamList::eval()
{
    return nullptr;
}

Value *ConstDecls::eval()
{
    return nullptr;
}

Value *InitVals::eval()
{
    return nullptr;
}

Value *FuncDef::eval()
{
    // check if function has been defined
    auto it = TheModule->getFunction(ident);
    if (it != nullptr)
    {
        fprintf(stderr, "Error: %s has been defined\n", ident.c_str());
        return nullptr;
    }
    sym_table.createScope();
    int _type = this->type->type;
    std::vector<Type *> Params;
    auto p = params->_params;
    for (int i = 0; i < p.size(); ++i)
    {
        Params.push_back((Type *)p[i]->eval());
    }
    FunctionType *FT = FunctionType::get(_type == 1 ? Type::getInt32Ty(*TheContext) : Type::getVoidTy(*TheContext), Params, false);
    Function *TheFunction = Function::Create(FT, Function::ExternalLinkage, ident, *TheModule);
    int i = 0;
    for (auto &Arg : TheFunction->args())
    {
        Arg.setName(((FuncFParam *)p[i])->ident);
        sym_table.setValue(((FuncFParam *)p[i])->ident, &Arg);
        i++;
    }
    BasicBlock *bb = BasicBlock::Create(*TheContext, "entry", TheFunction);
    Builder->SetInsertPoint(bb);
    if (block)
    {
        Value *ret = block->eval();
    }
    else
    {
        Builder->CreateRetVoid();
    }
    sym_table.popScope();
    return nullptr;
}

Value *ConstInits::eval()
{
    fprintf(stderr, "Called from ConstInits, This should not be called\n");
    return nullptr;
}

Value *FuncType::eval()
{
    return nullptr;
}

Value *FuncFParam::eval()
{
    Type *type = nullptr;
    if (_dims.empty())
    {
        type = Type::getInt32Ty(*TheContext);
    }
    for (int i = (int)_dims.size() - 1; i >= 0; --i)
    {
        if (_dims[i] == nullptr)
        {
            type = PointerType::get(type, 0);
        }
        else
        {
            type = ArrayType::get(type, _dims[i]->getConstValue());
        }
    }
    sym_table.insert(ident, nullptr, type);
    return (Value *)type;
}

Value *Dim::eval()
{
    return nullptr;
}

Value *FuncFParams::eval()
{
    return nullptr;
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

Value *BlockItem::eval()
{
    if (_stmt)
    {
        return _stmt->eval();
    }
    if (_decl)
    {
        return _decl->eval();
    }
    return nullptr;
}

Value *BlockItems::eval()
{
    fprintf(stderr, "Called from BlockItems, This should not be called\n");
    return nullptr;
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

Value *Block::eval()
{
    for (auto item : _block_items)
    {
        item->eval();
    }
    return nullptr;
}

void Assignment::print(int dep)
{
    print_space(dep);
    printf("`-Assignment\n");
    _lval->print(dep + 2);
    _exp->print(dep + 2);
}

Value *Assignment::eval()
{
    bool t= isAssign;
    isAssign = false;
    auto l = this->_lval->eval();
    isAssign = true;
    auto r = this->_exp->eval();
    isAssign = false;
    isAssign = t;
    // l->dump();
    // r->dump();
    return Builder->CreateStore(r, l);
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

Value *IfStmt::eval()
{
    Value *cond = this->condition->eval();
    if (cond->getType() != Type::getInt1Ty(*TheContext)) {
        cond = Builder->CreateICmpNE(cond, ConstantInt::get(Type::getInt32Ty(*TheContext), 0, true), "ifcond");
    }
    auto TheFunction = Builder->GetInsertBlock()->getParent();
    if (this->false_part)
    {
        auto TrueBB = BasicBlock::Create(*TheContext, "true");
        auto FalseBB = BasicBlock::Create(*TheContext, "false");
        auto ToEndBB = BasicBlock::Create(*TheContext, "toend");
        Builder->CreateCondBr(cond, TrueBB, FalseBB);
        TheFunction->getBasicBlockList().push_back(TrueBB);
        Builder->SetInsertPoint(TrueBB);
        auto true_val = this->true_part->eval();
        if (!isRet && !isBranch)
            Builder->CreateBr(ToEndBB);
        isRet = false;
        isBranch = false;
        TheFunction->getBasicBlockList().push_back(FalseBB);
        Builder->SetInsertPoint(FalseBB);
        auto false_val = this->false_part->eval();
        if (!isRet && !isBranch)
            Builder->CreateBr(ToEndBB);
        isRet = false;
        isBranch = false;
        TheFunction->getBasicBlockList().push_back(ToEndBB);
        Builder->SetInsertPoint(ToEndBB);
        return nullptr;
    }
    else
    {
        auto TrueBB = BasicBlock::Create(*TheContext, "true");
        auto ToEndBB = BasicBlock::Create(*TheContext, "toend");
        Builder->CreateCondBr(cond, TrueBB, ToEndBB);
        TheFunction->getBasicBlockList().push_back(TrueBB);
        Builder->SetInsertPoint(TrueBB);
        auto true_val = this->true_part->eval();
        if (!isRet && !isBranch)
            Builder->CreateBr(ToEndBB);
        isRet = false;
        isBranch = false;
        TheFunction->getBasicBlockList().push_back(ToEndBB);
        Builder->SetInsertPoint(ToEndBB);
        return nullptr;
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
    auto TheFunction = Builder->GetInsertBlock()->getParent();
    if (TheFunction == nullptr)
    {
        fprintf(stderr, "TheFunction is null\n");
        return nullptr;
    }
    auto cur = Builder->GetInsertBlock();

    auto CondBB = BasicBlock::Create(*TheContext, "cond");
    auto BodyBB = BasicBlock::Create(*TheContext, "body");
    auto EndBB = BasicBlock::Create(*TheContext, "end");
    TheFunction->getBasicBlockList().push_back(CondBB);
    Builder->SetInsertPoint(CondBB);
    Value *cond = this->condition->eval();
    if (cond->getType() != Type::getInt1Ty(*TheContext)) {
        cond = Builder->CreateICmpNE(cond, ConstantInt::get(Type::getInt32Ty(*TheContext), 0, true), "ifcond");
    }
    Builder->CreateCondBr(cond, BodyBB, EndBB);
    TheFunction->getBasicBlockList().push_back(BodyBB);
    Builder->SetInsertPoint(BodyBB);
    holeStack.push({BodyBB, EndBB});
    body->eval();
    holeStack.pop();
    Builder->CreateBr(CondBB);
    Builder->SetInsertPoint(cur);
    Builder->CreateBr(CondBB);
    
    TheFunction->getBasicBlockList().push_back(EndBB);
    Builder->SetInsertPoint(EndBB);
    return nullptr;
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
            isRet = true;
            auto v = exp->eval();
            if (v->getType() == Type::getInt32PtrTy(*TheContext)) {
                v = Builder->CreateLoad(Type::getInt32Ty(*TheContext), v);
            }
            return Builder->CreateRet(v);
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
            isRet = true;
            return Builder->CreateRetVoid();
        }
        else if (type == 1)
        {
            if (holeStack.empty())
            {
                fprintf(stderr, "Error: break stmt should be in a loop\n");
                return nullptr;
            }
            auto top = holeStack.top();
            // break stmt
            isBranch = true;
            return Builder->CreateBr(top.second);
        }
        else if (type == 2)
        {
            if (holeStack.empty())
            {
                fprintf(stderr, "Error: continue stmt should be in a loop\n");
                return nullptr;
            }
            // continue stmt
            // we will generate the stmt later
            // use 2 to represent continue
            auto top = holeStack.top();
            isBranch = true;
            return Builder->CreateBr(top.first);
        }
        else
        {
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
        bool t= isAssign;
        isAssign = true;
        Value *left = add_exp->eval();
        // left->dump();
        Value *right = mul_exp->eval();
        // right->dump();
        if (left && left->getType()->getTypeID() != Type::TypeID::IntegerTyID) {
            left = Builder->CreateLoad(Type::getInt32Ty(*TheContext), left);
        }
        if (left && left->getType()->getTypeID() != Type::TypeID::IntegerTyID) {
            right = Builder->CreateLoad(Type::getInt32Ty(*TheContext), right);
        }
        isAssign = t;
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
        auto l = mul_exp->eval();
        // if (l && l->getType() == Type::getInt32Ty(*TheContext)) {
        //     l = Builder->CreateLoad(Type::getInt32Ty(*TheContext), l);
        // }
        return l;
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
    if (genConst) {
        if (!add_exp->isConst()) {
            fprintf(stderr, "Error: const expression expected\n");
            return nullptr;
        }
        return ConstantInt::get(Type::getInt32Ty(*TheContext), add_exp->getConstValue());
    }
    
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
    Function* TheFunction = Builder->GetInsertBlock()->getParent();
    bool isGlobal = true;
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
        // val = Builder->CreateLoad(sym_table.getType(ident), val);
        isGlobal = false;
    }
    // TODO TYPE CHECK
    if (this->selectors.empty())
    {
        // just a variable
        return val;
    }
    else
    {
        // array
        Type *t = nullptr;
        if (isGlobal)
        {
            t = globalMap[ident];
        }
        else
        {
            t = sym_table.getType(ident);
        }
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
            val = Builder->CreateGEP(t, val, {ConstantInt::get(Type::getInt32Ty(*TheContext), 0), idx});
            t = t->getArrayElementType();
        }
        if (isAssign)
            return Builder->CreateLoad(t, val);
        // isGEP = true;
        // GEPType
        // val->dump();
        return val;
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

Value *PrimaryExp::eval()
{
    if (exp)
    {
        return exp->eval();
    }
    else if (lval)
    {
        auto l = lval->eval();
        if (l->getType()->getTypeID() != Type::TypeID::IntegerTyID)
            return Builder->CreateLoad(Type::getInt32Ty(*TheContext), l);
        return l;
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
        bool t= isAssign;
        isAssign = true;
        auto left = mul_exp->eval();
        auto right = unary_exp->eval();
        if (left->getType() != Type::getInt32Ty(*TheContext)) {
            left = Builder->CreateLoad(Type::getInt32Ty(*TheContext), left);
        }
        if (right->getType() != Type::getInt32Ty(*TheContext)) {
            right = Builder->CreateLoad(Type::getInt32Ty(*TheContext), right);
        }
        isAssign = t;
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
        if (left->getType() != Type::getInt32Ty(*TheContext)) {
            left = Builder->CreateLoad(Type::getInt32Ty(*TheContext), left);
        }
        auto right = add->eval();
        if (right->getType() != Type::getInt32Ty(*TheContext)) {
            right = Builder->CreateLoad(Type::getInt32Ty(*TheContext), right);
        }
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
        if (left->getType() == Type::getInt32Ty(*TheContext)) {
            left = Builder->CreateICmpNE(left, ConstantInt::get(Type::getInt32Ty(*TheContext), 0));    
        }
        auto right = land->eval();
        if (right->getType() == Type::getInt32Ty(*TheContext)) {
            right = Builder->CreateICmpNE(right, ConstantInt::get(Type::getInt32Ty(*TheContext), 0));    
        }

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

bool ConstExp::isConst()
{
    return add->isConst();
}

int ConstExp::getConstValue()
{
    return add->getConstValue();
}

bool AddExp::isConst()
{
    if (add_exp)
    {
        return add_exp->isConst() && mul_exp->isConst();
    }
    else
    {
        return mul_exp->isConst();
    }
}

int AddExp::getConstValue()
{
    if (add_exp)
    {
        if (op == '+')
        {
            return add_exp->getConstValue() + mul_exp->getConstValue();
        }
        else
        {
            return add_exp->getConstValue() - mul_exp->getConstValue();
        }
    }
    else
    {
        return mul_exp->getConstValue();
    }
}

bool MulExp::isConst()
{
    if (mul_exp)
    {
        return mul_exp->isConst() && unary_exp->isConst();
    }
    else
    {
        return unary_exp->isConst();
    }
}

int MulExp::getConstValue()
{
    if (mul_exp)
    {
        if (op == '*')
        {
            return mul_exp->getConstValue() * unary_exp->getConstValue();
        }
        else
        {
            return mul_exp->getConstValue() / unary_exp->getConstValue();
        }
    }
    else
    {
        return unary_exp->getConstValue();
    }
}

bool UnaryExp::isConst()
{
    if (primary_exp)
        return primary_exp->isConst();
    else if (unary_exp)
        return unary_exp->isConst();
    else
        return false;
}

int UnaryExp::getConstValue()
{
    if (primary_exp)
        return primary_exp->getConstValue();
    else if (unary_exp)
        return -unary_exp->getConstValue();
    else
        return 0;
}

bool PrimaryExp::isConst()
{
    if (lval)
        return lval->isConst();
    else if (exp)
        return exp->isConst();
    else
        return true;
}

int PrimaryExp::getConstValue()
{
    if (lval)
        return lval->getConstValue();
    else if (exp)
        return exp->getConstValue();
    else
        return this->num;
}

bool LVal::isConst()
{
    if (sym_table.isempty())
    {
        // just global
        auto i = TheModule->getGlobalVariable(ident);
        if (i)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        auto i = sym_table.lookup(ident);
        if (i)
        {
            return sym_table.isConst(ident);
        }
        else
        {
            return TheModule->getGlobalVariable(ident) != nullptr;
        }
    }
}

int LVal::getConstValue()
{
    // TODO
    return 0;
}

bool Exp::isConst()
{
    return this->add_exp->isConst();
}

int Exp::getConstValue()
{
    return this->add_exp->getConstValue();
}

bool InitVal::isConst()
{
    if (_init_vals.size() != 1)
    {
        return false;
    }
    return _init_vals[0]->isConst();
}

int InitVal::getConstValue()
{
    return _init_vals[0]->getConstValue();
}