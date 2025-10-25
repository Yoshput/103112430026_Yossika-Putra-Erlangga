#ifndef LISTBUAH_H
#define LISTBUAH_H

#define Nil NULL
#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address;

struct node {
    dataBuah isidata;
    address next;
};

struct linkedlist {
    address first;
};

// ==== DEKLARASI / PROTOTYPE ====
bool isEmpty(linkedlist List);
void createList(linkedlist &List);

address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void printList(linkedlist List);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// === Fungsi update data ===
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address nodePrev);

#endif
