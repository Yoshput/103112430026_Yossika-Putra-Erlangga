#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* First = NULL;

void insertLast(Node*& L, int X) {
    Node* baru = new Node;
    baru->data = X;
    baru->next = NULL;

    if (L == NULL) {
        L = baru;
    } else {
        Node* bantu = L;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

bool searchX(Node* L, int X) {
    Node* bantu = L;
    while (bantu != NULL) {
        if (bantu->data == X)
            return true;
        bantu = bantu->next;
    }
    return false;
}

void deleteCondition(Node*& L, int X) {
    if (L == NULL) {
        cout << "List kosong\n";
        return;
    }

    if (!searchX(L, X)) {
        cout << "Tidak ada elemen bernilai " << X << " dalam list\n";
        return;
    }

    if (L->data == X) {
        Node* hapus = L;
        L = L->next;
        delete hapus;
        cout << "Elemen awal (" << X << ") dihapus.\n";
        return;
    }

    Node* bantu = L;
    while (bantu->next != NULL && bantu->next->data != X) {
        bantu = bantu->next;
    }

    if (bantu->next == NULL) {
        cout << "Tidak ada elemen bernilai X\n";
        return;
    }

    if (bantu->next->next == NULL) {
        Node* hapus = bantu->next;
        bantu->next = NULL;
        delete hapus;
        cout << "Elemen akhir (" << X << ") dihapus.\n";
        return;
    }

    else {
        Node* hapus = bantu->next->next;
        bantu->next->next = hapus->next;
        cout << "Elemen setelah " << X << " (" << hapus->data << ") dihapus.\n";
        delete hapus;
    }
}

void printList(Node* L) {
    Node* bantu = L;
    while (bantu != NULL) {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }
    cout << "NULL\n";
}

int main() {
    insertLast(First, 15);
    insertLast(First, 30);
    insertLast(First, 35);
    insertLast(First, 40);
    insertLast(First, 50);

    cout << "List awal: ";
    printList(First);

    cout << "\nMenghapus elemen setelah 30:\n";
    deleteCondition(First, 30);
    printList(First);

    cout << "\nMenghapus elemen awal (15):\n";
    deleteCondition(First, 15);
    printList(First);

    cout << "\nMenghapus elemen akhir (50):\n";
    deleteCondition(First, 50);
    printList(First);

    return 0;
}
