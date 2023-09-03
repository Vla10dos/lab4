#include "BinaryTree.h"
#include <cassert>

using namespace std;

// testing insertion, delete, traversals and print keys
void tests(){
    bool flag = true;
    int ind = 0;
    int* ar = new int[5]{50, 60, 79, 80, 90};
    BinaryTree<int>* tree = new BinaryTree<int>(0, 50);
    tree -> insert(tree, 1, 30);
    tree -> insert(tree, 2, 40);
    tree -> insert(tree, 3, 60);
    tree -> insert(tree, 4, 79);
    tree -> insert(tree, 5, 80);
    tree -> insert(tree, 6, 90);
    tree -> deleteNodeByKey(tree, 1);
    tree -> deleteNodeByKey(tree, 2);
    BinaryTree<int>* curr = tree;
    while (curr != nullptr && ind < 5) {
        assert(ar[ind] == curr->getValue());
        curr = curr->getLeft();
        if (curr == nullptr) {
            curr = tree->getRight();
            tree = tree->getRight();
        }
        ind++;
    }
    
}

void test() {
    bool flag = true;
    int ind = 0;
    int* ar = new int[4]{60, 79, 80, 90};
    BinaryTree<int>* tree = new BinaryTree<int>(0, 50);
    tree->deleteNodeByKey(tree, 1);
    tree->insert(tree, 1, 30);
    tree->insert(tree, 2, 40);
    tree->insert(tree, 3, 60);
    tree->insert(tree, 4, 79);
    tree->insert(tree, 5, 80);
    tree->insert(tree, 6, 90);
   

    BinaryTree<int>* subtree = tree->SubTree(tree, 3);
    BinaryTree<int>* curr = subtree;
    while (curr != nullptr && ind < 4) {
        assert(ar[ind] == curr->getValue());
        curr = curr->getLeft();
        if (curr == nullptr) {
            curr = subtree->getRight();
            subtree = subtree->getRight();
        }
        ind++;
    }
}

int main(){
    tests();
    test();
    cout << "\t\t\t\t\t\t\033[32mALL TESTS HAVE BEEN SUCCESSFULLY VERIFIED\033[0m\n";
    return 0;
}
