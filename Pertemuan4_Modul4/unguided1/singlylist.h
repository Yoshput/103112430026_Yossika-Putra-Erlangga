#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;
};

bool isEmpty(List L);
void createList(List &L);
Node* alokasi(int nilai);
void dealokasi(Node* &P);
void insertFirst(List &L, Node* P);
void insertAfter(Node* Prec, Node* P);
void insertLast(List &L, Node* P);
void printList(List L);

#endif
