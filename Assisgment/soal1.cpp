#include <iostream>
#include <string>
using namespace std;

    struct Node {
    string nama;
    Node *next;
};

    Node *head = NULL;

    void insertAkhir(string x) {
    Node *baru = new Node;
    baru->nama = x;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
        return;
    }

    Node *p = head;
    while (p->next != NULL) p = p->next;
    p->next = baru;


    }

    void deleteNama(string x) {
    if (head == NULL) return;

    Node *p = head;
    Node *prev = NULL;

    while (p != NULL && p->nama != x) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) return;
    if (prev == NULL) head = head->next;
    else prev->next = p->next;

    delete p;


    }

    void viewList() {
    Node *p = head;
    while (p != NULL) {
    cout << p->nama << " ";
    p = p->next;
    }
    cout << endl;
    }

    int hitungGenap() {
    int total = 0;
    Node *p = head;
    while (p != NULL) {
    int len = p->nama.length();
    if (len % 2 == 0) total++;
    p = p->next;
    }
    return total;
    }

        int main() {
        int menu;
        string x;

        do {
            cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
            cin >> menu;

        if (menu == 1) {
            cout << "Masukkan nama: ";
            cin >> x;
            insertAkhir(x);
        }
        if (menu == 2) {
            cout << "Masukkan nama untuk delete: ";
            cin >> x;
            deleteNama(x);
        }
        if (menu == 3) viewList();
        if (menu == 4) {
            cout << "Jumlah nama dengan huruf genap: "
                << hitungGenap() << endl;
            }

        } while (menu != 0);

        return 0;

    

}