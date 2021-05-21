#include <iostream>

#include "Table.h"
#include "DoubleLinkedList.h"
#include "Heap.h"
#include "TreeBST.h"
#include "Tests.h"


void menuTreeBst() {
    int b, c;
    TreeBST tree;
    do {
        std::cout << "1. Dodaj element\n"
                     "2. Usun element\n"
                     "3. Zrownowaz drzewo\n"
                     "4. Obroc w prawo\n"
                     "5. Obroc w lewo\n"
                     "6. Wyszukaj element\n"
                     "7. Wczytaj z pliku\n"
                     "8. Cofnij do menu glownego\n"
                     "Wybierz funkcje:";
        std::cin >> b;
        std::cout << std::endl;
        switch (b - 1) {
            case 0:
                std::cout << "Podaj liczbe do wstawienia:";
                std::cin >> c;
                std::cout << std::endl;
                tree.addElementToBST(c);
                break;
            case 1:
                std::cout << "Podaj liczbe do usuniecia:";
                std::cin >> c;
                std::cout << std::endl;
                tree.deleteElementFromTree(c);
                break;
            case 2:
                tree.balanceTree();
                break;
            case 3:
                std::cout << "Podaj liczbe do obrocenia:";
                std::cin >> c;
                tree.rotationRight(tree.findElementBST(c));
                break;
            case 4:
                std::cout << "Podaj liczbe do obrocenia:";
                std::cin >> c;
                tree.rotationLeft(tree.findElementBST(c));
                break;
            case 5:
                std::cout << "Podaj liczbe do wyszukania:";
                std::cin >> c;
                std::cout << std::endl;
                if (tree.findElementBST(c) != nullptr)
                    std::cout << "Wskaznik na wezel:" << tree.findElementBST(c);
                else
                    std::cout << "Nie ma takiej liczby";
                std::cout << std::endl;
                break;
            case 6:
                tree.loadDataFromFile();
                break;
        }
        tree.showTree();
    } while (b != 8);
}

void menuHeap() {
    int b, c, d;
    Heap heap;

    do {
        std::cout << "1. Dodaj element\n"
                     "2. Usun element ze szczytu\n"
                     "3. Wyszukaj liczbe\n"
                     "4. Wczytaj z pliku\n"
                     "5. Cofnij do menu glownego\n"
                     "Wybierz funkcje:";
        std::cin >> b;
        std::cout << std::endl;
        switch (b - 1) {
            case 0:
                std::cout << "Podaj liczbe do wstawienia:";
                std::cin >> c;
                std::cout << std::endl;
                heap.addNumberToHeap(c);
                break;
            case 1:
                heap.deletePeak();
                break;
            case 2:
                std::cout << "Podaj liczbe do wyszukania:";
                std::cin >> c;
                std::cout << std::endl;
                d = heap.findNumberInHeap(c);
                if (d == -1)
                    std::cout << "Nie ma takiej liczby w liscie";
                else
                    std::cout << "Indeks: " << d;
                break;
            case 3:
                heap.loadDataFromFile();
                break;

        }
        std::cout << std::endl;
        heap.showHeap();
        heap.getTable()->showTable();
    } while (b != 5);
}

void menuList() {
    int b, c, d, e;
    DoubleLinkedList list;
    do {
        std::cout << "1. Dodaj element\n"
                     "2. Usun element\n"
                     "3. Wyszukaj\n"
                     "4. Wczytaj dane z pliku\n"
                     "5. Cofnij do menu glownego\n"
                     "Wybierz funkcje:";
        std::cin >> b;
        std::cout << std::endl;
        switch (b - 1) {
            case 0:
                do {
                    std::cout << "1. Dodaj element na poczatku\n"
                                 "2. Dodaj element na koncu\n"
                                 "3. Dodaj element na konkretnym indeksie\n"
                                 "4. Cofnij do menu listy\n"
                                 "Wybierz funkcje:";
                    std::cin >> c;
                    std::cout << std::endl;
                    switch (c - 1) {
                        case 0:
                            std::cout << "Podaj liczbe do wstawienia:";
                            std::cin >> d;
                            std::cout << std::endl;
                            list.beginAddElementToList(d);
                            break;
                        case 1:
                            std::cout << "Podaj liczbe do wstawienia:";
                            std::cin >> d;
                            std::cout << std::endl;
                            list.endAddElementToList(d);
                            break;
                        case 2:
                            std::cout << "Podaj liczbe do wstawienia:";
                            std::cin >> d;
                            std::cout << "Podaj indeks:";
                            std::cin >> e;
                            list.positionAddElementToList(d, e);
                            break;
                    }
                    list.showList();
                    list.showListReverse();
                    std::cout << std::endl;
                } while (c != 4);
                break;
            case 1:
                do {
                    std::cout << "1. Usun element na poczatku\n"
                                 "2. Usun element na koncu\n"
                                 "3. Usun element na konkretnym indeksie\n"
                                 "4. Cofnij do menu listy\n"
                                 "Wybierz funkcje:";
                    std::cin >> c;
                    std::cout << std::endl;
                    switch (c - 1) {
                        case 0:
                            list.beginDeleteElementToList();
                            break;
                        case 1:
                            list.endDeleteElementToList();
                            break;
                        case 2:
                            std::cout << "Podaj indeks:" << std::endl;
                            std::cin >> d;
                            list.positionDeleteElementToList(d);
                    }
                    list.showList();
                    list.showListReverse();
                    std::cout << std::endl;
                } while (c != 4);
                break;
            case 2:
                do {
                    std::cout << "1. Wyszukaj liczbe\n"
                                 "2. Zwroc wartosc elementu pod danym indeksem\n"
                                 "3. Cofnij do menu listy\n"
                                 "Wybierz funkcje:";
                    std::cin >> c;
                    std::cout << std::endl;
                    switch (c - 1) {
                        case 0:
                            std::cout << "Podaj liczbe do wyszukania:";
                            std::cin >> d;
                            std::cout << std::endl;
                            d = list.findNumber(d);
                            if (d == -1)
                                std::cout << "Nie ma takiej liczby w liscie";
                            else
                                std::cout << "Indeks: " << d;

                            break;
                        case 1:
                            std::cout << "Podaj indeks:";
                            std::cin >> d;
                            if (d >= 0 && d < list.getSize())
                                std::cout << "Liczba: " << list.getNumber(d);
                            else
                                std::cout << "Bledny indeks";
                            break;
                    }
                    std::cout << std::endl;
                    list.showList();
                    list.showListReverse();
                    std::cout << std::endl;
                } while (c != 3);
                break;
            case 3:
                list.loadDataFromFile();
                list.showList();
                std::cout << std::endl;
                break;
        }
    } while (b != 5);
}

void menuTable() {
    int b, c, d, e;
    Table table;

    do {
        std::cout << "1. Dodaj element\n"
                     "2. Usun element\n"
                     "3. Wyszukaj\n"
                     "4. Wczytaj dane z pliku\n"
                     "5. Cofnij do menu glownego\n"
                     "Wybierz funkcje:";
        std::cin >> b;
        std::cout << std::endl;
        switch (b - 1) {
            case 0:
                do {
                    std::cout << "1. Dodaj element na poczatku\n"
                                 "2. Dodaj element na koncu\n"
                                 "3. Dodaj element na konkretnym indeksie\n"
                                 "4. Cofnij do menu tabeli\n"
                                 "Wybierz funkcje:";
                    std::cin >> c;
                    std::cout << std::endl;
                    switch (c - 1) {
                        case 0:
                            std::cout << "Podaj liczbe do wstawienia:";
                            std::cin >> d;
                            std::cout << std::endl;
                            table.addAtTheBegin(d);
                            break;
                        case 1:
                            std::cout << "Podaj liczbe do wstawienia:";
                            std::cin >> d;
                            std::cout << std::endl;
                            table.addAtTheEnd(d);
                            break;
                        case 2:
                            std::cout << "Podaj liczbe do wstawienia:";
                            std::cin >> d;
                            std::cout << "Podaj indeks:";
                            std::cin >> e;
                            table.addAtThePosition(d, e);
                            break;
                    }
                    table.showTable();
                    table.showTableReverse();
                } while (c != 4);
                break;
            case 1:
                do {
                    std::cout << "1. Usun element na poczatku\n"
                                 "2. Usun element na koncu\n"
                                 "3. Usun element na konkretnym indeksie\n"
                                 "4. Cofnij do menu tabeli\n"
                                 "Wybierz funkcje:";
                    std::cin >> c;
                    std::cout << std::endl;
                    switch (c - 1) {
                        case 0:
                            table.deleteAtTheBegin();
                            break;
                        case 1:
                            table.deleteAtTheEnd();
                            break;
                        case 2:
                            std::cout << "Podaj indeks:" << std::endl;
                            std::cin >> d;
                            table.deleteAtThePosition(d);
                    }
                    table.showTable();
                    table.showTableReverse();
                } while (c != 4);
                break;
            case 2:
                do {
                    std::cout << "1. Wyszukaj liczbe\n"
                                 "2. Zwroc wartosc elementu pod danym indeksem\n"
                                 "3. Cofnij do menu tabeli\n"
                                 "Wybierz funkcje:";
                    std::cin >> c;
                    std::cout << std::endl;
                    switch (c - 1) {
                        case 0:
                            std::cout << "Podaj liczbe do wyszukania:";
                            std::cin >> d;
                            std::cout << std::endl;
                            d = table.findNumber(d);
                            if (d == -1)
                                std::cout << "Nie ma takiej liczby w tablicy";
                            else
                                std::cout << "Indeks: " << d;
                            break;
                        case 1:
                            std::cout << "Podaj indeks:";
                            std::cin >> d;
                            if (d >= 0 && d < table.getSize())
                                std::cout << "Liczba: " << *table.getNumber(d);
                            else
                                std::cout << "Bledny indeks";
                            break;
                    }
                    std::cout << std::endl;
                } while (c != 3);
                break;
            case 3:
                table.loadDataFromFile();
                table.showTable();
                break;
        }
    } while (b != 5);
}

void menu() {
    int a;
    do {
        std::cout << "1. Tablica\n"
                     "2. Lista\n"
                     "3. Kopiec typu MAX\n"
                     "4. Drzewo BST\n"
                     "5. Wyjdz\n"
                     "Wybierz strukture:";
        std::cin >> a;
        std::cout << std::endl;
        switch (a - 1) {
            case 0:
                menuTable();
                break;
            case 1:
                menuList();
                break;
            case 2:
                menuHeap();
                break;
            case 3:
                menuTreeBst();
                break;
        }

    } while (a != 5);
}

int main() {

    //menu();

    Tests test;
    test.startTest();


    return 0;
}
