#ifndef BINNARY_H
#define BINNARY_H

#include <iostream>
using namespace std;

// Struktur node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Prototipe fungsi
Node* createNode(int value);
void append(Node* &head, int value);
void printList(Node* head);
Node* getMiddle(Node* start, Node* end);
Node* binarySearch(Node* head, int key);

#endif
