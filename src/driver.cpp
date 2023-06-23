#include <cstdio>
#include <string>
#include <cassert>
#include "token.h"
#include "scanner.h"
#include "ast.h"

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>

extern AST *result;

llvm::LLVMContext *TheContext;
llvm::IRBuilder<> *Builder;
llvm::Module *TheModule;

const char *token_to_string(int tok)
{
    switch (tok)
    {
    case YYEOF:
        return "eof";
    case tok_int:
        return "int";
    case tok_void:
        return "void";
    case tok_char:
        return "char";
    case tok_number:
        return "number";
    case tok_string_literal:
        return "string_literal";
    case tok_identifier:
        return "identifier";
    case tok_const:
        return "const";
    case tok_comma:
        return "comma";
    case tok_semicolon:
        return "semicolon";
    case tok_assign:
        return "equal";
    case tok_plus:
        return "plus";
    case tok_minus:
        return "minus";
    case tok_star:
        return "star";
    case tok_slash:
        return "slash";
    case tok_mod:
        return "mod";
    case tok_lparen:
        return "lparen";
    case tok_rparen:
        return "rparen";
    case tok_lbrace:
        return "lbrace";
    case tok_rbrace:
        return "rbrace";
    case tok_lbracket:
        return "lbracket";
    case tok_rbracket:
        return "rbracket";
    case tok_lt:
        return "lt";
    case tok_gt:
        return "gt";
    case tok_le:
        return "le";
    case tok_ge:
        return "ge";
    case tok_eq:
        return "eq";
    case tok_ne:
        return "ne";
    case tok_and:
        return "and";
    case tok_or:
        return "or";
    case tok_not:
        return "not";
    case tok_if:
        return "if";
    case tok_else:
        return "else";
    case tok_while:
        return "while";
    case tok_break:
        return "break";
    case tok_continue:
        return "continue";
    case tok_return:
        return "return";
    default:
        return "unknown";
    }
}

int lexer_mode(const char *filename)
{
    yyin = fopen(filename, "r");
    if (yyin == nullptr)
    {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
        return 1;
    }
    int tok = -1;
    do
    {
        tok = yylex();
        fprintf(stderr, "token: %s\n", token_to_string(tok));
    } while (tok != YYEOF);
    return 0;
}

int parser_mode(const char *filename)
{
    yyin = fopen(filename, "r");
    if (yyin == nullptr)
    {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
        return 1;
    }
    fprintf(stderr, "Parsing file %s\n", filename);

    int yyresult = yyparse();
    if (yyresult != 0)
    {
        fprintf(stderr, "Error: parsing failed\n");
        return 1;
    }

    assert(result);
    result->print(0);

    delete result;

    return 0;
}

int ir_mode(const char* filename) {
    yyin = fopen(filename, "r");
    if (yyin == nullptr) {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
        return 1;
    }
    fprintf(stderr, "Parsing file %s\n", filename);

    int yyresult = yyparse();
    if (yyresult != 0) {
        fprintf(stderr, "Error: parsing failed\n");
        return 1;
    }

    assert(result);

    llvm::LLVMContext context;
    llvm::Module module(filename, context);
    llvm::IRBuilder<> builder(context);
    TheContext = &context;
    Builder = &builder;
    TheModule = &module;

    result->eval();

    module.dump();
    return 0;
}

int main(int argc, const char **argv)
{
    yydebug = 0;
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s --[lexer|parser|IR] <file>\n", argv[0]);
        return 1;
    }

    if (argv[1] == std::string("--lexer"))
    {
        // lexer mode
        if (argc < 3)
        {
            fprintf(stderr, "Usage: %s --[lexer|parser|IR] <file>\n", argv[0]);
            return 1;
        }
        return lexer_mode(argv[2]);
    }
    else if (argv[1] == std::string("--parser"))
    {
        // parser mode
        if (argc < 3)
        {
            fprintf(stderr, "Usage: %s --[lexer|parser|IR] <file>\n", argv[0]);
            return 1;
        }
        return parser_mode(argv[2]);
    }
    else if (argv[1] == std::string("--IR"))
    {
        // IR-GEN 
        if (argc < 3)
        {
            fprintf(stderr, "Usage: %s --[lexer|parser|IR] <file>\n", argv[0]);
            return 1;
        }
        return ir_mode(argv[2]);
    }
    else
    {
        fprintf(stderr, "Usage: %s --[lexer|parser|IR] <file>\n", argv[0]);
        return 1;
    }

    return 0;
}