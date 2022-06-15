#ifndef _MAIN_H
#define _MAIN_H

#include "args/argParser.h"

enum Severity {
    LOG,
    WARNING,
    ERROR
};

inline CmdArgs* args;

#endif