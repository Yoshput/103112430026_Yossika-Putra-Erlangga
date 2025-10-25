#include "binnary.h"
#include <iostream>
using namespace std;

int main() {
    Node* head = NULL;

    cout << "BINARY SEARCH PADA LINKED LIST" << endl;

    // Buat linked list terurut
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    printList(head);

    // Pencarian pertama
    int cari1 = 40;
    cout << "Mencari nilai: " << cari1 << endl;
    binarySearch(head, cari1);

    cout << "\n------------------------------------------\n" << endl;

    // Pencarian kedua
    int cari2 = 25;
    cout << "Mencari nilai: " << cari2 << endl;
    binarySearch(head, cari2);

    return 0;
}
