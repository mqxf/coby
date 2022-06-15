#ifndef _PARSER_H
#define _PARSER_H

#include <vector>
#include "AST/rootAST.h"
#include "AST/funcAST.h"
#include "AST/exprAST.h"
#include "AST/stmtAST.h"
#include "../lexer/lexer.h"
#include "../lexer/token.h"

class Parser {
    private:
        Lexer* lexer;
        std::vector<Token*> tokens;
        Token* token;
        size_t i;
        size_t len;

        Token* peek(size_t offset);

    public:
        Parser(Lexer* lexer);
        size_t length() { return len; }
        std::string tokenStr();
        RootAST* parse();


};

#endif