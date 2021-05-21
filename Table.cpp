#include <iostream>
#include <cstring>
#include "Table.h"
#include "LoadFile.h"

//alokowanie pamieci dla zadanego rozmiaru tablicy
int *Table::changeTableSize(int position, bool deleting) {

    if (size % 2 == 1) {
        newStartingPosition = new int[size];
        copyValues(position, size, newStartingPosition, oldStartingPosition, deleting);
        if (size != 1)
            delete[]oldStartingPosition;
        return newStartingPosition;

    } else {
        oldStartingPosition = new int[size];
        copyValues(position, size, oldStartingPosition, newStartingPosition, deleting);
        delete[]newStartingPosition;
        return oldStartingPosition;
    }

}

//zwiekszanie rozmiaru tablicy
int *Table::extensionTableSize(int position) {
    size++;
    return changeTableSize(position, false);
}

//zmniejszanie rozmiaru tablicy
void Table::reductionTableSize(int position) {
    size--;
    changeTableSize(position, true);
}

//dodawanie elementow na koncu tablicy
void Table::addAtTheBegin(int numberToAdd) {
    *(extensionTableSize(0)) = numberToAdd;
}

//dodawanie elementow na poczatku tablicy
void Table::addAtTheEnd(int numberToAdd) {
    *(extensionTableSize(-1) + size - 1) = numberToAdd;
}

//dodanie elementu na konkretnym indeksie
void Table::addAtThePosition(int numberToAdd, int position) {
    if (position < 0 || position > size)
        std::cout << "Niepoprawny indeks" << std::endl;
    else
        *(extensionTableSize(position) + position) = numberToAdd;
}

//kopiowanie elementow w momencie w ktorym zmieniamy rozmiar tablicy
void Table::copyValues(int position, int size, int *newPointer,
                       int const *oldPointer, bool deleting) {

    //na poczatku tablicy
    if (position == 0) {
        if (!deleting) //dodawanie
            for (int i = 1; i < size; i++) {
                newPointer[i] = oldPointer[i - 1];
            }
        else //usuwanie
            for (int i = 0; i < size; i++) {
                newPointer[i] = oldPointer[i + 1];
            }
        //na koncu tablicy
    } else if (position == -1) {
        if (!deleting) { //dodawanie
            if (size - 1 != 0)
                for (int i = 0; i < size - 1; i++) {
                    newPointer[i] = oldPointer[i];
                }
        } else { //odejmowanie
            for (int i = 0; i < size; i++) {
                newPointer[i] = oldPointer[i];
            }
        }
        //o zadanym indeksie
    } else {
        if (!deleting) //dodawanie
            for (int i = 0; i < size; i++) {
                if (i > position)
                    newPointer[i] = oldPointer[i - 1];
                else
                    newPointer[i] = oldPointer[i];
            }
        else //odejmowanie
            for (int i = 0; i < size; i++) {
                if (i >= position)
                    newPointer[i] = oldPointer[i + 1];
                else
                    newPointer[i] = oldPointer[i];
            }
    }
}

//usuniecie pierwszego elementu
void Table::deleteAtTheBegin() {
    if (size > 0)
        reductionTableSize(0);
}

//usuniecie ostatniego elementu
void Table::deleteAtTheEnd() {
    if (size > 0)
        reductionTableSize(-1);
}

//usuniecie elementu o danym indeksie
void Table::deleteAtThePosition(int position) {
    if (position < 0 || position >= size)
        std::cout << "Niepoprawny indeks" << std::endl;
    else
        reductionTableSize(position);
}

//wyswietlenie tablicy
void Table::showTable() {
    std::cout << "Tablica : [ ";
    if (size % 2 == 1) {
        for (int i = 0; i < size; i++) {
            std::cout << newStartingPosition[i] << " ";
        }

    } else {
        for (int i = 0; i < size; i++) {
            std::cout << oldStartingPosition[i] << " ";
        }
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;
}

//wyswietlenie tablicy w odwrotnym kierunku
void Table::showTableReverse() {
    std::cout << "Tablica od konca : [ ";
    if (size % 2 == 1) {
        for (int i = size - 1; i >= 0; i--) {
            std::cout << newStartingPosition[i] << " ";
        }
    } else {
        for (int i = size - 1; i >= 0; i--) {
            std::cout << oldStartingPosition[i] << " ";
        }
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;
}

//pobranie rozmiaru tablicy
int Table::getSize() {
    return size;
}

//pobieranie liczby o danych indeksie z tablicy
int *Table::getNumber(int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    } else {
        if (size % 2 == 1)
            return newStartingPosition + index;
        else
            return oldStartingPosition + index;
    }
}

//pobieranie wskaznika na tablice
int *Table::getTable() {
    if (size % 2 == 1)
        return newStartingPosition;
    else
        return oldStartingPosition;
}

//usuwanie tablicy
void Table::deleteTable() {
    if (size > 0) {
        if (size % 2 == 1)
            delete[]newStartingPosition;
        else
            delete[]oldStartingPosition;
        size = 0;
    }
}

//wyszukiwanie liczby
//zwraca index
int Table::findNumber(int numberToFind) {
    for (int i = 0; i < size; i++) {
        if (getTable()[i] == numberToFind)
            return i;
    }
    return -1;
}

//wczytywanie danych z pliku
void Table::loadDataFromFile() {

    deleteTable();

    LoadFile file;
    int *fileTable = file.getDataFromFile();
    if (fileTable == nullptr) {
        std::cout << "Brak pliku" << std::endl;
    } else {
        createTable(fileTable[0]);

        for (int i = 1; i <= size; i++) {
            getTable()[i - 1] = fileTable[i];
        }

    }
}

//tworzenie tablicy o zadanym rozmiarze
//wykorzystywane tylko przy wczytywaniu z pliku
void Table::createTable(int sizeDeclaration) {

    if (sizeDeclaration % 2 == 1)
        newStartingPosition = new int[sizeDeclaration];
    else
        oldStartingPosition = new int[sizeDeclaration];

    size = sizeDeclaration;
}

