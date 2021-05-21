#include <iostream>
#include "TreeBST.h"
#include "LoadFile.h"
#include <cmath>

//dodanie elementow do drzewa
void TreeBST::addElementToBST(int numberToAdd) {

    n++;
    if (root == nullptr)
        root = new TreeElement(numberToAdd);
    else
        addElementDeeper(root, numberToAdd);
}

//dodawnie na glebszych poziomach elementow do drzewa
void TreeBST::addElementDeeper(TreeElement *pointer, int numberToAdd) {

    if (numberToAdd >= pointer->number) {
        if (pointer->right == nullptr) {
            pointer->right = new TreeElement(numberToAdd);
            pointer->right->up = pointer;
        } else
            addElementDeeper(pointer->right, numberToAdd);
    } else {
        if (pointer->left == nullptr) {
            pointer->left = new TreeElement(numberToAdd);
            pointer->left->up = pointer;
        } else
            addElementDeeper(pointer->left, numberToAdd);
    }
}

//obrot wezla w prawo
void TreeBST::rotationRight(TreeBST::TreeElement *pointer) {

    if (pointer != nullptr) {
        if (pointer->left != nullptr) {
            TreeElement *secondPointer = pointer->left;

            secondPointer->up = pointer->up;
            pointer->left = secondPointer->right;
            if (pointer->left != nullptr)
                pointer->left->up = pointer;
            pointer->up = secondPointer;
            secondPointer->right = pointer;

            if (pointer == root) {
                root = secondPointer;
            } else {
                if (secondPointer->up->right == pointer)
                    secondPointer->up->right = secondPointer;
                else
                    secondPointer->up->left = secondPointer;
            }
        }
    }
}

//obrot wezla w lewo
void TreeBST::rotationLeft(TreeBST::TreeElement *pointer) {

    if (pointer != nullptr) {
        if (pointer->right != nullptr) {
            TreeElement *secondPointer = pointer->right;

            secondPointer->up = pointer->up;
            pointer->right = secondPointer->left;
            if (pointer->right != nullptr)
                pointer->right->up = pointer;
            pointer->up = secondPointer;
            secondPointer->left = pointer;

            if (pointer == root) {
                root = secondPointer;
            } else {
                if (secondPointer->up->right == pointer)
                    secondPointer->up->right = secondPointer;
                else
                    secondPointer->up->left = secondPointer;
            }
        }
    }
}

//rownowazenie drzewa
void TreeBST::balanceTree() {

    if (n > 0) {
        createLinearList();                                         //tworzymy liste liniowa

        int numberOfRotation = (int) (pow(2, (int) (log2(n + 1))) - 1); //obliczamy ilosc rotacji
        balanceRotation(n - numberOfRotation);

        while (numberOfRotation > 1) {                                  //obracamy okreslona ilosc wezlow
            numberOfRotation = (int) (numberOfRotation / 2);
            balanceRotation(numberOfRotation);
        }
    }
}

//odpowiada za odpowiednia ilosc obrotow, aby mozna bylo zrownowazyc drzewo
void TreeBST::balanceRotation(int numberOfRotation) {

    TreeElement *pointer = root;

    for (int i = 0; i < numberOfRotation; i++) {
        rotationLeft(pointer);
        pointer = pointer->up->right;
    }
}

//tworzenie listy liniowej
void TreeBST::createLinearList() {

    TreeElement *pointer = root;

    while (true) {
        if (pointer->left == nullptr && pointer->right == nullptr) {
            break;
        } else if (pointer->left != nullptr) {
            rotationRight(pointer);
            pointer = pointer->up;
        } else {
            pointer = pointer->right;
        }
    }
}

//wyszukiwanie wezla z podana liczba
TreeBST::TreeElement *TreeBST::findElementBST(int numberToFind) {
    if (root != nullptr) {
        TreeElement *pointer = root;
        while (true) {
            if (pointer->number > numberToFind) {
                if (pointer->left != nullptr)
                    pointer = pointer->left;
                else
                    return nullptr;
            } else if (pointer->number < numberToFind) {
                if (pointer->right != nullptr)
                    pointer = pointer->right;
                else
                    return nullptr;
            } else
                return pointer;
        }
    }

}

//wyswietlanie drzewa
//wyswietlanie zaimplementowane na podstawie https://eduinf.waw.pl
void TreeBST::showTree(std::string sp, std::string sn, TreeElement *pointer) {

    std::string s;

    if (pointer) {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        showTree(s + cp, cr, pointer->right);

        s = s.substr(0, sp.length() - 2);
        std::cout << s << sn << pointer->number << std::endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        showTree(s + cp, cl, pointer->left);
    }
}

//wywolanie metody do wyswietlenia drzewa z parametrami wejsciowymi
void TreeBST::showTree() {
    showTree("", "", root);
}

//usuwanie wezla z drzewa
void TreeBST::deleteElementFromTree(int elementToDelete) {

    TreeElement *pointer = findElementBST(elementToDelete);

    if (pointer != nullptr) {
        n--;
        //usuwanie liscia
        if (pointer->left == nullptr && pointer->right == nullptr) {
            if (pointer == root) {
                root = nullptr;
            } else {
                if (pointer->up->right == pointer)
                    pointer->up->right = nullptr;
                else
                    pointer->up->left = nullptr;
            }
            delete pointer;

            //usuwanie rodzica, który ma tylko prawego syna
        } else if (pointer->left == nullptr) {
            if (pointer == root) {
                pointer->right->up = nullptr;
                root = pointer->right;

            } else {
                if (pointer->up->right == pointer)
                    pointer->up->right = pointer->right;
                else
                    pointer->up->left = pointer->right;
                pointer->right->up = pointer->up;
            }
            delete pointer;
            //usuwanie rodzica, który ma tylko lewego syna
        } else if (pointer->right == nullptr) {
            if (pointer == root) {
                pointer->left->up = nullptr;
                root = pointer->left;
            } else {
                if (pointer->up->right == pointer)
                    pointer->up->right = pointer->left;
                else
                    pointer->up->left = pointer->left;
                pointer->left->up = pointer->up;
            }
            delete pointer;

            //usuwanie rodzica, który ma dwóch synów
        } else {
            TreeElement *secondPointer = pointer->right;
            while (secondPointer->left != nullptr) {
                secondPointer = secondPointer->left;
            }
            if (pointer->right == secondPointer) {
                pointer->right = secondPointer->right;
                if (secondPointer->right != nullptr)
                    secondPointer->right->up = pointer;
            } else {
                if (secondPointer->right == nullptr) {
                    secondPointer->up->left = nullptr;
                } else {
                    secondPointer->right->up = secondPointer->up;
                    secondPointer->up->left = secondPointer->right;
                }
            }
            pointer->number = secondPointer->number;

            delete secondPointer;
        }
    } else
        std::cout << "Brak elementu do usuniecia" << std::endl;
}

//usuwanie calego drzewa
void TreeBST::deleteTree(TreeElement *pointer) {

    if (pointer) {
        deleteTree(pointer->left);
        deleteTree(pointer->right);
        delete pointer;
    }
    root = nullptr;
    n = 0;
}

//wywolanie metody usuwania drzewa z parametrem
void TreeBST::deleteTree() {
    deleteTree(root);
}

//wczytujemy dane z pliku
void TreeBST::loadDataFromFile() {

    deleteTree();

    LoadFile file;
    int *fileTable = file.getDataFromFile();

    if (fileTable == nullptr)
        std::cout << "Brak pliku" << std::endl;
    else {
        for (int i = 1; i <= fileTable[0]; i++) {
            addElementToBST(fileTable[i]);
        }
    }

}



