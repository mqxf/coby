#include <string>
#include <iostream>
#include <fstream>

#include "file.h"

File::File(const std::string filename) {
    this->filename = filename;
}

void File::write(std::string buffer) { 
    std::ofstream file;
    file.open(filename, std::ios::out);
    if (file.is_open()) {
        file << buffer;
        file.close();
    }
    else {
        std::cerr << "ERROR: Cannot write to file '" << filename << "'\n";
        exit(1);
    }
}

std::string File::read() { 
    std::string buffer;
    std::string line;

    std::ifstream file;
    file.open(filename, std::ios::in);
    if (file.is_open()) {
        while(getline(file, line)) {
            buffer.append(line);
            buffer.push_back('\n');
        }
        file.close();
    }
    else {
        std::cerr << "ERROR: Cannot read from file '" << filename << "'\n";
        exit(1);
    }
    return buffer;
}