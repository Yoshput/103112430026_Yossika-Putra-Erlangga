#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambah elemen di akhir list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head)
        head = newNode; 
    else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Fungsi untuk mendapatkan node ke-n (0-based index)
Node* getNode(Node* head, int index) {
    for (int i = 0; i < index && head; i++)
        head = head->next;
    return head;
}

// Fungsi binary search di linked list (asumsi list sudah terurut naik)
Node* binarySearch(Node* head, int key) {
    // Hitung panjang list
    int size = 0;
    for (Node* current = head; current; current = current->next)
        size++;

    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        Node* midNode = getNode(head, mid);

        if (!midNode) return nullptr;

        if (midNode->data == key)
            return midNode;
        else if (midNode->data < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return nullptr;
}

int main() {
    Node* head = nullptr;

    // Buat list terurut
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    // Cari elemen
    Node* result = binarySearch(head, 40);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
