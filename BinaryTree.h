#include <iostream>

using namespace std;

template <typename T>
class BinaryTree{

    int key;
    T value;
    BinaryTree* left;
    BinaryTree* right;

public:
    BinaryTree() {
        left = nullptr;
        right = nullptr;
    }
    
    BinaryTree(int k, T v) {
        key = k;
        value = v;
        left = NULL;
        right = NULL;
    }
    
    ~BinaryTree() {
        if (left != NULL) {
            delete left;
            left = NULL;
        }
        if (right != NULL) {
            delete right;
            right = NULL;
        }
    }
    
    int getKey (){
        return this -> key;
    }
    
    void setKey(BinaryTree* node, int key) {
        node->key = key;
    }

    T getValue (){
        return this->value;
    }
    
    void setValue(BinaryTree* node, T value) {
        node->value = value;
    }
    
    BinaryTree* getLeft() {
        return left;
    }

    BinaryTree* getRight() {
        return right;
    }
    
    void setLeft(BinaryTree<T>* node) {
        this->left = node;
    }

    void setRight(BinaryTree<T>* node) {
        this->right = node;
    }
    bool containsKey(BinaryTree<T>* root, int key) {
        if (root == nullptr) {
                return false;
        }
        if (root->key == key) {
                return true;
        }
        return containsKey(root->left, key) || containsKey(root->right, key);
    }
        
    template <typename U = T>
    BinaryTree<T>* insert(BinaryTree<T>* root, U value) {
        if constexpr (std::is_same_v<U, int>) {
            int key = value;
            return insert(root, key, value);
        }
        else if constexpr (std::is_same_v<U, double>) {
            int key = static_cast<int>(value);
            return insert(root, key, value);
        } 
        else if constexpr (std::is_same_v<U, string>) {
            int key = 0;
            for (char c : value) {
                key += static_cast<int>(c);
            }
            return insert(root, key, value);
        } 
        else {
            return nullptr;
        }
    }

        BinaryTree<T>* insert(BinaryTree<T>* root, int key, T value) {
            if (root == nullptr) {
                return new BinaryTree<T>(key, value);
            }

            if (key < root->key) {
                if (root->left == nullptr) {
                    root->left = new BinaryTree<T>(key, value);
                } 
                else {
                    root->left = insert(root->left, key, value);
                }
            } 
            else if (key > root->key) {
                if (root->right == nullptr) {
                    root->right = new BinaryTree<T>(key, value);
                } 
                else {
                    root->right = insert(root->right, key, value);
                }
            } 
            else {
                root->value = value;
            }
            return root;
        }

    BinaryTree* search(BinaryTree* root, int key) {
        if (root == NULL || root->key == key) {
            return root;
        }

        if (key < root->key) {
            return search(root->left, key);
        }
        
        else {
            return search(root->right, key);
        }
    }
    
    BinaryTree<T>* deleteNodeByKey(BinaryTree<T>*& root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (key < root->key) {
            root->left = deleteNodeByKey(root->left, key);
        } 
        else if (key > root->key) {
            root->right = deleteNodeByKey(root->right, key);
        } 
        else {
            if (root->left == nullptr && root->right == nullptr) {
                // Проверяем, является ли root последним элементом в дереве
                if (root->left == nullptr && root->right == nullptr) {
                    delete root;
                    root = nullptr;
                }
            } else if (root->left == nullptr) {
                BinaryTree<T>* temp = root->right;
                root->right = nullptr;
                delete root;
                root = temp;
            } else if (root->right == nullptr) {
                BinaryTree<T>* temp = root->left;
                root->left = nullptr;
                delete root;
                root = temp;
            } else {
                BinaryTree<T>* temp = findMin(root->right);
                root->key = temp->key;
                root->value = temp->value;
                root->right = deleteNodeByKey(root->right, temp->key);
            }
        }
        return root;
    }
    
    BinaryTree* findMin(BinaryTree* node) {
        BinaryTree* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    void preOrderTraversal(BinaryTree* root) { // root-left-right
        if (root != NULL) {
            cout << root -> value << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }

    void postOrderTraversal(BinaryTree* root) { // left-right-root
        if (root != NULL) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->value << " ";
        }
    }

    void inOrderTraversal(BinaryTree* root) {  // left-root-right
        if (root != NULL) {
            inOrderTraversal(root->left);
            cout << root->value << " ";
            inOrderTraversal(root->right);
        }
    }
    
    void printKeys(BinaryTree<T>* root) {
        if (root == NULL) {
            return;
        }
        
        printKeys(root->left);
        cout << root->key << " ";
        printKeys(root->right);
    }
    
    BinaryTree<T>* SubTree(BinaryTree<T>* root, int key) {
        BinaryTree<T>* subtreeRoot = search(root, key);
        if (subtreeRoot == nullptr) {
            return nullptr;
        }
        BinaryTree<T>* leftSubtree = subtreeRoot->getLeft();
        BinaryTree<T>* rightSubtree = subtreeRoot->getRight();
        BinaryTree<T>* newSubtreeRoot = new BinaryTree<T>(subtreeRoot->getKey(), subtreeRoot->getValue());
        if (leftSubtree != nullptr) {
            BinaryTree<T>* newLeftSubtree = copyTree(leftSubtree);
            newSubtreeRoot->setLeft(newLeftSubtree);
        }
        if (rightSubtree != nullptr) {
            BinaryTree<T>* newRightSubtree = copyTree(rightSubtree);
            newSubtreeRoot->setRight(newRightSubtree);
        }
        return newSubtreeRoot;
    }
    
    BinaryTree<T>* copyTree(BinaryTree<T>* root) {
        if (root == nullptr) {
            return nullptr;
        }
        BinaryTree<T>* newRoot = new BinaryTree<T>(root->getKey(), root->getValue());
        newRoot->setLeft(copyTree(root->getLeft()));
        newRoot->setRight(copyTree(root->getRight()));
        return newRoot;
    }
};



