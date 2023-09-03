#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

template <typename T>
void treeMenu() {
    int key;
    T value;
    BinaryTree<T>* tree = new BinaryTree<T>();
    BinaryTree<T>* node;
    BinaryTree<T>* subtree;
    tree = tree -> deleteNodeByKey(tree, 0);
    int choice;
    cout << "Press CTRL + D to exit" << endl;
    cout << "\t\t\t\t\t\t\033[32mInsert a node - 1\033[0m\n";
    cout << "\t\t\t\t\t\t\033[32mSearch for a node - 2\033[0m\n";
    cout << "\t\t\t\t\t\t\033[32mDelete a node by key - 3\033[0m\n";
    cout << "\t\t\t\t\t\t\033[32mPrint keys - 4\033[0m\n";
    cout << "\t\t\t\t\t\t\033[32mTraverse the tree in pre-order - 5(KLR)\033[0m\n";
    cout << "\t\t\t\t\t\t\033[32mTraverse the tree in post-order - 6(LRK)\033[0m\n";
    cout << "\t\t\t\t\t\t\033[32mTraverse the tree in in-order - 7(LKR)\033[0m\n";
    cout << "\t\t\t\t\t\t\033[32mCreate a subtree - 8\033[0m\n";
    cout << "Enter your choice: ";
    cout << endl;
    while(cin >> choice) {
        if (cin.eof()) exit(0);

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree = tree->insert(tree, value);
                cout << endl;
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                node = tree->search(tree, key);
                if (node != nullptr) {
                    cout << "Your node: " << node->getValue() << endl;
                } else {
                    cout << "\033[31mNode with a key not found.\033[0m" << endl;
                }
                cout << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                tree->deleteNodeByKey(tree, key);
                cout << endl;
                break;
            case 4:
                cout << "Keys: ";
                tree->printKeys(tree);
                cout << endl << endl;
                break;
            case 5:
                cout << "Pre-order traversal: ";
                tree->preOrderTraversal(tree);
                cout << endl << endl;
                break;
            case 6:
                cout << "Post-order traversal: ";
                tree->postOrderTraversal(tree);
                cout << endl << endl;
                break;
            case 7:
                cout << "In-order traversal: ";
                tree->inOrderTraversal(tree);
                cout << endl << endl;
                break;
            case 8:
                cout << "Enter key to create a subtree: ";
                cin >> key;
                subtree = tree->SubTree(tree, key);
                if (subtree != nullptr) {
                    cout << "Subtree created successfully." << endl;
                    cout << "Subtree keys: ";
                    subtree->printKeys(subtree);
                    cout << endl;
                    cout << "Subtree values: ";
                    subtree -> inOrderTraversal(subtree);
                } else {
                    cout << "\033[31mSubtree creation failed\033[0m" << endl;
                }
                cout << endl << endl;
                break;
            default:
                cout << "\033[31mERROR!\033[0m\n";
                break;
        }
        cout << "\t\t\t\t\t\t\033[32mInsert a node - 1\033[0m\n";
        cout << "\t\t\t\t\t\t\033[32mSearch for a node - 2\033[0m\n";
        cout << "\t\t\t\t\t\t\033[32mDelete a node by key - 3\033[0m\n";
        cout << "\t\t\t\t\t\t\033[32mPrint keys - 4\033[0m\n";
        cout << "\t\t\t\t\t\t\033[32mTraverse the tree in pre-order - 5(KLR)\033[0m\n";
        cout << "\t\t\t\t\t\t\033[32mTraverse the tree in post-order - 6(LRK)\033[0m\n";
        cout << "\t\t\t\t\t\t\033[32mTraverse the tree in in-order - 7(LKR)\033[0m\n";
        cout << "\t\t\t\t\t\t\033[32mCreate a subtree - 8\033[0m\n";
        cout << "Enter your choice: ";

    }
}

int menu(){
    int choice;
    if (cin.eof()) exit(0);
    cout << "\nChoose your data type\n\n";
    cout << "1. int tree" << endl;
    cout << "2. double tree" << endl;
    cout << "3. string tree" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            treeMenu<int>();
            break;
        case 2:
            treeMenu<double>();
            break;
        case 3:
            treeMenu<string>();
            break;
    }
    return 0;
}
