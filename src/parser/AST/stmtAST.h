#ifndef _STMT_AST_H
#define _STMT_AST_H

#include <vector>
#include <string>
#include "exprAST.h"
#include "stmtAST.h"
#include "../../utils/utils.h"
#include <llvm/IR/Value.h>

using namespace llvm;

class StatementAST {
    public:
        virtual ~StatementAST() {}
        virtual Value* codegen() = 0;
};

class IncludeAST : public StatementAST {
    private:
        std::string library;

    public:
        IncludeAST(std::string library);
        Value* codegen() override;
};

class ReturnAST : public StatementAST {
    private:
        DataType type;
        std::string value;
    public:
        ReturnAST(DataType type, std::string value);
        Value* codegen() override;
};

class VarDefAST : public StatementAST {
    private:
        std::string identifier;
        bool defined;
        DataType type;
        std::string value;
    public:
        VarDefAST(std::string identider, DataType type, std::string value);
        Value* codegen() override;
};

class ConditionalAST : public StatementAST {
    private:
        ExpressionAST* condition;
        StatementAST* statement;
    public:
        ConditionalAST(ExpressionAST* condition, StatementAST* statement);
        Value* codegen() override;
};

class LoopAST : public StatementAST {
    private:
        ExpressionAST* condition;
        StatementAST* statement;
    public:
        LoopAST(ExpressionAST* condition, StatementAST* statement);
        Value* codegen() override;
};

class ExpressionStatementAST : public StatementAST {
    private:
        ExpressionAST* expression;
    public:
        ExpressionStatementAST(ExpressionAST* expression);
        Value* codegen() override;
};
class CompountAST : public StatementAST {
    private:
        std::vector<StatementAST*> statements;
    public:
        CompountAST();
        void addStatement(StatementAST* statement);
        Value* codegen() override;
};

class NoOpAST : public StatementAST {
    public:
        NoOpAST();
};

#endif