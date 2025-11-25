#include <iostream>
using namespace std;

struct Node {
int nilai;
Node *prev;
Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertAkhir(int x) {
Node *baru = new Node;
baru->nilai = x;
baru->prev = NULL;
baru->next = NULL;

if (head == NULL) {
    head = tail = baru;
    return;
}

tail->next = baru;
baru->prev = tail;
tail = baru;


}

void deleteAkhir() {
if (head == NULL) return;

if (head == tail) {
    delete head;
    head = tail = NULL;
    return;
}

Node *hapus = tail;
tail = tail->prev;
tail->next = NULL;
delete hapus;


}

    void viewDepan() {
        Node *p = head;
            while (p != NULL) {
            cout << p->nilai << " ";
            p = p->next;
            }
        cout << endl;
}

void reverseList() {
Node *p = head;
Node *temp = NULL;

while (p != NULL) {
    temp = p->prev;
    p->prev = p->next;
    p->next = temp;
    p = p->prev;
}

if (temp != NULL) {
    head = temp->prev;
    tail = temp;
}


}

int main() {
int menu;
int x;

do {
    cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit\n";
    cin >> menu;
    if (menu == 1) {
        cout << "Masukkan nilai: ";
        cin >> x;
        insertAkhir(x);
    }

    if (menu == 2) deleteAkhir();
    if (menu == 3) viewDepan();

    if (menu == 4) {
        reverseList();
        cout << "List setelah di-reverse: ";
        viewDepan();
    }

} while (menu != 0);

return 0;


}