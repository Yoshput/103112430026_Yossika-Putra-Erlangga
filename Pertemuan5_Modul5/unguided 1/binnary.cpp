#include "binnary.h"

// Membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Menambahkan node di akhir (append)
void append(Node* &head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Menampilkan isi linked list
void printList(Node* head) {
    Node* temp = head;
    cout << "Linked List yang dibuat: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Mendapatkan node tengah antara dua node
Node* getMiddle(Node* start, Node* end) {
    if (start == NULL)
        return NULL;

    Node* slow = start;
    Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

// Binary Search dengan tampilan langkah pencarian
Node* binarySearch(Node* head, int key) {
    Node* start = head;
    Node* end = NULL;
    int iterasi = 1;

    cout << "\nProses Pencarian:" << endl;

    while (start != end) {
        Node* mid = getMiddle(start, end);
        if (mid == NULL)
            return NULL;

        cout << "Iterasi " << iterasi++ << ": Mid = " << mid->data;

        if (mid->data == key) {
            cout << " (indeks tengah) - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << mid << endl;
            cout << "Data node: " << mid->data << endl;
            if (mid->next != NULL)
                cout << "Node berikutnya: " << mid->next->data << endl;
            else
                cout << "Node berikutnya: NULL" << endl;
            return mid;
        }
        else if (mid->data < key) {
            cout << " (indeks tengah) -> Cari di bagian kanan" << endl;
            start = mid->next;
        }
        else {
            cout << " (indeks tengah) -> Cari di bagian kiri" << endl;
            end = mid;
        }
    }

    cout << "Tidak ada elemen tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return NULL;
}
