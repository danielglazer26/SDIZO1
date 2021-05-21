#include <iostream>
#include "Heap.h"
#include "LoadFile.h"

//dodanie elementu do kopca
void Heap::addNumberToHeap(int numberToAdd) {
    int index = table.getSize();
    table.addAtTheEnd(numberToAdd);
    recoveryMaxHeap(&index);
}

//budowanie kopca wraz z dodawanymi elementami
void Heap::recoveryMaxHeap(int *index) {
    while (*index != 0) {
        if (*table.getNumber(*index) > *table.getNumber((int) ((*index - 1) / 2))) {
            swap(((*index - 1) / 2), *index);
            *index = (*index - 1) / 2;
        } else
            break;
    }
}

//usuwanie szczytu kopca
void Heap::deletePeak() {
    if (table.getSize() != 0) {
        int index = table.getSize() - 1;                    //ostatni element wstawiamy na szczyt kopca
        *table.getTable() = *table.getNumber(index);
        table.deleteAtTheEnd();
        index = 0;
        while (true) {                                      //przywracamy wlasnosc kopca
            if (2 * index + 2 < table.getSize()) {
                if (*table.getNumber(2 * index + 2) > *table.getNumber(2 * index + 1)) {
                    if (*table.getNumber(2 * index + 2) > *table.getNumber(index)) {
                        swap(2 * index + 2, index);
                        index = 2 * index + 2;
                    } else
                        break;
                } else {
                    if (*table.getNumber(2 * index + 1) > *table.getNumber(index)) {
                        swap(2 * index + 1, index);
                        index = 2 * index + 1;
                    } else
                        break;
                }
            } else {
                if (2 * index + 1 < table.getSize()) {
                    if (*table.getNumber(2 * index + 1) > *table.getNumber(index))
                        swap(2 * index + 1, index);
                    else
                        break;
                } else
                    break;
            }
        }
    } else
        std::cout << "Brak elementu do usuniecia\n";
}

//wyswietla kopiec
//wyswietlanie zaimplementowane na podstawie https://eduinf.waw.pl
void Heap::showHeap(std::string sp, std::string sn, int v) {
    std::string s;
    if (v < table.getSize()) {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        showHeap(s + cp, cr, 2 * v + 2);

        s = s.substr(0, sp.length() - 2);

        std::cout << s << sn << *table.getNumber(v) << std::endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        showHeap(s + cp, cl, 2 * v + 1);
    }
}

//zamienia liczby na okreslonych indeksach w tablicy
void Heap::swap(int index1, int index2) {
    int swap = *table.getNumber(index2);
    table.getTable()[index2] = *table.getNumber(index1);
    table.getTable()[index1] = swap;
}

//wczytanie danych z pliku
void Heap::loadDataFromFile() {

    getTable()->deleteTable();

    LoadFile file;
    int *t = file.getDataFromFile();
    if (t == nullptr) {
        std::cout << "Brak pliku\n";
    } else {
        for (int i = 1; i <= t[0]; i++) {
            addNumberToHeap(t[i]);
        }
    }

}

//wywoluje wyswietlanie kopca
void Heap::showHeap() {
    showHeap("", "", 0);
}

//pobiera tablice na ktorej zaimplementowany jest kopiec
Table *Heap::getTable() {
    return &table;
}

//wywoluje funkce rekurencyjna od poszukwiania liczby
int Heap::findNumberInHeap(int numberToFind) {
    if (table.getSize() > 0)
        return recursionFindNumber(numberToFind, 0);
    else {
        std::cout << "Kopiec jest pusty" << std::endl;
        return -1;
    }
}

//wyszukiwanie liczby w kopcu
int Heap::recursionFindNumber(int numberToFind, int i) {

    if (numberToFind == *table.getNumber(i))
        return i;
    else {
        //sprawdzamy czy ojciec ma dwoch synow
        if (2 * i + 2 < table.getSize()) {
            //sprawdzamy czy w prawym poddrzewie moze znajdowac sie poszukwiana liczba
            if (numberToFind <= *table.getNumber(2 * i + 2)) {
                int res = recursionFindNumber(numberToFind, 2 * i + 2);
                if (res != -1)
                    return res;
            }
            //sprawdzamy czy w lewym poddrzewie moze znajdowac sie poszukwiana liczba
            if (numberToFind <= *table.getNumber(2 * i + 1))
                return recursionFindNumber(numberToFind, 2 * i + 1);

        } else {
            //sprawdzamy czy ojciec ma chociaz jednego syna
            if (2 * i + 1 < table.getSize()) {
                if (numberToFind <= *table.getNumber(2 * i + 1))
                    return recursionFindNumber(numberToFind, 2 * i + 1);
            }
        }
    }
    return -1;
}
