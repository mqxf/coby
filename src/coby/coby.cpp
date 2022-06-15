#include <string>
#include <iostream>
#include "coby.h"
#include "../file/file.h"
#include "../lexer/lexer.h"
#include "../lexer/token.h"

std::string compile(std::string src) {

    Lexer* lexer = new Lexer(src);
    Token* token = new Token("", Token::Type::TOKEN_ID);

    while (token->type != Token::Type::TOKEN_EOF) {
        token = lexer->nextToken();
        std::cout << tokenToStr(token) << std::endl;
    }

    return "";
}

void compileFile(std::string inputFile, std::string outputFile) {
    File* inFile = new File(inputFile);
    std::string src = inFile->read();
    std::string out = compile(src);
    //File* outFile = new File(outputFile);
    //outFile->write(out);
}