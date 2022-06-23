#ifndef _FUNC_AST_H
#define _FUNC_AST_H

#include <vector>
#include <string>
#include <llvm/IR/Value.h>
#include "stmtAST.h"
#include "exprAST.h"
#include "../../utils/utils.h"

using namespace llvm;

class FunctionAST {
    private:
        std::string name;
        DataType returnType;
        StatementAST* body;
        std::vector<std::string> args;
        std::vector<DataType> argTypes;
    public:
        FunctionAST(std::string name, DataType returnType);
        FunctionAST* addArgument(ExpressionAST* arg);
        FunctionAST* addBody(StatementAST* body);
        Function* codegen();
};

#endif