#include "linear.h"
#include <iostream>
using namespace std;

int main() {
    Node* head = NULL;

    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;

    // Membuat linked list (tidak harus terurut)
    append(head, 45);
    append(head, 20);
    append(head, 60);
    append(head, 10);
    append(head, 30);

    printList(head);

    // Pencarian pertama (ditemukan)
    int cari1 = 60;
    cout << "Mencari nilai: " << cari1 << endl;
    linearSearch(head, cari1);

    cout << "\n------------------------------------------\n" << endl;

    // Pencarian kedua (tidak ditemukan)
    int cari2 = 25;
    cout << "Mencari nilai: " << cari2 << endl;
    linearSearch(head, cari2);

    return 0;
}
