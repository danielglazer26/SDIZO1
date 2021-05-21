

#include <iostream>
#include "DoubleLinkedList.h"
#include "LoadFile.h"

//dodanie elementu na poczatku listy
void DoubleLinkedList::beginAddElementToList(int numberToAdd) {

    if (headIsNotNULL(numberToAdd)) {
        head->previous = new ListElement();
        head->previous->next = head;
        head = head->previous;
        head->number = numberToAdd;
    }
}

//dodanie elementu na koncu listy
void DoubleLinkedList::endAddElementToList(int numberToAdd) {

    if (headIsNotNULL(numberToAdd)) {
        tail->next = new ListElement();
        tail->next->previous = tail;
        tail = tail->next;
        tail->number = numberToAdd;
    }

}

//sprawdzenie czy do glowy jest przypisany jakis wskaznik
//czy jest jakis element w liscie
bool DoubleLinkedList::headIsNotNULL(int numberToAdd) {

    size++;
    if (head == nullptr) {
        head = new ListElement();
        head->number = numberToAdd;
        tail = head;
        return false;
    }
    return true;
}

//dodanie elementu na odpowiedni indeks
void DoubleLinkedList::positionAddElementToList(int numberToAdd, int position) {

    if (position > size || position < 0)
        std::cout << "Bledny indeks" << std::endl;
    else if (position == size)
        endAddElementToList(numberToAdd);
    else if (position == 0)
        beginAddElementToList(numberToAdd);
    else {
        int headOrTail = size / 2;      //sprawdzamy czy lepiej jest przesuwac sie po liscie zaczynajac od ogona
        //czy zaczynajac od glowy

        if (headOrTail > position) {
            ListElement *pointerPrevious = head;
            for (int i = 1; i < position; i++) {
                pointerPrevious = pointerPrevious->next;
            }
            ListElement *pointerNext = pointerPrevious->next;

            changePointers(pointerNext, pointerPrevious, numberToAdd);
        } else {
            ListElement *pointerNext = tail;
            for (int i = size - 1; i > position; i--) {
                pointerNext = pointerNext->previous;
            }
            ListElement *pointerPrevious = pointerNext->previous;

            changePointers(pointerNext, pointerPrevious, numberToAdd);
        }
        size++;
    }
}

//przesuniecie wskaznikow wskazujacych na kolejne elementy
void DoubleLinkedList::changePointers(ListElement *pointerNext, ListElement *pointerPrevious, int numberToAdd) {

    pointerPrevious->next = new ListElement();
    pointerPrevious->next->previous = pointerPrevious;
    pointerPrevious = pointerPrevious->next;
    pointerPrevious->number = numberToAdd;
    pointerPrevious->next = pointerNext;
    pointerNext->previous = pointerPrevious;
}

//usuniecie poczatkowego elementu
void DoubleLinkedList::beginDeleteElementToList() {
    if (head != nullptr) {
        ListElement *pointer;
        if (head != tail) {
            pointer = head->next;
            delete head;
            head = pointer;
        } else {
            delete head;
            head = tail = nullptr;
        }
        size--;
    }
}

//usuniecie ostatniego elementu
void DoubleLinkedList::endDeleteElementToList() {
    if (head != nullptr) {
        ListElement *pointer;
        if (head != tail) {
            pointer = tail->previous;
            delete tail;
            tail = pointer;
        } else {
            delete tail;
            head = tail = nullptr;
        }
        size--;
    }
}

//usuniecie elementu o danym indeksie
void DoubleLinkedList::positionDeleteElementToList(int position) {

    if (position >= size || position < 0)
        std::cout << "Bledny indeks" << std::endl;
    else if (position == 0)
        beginDeleteElementToList();
    else if (position == size - 1)
        endDeleteElementToList();
    else {
        int headOrTail = size / 2;      //sprawdzamy czy lepiej jest przesuwac sie po liscie zaczynajac od ogona
        //czy zaczynajac od glowy
        if (headOrTail > position) {
            ListElement *pointerPrevious = head;
            for (int i = 1; i < position; i++) {
                pointerPrevious = pointerPrevious->next;
            }
            ListElement *pointerNext = pointerPrevious->next->next;
            changePointersDelete(pointerNext, pointerPrevious);
        } else {
            ListElement *pointerNext = tail;
            for (int i = size - 2; i > position; i--) {
                pointerNext = pointerNext->previous;
            }
            ListElement *pointerPrevious = pointerNext->previous->previous;
            changePointersDelete(pointerNext, pointerPrevious);
        }
        size--;
    }
}

//przesuniecie wskaznikow wskazujacych na kolejne elementy dla metody usuwania
void DoubleLinkedList::changePointersDelete(ListElement *pointerNext, ListElement *pointerPrevious) {
    delete pointerPrevious->next;
    pointerPrevious->next = pointerNext;
    pointerNext->previous = pointerPrevious;
}

//wyswietlenie listy
void DoubleLinkedList::showList() {
    std::cout << "Lista: [ ";
    if (head != nullptr) {
        ListElement *pointer = head;
        while (pointer != tail) {
            std::cout << pointer->number << " ";
            pointer = pointer->next;
        }
        std::cout << pointer->number;
    }
    std::cout << " ]" << std::endl;
}

//wyswietlenie odwrotnie listy
void DoubleLinkedList::showListReverse() {
    std::cout << "Lista od konca: [ ";
    if (tail != nullptr) {
        ListElement *pointer = tail;
        while (pointer != head) {
            std::cout << pointer->number << " ";
            pointer = pointer->previous;
        }
        std::cout << pointer->number;
    }
    std::cout << " ]" << std::endl;
}

//szukanie okreslonej liczby w liscie
//metoda zwraca indeks liczby
int DoubleLinkedList::findNumber(int numberToFind) {
    ListElement *pointer = head;
    int i = 0;
    while (numberToFind != pointer->number) {
        if (pointer == tail)
            return -1;
        pointer = pointer->next;
        i++;
    }
    return i;
}

//zwracaca element zapisany na podanym indeksie
int DoubleLinkedList::getNumber(int index) {
    if (index >= 0 && index < size) {
        int headOrTail = size / 2;
        //sprawdzamy czy lepiej jest przesuwac sie po liscie zaczynajac od ogona
        //czy zaczynajac od glowy

        ListElement *pointer;


        if (headOrTail > index) {
            pointer = head;
            for (int i = 0; i < index; i++) {
                pointer = pointer->next;
            }
        } else {
            pointer = tail;
            for (int i = size - 1; i > index; i--) {
                pointer = pointer->previous;
            }
        }
        return pointer->number;

    }
    std::cout << "Nie ma takiego indeksu" << std::endl;
    return -1;
}

//wczytanie danych z pliku
void DoubleLinkedList::loadDataFromFile() {


    deleteList();
    LoadFile file;
    int *table = file.getDataFromFile();

    if (table == nullptr) {
        std::cout << "Brak pliku\n";
    } else {
        for (int i = 1; i <= table[0]; i++) {
            endAddElementToList(table[i]);
        }
    }

}

//usuwanie listy
void DoubleLinkedList::deleteList() {
    if(size > 1) {
        ListElement *pointer = tail->previous;
        while (pointer != head) {
            delete pointer->next;
            pointer = pointer->previous;
        }
        delete head;
        head = tail = nullptr;
    } else if(size == 1){
        delete head;
        head = tail = nullptr;
    }
    size = 0;
}

//pobranie rozmiaru listy
int DoubleLinkedList::getSize() {
    return size;
}


