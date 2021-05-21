
#include <iostream>
#include "LoadFile.h"


int *LoadFile::getDataFromFile() {
    std::cout << "Podaj nazwe pliku:";
    std::cin >> nameFile;

    file.open(nameFile);

    if (!file.is_open())
        return nullptr;
    else {
        int size;
        file >> size;

        table = new int[size + 1];
        *table = size;
        for (int i = 1; i <= size; i++) {
            file >> table[i];
        }
        file.close();
    }
    return table;

}



