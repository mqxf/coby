#include <vector>
#include <string>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include "funcAST.h"
#include "../../utils/utils.h"

using namespace llvm;

FunctionAST::FunctionAST(std::string name, DataType returnType) {
    this->name = name;
    this->returnType = returnType;
}

FunctionAST* FunctionAST::addArgument(ExpressionAST* arg) {
    this->args.push_back(arg);
    return this;
}

FunctionAST* FunctionAST::addBody(StatementAST* body) {
    this->body = body;
    return this;
}

Function* FunctionAST::codegen() {

    Function *function = mod->getFunction(this->name);

    if (!function) {
        std::vector<Type*> types; //make types based on args
        FunctionType* type = FunctionType::get(Type::getDoubleTy(*context), types, false); //change Type::getDoubleTy to function type

        function = Function::Create(type, Function::ExternalLinkage, name, mod.get());

        unsigned Idx = 0;
        for (auto &Arg : function->args()) {
            Arg.setName(args[Idx++]);
        }
    }   

    if (!function) {
        return nullptr;
    }

    BasicBlock *BB = BasicBlock::Create(*context, "entry", function);
    builder->SetInsertPoint(BB);

    namedValues.clear();

    for (auto &Arg : function->args())
        namedValues[std::string(Arg.getName())] = &Arg;

    if (Value *retVal = body->codegen()) {
        builder->CreateRet(retVal);

        verifyFunction(*function);

        return function;
    }

  // Error reading body, remove function.
  function->eraseFromParent();
  return nullptr;
}