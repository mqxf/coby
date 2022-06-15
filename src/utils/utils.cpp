#include <string>
#include "utils.h"

char strToEsc(std::string str) {
    if (str.length() <= 1) return 0;
    if (str[0] != '\\') return 0;
    char c = str[1];

    switch (c) {
        case 'n': return '\n';
        case 't': return '\t';
        case 'r': return '\r';
        case '\\': return c;
        default: return c;
    }

    return c;
}

std::string strFormat(std::string str) {
    std::string out;
    size_t len = str.length();

    size_t i = 0;
    while (str[i] != '\0' && i < len) {
        if (str[i] == '\\') {
            char escape = strToEsc(str.substr(i, 2));
            out.push_back(escape);
            i += 2;
        }
        else {
            out.push_back(str[i]);
            i += 1;
        }
    }
    return out;
}