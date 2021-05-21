
#ifndef SDIZO1_LOADFILE_H
#define SDIZO1_LOADFILE_H


#include <fstream>

class LoadFile {

private:
    int *table;
    std::ifstream file;
    std::string nameFile;

public:
    ~LoadFile() { delete table; }

    int *getDataFromFile();

};


#endif //SDIZO1_LOADFILE_H
