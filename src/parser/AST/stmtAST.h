#ifndef _STMT_AST_H
#define _STMT_AST_H

#include <vector>
#include <string>
#include "exprAST.h"
#include "stmtAST.h"
#include "../../utils/utils.h"
#include <llvm/IR/Value.h>

class StatementAST {
    public:
        virtual ~StatementAST() {}
        virtual llvm::Value* codegen() = 0;
};

class IncludeAST : public StatementAST {
    private:
        std::string library;

    public:
        IncludeAST(std::string library);
};

class ReturnAST : public StatementAST {
    private:
        Type type;
        std::string value;
    public:
        ReturnAST(Type type, std::string value);
};

class VarDefAST : public StatementAST {
    private:
        std::string identider;
        bool defined;
        Type type;
        std::string value;
    public:
        VarDefAST(std::string identider, Type type, std::string value);
};

class ConditionalAST : public StatementAST {
    private:
        ExpressionAST* condition;
        StatementAST* statement;
    public:
        ConditionalAST(ExpressionAST* condition, StatementAST* statement);
};

class LoopAST : public StatementAST {
    private:
        ExpressionAST* condition;
        StatementAST* statement;
    public:
        LoopAST(ExpressionAST* condition, StatementAST* statement);
};

class ExpressionStatementAST : public StatementAST {
    private:
        ExpressionAST* expression;
    public:
        ExpressionStatementAST(ExpressionAST* expression);
};
class CompountAST : public StatementAST {
    private:
        std::vector<StatementAST*> statements;
    public:
        CompountAST();
        void addStatement(StatementAST* statement);
};

class NoOpAST : public StatementAST {
    public:
        NoOpAST();
};

#endif