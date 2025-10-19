#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    Node *P1, *P2, *P3, *P4, *P5;
    P1 = alokasi(1);
    P2 = alokasi(9);
    P3 = alokasi(8);
    P4 = alokasi(2);
    P5 = alokasi(0);

    insertFirst(L, P1);   // 1
    insertAfter(P1, P2);  // 1 -> 9
    insertAfter(P2, P3);  // 1 -> 9 -> 8
    insertAfter(P3, P4);  // 1 -> 9 -> 8 -> 2
    insertLast(L, P5);    // 1 -> 9 -> 8 -> 2 -> 0

    cout << "Isi Linked List: ";
    printList(L);

    return 0;
}
