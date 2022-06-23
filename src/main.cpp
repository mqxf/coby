#include <iostream>
#include <string>

#include "main.h"
#include "args/argParser.h"
#include "file/file.h"
#include "coby/coby.h"
#include "utils/utils.h"

int main(int argc, char* argv[]){

    std::string* arg = (std::string*) calloc(argc, sizeof(std::string));
    for(int i = 0; i < argc; i++) arg[i].append(argv[i]);

    ArgParser* argParser = new ArgParser(arg, argc);
    args = argParser->parse();

    compileFile(args->inputFilename, args->outputFilename);

    return 0;
}