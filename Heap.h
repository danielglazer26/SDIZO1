
#ifndef SDIZO1_HEAP_H
#define SDIZO1_HEAP_H


#include "Table.h"

class Heap {

private:
    std::string cr, cl, cp;

    Table table;

    void swap(int index1, int index2);

    void recoveryMaxHeap(int *index);

    void showHeap(std::string sp, std::string sn, int v);

public:

    Heap() {
        cr = cl = cp = "  ";
        cr[0] = 218;
        cr[1] = 196;
        cl[0] = 192;
        cl[1] = 196;
        cp[0] = 179;
    }

    void addNumberToHeap(int numberToAdd);

    void deletePeak();

    void showHeap();

    void loadDataFromFile();

    Table *getTable();

    int findNumberInHeap(int numberToFind);

    int recursionFindNumber(int numberToFind, int i);
};


#endif //SDIZO1_HEAP_H
