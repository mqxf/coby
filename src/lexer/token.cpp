#include <string>
#include "token.h"

Token::Token(std::string value, Token::Type type) {
    this->type = type;
    this->value = value;
}

Token::Token(Token::Type type, std::string value) {
    this->type = type;
    this->value = value;
}

const std::string tokenTypeToStr(Token::Type type) {
    switch(type) {
        case Token::Type::TOKEN_ID: return "TOKEN_ID";
        case Token::Type::TOKEN_STRING: return "TOKEN_STRING";
        case Token::Type::TOKEN_CHAR: return "TOKEN_CHAR";
        case Token::Type::TOKEN_INT: return "TOKEN_INT";
        case Token::Type::TOKEN_FLOAT: return "TOKEN_FLOAT";
        case Token::Type::TOKEN_HEX: return "TOKEN_HEX";
        case Token::Type::TOKEN_BIN: return "TOKEN_BIN";
        case Token::Type::TOKEN_SEMICOLON: return "TOKEN_SEMICOLON";
        case Token::Type::TOKEN_COMMA: return "TOKEN_COMMA";
        case Token::Type::TOKEN_DOT: return "TOKEN_DOT";
        case Token::Type::TOKEN_COLON: return "TOKEN_COLON";
        case Token::Type::TOKEN_LEFT_PAREN: return "TOKEN_RIGHT_PAREN";
        case Token::Type::TOKEN_RIGHT_PAREN: return "TOKEN_RIGHT_PAREN";
        case Token::Type::TOKEN_LEFT_BRACKET: return "TOKEN_LEFT_BRACKET";
        case Token::Type::TOKEN_RIGHT_BRACKET: return "TOKEN_RIGHT_BRACKET";
        case Token::Type::TOKEN_LEFT_BRACE: return "TOKEN_LEFT_BRACE";
        case Token::Type::TOKEN_RIGHT_BRACE: return "TOKEN_RIGHT_BRACE";
        case Token::Type::TOKEN_PLUS: return "TOKEN_PLUS";
        case Token::Type::TOKEN_INCREASE: return "TOKEN_INCREASE";
        case Token::Type::TOKEN_MINUS: return "TOKEN_MINUS";
        case Token::Type::TOKEN_DECREASE: return "TOKEN_DECREASE";
        case Token::Type::TOKEN_DIVIDE: return "TOKEN_DIVIDE";
        case Token::Type::TOKEN_MULTIPLY: return "TOKEN_MULTIPLY";
        case Token::Type::TOKEN_POWER: return "TOKEN_POWER";
        case Token::Type::TOKEN_MODULO: return "TOKEN_MODULO";
        case Token::Type::TOKEN_EQUALS: return "TOKEN_EQUALS";
        case Token::Type::TOKEN_DOUBLE_EQUALS: return "TOKEN_DOUBLE_EQUALS";
        case Token::Type::TOKEN_GREATER_THAN: return "TOKEN_GREATER_THAN";
        case Token::Type::TOKEN_LESS_THAN: return "TOKEN_LESS_THAN";
        case Token::Type::TOKEN_GREATER_EQUALS: return "TOKEN_GRATER_EQUALS";
        case Token::Type::TOKEN_LESS_EQUALS: return "TOKEN_LESS_EQUALS";
        case Token::Type::TOKEN_CHAIN: return "TOKEN_CHAIN";
        case Token::Type::TOKEN_AND: return "TOKEN_AND";
        case Token::Type::TOKEN_OR: return "TOKEN_OR";
        case Token::Type::TOKEN_BIT_OR: return "TOKEN_BIT_OR";
        case Token::Type::TOKEN_XOR: return "TOKEN_XOR";
        case Token::Type::TOKEN_BIT_LEFT_SHIFT: return "TOKEN_BIT_LEFT_SHIFT";
        case Token::Type::TOKEN_BIT_RIGHT_SHIFT: return "TOKEN_BIT_RIGHT_SHIFT";
        case Token::Type::TOKEN_NEGATE: return "TOKEN_NEGATE";
        case Token::Type::TOKEN_IF: return "TOKEN_IF";
        case Token::Type::TOKEN_ELSE_IF: return "TOKEN_ELSE_IF";
        case Token::Type::TOKEN_EXTRACT: return "TOKEN_EXTRACT";
        case Token::Type::TOKEN_INJECT: return "TOKEN_INJECT";
        case Token::Type::TOKEN_PREPROCESSOR: return "TOKEN_PREPROCESSOR";
        case Token::Type::TOKEN_CONTAINS_VALUE: return "TOKEN_CONTAINS_VALUE";
        case Token::Type::TOKEN_CONTAINS_KEY: return "TOKEN_CONTAINS_KEY";
        case Token::Type::TOKEN_ADDRESS: return "TOKEN_ADDRESS";
        case Token::Type::TOKEN_EOF: return "TOKEN_EOF";
        default: return "Invalid token type";
    }
}

std::string tokenToStr(Token* token) {
    std::string buffer = "<TOKEN -> value = \"";
    buffer.append(token->value);
    buffer.append("\", type = '");
    buffer.append(tokenTypeToStr(token->type));
    buffer.append("'>;");
    return buffer;
}