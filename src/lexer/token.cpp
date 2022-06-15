#include <string>
#include "token.h"

Token::Token(Token::Type type, std::string value) {
    this->type = type;
    this->value = value;
}

const std::string tokenTypeToStr(Token::Type type) {
    switch(type) {
        case Token::Type::TOKEN_ID: return "TOKEN_ID";
        case Token::Type::TOKEN_EOF: return "TOKEN_EOF";
        default: return "";
    }
}

std::string tokenToStr(Token* token) {
    std::string buffer = "<TOKEN -> type = '";
    buffer.append(tokenTypeToStr(token->type));
    buffer.append("', value = \"");
    buffer.append(token->value);
    buffer.append("\">;");
    return buffer;
}