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

    AST* result = nullptr;
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
%token tok_if tok_and tok_or tok_not tok_else
%token tok_while tok_break tok_continue tok_return
%token tok_unknown
%token <strVal> tok_identifier
%token <intVal> tok_number

%type <ast> CompUnits CompUnit Decl FuncDef ConstDecl ConstDecls VarDecl ConstDef ConstSelector ConstInitVal ConstInits VarDecls VarDef InitVal InitVals FuncFParams FuncFParam Block BlockItems BlockItem Stmt Exp Cond LVal PrimaryExp UnaryExp FuncRParams MulExp AddExp RelExp EqExp LAndExp LOrExp ConstExp
%type <ast> FuncFParamList
%type <ast> FuncFParamDim
%type <ast> LValSelector

%start Program

%%

Program: CompUnits {
    result = (AST*) $1;
}

CompUnits: CompUnit { 
    auto tmp = new CompUnit();
    tmp->add_comp_unit((AST*) $1);
    $$ = (void*) tmp;
 }
| CompUnits CompUnit {
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
    delete (ConstDecls*)$3;
}
;

ConstDecls: ConstDef {
    auto tmp = new ConstDecls();
    tmp->add_const_decl((ConstDef*) $1);
    $$ = (void*) tmp;
}
| ConstDecls tok_comma ConstDef {
    auto tmp = (ConstDecls*) $1;
    tmp->add_const_decl((ConstDef*) $3);
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
    tmp->add_const_val((ConstExp*) $1);
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
    delete (ConstInits*) $2;
};

ConstInits: ConstInitVal {
    auto tmp = new ConstInits();
    tmp->add_const_init((ConstInitVal*) $1);
    $$ = (void*) tmp;
}
| ConstInits tok_comma ConstInitVal {
    auto tmp = (ConstInits*) $1;
    tmp->add_const_init((ConstInitVal*) $3);
    $$ = (void*) tmp;
};

VarDecl: tok_int VarDecls tok_semicolon {
    auto tmp = ((VarDecls*) $2)->_var_decls;
    auto var = new VarDecl(tmp);
    $$ = (void*) var;
    delete (VarDecls*) $2;
};

VarDecls: VarDef {
    auto tmp = new VarDecls();
    tmp->add_var_decl((VarDef*) $1);
    $$ = (void*) tmp;
}
| VarDecls tok_comma VarDef {
    auto tmp = (VarDecls*) $1;
    tmp->add_var_decl((AST*) $3);
    $$ = (void*) tmp;
};

VarDef: tok_identifier ConstSelector {
    std::string ident($1);
    delete $1;
    auto selector = (ConstSelector*) $2;
    auto tmp = new VarDef(ident, selector, nullptr);
    $$ = (void*) tmp;
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
    tmp->set_array();
    $$ = (void*) tmp;
}
| tok_lbrace InitVals tok_rbrace {
    auto tmp = ((InitVals*) $2)->_init_vals;
    auto init_val = new InitVal(tmp);
    init_val->set_array();
    $$ = (void*) init_val;
    delete (InitVals*)$2;
};

InitVals: InitVal {
    auto tmp = new InitVals();
    tmp->add_init_val((AST*) $1);
    $$ = (void*) tmp;
}
| InitVals tok_comma InitVal {
    auto tmp = (InitVals*) $1;
    tmp->add_init_val((InitVal*) $3);
    $$ = (void*) tmp;
};

FuncDef: tok_int tok_identifier tok_lparen FuncFParams tok_rparen Block {
    std::string ident($2);
    delete (char*)$2;
    auto func_type = new FuncType(1);
    auto func_fparams = (FuncFParams*) $4;
    auto block = (Block*) $6;
    auto tmp = new FuncDef(func_type, ident, func_fparams, block);
    $$ = (void*) tmp;
}
| tok_void tok_identifier tok_lparen FuncFParams tok_rparen Block {
    std::string ident($2);
    delete (char*)$2;
    auto func_type = new FuncType(0);
    auto func_fparams = (FuncFParams*) $4;
    auto block = (Block*) $6;
    auto tmp = new FuncDef(func_type, ident, func_fparams, block);
    $$ = (void*) tmp;
}
;

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
    tmp->add_param((FuncFParam*) $1);
    $$ = (void*) tmp;
} 
| FuncFParamList tok_comma FuncFParam {
    auto tmp = (FuncFParamList*) $1;
    tmp->add_param((FuncFParam*) $3);
    $$ = (void*) tmp;
};

FuncFParam: tok_int tok_identifier {
    std::string ident($2);
    delete (char*)$2;
    $$ = (void*) (new FuncFParam(ident));
}
| tok_int tok_identifier tok_lbracket tok_rbracket FuncFParamDim {
    std::string ident($2);
    delete (char*)$2;
    auto dim = (Dim*) $5;
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
    auto tmp = new Dim();
    $$ = (void*) tmp;
}
| FuncFParamDim tok_lbracket Exp tok_rbracket {
    auto tmp = (Dim*) $1;
    tmp->add_dim((AST*) $3);
    $$ = (void*) tmp;
};

Block: tok_lbrace BlockItems tok_rbrace {
    auto tmp = ((BlockItems*) $2) -> _block_items;
    auto block = new Block(tmp);
    delete (BlockItems*)$2;
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
    $$ = (void*) (new Stmt(exp));
}
| Block {
    auto block = (Block*) $1;
    $$ = (void*) (new Stmt(block));
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
| tok_while tok_lparen Cond tok_rparen Stmt {
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
    std::string ident($1);
    delete (char*)$1;
    auto tmp = ((LValSelector*) $2) -> _selectors;
    auto lval = new LVal(ident, tmp);
    $$ = (void*) lval;
    delete $2;
}
;

LValSelector: {
    auto tmp = new LValSelector();
    $$ = (void*) tmp;
}
| LValSelector tok_lbracket Exp tok_rbracket {
    auto tmp = (LValSelector*) $1;
    tmp->add_selector((AST*) $3);
    $$ = (void*) tmp;
}
;

PrimaryExp: tok_lparen Exp tok_rparen {
    $$ = (void*) (new PrimaryExp((Exp*) $2));
}
| LVal {
    $$ = (void*) (new PrimaryExp((LVal*) $1));
}
| tok_number {
    $$ = (void*) (new PrimaryExp($1));
}
;

UnaryExp: PrimaryExp {
    $$ = (void*) (new UnaryExp((PrimaryExp*) $1));
}
| tok_identifier tok_lparen FuncRParams tok_rparen {
    std::string ident($1);
    delete (char*)$1;
    auto tmp = ((FuncRParams*) $3) -> _params;
    $$ = (void*) (new UnaryExp(ident, tmp));
    delete $3;
}
| tok_plus UnaryExp {
    $$ = (void*) (new UnaryExp('+', (UnaryExp*) $2));
}
| tok_minus UnaryExp {
    $$ = (void*) (new UnaryExp('-', (UnaryExp*) $2));
}
| tok_not UnaryExp {
    $$ = (void*) (new UnaryExp('!', (UnaryExp*) $2));
}
;

FuncRParams: {
    $$ = (void*) (new FuncRParams());
}
| Exp {
    auto tmp = new FuncRParams();
    tmp->add_param((AST*) $1);
    $$ = (void*) tmp;
}
| FuncRParams tok_comma Exp {
    auto tmp = (FuncRParams*) $1;
    tmp->add_param((AST*) $3);
    $$ = (void*) tmp;
}
;

MulExp: UnaryExp {
    $$ = (void*) (new MulExp((UnaryExp*) $1));
}
| MulExp tok_star UnaryExp {
    $$ = (void*) (new MulExp((MulExp*) $1, '*', (UnaryExp*) $3));
}
| MulExp tok_slash UnaryExp {
    $$ = (void*) (new MulExp((MulExp*) $1, '/', (UnaryExp*) $3));
}
| MulExp tok_mod UnaryExp {
    $$ = (void*) (new MulExp((MulExp*) $1, '%', (UnaryExp*) $3));
}
;

AddExp: MulExp {
    $$ = (void*) (new AddExp((MulExp*) $1));
}
| AddExp tok_plus MulExp {
    $$ = (void*) (new AddExp((AddExp*) $1, '+', (MulExp*) $3));
}
| AddExp tok_minus MulExp {
    $$ = (void*) (new AddExp((AddExp*) $1, '-', (MulExp*) $3));
}
;

RelExp: AddExp {
    $$ = (void*) (new RelExp((AddExp*)$1));
}
| RelExp tok_gt AddExp {
    $$ = (void*) (new RelExp((RelExp*)$1, ">", (AddExp*)$3));
}
| RelExp tok_lt AddExp {
    $$ = (void*) (new RelExp((RelExp*)$1, "<", (AddExp*)$3));
}
| RelExp tok_ge AddExp {
    $$ = (void*) (new RelExp((RelExp*)$1, ">=", (AddExp*)$3));
}
| RelExp tok_le AddExp {
    $$ = (void*) (new RelExp((RelExp*)$1, "<=", (AddExp*)$3));
}
;

EqExp: RelExp {
    $$ = (void*) (new EqExp((RelExp*)$1));
}
| EqExp tok_eq RelExp {
    $$ = (void*) (new EqExp((EqExp*)$1, "==", (RelExp*)$3));
}
| EqExp tok_ne RelExp {
    $$ = (void*) (new EqExp((EqExp*)$1, "!=", (RelExp*)$3));
}
;

LAndExp: EqExp {
    $$ = (void*) (new LAndExp((EqExp*)$1));
}
| LAndExp tok_and EqExp {
    $$ = (void*) (new LAndExp((LAndExp*)$1, (EqExp*)$3));
}
;

LOrExp: LAndExp {
    $$ = (void*) (new LOrExp((LAndExp*)$1));
}
| LOrExp tok_or LAndExp {
    $$ = (void*) (new LOrExp((LOrExp*)$1, (LAndExp*)$3));
}
;

ConstExp: AddExp {
    $$ = (void*) (new ConstExp((AddExp*) $1));
}
;


%%