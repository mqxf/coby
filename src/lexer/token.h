#ifndef _TOKEN_H
#define _TOKEN_H

#include <string>

class Token {

public:
        std::string value;
        enum Type {
            TOKEN_ID,
            TOKEN_EOF
        } type;
        Token(Token::Type type, std::string value);

};

const std::string tokenTypeToStr(Token::Type type);
std::string tokenToStr(Token* token);

#endif