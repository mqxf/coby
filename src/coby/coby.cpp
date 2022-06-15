#include <string>
#include <iostream>
#include "coby.h"
#include "../file/file.h"
#include "../lexer/lexer.h"
#include "../lexer/token.h"

std::string compile(std::string src) {

    Lexer* lexer = new Lexer(src);
    Token* token;
    std::string tokens;

    while ((token = lexer->nextToken())->type != Token::Type::TOKEN_EOF) {
        //std::cout << tokenToStr(token) << std::endl;
        tokens.append(tokenToStr(token));
        tokens.push_back('\n');
    }

    return tokens;
}

void compileFile(std::string inputFile, std::string outputFile) {
    File* inFile = new File(inputFile);
    std::string src = inFile->read();
    std::string out = compile(src);
    File* outFile = new File(outputFile);
    outFile->write(out);
}