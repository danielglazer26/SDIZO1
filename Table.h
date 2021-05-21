
#ifndef SDIZO1_TABLE_H
#define SDIZO1_TABLE_H


class Table {
private:
    int size = 0;
    int *newStartingPosition;
    int *oldStartingPosition;

    void copyValues(int position, int size, int *newPointer,
                    int const *oldPointer, bool deleting);

    int *changeTableSize(int position, bool deleting);

    int *extensionTableSize(int position);

    void reductionTableSize(int position);

public:
    ~Table() { deleteTable(); }

    void addAtTheBegin(int numberToAdd);

    void addAtTheEnd(int numberToAdd);

    void addAtThePosition(int numberToAdd, int position);

    void deleteAtTheBegin();

    void deleteAtTheEnd();

    void deleteAtThePosition(int position);

    void showTable();

    int getSize();

    int *getTable();

    int *getNumber(int index);

    void showTableReverse();

    void deleteTable();

    void loadDataFromFile();

    int findNumber(int numberToFind);

    void createTable(int size);
};


#endif //TABLICADYNAMICZNA2_TABLE_H
