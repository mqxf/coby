#include <string>
#include "lexer.h"
#include "token.h"

Lexer::Lexer(std::string code) {
    this->code = code;
    length = this->code.length();
    i = 0;
    c = code[0];
}

void Lexer::advance() {
    if ((i + 1) < length) {
        i++;
        c = code[i];
    }
}

void Lexer::skipWhitespace() {
    while (c == 10 || c == 13 || c == '\t' || c == ' ') {
        advance();
    }
}

Token* Lexer::nextToken() {
    return nullptr;
}