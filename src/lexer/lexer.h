#ifndef _LEXER_H
#define _LEXER_H

#include <string>

class Lexer {

    private:
        std::string code;
        char c;
        size_t length;
        size_t i;

        void skipWhitespace();
        

    public:
        Lexer(std::string code);

};

#endif