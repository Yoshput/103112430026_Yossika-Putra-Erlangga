#include <iostream>
using namespace std;

#define MAXQ 100

// Struktur data Queue
struct Queue {
    int data[MAXQ];
    int front;
    int rear;
};

// Membuat queue kosong
Queue createQueue() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

// Mengecek apakah queue kosong
bool isEmpty(Queue q) {
    return (q.front == -1 && q.rear == -1);
}

// Mengecek apakah queue penuh
bool isFull(Queue q) {
    return (q.rear == MAXQ - 1);
}

// Menambahkan data ke antrian
void enqueue(Queue &q, int value) {
    if (isFull(q)) {
        cout << " Queue penuh!\n";
    } else {
        if (isEmpty(q)) {
            q.front = 0;
        }
        q.rear++;
        q.data[q.rear] = value;
        cout << "➡ Data " << value << " masuk ke antrian.\n";
    }
}

// Mengeluarkan data dari antrian
void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << " Queue kosong!\n";
    } else {
        cout << "⬅ Data " << q.data[q.front] << " keluar dari antrian.\n";
        if (q.front == q.rear) {
            q.front = q.rear = -1; // Reset
        } else {
            q.front++;
        }
    }
}

// Menampilkan isi antrian
void tampilQueue(Queue q) {
    cout << "\n=== Isi Antrian ===\n";
    if (isEmpty(q)) {
        cout << "Antrian kosong.\n";
    } else {
        for (int i = q.front; i <= q.rear; i++) {
            cout << q.data[i] << " ";
        }
        cout << endl;
    }
    cout << "===================\n";
}

int main() {
    Queue q = createQueue();

    // Tambah data ke antrian
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Tampilkan isi antrian
    tampilQueue(q);

    // Keluarkan satu data dari antrian
    dequeue(q);

    // Tampilkan isi antrian setelah dequeue
    tampilQueue(q);

    return 0;
}