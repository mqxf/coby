#ifndef _UTILS_H
#define _UTILS_H

#include <string>
#include <memory>
#include <map>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include "../lexer/token.h"

using namespace llvm;

inline static std::unique_ptr<LLVMContext> context;
inline static std::unique_ptr<Module> mod;
inline static std::unique_ptr<IRBuilder<>> builder;
inline static std::map<std::string, Value*> namedValues;

enum Severity {
    LOG,
    WARNING,
    ERROR
};

enum DataType {
    INT,
    STRING,
    FLOAT,
    BOOL,
    VOID,
    COLLECTION,
    LIBARY,
    LIST,
    CLASSPTR
};

char strToEsc(std::string str);
std::string strFormat(std::string str);
void log(std::string message, Severity severity);
int getBinOpPrec(Token::Type type);
void initModule();

#endif