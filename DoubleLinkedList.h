

#ifndef SDIZO1_DOUBLELINKEDLIST_H
#define SDIZO1_DOUBLELINKEDLIST_H


class DoubleLinkedList {
private:

    struct ListElement {
        int number;
        ListElement *previous;
        ListElement *next;
    };

    ListElement *head = nullptr;
    ListElement *tail = nullptr;
    int size = 0;

    bool headIsNotNULL(int numberToAdd);

    static void changePointers(ListElement *pointerNext, ListElement *pointerPrevious, int numberToAdd);

    static void changePointersDelete(ListElement *pointerNext, ListElement *pointerPrevious);

public:
    ~DoubleLinkedList() { deleteList(); }

    void endAddElementToList(int numberToAdd);

    void beginAddElementToList(int numberToAdd);

    void positionAddElementToList(int numberToAdd, int position);

    void beginDeleteElementToList();

    void endDeleteElementToList();

    void positionDeleteElementToList(int position);

    void showList();

    void showListReverse();

    int findNumber(int numberToFind);

    int getNumber(int index);

    void loadDataFromFile();

    void deleteList();

    int getSize();
};


#endif //SDIZO1_DOUBLELINKEDLIST_H
