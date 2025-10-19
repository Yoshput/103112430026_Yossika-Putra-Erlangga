#include "Singlylist.h"
#include <iostream>
using namespace std;

bool isEmpty(List L) {
    return (L.first == Nil);
}

void createList(List &L) {
    L.first = Nil;
}

Node* alokasi(int nilai) {
    Node* P = new Node;
    P->data = nilai;
    P->next = Nil;
    return P;
}

void dealokasi(Node* &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, Node* P) {
    P->next = L.first;
    L.first = P;
}

void insertAfter(Node* Prec, Node* P) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, Node* P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        Node* Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void printList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        Node* P = L.first;
        while (P != Nil) {
            cout << P->data << " ";
            P = P->next;
        }
        cout << endl;
    }
}
