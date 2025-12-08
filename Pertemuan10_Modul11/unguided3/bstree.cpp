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

void printPreOrder(Node* root) {
    if (root != nullptr) {
        cout << root->info << " ";
        printPreOrder(root->left); 
        printPreOrder(root->right); 
    }
}

void printPostOrder(Node* root) {
    if (root != nullptr) {
        printPostOrder(root->left);  
        printPostOrder(root->right);  
        cout << root->info << " ";  
    }
}

bool isEmpty(Node* root) {
    return root == nullptr;
}
