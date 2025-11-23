#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0;
}

bool isFull(Queue Q) {
    return Q.count == MAX;
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        Q.info[Q.tail] = x;
        Q.tail = (Q.tail + 1) % MAX;
        Q.count++;
    }
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        int x = Q.info[Q.head];
        Q.head = (Q.head + 1) % MAX;
        Q.count--;
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " : ";
    if (isEmpty(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int index = Q.head;
    for (int i = 0; i < Q.count; i++) {
        cout << Q.info[index] << " ";
        index = (index + 1) % MAX;
    }
    cout << endl;
}
