%{
    #include "ast.h"
    #include "token.h"  
    #include <cstdio> 
    #include <vector>

    int yylex();

    #define yyerror(x) \
    do {\
        fprintf(stderr, "error: %s\n", x); \
    } while(0)
%}

%output "parser.cpp"
%defines "token.h"

%union {
    int intVal;
    char *strVal;
    void *ast;
}

%token tok_int tok_void tok_char tok_string_literal
%token tok_const tok_comma tok_semicolon tok_assign
%token tok_plus tok_minus tok_star tok_slash tok_mod
%token tok_lparen tok_rparen tok_lbrace tok_rbrace tok_lbracket tok_rbracket
%token tok_lt tok_gt tok_le tok_ge tok_eq tok_ne
%token tok_and tok_or tok_not
%token tok_if tok_else tok_while tok_break tok_continue tok_return
%token tok_unknown
%token <strVal> tok_identifier
%token <intVal> tok_number

%type <ast> CompUnits CompUnit Decl FuncDef ConstDecl ConstDecls VarDecl ConstDefs ConstDef ConstSelector ConstInitVal ConstInits VarDecls VarDef InitVal InitVals FuncFParams FuncFParam Block BlockItems BlockItem Stmt Exp Cond LVal LVals PrimaryExp UnaryExp Args MulExp AddExp RelExp EqExp LAndExp LOrExp ConstExp
%type <ast> FuncType
%type <ast> FuncFParamList
%type <ast> FuncFParamDim
%type <ast> LValSelector

%start CompUnits

%%

CompUnits: CompUnit { 
    auto tmp = new CompUnit();
    tmp->add_comp_unit((AST*) $1);
 }
| CompUnits CompUnits {
    auto tmp = (CompUnit*) $1;
    tmp->add_comp_unit((AST*) $2);
    $$ = (void*) tmp;
}
;

CompUnit: Decl {
    $$ = (void*) $1;
}
| FuncDef {
    $$ = (void*) $1;
}
;

Decl: ConstDecl {
    auto const_ = (ConstDecl*) $1;
    auto tmp = new Decl(const_);
    $$ = (void*) tmp;
}
| VarDecl {
    auto var = (VarDecl*) $1;
    auto tmp = new Decl(var);
    $$ = (void*) tmp;
}
;

ConstDecl: tok_const tok_int ConstDecls tok_semicolon {
    auto tmp = ((ConstDecls*) $3)->_const_decls;
    auto const_ = new ConstDecl(tmp);
    $$ = (void*) const_;
    delete $3;
}
;

ConstDecls: ConstDef {
    auto tmp = new ConstDecls();
    tmp->add_const_def((ConstDef*) $1);
    $$ = (void*) tmp;
}
| ConstDecls tok_comma ConstDef {
    auto tmp = (ConstDecls*) $1;
    tmp->add_const_def((ConstDef*) $3);
    $$ = (void*) tmp;
}
;

ConstDef: tok_identifier ConstSelector tok_assign ConstInitVal {
    std::string name($1);
    delete $1;
    auto selector = (ConstSelector*) $2;
    auto init_val = (ConstInitVal*) $4;
    auto tmp = new ConstDef(name, selector, init_val);
    $$ = (void*) tmp;
}
;

ConstSelector: {
    $$ = nullptr;
}
| ConstSelector tok_lbracket ConstExp tok_rbracket {
    auto tmp = (ConstSelector*) $1;
    if (tmp == nullptr)
        tmp = new ConstSelector();
    tmp->add_selector((ConstExp*) $3);
    $$ = (void*) tmp;
};

ConstInitVal: ConstExp {
    auto tmp = new ConstInitVal();
    tmp->add_init_val((ConstExp*) $1);
    $$ = (void*) tmp;
}
| tok_lbrace tok_rbrace {
    auto tmp = new ConstInitVal();
    $$ = (void*) tmp;
}
| tok_lbrace ConstInits tok_rbrace {
    auto tmp = ((ConstInits*) $2)->_const_inits;
    auto init_val = new ConstInitVal(tmp);
    $$ = (void*) init_val;
    delete $2;
};

ConstInits: ConstInitVal {
    auto tmp = new ConstInits();
    tmp->add_const_init_val((ConstInitVal*) $1);
    $$ = (void*) tmp;
}
| ConstInits tok_comma ConstInitVal {
    auto tmp = (ConstInits*) $1;
    tmp->add_const_init_val((ConstInitVal*) $3);
    $$ = (void*) tmp;
};

VarDecl: tok_int VarDecls tok_semicolon {
    auto tmp = ((VarDecls*) $2)->_var_decls;
    auto var = new VarDecl(tmp);
    $$ = (void*) var;
    delete $2;
};

VarDecls: VarDef {
    auto tmp = new VarDecls();
    tmp->add_var_def((VarDef*) $1);
    $$ = (void*) tmp;
}
| VarDecls tok_comma VarDef {
    auto tmp = (VarDecls*) $1;
    tmp->add_var_def((VarDef*) $3);
    $$ = (void*) tmp;
};

VarDef: tok_identifier ConstSelector {
    std::string ident($1);
    delete $1;
    auto selector = (ConstSelector*) $2;
    auto tmp = new VarDef(ident, selector, nullptr);
}
| tok_identifier ConstSelector tok_assign InitVal {
    std::string ident($1);
    delete $1;
    auto selector = (ConstSelector*) $2;
    auto init_val = (InitVal*) $4;
    auto tmp = new VarDef(ident, selector, init_val);
    $$ = (void*) tmp;
};

InitVal: Exp {
    auto tmp = new InitVal();
    tmp->add_init_val((Exp*) $1);
    $$ = (void*) tmp;
}
| tok_lbrace tok_rbrace {
    auto tmp = new InitVal();
    $$ = (void*) tmp;
}
| tok_lbrace InitVals tok_rbrace {
    auto tmp = ((InitVals*) $2)->_init_vals;
    auto init_val = new InitVal(tmp);
    $$ = (void*) init_val;
    delete $2;
};

InitVals: InitVal {
    auto tmp = new InitVals();
    tmp->add_init_val((InitVal*) $1);
    $$ = (void*) tmp;
}
| InitVals tok_comma InitVal {
    auto tmp = (InitVals*) $1;
    tmp->add_init_val((InitVal*) $3);
    $$ = (void*) tmp;
};

FuncDef: FuncType tok_identifier tok_lparen FuncFParams tok_rparen Block {
    std::string ident($2);
    delete $2;
    auto func_type = (FuncType*) $1;
    auto func_fparams = (FuncFParams*) $4;
    auto block = (Block*) $6;
    auto tmp = new FuncDef(ident, func_type, func_fparams, block);
    $$ = (void*) tmp;
};

FuncType: tok_int {
    $$ = (void*)(new FuncType(1));
}
| tok_void {
    $$ = (void*)(new FuncType(0));
};

FuncFParams: {
    auto tmp = new FuncFParams();
    $$ = (void*) tmp;
}
| FuncFParamList {
    auto t = ((FuncFParamList*) $1)->_params;
    auto tmp = new FuncFParams(t);
    $$ = (void*) tmp;
};

FuncFParamList: FuncFParam {
    auto tmp = new FuncFParamList();
    tmp->add_func_fparam((FuncFParam*) $1);
    $$ = (void*) tmp;
} 
| FuncFParamList tok_comma FuncFParam {
    auto tmp = (FuncFParamList*) $1;
    tmp->add_func_fparam((FuncFParam*) $3);
    $$ = (void*) tmp;
};

FuncFParam: tok_int tok_identifier {
    std::string ident($2);
    delete $2;
    $$ = (void*) (new FuncFParam(ident));
}
| tok_int tok_identifier tok_lbracket tok_rbracket FuncFParamDim {
    std::string ident($2);
    delete $2;
    auto dim = (FuncFParamDim*) $5;
    auto _dim = dim->_dim;
    std::vector<AST*> d;
    d.push_back(nullptr);
    for (int i = 0; i < _dim.size(); i++) {
        d.push_back(_dim[i]);
    }
    delete dim;
    $$ = (void*) (new FuncFParam(ident, d));
};

FuncFParamDim: {
    auto tmp = new FuncFParamDim();
    $$ = (void*) tmp;
}
| FuncFParamDim tok_lbracket Exp tok_rbracket {
    auto tmp = (FuncFParamDim*) $1;
    tmp->add_dim((AST*) $3);
    $$ = (void*) tmp;
};

Block: tok_lbrace BlockItems tok_rbrace {
    auto tmp = ((BlockItems*) $2) -> _block_items;
    delete $2;
    auto block = new Block(tmp);
    $$ = (void*) block;
};

BlockItems: {
    auto tmp = new BlockItems();
    $$ = (void*) tmp;
}
| BlockItems BlockItem {
    auto tmp = (BlockItems*) $1;
    tmp->add_block_item((BlockItem*) $2);
    $$ = (void*) tmp;
};

BlockItem: Stmt {
    auto tmp = (Stmt*) $1;
    $$ = (void*) (new BlockItem(tmp));
}
| Decl {
    auto tmp = (Decl*) $1;
    $$ = (void*) (new BlockItem(tmp));
}
;

Stmt: LVal tok_assign Exp tok_semicolon {
    auto lval = (LVal*) $1;
    auto exp = (Exp*) $3;
    auto tmp = new Assignment(lval, exp);
    $$ = (void*) (new Stmt(tmp));
}
| tok_semicolon {
    $$ = (void*) (new Stmt());
}
| Exp tok_semicolon {
    auto exp = (Exp*) $1;
    auto tmp = new ExpStmt(exp);
    $$ = (void*) (new Stmt(tmp));
}
| Block {
    auto block = (Block*) $1;
    auto tmp = new BlockStmt(block);
    $$ = (void*) (new Stmt(tmp));
}
| tok_if tok_lparen Cond tok_rparen Stmt {
    auto cond = (Cond*) $3;
    auto stmt = (Stmt*) $5;
    auto tmp = new IfStmt(cond, stmt);
    $$ = (void*) (new Stmt(tmp));
}
| tok_if tok_lparen Cond tok_rparen Stmt tok_else Stmt {
    auto cond = (Cond*) $3;
    auto stmt1 = (Stmt*) $5;
    auto stmt2 = (Stmt*) $7;
    auto tmp = new IfStmt(cond, stmt1, stmt2);
    $$ = (void*) (new Stmt(tmp));
}
| tok_while tok_lparen Cond tok_rparen Stmt{
    auto cond = (Cond*) $3;
    auto stmt = (Stmt*) $5;
    auto tmp = new WhileStmt(cond, stmt);
    $$ = (void*) (new Stmt(tmp));
}
| tok_break tok_semicolon {
    $$ = (void*) (new Stmt(1));
}
| tok_continue tok_semicolon {
    $$ = (void*) (new Stmt(2));
}
| tok_return Exp tok_semicolon {
    $$ = (void*) (new Stmt(0, (Exp*) $2));
}
| tok_return tok_semicolon {
    $$ = (void*) (new Stmt(0));
}
;

Exp: AddExp {
    $$ = (void*) (new Exp((AddExp*) $1));
};

Cond: LOrExp {
    $$ = (void*) (new Cond((LOrExp*) $1));
};

LVal: tok_identifier LValSelector {

}
| tok_identifier {
    std::string ident($1);
    delete $1;
    $$ = (void*) (new LVal(ident));
};

LValSelector: {
    auto tmp = new LValSelector();
    $$ = (void*) tmp;
};


%%