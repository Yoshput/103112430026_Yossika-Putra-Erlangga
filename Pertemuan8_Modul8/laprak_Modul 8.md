# Laporan Praktikum Modul 8 – Queue
<p align="center">Yossika Putra Erlangga - 103112430026</p>

---
## Dasar Teori
Queue adalah struktur data linear yang bekerja berdasarkan prinsip **FIFO (First In First Out)**, dimana elemen yang pertama masuk akan menjadi elemen pertama yang keluar. Konsep ini banyak digunakan dalam berbagai sistem komputasi yang memerlukan pengolahan data secara berurutan, seperti *task scheduling*, *message buffering*, dan *network packet handling* [2].

Dalam kajian ilmiah, queue dikategorikan sebagai salah satu struktur data fundamental karena digunakan untuk mengatur sumber daya yang terbatas serta memproses permintaan secara teratur. Menurut studi dalam *International Journal of Computer Applications*, queue merupakan mekanisme penting dalam desain algoritma antrian, simulasi sistem, dan pengelolaan proses pada sistem operasi modern [3].

Queue dapat direpresentasikan menggunakan:
- **Linked List** → bersifat dinamis, dapat menambah elemen tanpa batas selama memori tersedia.
- **Array** → bersifat statis, membutuhkan manajemen indeks HEAD dan TAIL.

dan memiliki dua operasi utama:
1. **Enqueue** – menambahkan elemen ke bagian belakang (TAIL)
2. **Dequeue** – menghapus elemen dari bagian depan (HEAD)

Queue digunakan dalam berbagai bidang seperti:
- Sistem antrian CPU (*Round Robin Scheduling*)
- Simulasi layanan (bank, rumah sakit, bandara)
- Sistem komunikasi data dan jaringan
- Struktur buffer pada I/O device [4]

---
## Dasar Pemrograman
Implementasi queue dalam bahasa pemrograman sering memanfaatkan struktur **array** atau **linked list**, masing-masing memiliki karakteristik yang berbeda. Representasi menggunakan array umumnya lebih sederhana, tetapi ukuran queue menjadi tetap. Sebaliknya, penggunaan linked list memungkinkan queue bersifat dinamis dan fleksibel [5].

Dalam pemrograman C/C++, queue umumnya diimplementasikan dengan komponen sebagai berikut:
- **info[]** atau **node.info** → menyimpan data
- **HEAD** → menunjuk ke elemen paling depan
- **TAIL** → menunjuk ke elemen paling belakang

Operasi dasar yang diimplementasikan:
- `createQueue()` → menginisialisasi queue kosong
- `enqueue(x)` → memasukkan elemen ke belakang
- `dequeue()` → menghapus elemen dari depan
- `isEmpty()` dan `isFull()` → memeriksa status queue
- `printInfo()` → menampilkan seluruh elemen dalam queue

Penggunaan queue dalam kode sering dikaitkan dengan algorithm control-flow, misalnya **Breadth-First Search** (BFS), sistem event-driven, serta implementasi *task manager* pada sistem operasi [6].

---
## Guided 1 – Implementasi Queue dengan Linked List

### queue.h
```cpp
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int angka);

#endif
```

### queue.cpp
```cpp
#include "queue.h"
#include <iostream>
using namespace std;

bool isEmpty(queue Q){
    return Q.head == Nil;
}

void createQueue(queue &Q){
    Q.head = Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q)){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        cout << "node " << nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
        dealokasi(nodeHapus);
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node posisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
}

void searchData(queue Q, int data){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                break;
            }
            posisi++;
            nodeBantu = nodeBantu->next;
        }
        if(!found){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
        }
    }
}
```

### main.cpp
```cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enqueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah dequeue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}
```
### Penjelasan :
Di Guided 1, kita belajar bikin queue dengan linked list, jadi ukuran antrian bisa nambah terus selama masih ada memori. Cara kerjanya simpel: kalau kita enqueue, data baru ditaruh di belakang; kalau dequeue, data paling depan diambil duluan. Semua pakai pointer, jadi nggak ada proses geser-geser data kayak di array. Kita juga bisa ngubah dan nyari data dengan cara jalanin pointer dari head sampai ketemu. Intinya, queue model ini fleksibel dan enak dipakai untuk antrian yang ukuran datanya sering berubah-ubah.

---
## Guided 2 – Implementasi Queue Array (Circular Queue)

### queue.h
```cpp
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

### queue.cpp
```cpp
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
    return Q.count == MAX_QUEUE;
}

void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) {
        Q.info[Q.tail] = x;
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
        Q.count++;
    } else {
        cout << "Antrean Penuh!" << endl;
    }
}

int dequeue(Queue &Q) {
    if (!isEmpty(Q)) {
        int x = Q.info[Q.head];
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--;
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) {
        int i = Q.head;
        int n = 0;
        while (n < Q.count) {
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX_QUEUE;
            n++;
        }
    }
    cout << "]" << endl;
}
```

### main.cpp
```cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main(){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "
 Enqueue 3 elemen" << endl;
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);

    cout << "
 Dequeue 1 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "
 Enqueue 2 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```
### Penjelasan : 
Di Guided 2, queue dibuat pakai **array** tapi model **circular**, jadi walaupun array penuh, indeksnya bisa muter lagi ke awal. Ini bikin array lebih efisien dan nggak perlu geser-geser data waktu dequeue. Head cuma maju satu langkah tiap kali data keluar, tail juga maju kalau ada data masuk, semuanya pakai modulo biar muter. Hasilnya: antrian tetap rapi, cepat, dan nggak boros space.

---
# UNGUIDED

## Unguided 1 – ADT Queue Alternatif 1 (Head Diam, Tail Bergerak)

1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
	![Screenshot Alternatif 1 Output](output/soal1_unguided1.png)
	

Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).
![Screenshot Alternatif 1 Output](output/soal2_unguided1.png)

### queue.h
```cpp
#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5

struct Queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

### queue.cpp
```cpp
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return Q.head == -1;
}

bool isFull(Queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        int x = Q.info[Q.head];

        // SHIFTING (sesuai Alternatif 1)
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }

        Q.tail--;

        if (Q.tail < Q.head) {
            Q.head = -1;
            Q.tail = -1;
        }

        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " : ";

    if (isEmpty(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

```

### main.cpp
```cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "------------------------" << endl;
    cout << " H - T \t| Queue info" << endl;
    cout << "------------------------" << endl;

    printInfo(Q); 
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan8_Modul8/output/output-Unguided1-Modul8.png)

### Penjelasan: 
Unguided 1 pakai cara paling dasar: head selalu di posisi awal array, tail maju terus kalau ada data baru. Masalahnya, waktu dequeue, semua elemen harus digeser ke depan satu-satu. Jadi, walaupun simpel banget dan gampang dipahami, cara ini kurang efisien karena operasi geser itu lumayan makan waktu kalau datanya banyak.

## Unguided 2 – ADT Queue Alternatif 2 (Head dan Tail Bergerak)
Pada alternatif ini HEAD dan TAIL bergerak tanpa pergeseran kecuali jika queue hampir penuh.

### queue.h
```cpp
#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5

struct Queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

### queue.cpp
```cpp
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return Q.head == -1;
}

bool isFull(Queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        int x = Q.info[Q.head];
        Q.head++;

        if (Q.head > Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " : ";
    if (isEmpty(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

```

### main.cpp
```cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    cout << "------------------------" << endl;
    cout << " H - T \t| Queue info" << endl;
    cout << "------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 3); printInfo(Q);
    enqueue(Q, 8); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan8_Modul8/output/output-Unguided2-Modul8.png)

Penjelasan: HEAD dan TAIL sama-sama bergerak, sehingga tidak ada shifting kecuali pada kondisi tertentu.

## Unguided 3 – ADT Queue Alternatif 3 (Circular Queue)
Representasi circular queue memungkinkan HEAD dan TAIL berputar kembali ke indeks awal.

### queue.h
```cpp
#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5

struct Queue {
    int info[MAX];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

### queue.cpp
```cpp
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

```

### main.cpp
```cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    cout << "------------------------" << endl;
    cout << " H - T \t| Queue info" << endl;
    cout << "------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 1); printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    enqueue(Q, 8); printInfo(Q); // tail muter
    dequeue(Q);    printInfo(Q);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan8_Modul8/output/output-Unguided3-Modul8.png)

Penjelasan: Circular queue membuat antrian efisien tanpa shifting, karena HEAD dan TAIL berputar ketika mencapai indeks maksimal.

---
## Kesimpulan
Pada praktikum Modul 8 ini, mahasiswa mempelajari konsep dan implementasi Queue dalam berbagai bentuk: linked list, array linear, dan circular queue. Queue sebagai struktur data FIFO digunakan untuk memproses data secara berurutan, dan setiap alternatif implementasi memiliki karakteristik serta kelebihan masing‑masing. Queue berbasis linked list lebih fleksibel karena dinamis, sedangkan queue berbasis array lebih terstruktur dan dapat dibuat efisien melalui circular buffer. Melalui guided dan unguided, mahasiswa dapat memahami bagaimana operasi enqueue, dequeue, traversal, serta pengelolaan memori dilakukan, sekaligus melihat perbedaan kinerja antar metode. Secara keseluruhan, pemahaman queue menjadi dasar penting dalam pengembangan aplikasi seperti sistem antrian, buffer data, streaming, dan algoritma penjadwalan.

---
## Referensi
1. GeeksforGeeks (2024). *Queue Data Structure Overview*.
2. Goodrich, M., Tamassia, R., Goldwasser, M. (2014). *Data Structures & Algorithms in C++*. Wiley.
3. Sharma, A., & Singh, P. (2020). "Analysis of Queue Data Structures in System Simulation", *International Journal of Computer Applications*.
4. Stallings, W. (2018). *Operating Systems: Internals and Design Principles*. Pearson.
5. Malik, D. S. (2018). *Data Structures Using C++*. Cengage Learning.
6. Kurniawan, A. (2021). *Struktur Data dalam Bahasa C++*. Informatika Bandung.

