#ifndef _UTILS_H
#define _UTILS_H

#include <string>

enum Severity {
    LOG,
    WARNING,
    ERROR
};

enum Type {
    INT,
    STRING,
    FLOAT,
    BOOL,
    VOID,
    COLLECTION,
    LIBARY,
    LIST,
    CLASSPTR
};

char strToEsc(std::string str);
std::string strFormat(std::string str);
void log(std::string message, Severity severity);

#endif