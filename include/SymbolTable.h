#ifndef __SYM_TABLE__
#define __SYM_TABLE__

#include <map>
#include <string>
#include <stack>
#include <llvm/IR/Value.h>

class SymbolTable {
    private:
        std::map<std::string, llvm::Value*>* table;
        std::map<std::string, llvm::Type*>* typeTable;
        std::stack<std::map<std::string, llvm::Value*>*> stack;
        std::stack<std::map<std::string, llvm::Type*>*> typeStack;
    public:
        SymbolTable();
        ~SymbolTable();
        void createScope();
        void popScope();
        void insert(const std::string&, llvm::Value*, llvm::Type*);
        llvm::Value* lookup(const std::string&);
        llvm::Type* getType(const std::string&);
};

#endif