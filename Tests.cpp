#include <windows.h>
#include <iomanip>
#include <random>
#include <iostream>
#include "Tests.h"
#include "Table.h"
#include "DoubleLinkedList.h"
#include "Heap.h"
#include "TreeBST.h"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(1, 1000000);

long long int Tests::read_QPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return ((long long int) count.QuadPart);
}

void Tests::startTest() {

    int sizeOfStructure = 1000;
    QueryPerformanceFrequency((LARGE_INTEGER *) &frequency);

    for (int i = 0; i < 10; i++) {

        tableTest(sizeOfStructure);

        //listTest(sizeOfStructure);

        //heapTest(sizeOfStructure);

        //treeTest(sizeOfStructure)

        sizeOfStructure += 1000;
    }

}


void Tests::tableTest(int sizeOfStructure) {

    /*Table table;

    table.createTable(sizeOfStructure);
    for (int i = 0; i < sizeOfStructure; i++) {
        table.getTable()[i] = dist(gen);
    }
    std::uniform_int_distribution<> dist2(0, sizeOfStructure - 1);*/

    double averageTime = 0;

    for (int i = 0; i < 10; i++) {

        //int value = dist(gen);
        //int index = dist2(gen);
       // table.addAtThePosition(0, index);
        start = read_QPC();

        Sleep(1000);
        //table.addAtTheBegin(value);
        //table.addAtTheEnd(value)
        //table.addAtThePosition(value, index);
        //table.findNumber(0);

        elapsed = read_QPC() - start;

        averageTime += (1000.0 * elapsed)/frequency;

        //table.deleteAtTheBegin();
        //table.deleteAtTheEnd();
        //table.deleteAtThePosition(index);

        //std::cout << "Time [s] = " <<  std::fixed <<  std::setprecision(3) << (float)elapsed /frequency <<  std::endl;
        //std::cout << "Time [ms] = " << std::setprecision(3) << (float) (1000.0 * elapsed /frequency) << std::endl;
        //std::cout << "Time [us] = " << std::setprecision(0) << (1000000.0 * elapsed)/frequency << std::endl;
    }
    //table.deleteTable();

    std::cout << averageTime / 10 << "\n";
}

void Tests::listTest(int sizeOfStructure) {

    DoubleLinkedList list;

    for (int i = 0; i < sizeOfStructure; i++) {
        list.endAddElementToList(dist(gen));
    }

    //std::uniform_int_distribution<> dist2(1, sizeOfStructure - 1);

    double averageTime = 0;

    for (int i = 0; i < 1000; i++) {
        int value = dist(gen);
        //int index = dist2(gen);

        //list.positionAddElementToList(0, index);
        start = read_QPC();

        //list.endDeleteElementToList();
        list.beginAddElementToList(value);
        //list.endAddElementToList(value);
        //list.positionAddElementToList(value, index);
        //list.findNumber(0);

        elapsed = read_QPC() - start;

        list.endAddElementToList(value);
        //list.beginDeleteElementToList();
        //list.endDeleteElementToList();
        //list.positionDeleteElementToList(index);

        //averageTime += (float) (1000.0 * elapsed /frequency);
        averageTime += (1000000.0 * elapsed) / frequency;
    }
    list.deleteList();
    std::cout << averageTime / 1000 << "\n";
}

void Tests::heapTest(int sizeOfStructure) {
    Heap heap;
    for (int i = 0; i < sizeOfStructure; i++) {
        heap.addNumberToHeap(dist(gen));
    }

    double averageTime = 0;
    for (int i = 0; i < 1000; i++) {
        int value = dist(gen);

        //heap.addNumberToHeap(value);
        start = read_QPC();
        heap.findNumberInHeap(value);
        //heap.deletePeak();
        elapsed = read_QPC() - start;

        //heap.getTable()->deleteAtTheEnd();

        averageTime += (1000000.0 * elapsed / frequency);

    }
    std::cout << averageTime / 1000 << "\n";
}

void Tests::treeTest(int sizeOfStructure) {

    TreeBST tree;

    for (int i = 0; i < sizeOfStructure; i++) {
        tree.addElementToBST(dist(gen));
    }

    //tree.balanceTree();
    double averageTime = 0;

    for (int i = 0; i < 1000; i++) {
        int value = dist(gen);
        //int index = dist2(gen);
        //tree.findElementBST(value);

        start = read_QPC();

        tree.balanceTree();
        //tree.addElementToBST(value);

        elapsed = read_QPC() - start;
       // tree.deleteElementFromTree(value);

        averageTime += (1000.0* elapsed) / frequency;

        //averageTime += (1000000.0 * elapsed) / frequency;

    }
    std::cout << averageTime / 1000 << "\n";
}
