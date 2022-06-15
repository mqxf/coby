#include <string>
#include <iostream>
#include <vector>
#include "parser.h"
#include "../main.h"
#include "../lexer/lexer.h"
#include "../lexer/token.h"

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

Parser::Parser(Lexer* lexer) {
    this->lexer = lexer;
    len = 0;
    i = 0;
    while ((token = lexer->nextToken())->type != Token::Type::TOKEN_EOF) {
        tokens.push_back(token);
        len++;
    }
    tokens.push_back(new Token("", Token::Type::TOKEN_EOF));
    len++;
    token = tokens[0];
}

std::string Parser::tokenStr() {
    std::string buffer;
    for (size_t j = 0; j < len; j++) {
        buffer.append(tokenToStr(tokens[j]));
        buffer.push_back('\n');
    }
    buffer.pop_back();
    return buffer;
}

Token* Parser::peek(size_t offset) {
    if (i + offset < len) {
        return tokens[i + offset];
    }
    return nullptr;
}

//TODO: Replace with AST
void parse() {

}