#include <iostream>
#include <string>

#include "argParser.h"

ArgParser::ArgParser(std::string* args, int len) {
    this->args = args;
    this->len = len;
}

CmdArgs* ArgParser::parse() {
    CmdArgs* cmdArgs = new CmdArgs();

    if (len < 2) {
        std::cerr << "ERROR: No input file specified" << std::endl;
        exit(1);
    }

    for (int i = 1; i < len; i++) {
        if (args[i][0] == '-') {
            if (args[i] == "-o") {
                i++;
                if (i >= len) {
                    std::cout << "WARNING: -o option used but no output file specified" << std::endl;
                }
                else {
                    cmdArgs->outputFilename = args[i];
                }
            }
            else if (args[i] == "-silent" || args[i] == "-s") {
                cmdArgs->silent = true;
                cmdArgs->verbose = false;
            }
            else if (args[i] == "-verbose" || args[i] == "-v") {
                cmdArgs->verbose = true;
                cmdArgs->silent = false;
            }
            else if (args[i] == "-S") {
                cmdArgs->assembly = true;
                cmdArgs->machine = false;
                cmdArgs->object = false;
            }
            else if (args[i] == "-c") {
                cmdArgs->object = true;
                cmdArgs->assembly = false;
                cmdArgs->machine = false;
            }
            else {
                std::cout << "WARNING: Unknown argument '" << args[i] << "'. Ignoring..." << std::endl;
            }
        }
        else {
            cmdArgs->inputFilename = args[i];
        }
    }

    if (cmdArgs->inputFilename == "") {
        std::cerr << "ERROR: No input file specified" << std::endl;
        exit(1);
    }

    if (cmdArgs->inputFilename.length() < 6 || cmdArgs->inputFilename.substr(cmdArgs->inputFilename.length() - 5, 5) != ".coby") {
        std::cerr << "ERROR: Invalid input file extension, please provide a .coby source file" << std::endl;
        exit(1);
    }

    if (cmdArgs->outputFilename == "") {
        cmdArgs->outputFilename = cmdArgs->inputFilename.substr(0, cmdArgs->inputFilename.length() - 5);

        if (cmdArgs->assembly) {
            cmdArgs->outputFilename.append(".s");
        }
        else if (cmdArgs->object) {
            cmdArgs->outputFilename.append(".o");
        }

        if (cmdArgs->verbose) {
            std::cout << "WARNING: No output file provided, auto generating output file name. THIS CAN OVERWRITE EXISTING FILES!" << std::endl;
        }
    }

    return cmdArgs;
}