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