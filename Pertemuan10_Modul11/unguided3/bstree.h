#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;  

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

Node* alokasi(infotype x);
void insertNode(Node*& root, infotype x);
void printPreOrder(Node* root);
void printPostOrder(Node* root);
void printInOrder(Node* root);
bool isEmpty(Node* root);

#endif
