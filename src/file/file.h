#ifndef _FILE_H
#define _FILE_H

#include <string>

class File {

    private:
        std::string filename;

    public:
        File(const std::string filename);
        std::string read();
        void write(const std::string buffer);

};

#endif