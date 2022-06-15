#include <string>
#include <iostream>
#include "coby.h"
#include "../file/file.h"
#include "../lexer/lexer.h"
#include "../lexer/token.h"
#include "../parser/parser.h"

std::string compile(std::string src) {

    Lexer* lexer = new Lexer(src);
    Parser* parser = new Parser(lexer);

    return parser->tokenStr();
}

void compileFile(std::string inputFile, std::string outputFile) {
    File* inFile = new File(inputFile);
    std::string src = inFile->read();
    std::string out = compile(src);
    File* outFile = new File(outputFile);
    outFile->write(out);
}