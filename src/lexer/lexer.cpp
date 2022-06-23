#include <string>
#include <iostream>
#include "lexer.h"
#include "token.h"
#include "../utils/utils.h"

Lexer::Lexer(std::string src) {
    this->src = src;
    length = this->src.length();
    i = 0;
    c = src[0];
}

char Lexer::peek(size_t offset) {
    if (i + offset < length) {
        return src[i + offset];
    }
    return 0;
} 

void Lexer::advance() {
    if ((i + 1) < length) {
        i++;
        c = src[i];
    }
    else {
        i++;
        c = 0;
    }
}

void Lexer::skipWhiteSpace() {
    while (c == 10 || c == 13 || c == '\t' || c == ' ') {
        advance();
    }
}

void Lexer::skipComment() {
    if (c == '.' && peek(1) == '.') {
        if (peek(2) == '.') {
            advance();
            for (;;) {
                if (c == '.' && peek(1) == '.' && peek(2) == '.') {
                    advance();
                    advance();
                    advance();
                    break;
                }
                advance();
            }
        }
        else {
            while (c !='\n') advance();
        }
        skipWhiteSpace();
        skipComment();
    }
}

Token* Lexer::advanceWith(Token* token) {
    for (size_t i = 0; i < token->value.length(); i++) {
        advance();
    }
    return token;
}

Token* Lexer::nextId() {
    std::string value;
    while (isalnum(c)) {
        value.push_back(c);
        advance();
    }
    if (value == "not") return new Token(value, Token::Type::TOKEN_NEGATE);
    return new Token(value, Token::Type::TOKEN_ID);
}

Token* Lexer::nextNumber() {
    if (c == '0') {
        if (peek(1) == 'x') {
            advance();
            advance();
            return nextHexadecimal();
        }
        if (peek(1) == 'b') {
            advance();
            advance();
            return nextBinary();
        }
    }

    //TODO: check for float

    std::string value;
    while (isdigit(c)) {
        value.push_back(c);
        advance();
    }
    if (c == '.') return nextFloat(value);
    return new Token(value, Token::Type::TOKEN_INT);   
}

Token* Lexer::nextBinary() {
    std::string value;
    while (c == '0' || c == '1') {
        value.push_back(c);
        advance();
    }
    return new Token(value, Token::Type::TOKEN_BIN);
}

Token* Lexer::nextHexadecimal() {
    std::string value;
    while (isxdigit(c)) {
        value.push_back(c);
        advance();
    }
    return new Token(value, Token::Type::TOKEN_HEX);
}

Token* Lexer::nextFloat(std::string base) {
    base.push_back('.');
    advance();
    while (isdigit(c)) {
        base.push_back(c);
        advance();
    }
    return new Token(base, Token::Type::TOKEN_FLOAT);
}

Token* Lexer::nextString() {
    std::string value;
    advance();
    while (c != '"') {
        value.push_back(c);
        advance();
    }
    advance();
    std::string formatted = strFormat(value);
    return new Token(formatted, Token::Type::TOKEN_STRING);
}

Token* Lexer::nextChar() {
    std::string value;
    advance();
    while (c != '\'') {
        value.push_back(c);
        advance();
    }
    advance();
    std::string formatted = strFormat(value);
    return new Token(formatted, Token::Type::TOKEN_CHAR);
}

Token* Lexer::nextToken() {
    skipWhiteSpace();
    skipComment();

    if (isalpha(c)) {
        return nextId();
    }
    if(isdigit(c)){
        return nextNumber();
    }

    //switch, if token is something that can be used in multi charcter token, check for that first with lexerPeek();
    //parse as string at token ""
    //parse as char at token ''


    switch (c) {
        case '-':
            if (peek(1) == '>') return advanceWith(new Token("->", Token::Type::TOKEN_EXTRACT));
            if (peek(1) == '-') return advanceWith(new Token("--", Token::Type::TOKEN_DECREASE));
            if (peek(1) == '?') return advanceWith(new Token("-?", Token::Type::TOKEN_CONTAINS_KEY));
            return advanceWith(new Token("-", Token::Type::TOKEN_MINUS));
        case '+':
            if (peek(1) == '+') return advanceWith(new Token("++", Token::Type::TOKEN_INCREASE));
            return advanceWith(new Token("+", Token::Type::TOKEN_PLUS));
        case '=':
            if (peek(1) == '>') return advanceWith(new Token("=>", Token::Type::TOKEN_INJECT));
            if (peek(1) == '=') return advanceWith(new Token("==", Token::Type::TOKEN_DOUBLE_EQUALS));
            if (peek(1) == '?') return advanceWith(new Token("=?", Token::Type::TOKEN_CONTAINS_VALUE));
            return advanceWith(new Token("=", Token::Type::TOKEN_EQUALS));  
        case '&': 
            if (peek(1) == '&') return advanceWith(new Token("&&", Token::Type::TOKEN_AND));
            if (peek(1) == '?') return advanceWith(new Token("&?", Token::Type::TOKEN_ELSE_IF));
            return advanceWith(new Token("&", Token::Type::TOKEN_CHAIN));
        case '<':
            if(peek(1) == '=') return advanceWith(new Token("<=", Token::Type::TOKEN_LESS_EQUALS));
            if(peek(1) == '<') return advanceWith(new Token("<<", Token::Type::TOKEN_BIT_LEFT_SHIFT));
            return advanceWith(new Token("<", Token::Type::TOKEN_LESS_THAN));
        case '|': 
            if(peek(1) == '|') return advanceWith(new Token("||", Token::Type::TOKEN_OR));
            return advanceWith(new Token("|", Token::Type::TOKEN_BIT_OR));
        case '>':
            if(peek(1) == '=') return advanceWith(new Token(">=", Token::Type::TOKEN_GREATER_EQUALS));
            if(peek(1) == '>') return advanceWith(new Token(">>", Token::Type::TOKEN_BIT_RIGHT_SHIFT));
            return advanceWith(new Token(">", Token::Type::TOKEN_GREATER_THAN));
        case '*':
            if (peek(1) == '*') return advanceWith(new Token("**", Token::Type::TOKEN_POWER));
            return advanceWith(new Token("*", Token::Type::TOKEN_MULTIPLY));
        case '\'': return nextChar();
        case '\"': return nextString();
        case ',': return advanceWith(new Token(",", Token::Type::TOKEN_COMMA));
        case ';': return advanceWith(new Token(";", Token::Type::TOKEN_SEMICOLON));
        case ':': return advanceWith(new Token(":", Token::Type::TOKEN_COLON));
        case '^': return advanceWith(new Token("^", Token::Type::TOKEN_XOR));
        case '%': return advanceWith(new Token("%", Token::Type::TOKEN_MODULO));
        case '!': return advanceWith(new Token("!", Token::Type::TOKEN_NEGATE));
        case '#': return advanceWith(new Token("#", Token::Type::TOKEN_PREPROCESSOR));
        case '?': return advanceWith(new Token("?", Token::Type::TOKEN_IF)); 
        case '(': return advanceWith(new Token("(", Token::Type::TOKEN_LEFT_PAREN));
        case '[': return advanceWith(new Token("[", Token::Type::TOKEN_LEFT_BRACKET));
        case '{': return advanceWith(new Token("{", Token::Type::TOKEN_LEFT_BRACE));
        case ')': return advanceWith(new Token(")", Token::Type::TOKEN_RIGHT_PAREN));
        case ']': return advanceWith(new Token("]", Token::Type::TOKEN_RIGHT_BRACKET));
        case '}': return advanceWith(new Token("}", Token::Type::TOKEN_RIGHT_BRACE));
        case '.': return advanceWith(new Token(".", Token::Type::TOKEN_DOT));
        case '/': return advanceWith(new Token("/", Token::Type::TOKEN_DIVIDE));
        case '@': return advanceWith(new Token("@", Token::Type::TOKEN_ADDRESS));
        case '\0': break;
        default:
            std::cerr << "ERROR: Invalid token: '" << c << "'\n";
            exit(1);
            break;
    }
    return new Token("", Token::Type::TOKEN_EOF);
}