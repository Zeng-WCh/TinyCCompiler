#include "SymbolTable.h"
#include <llvm/IR/Value.h>

SymbolTable::SymbolTable() {
    table = new std::map<std::string, llvm::Value*>();
    typeTable = new std::map<std::string, llvm::Type*>();
}

SymbolTable::~SymbolTable() {
    if (table)
        delete table;
    while (!stack.empty()) {
        auto it = stack.top();
        delete it;
        stack.pop();
    }
    if (typeTable)
        delete typeTable;
    while (!typeStack.empty()) {
        auto it = typeStack.top();
        delete it;
        typeStack.pop();
    }
}

void SymbolTable::createScope() {
    stack.push(table);
    typeStack.push(typeTable);
    table = new std::map<std::string, llvm::Value*>();
    typeTable = new std::map<std::string, llvm::Type*>();
}

void SymbolTable::popScope() {
    delete table;
    delete typeTable;
    table = stack.top();
    typeTable = typeStack.top();
    stack.pop();
    typeStack.pop();
}

void SymbolTable::insert(const std::string& name, llvm::Value* value, llvm::Type* type) {
    if (this->table == nullptr) {
        fprintf(stderr, "Error: table is null\n");
    }
    table->insert(std::pair<std::string, llvm::Value*>(name, value));
    typeTable->insert(std::pair<std::string, llvm::Type*>(name, type));
}

llvm::Value* SymbolTable::lookup(const std::string& ident) {
    if (this->table == nullptr) {
        fprintf(stderr, "Error: table is null\n");
        return nullptr;
    }
    auto it = table->find(ident);
    if (it != table->end()) {
        return it->second;
    }
    return nullptr;
}

llvm::Type* SymbolTable::getType(const std::string& ident) {
    if (this->typeTable == nullptr) {
        fprintf(stderr, "Error: table is null\n");
        return nullptr;
    }
    auto it = typeTable->find(ident);
    if (it != typeTable->end()) {
        return it->second;
    }
    return nullptr;
}