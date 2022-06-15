#ifndef _LEXER_H
#define _LEXER_H

#include <string>
#include "token.h"

class Lexer {

    private:
        std::string src;
        char c;
        size_t length;
        size_t i;

        char peek(size_t offset);
        void advance();
        void skipWhiteSpace();
        void skipComment();
        Token* advanceWith(Token* token);
        Token* nextId();
        Token* nextNumber();
        Token* nextBinary();
        Token* nextHexadecimal();
        Token* nextFloat(std::string base);
        Token* nextString();
        Token* nextChar();

    public:
        Lexer(std::string src);
        bool ended();
        Token* nextToken();

};

#endif