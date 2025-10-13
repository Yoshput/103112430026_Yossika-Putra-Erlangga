#include <iostream>
using namespace std;

struct Node {
    float data;
    Node* next;
};

Node* L = NULL;

void createList(Node*& L) {
    L = NULL;
}

Node* createElement(float X) {
    Node* elm = new Node;
    elm->data = X;
    elm->next = NULL;
    return elm;
}

void insertAscending(Node*& L, Node* elm) {
    if (L == NULL || elm->data < L->data) {
        elm->next = L;
        L = elm;
    } else {
        Node* bantu = L;
        while (bantu->next != NULL && bantu->next->data < elm->data) {
            bantu = bantu->next;
        }
        elm->next = bantu->next;
        bantu->next = elm;
    }
}

void printList(Node* L) {
    Node* bantu = L;
    while (bantu != NULL) {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }
    cout << "NULL" << endl;
}

int main() {
    createList(L);

    insertAscending(L, createElement(10.5));
    insertAscending(L, createElement(12.0));
    insertAscending(L, createElement(20.9));
    insertAscending(L, createElement(25.1));

    cout << "List awal:" << endl;
    printList(L);

    cout << "\nMenambahkan data 15.5:" << endl;
    insertAscending(L, createElement(15.5));
    printList(L);

    return 0;
}
