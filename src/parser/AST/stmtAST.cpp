#include <string>
#include "stmtAST.h"


IncludeAST::IncludeAST(std::string library) {
    this->library = library;
}

Value* IncludeAST::codegen() {

}

ReturnAST::ReturnAST(DataType type, std::string value) {
    this->type = type;
    this->value = value;
}

Value* ReturnAST::codegen() {

}

VarDefAST::VarDefAST(std::string identider, DataType type, std::string value) {
    this->identifier = identider;
    this->type = type;
    this->value = value;
    this->defined = !(value == "");
}

Value* VarDefAST::codegen() {
    
}

ConditionalAST::ConditionalAST(ExpressionAST* condition, StatementAST* statement) {
    this->condition = condition;
    this->statement = statement;
}

Value* ConditionalAST::codegen() {

}

LoopAST::LoopAST(ExpressionAST* condition, StatementAST* statement) {
    this->condition = condition;
    this->statement = statement;
}

Value* LoopAST::codegen() {

}

ExpressionStatementAST::ExpressionStatementAST(ExpressionAST* expression) {
    this->expression = expression;
}

Value* ExpressionStatementAST::codegen() {
    return this->expression->codegen();
}

void CompountAST::addStatement(StatementAST* statement) {
    this->statements.push_back(statement);
}

Value* CompountAST::codegen() {

}
