#include "bstree.h"

Node* alokasi(infotype x) {
    Node* newNode = new Node;
    newNode->info = x;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insertNode(Node*& root, infotype x) {
    if (root == nullptr) {
        root = alokasi(x);  
    } else if (x < root->info) {
        insertNode(root->left, x); 
    } else if (x > root->info) {
        insertNode(root->right, x);  
    }
}

void findNode(Node* root, infotype x) {
    if (root == nullptr) {
        cout << "Data " << x << " tidak ditemukan." << endl;
    } else if (x < root->info) {
        findNode(root->left, x);  
    } else if (x > root->info) {
        findNode(root->right, x);  
    } else {
        cout << "Data " << x << " ditemukan." << endl;
    }
}

void printInOrder(Node* root) {
    if (root != nullptr) {
        printInOrder(root->left);  
        cout << root->info << " - ";  
        printInOrder(root->right); 
    }
}


bool isEmpty(Node* root) {
    return root == nullptr;
}
