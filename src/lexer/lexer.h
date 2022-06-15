#ifndef _LEXER_H
#define _LEXER_H

#include <string>
#include "token.h"

class Lexer {

    private:
        std::string code;
        char c;
        size_t length;
        size_t i;

        void advance();
        void skipWhitespace();

    public:
        Lexer(std::string code);
        Token* nextToken();

};

#endif