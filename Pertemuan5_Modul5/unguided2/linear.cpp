#include "linear.h"

// Membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Menambah node di akhir
void append(Node* &head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Menampilkan seluruh isi linked list
void printList(Node* head) {
    Node* temp = head;
    cout << "Linked List yang dibuat: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Linear Search dengan tampilan langkah pencarian
Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:" << endl;
    Node* current = head;
    int index = 1;

    while (current != NULL) {
        cout << "Langkah " << index++ << ": Periksa node dengan data = " << current->data 
             << " (alamat: " << current << ")";

        if (current->next != NULL)
            cout << " | Node berikutnya: " << current->next->data;
        else
            cout << " | Node berikutnya: NULL";
        cout << endl;

        if (current->data == key) {
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << current << endl;
            cout << "Data node: " << current->data << endl;
            return current;
        }
        current = current->next;
    }

    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return NULL;
}
