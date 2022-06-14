#include <iostream>
#include <string>

#include "args/argParser.h"
#include "args.h"
#include "file/file.h"

int main(int argc, char* argv[]){

    std::string* arg = (std::string*) calloc(argc, sizeof(std::string));
    for(int i = 0; i < argc; i++) arg[i].append(argv[i]);

    ArgParser* argParser = new ArgParser(arg, argc);
    args = argParser->parse();

    File* file = new File(args->inputFilename);
    file->write("Hello");

    return 0;
}