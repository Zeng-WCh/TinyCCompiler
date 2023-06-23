#include "SymbolTable.h"
#include <llvm/IR/Value.h>

SymbolTable::SymbolTable() {
    table = new std::map<std::string, llvm::Value*>();
    typeTable = new std::map<std::string, llvm::Type*>();
    constTable = new std::map<std::string, bool>();
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
    if (constTable)
        delete constTable;
    while (!constStack.empty()) {
        auto it = constStack.top();
        delete it;
        constStack.pop();
    }
}

void SymbolTable::createScope() {
    stack.push(table);
    typeStack.push(typeTable);
    constStack.push(constTable);
    table = new std::map<std::string, llvm::Value*>();
    typeTable = new std::map<std::string, llvm::Type*>();
    constTable = new std::map<std::string, bool>();
}

void SymbolTable::popScope() {
    delete table;
    delete typeTable;
    delete constTable;
    table = stack.top();
    typeTable = typeStack.top();
    constTable = constStack.top();
    stack.pop();
    typeStack.pop();
    constStack.pop();
}

void SymbolTable::insert(const std::string& name, llvm::Value* value, llvm::Type* type, bool isConst) {
    if (this->table == nullptr) {
        fprintf(stderr, "Error: table is null\n");
    }
    table->insert(std::pair<std::string, llvm::Value*>(name, value));
    typeTable->insert(std::pair<std::string, llvm::Type*>(name, type));
    constTable->insert(std::pair<std::string, bool>(name, isConst));
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

bool SymbolTable::isConst(const std::string& ident) {
    if (this->constTable == nullptr) {
        fprintf(stderr, "Error: table is null\n");
        return false;
    }
    auto it = constTable->find(ident);
    if (it != constTable->end()) {
        return it->second;
    }
    return false;
}

bool SymbolTable::isempty() const {
    return stack.empty();
}

void SymbolTable::setValue(const std::string& ident, llvm::Value* v) {
    auto it = table->find(ident);
    if (it != table->end()) {
        it->second = v;
    }
}