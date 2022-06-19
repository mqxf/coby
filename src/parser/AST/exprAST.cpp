#include <iostream>
#include <vector>
#include "exprAST.h"

int getBinOpPrec(Token::Type type) {
    switch (type) {
        case Token::Type::TOKEN_AND: return 10;
        default: return -1;
    }
}