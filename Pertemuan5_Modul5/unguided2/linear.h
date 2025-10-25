#ifndef LINEAR_H
#define LINEAR_H

#include <iostream>
using namespace std;

// Struktur Node Linked List
struct Node {
    int data;
    Node* next;
};

// Fungsi dasar
Node* createNode(int value);
void append(Node* &head, int value);
void printList(Node* head);
Node* linearSearch(Node* head, int key);

#endif
