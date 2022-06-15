#ifndef _ROOT_AST_H
#define _ROOT_AST_H

#include <vector>
#include "funcAST.h"
#include "stmtAST.h"

class RootAST {
    private:
        std::vector<FunctionAST*> functions;
        std::vector<StatementAST*> statements;
    public:
        void addFunction(FunctionAST* function);
        void addStatement(StatementAST* statement);
        size_t getFunctionCount();
        size_t getStatementCount();
        FunctionAST* getFunction(size_t index);
        StatementAST* getStatement(size_t index);
};

#endif