#include <iostream>
#include <string>

#include "args/argParser.h"

CmdArgs* args;

int main(int argc, char* argv[]){

    std::string* arg = (std::string*) calloc(argc, sizeof(std::string));
    for(int i = 0; i < argc; i++) arg[i].append(argv[i]);

    ArgParser* argParser = new ArgParser(arg, argc);
    args = argParser->parse();

    std::cout << args->inputFilename << std::endl;
    std::cout << args->outputFilename << std::endl;
    std::cout << "Silent:" << args->silent << std::endl;
    std::cout << "Verbose:" << args->verbose << std::endl;
    std::cout << "Assembly:" << args->assembly << std::endl;
    std::cout << "Object:" << args->object << std::endl;
    std::cout << "Machine:" << args->machine << std::endl;

    return 0;
}