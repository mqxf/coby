#ifndef _ARG_PARSER_H
#define _ARG_PARSER_H

#include <string>

class CmdArgs {

    public:
        std::string inputFilename;
        std::string outputFilename;

        bool assembly = false;
        bool object = false;
        bool machine = true;

        bool silent = false;
        bool verbose = false;
    
        //bool for every type of warning, silent auto disables all, verbose adds extra stuff

};

class ArgParser {

    private:
        std::string* args;
        int len;

    public:
        ArgParser(std::string* args, int len);
        CmdArgs* parse();
};

#endif