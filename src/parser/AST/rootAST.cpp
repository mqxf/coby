#include <vector>
#include <string>
#include <iostream>
#include "rootAST.h"
#include "funcAST.h"
#include "stmtAST.h"

void RootAST::addFunction(FunctionAST* function) {
    functions.push_back(function);
}
        
void RootAST::addStatement(StatementAST* statement) {
    statements.push_back(statement);
}

size_t RootAST::getFunctionCount() {
    return functions.size();
}

size_t RootAST::getStatementCount() {
    return statements.size();
}

FunctionAST* RootAST::getFunction(size_t index) {
    if (index < functions.size()) {
        return functions[index];
    }
    return nullptr;
}

StatementAST* RootAST::getStatement(size_t index) {
    if (index < statements.size()) {
        return statements[index];
    }
    return nullptr;
}