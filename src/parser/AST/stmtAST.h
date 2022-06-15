#ifndef _STMT_AST_H
#define _STMT_AST_H

#include <vector>
#include <memory>
#include <string>
#include "exprAST.h"
#include "../../utils/utils.h"

class StatementAST {
    public:
        virtual ~StatementAST() {}
};

class IncludeAST : public StatementAST {
    std::string library;
};

class ReturnAST : public StatementAST {
    Type type;
    std::string value;
};

class VarDefAST : public StatementAST {
    std::string identider;
    bool defined;
    Type type;
    std::string value;
};

class ConditionalAST : public StatementAST {
    ExpressionAST* condition;

    bool result;
};

class LoopAST : public StatementAST {
    ExpressionAST* condition;

};

#endif