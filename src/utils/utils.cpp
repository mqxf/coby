#include <string>
#include <iostream>
#include <memory>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include "utils.h"
#include "../main.h"
#include "../lexer/token.h"

using namespace llvm;

char strToEsc(std::string str) {
    if (str.length() <= 1) return 0;
    if (str[0] != '\\') return 0;
    char c = str[1];

    switch (c) {
        case 'n': return '\n';
        case 't': return '\t';
        case 'r': return '\r';
        case '\\': return c;
        default: return c;
    }

    return c;
}

std::string strFormat(std::string str) {
    std::string out;
    size_t len = str.length();

    size_t i = 0;
    while (str[i] != '\0' && i < len) {
        if (str[i] == '\\') {
            char escape = strToEsc(str.substr(i, 2));
            out.push_back(escape);
            i += 2;
        }
        else {
            out.push_back(str[i]);
            i += 1;
        }
    }
    return out;
}

void log(std::string message, Severity severity) {
    if (severity == Severity::ERROR) {
        std::cerr << message;
    }
    else if (severity == Severity::WARNING && !args->silent) {
        std::cout << message;
    }
    else if (severity == Severity::LOG && args->verbose) {
        std::cout << message;
    }
}

int getBinOpPrec(Token::Type type) { 
    switch (type) {
        case Token::Type::TOKEN_PLUS: return 20;
        case Token::Type::TOKEN_MINUS: return 20;
        case Token::Type::TOKEN_DIVIDE: return 30;
        case Token::Type::TOKEN_MULTIPLY: return 30;
        case Token::Type::TOKEN_POWER: return 40;
        case Token::Type::TOKEN_MODULO: return 30;
        case Token::Type::TOKEN_EQUALS: return 5;
        case Token::Type::TOKEN_DOUBLE_EQUALS: return 10;
        case Token::Type::TOKEN_GREATER_THAN: return 10;
        case Token::Type::TOKEN_LESS_THAN: return 10;
        case Token::Type::TOKEN_GREATER_EQUALS: return 10;
        case Token::Type::TOKEN_LESS_EQUALS: return 10;
        case Token::Type::TOKEN_AND: return 10;
        case Token::Type::TOKEN_OR: return 10;
        case Token::Type::TOKEN_BIT_OR: return 10;
        case Token::Type::TOKEN_XOR: return 10;
        case Token::Type::TOKEN_BIT_LEFT_SHIFT: return 15;
        case Token::Type::TOKEN_BIT_RIGHT_SHIFT: return 15;
    }
}

void initModule() {
  context = std::make_unique<LLVMContext>();
  mod = std::make_unique<Module>("JIT", *context);
  builder = std::make_unique<IRBuilder<>>(*context);
}