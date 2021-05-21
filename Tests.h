#ifndef SDIZO1_TESTS_H
#define SDIZO1_TESTS_H


class Tests {
private:
    long long int frequency, start, elapsed;

    long long int read_QPC();

    void tableTest(int sizeOfStructure);

    void listTest(int sizeOfStructure);

    void heapTest(int sizeOfStructure);

    void treeTest(int sizeOfStructure);

public:

    void startTest();

};


#endif //SDIZO1_TESTS_H
