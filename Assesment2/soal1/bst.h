#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left;
    Node *right;
};

typedef Node *adrNode;

void createTree(adrNode &root);
bool isEmpty(adrNode root);
adrNode newNode(string nama, float berat, string tier);
void insertNode(adrNode &root, adrNode P);
adrNode searchByBeratBadan(adrNode root, float berat);
adrNode findParent(adrNode root, float berat);
adrNode mostLeft(adrNode root);
adrNode mostRight(adrNode root);
void inOrder(adrNode root);

#endif