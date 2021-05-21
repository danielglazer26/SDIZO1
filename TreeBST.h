
#ifndef SDIZO1_TREEBST_H
#define SDIZO1_TREEBST_H


class TreeBST {
private:
    std::string cr, cl, cp;

    int n = 0;

    struct TreeElement {
        TreeElement(int numberToAdd) { number = numberToAdd; }

        int number;
        TreeElement *left = nullptr;
        TreeElement *right = nullptr;
        TreeElement *up = nullptr;
    };

    TreeElement *root = nullptr;

    void addElementDeeper(TreeElement *pointer, int numberToAdd);

    void createLinearList();

    void balanceRotation(int numberOfRotation);

    void showTree(std::string sp, std::string sn, TreeElement *v);

    void deleteTree(TreeElement *pointer);

public:


    TreeBST() {
        cr = cl = cp = "  ";
        cr[0] = 218;
        cr[1] = 196;
        cl[0] = 192;
        cl[1] = 196;
        cp[0] = 179;
    }

    ~TreeBST() { deleteTree(); }

    void addElementToBST(int numberToAdd);

    void rotationRight(TreeElement *pointer);

    void rotationLeft(TreeElement *pointer);

    void balanceTree();

    TreeElement *findElementBST(int numberToFind);

    void showTree();

    void deleteTree();

    void deleteElementFromTree(int elementToDelete);

    void loadDataFromFile();
};


#endif //SDIZO1_TREEBST_H
