# <h1 align="center">Laporan Praktikum Modul 4 - Abstract Data Type (ADT)</h1>
<p align="center">Yossika Putra Erlangga - 103112430026</p>

---


## Dasar Teori

**Singly Linked List** atau **Linked List Satu Arah** adalah salah satu bentuk **struktur data dinamis** yang terdiri dari **sekumpulan node**, di mana setiap node menyimpan **data** dan **pointer (link)** menuju **node berikutnya** [1].  
Berbeda dengan array yang berukuran tetap, linked list memungkinkan **penambahan dan penghapusan data secara fleksibel** tanpa harus menggeser elemen lainnya [2].

### Komponen Utama
1. **Node**  
   Merupakan satu elemen dalam linked list yang terdiri atas dua bagian:
   - **Data** → menyimpan nilai/isi informasi.
   - **Pointer (next)** → menyimpan alamat dari node berikutnya.
   
2. **Head (Pointer Awal)**  
   Menunjuk ke node pertama dalam list. Jika list kosong, maka head = `NULL`.

3. **NULL Terminator**  
   Node terakhir selalu menunjuk ke `NULL` sebagai tanda akhir list.

---

### Operasi Dasar pada Singly Linked List
1. **Create (Membuat list kosong)**  
   Inisialisasi head dengan `NULL`.
2. **Insert (Menambah node)**  
   Menambahkan elemen baru di:
   - Awal list (insert first),
   - Tengah (insert after),
   - Akhir list (insert last).
3. **Delete (Menghapus node)**  
   Menghapus node berdasarkan posisi atau nilai tertentu.
4. **Traversal (Menelusuri list)**  
   Menampilkan seluruh elemen list mulai dari head hingga `NULL`.
5. **Search (Mencari node)**  
   Mencari node yang memiliki nilai tertentu.
6. **Update (Mengubah isi data)**  
   Mengganti nilai data pada node yang ditemukan.

---

### Kelebihan dan Kekurangan
| Kelebihan                                            | Kekurangan                                                      |
| ---------------------------------------------------- | --------------------------------------------------------------- |
| Ukuran dinamis (tidak perlu dideklarasikan di awal). | Akses data tidak bisa langsung (harus traversal satu per satu). |
| Efisien dalam operasi sisip dan hapus.               | Butuh memori tambahan untuk pointer.                            |
| Tidak perlu realokasi seperti array.                 | Lebih sulit diimplementasikan dan didebug.                      |

---

### Ilustrasi Struktur Linked List
```
[Data | Next] → [Data | Next] → [Data | NULL]
```
Contoh:
```
Head → [10 | •] → [20 | •] → [30 | NULL]
```

---

### Contoh Representasi Node dalam C++
```cpp
struct Node {
    int data;
    Node* next;
};
```
`Node* head = NULL;` digunakan sebagai awal list.

---

### Alur Kerja Insert Node di Awal
1. Buat node baru (`newNode`).
2. Isi data pada `newNode`.
3. Set `newNode->next = head`.
4. Pindahkan `head = newNode`.

---

### Alur Kerja Delete Node di Awal
1. Cek apakah list kosong (`head == NULL`).
2. Simpan node pertama di pointer sementara.
3. Pindahkan `head = head->next`.
4. Hapus node sementara.

---

### Aplikasi Singly Linked List
- Manajemen data antrian pelanggan (queue sederhana).  
- Struktur undo/redo pada aplikasi.  
- Implementasi stack, graph, dan hash table.  
- Sistem navigasi data dinamis pada game atau sistem basis data.

---

### Kesimpulan
Singly Linked List merupakan struktur data yang memungkinkan pengelolaan elemen secara **dinamis dan efisien**, terutama dalam hal **penyisipan dan penghapusan data** tanpa perlu pergeseran elemen seperti pada array. Konsep pointer menjadi inti dari implementasi linked list ini [3].

---

## Dasar Pemrograman

Pada implementasi **Singly Linked List** di C++, kita menggunakan **pointer dan struct/class** untuk membentuk node yang saling terhubung.

---
### Struktur Dasar Node
```cpp
struct Node {
    int data;
    Node* next;
};
```
- `data` → menyimpan nilai.  
- `next` → menunjuk ke node berikutnya.

---

### Inisialisasi Linked List Kosong
```cpp
Node* head = NULL;
```
List masih kosong karena belum ada node.

---

### Fungsi Membuat Node Baru
```cpp
Node* createNode(int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = NULL;
    return newNode;
}
```

---

### Fungsi Menambah Node di Awal
```cpp
void insertDepan(Node* &head, int nilai) {
    Node* newNode = createNode(nilai);
    newNode->next = head;
    head = newNode;
}
```

---

### Fungsi Menambah Node di Akhir
```cpp
void insertBelakang(Node* &head, int nilai) {
    Node* newNode = createNode(nilai);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
```

---

### Fungsi Menghapus Node di Awal
```cpp
void hapusDepan(Node* &head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}
```

---

### Fungsi Menampilkan Isi Linked List
```cpp
void tampil(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
```

---

### Fungsi Utama (Main Program)
```cpp
int main() {
    Node* head = NULL;

    insertDepan(head, 30);
    insertDepan(head, 20);
    insertDepan(head, 10);
    insertBelakang(head, 40);

    cout << "Isi Linked List: ";
    tampil(head);

    hapusDepan(head);
    cout << "Setelah hapus depan: ";
    tampil(head);

    return 0;
}
```

---

### Penjelasan
Program di atas menunjukkan bagaimana **node disisipkan dan dihapus secara dinamis** dalam sebuah singly linked list.  
Pointer `head` menjadi penanda awal list, sedangkan setiap node menunjuk ke node berikutnya sampai `NULL`. Operasi traversal dilakukan untuk menampilkan seluruh data.  

Implementasi ini sesuai dengan teori dalam Modul 4 — *Singly Linked List (Bagian Pertama)* [1][2].

---

## Guided

### Guided 1 - Penambahan Data(NIM, NAMA, UMUR)
#### File: `list.h`
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 

typedef struct node *address; 

struct node{ 
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif

```
#### File: `list.cpp`
```cpp
#include "list.h"
#include <iostream>
using namespace std;


bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
#### File: `main.cpp`
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}

```
```
Penjelasan progam di atas :
Program di atas adalah kita membuat dan menampilkan data menggunakan Singly Linked List di C++, di mana setiap node berisi data mahasiswa (nama, NIM, umur) dan saling terhubung melalui pointer next. Program ini mendemonstrasikan proses pembuatan list, alokasi node baru, serta penyisipan node di awal, tengah, dan akhir list menggunakan fungsi insertFirst, insertAfter, dan insertLast, kemudian seluruh isi list ditampilkan menggunakan printList.
```
### Guided2 - list.cpp versi ada penambahan delete
#### File: `list.h`
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 

typedef struct node *address; 

struct node{ 
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

```
#### File: `list.cpp`
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {

    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { 
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}

---
```

#### File: `main.cpp`
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
---
```
```
Penjelasan Ketiga Progam di atas :
Program di atas adalah kita memodifikasi pengembangan dari Guided 1 dengan penambahan fitur penghapusan node (delFirst, delLast, delAfter), penghitungan jumlah node (nbList), dan penghapusan seluruh list (deleteList), sehingga program ini menampilkan proses lengkap pengelolaan data dinamis mulai dari penyisipan, penghapusan, hingga pembersihan list menggunakan konsep Singly Linked List di C++ 

```

## Unguided

#### Soal 1 – Latihan Singly Linked List
Buatlah ADT **Singly Linked List** dengan spesifikasi berikut:  
Tipe data:
```
Type infotype : int
Type address : pointer to ElmList
Type ElmList < info : infotype, next : address >
Type List < First : address >
```
Prosedur dan fungsi yang harus dibuat:
- `CreateList( input/output L : List )`
- `alokasi( x : infotype ) -> address`
- `dealokasi( input/output P : address )`
- `printInfo( input L : List )`
- `insertFirst( input/output L : List, input P : address )`

Kemudian buatlah implementasi pada file `Singlylist.cpp` dan program utama di `main.cpp` dengan kode berikut:

---

#### 🗂️ File: `main.cpp`
```cpp
int main(){
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```

Sehingga linked list yang dihasilkan adalah:
```
9 → 12 → 8 → 0 → 2
```

**Output yang diharapkan:**
```
9 12 8 0 2
Process returned 0 (0x0)   execution time : 0.019 s
Press any key to continue.
```
#### A. Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif


```

#### B. Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) { L.first = Nil; }

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P) { delete P; }

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) cout << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        L.first = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        address Q = L.first;
        if (Q->next == Nil) {
            P = Q;
            L.first = Nil;
        } else {
            while (Q->next->next != Nil)
                Q = Q->next;
            P = Q->next;
            Q->next = Nil;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) {
    int n = 0;
    for (address P = L.first; P != Nil; P = P->next) n++;
    return n;
}

void deleteList(List &L) {
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}

```
#### C. main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L); 
    return 0;
}

```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan4_Modul4/output/Output-Unguided1-Modul4.png)

Penjelasan program di atas :
Di bagian ini programnya nunjukin gimana cara bikin dan nampilin **linked list satu arah**. Pertama list dikosongin dulu pakai `createList()`, terus tiap data dimasukin lewat `alokasi()` dan `insertFirst()` biar ditambah di depan. Pas semua udah masuk, fungsi `printInfo()` dipakai buat nampilin isi list dari depan sampai akhir. Hasil akhirnya data keprint berurutan jadi **9 → 12 → 8 → 0 → 2**.


### Soal 2 – Penghapusan Node
Dari hasil soal pertama, lakukan:
- Penghapusan node **9** menggunakan `deleteFirst()`
- Penghapusan node **2** menggunakan `deleteLast()`
- Penghapusan node **8** menggunakan `deleteAfter()`  
Kemudian tampilkan jumlah node menggunakan `nbList()` dan hapus seluruh node menggunakan `deleteList()`.

**Output yang diharapkan:**
```
12 0
Jumlah node : 2

- List Berhasil Terhapus -
Jumlah node : 0

```
### KODE C++
#### A. Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif


```

#### B. Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) { L.first = Nil; }

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P) { delete P; }

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) cout << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        L.first = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        address Q = L.first;
        if (Q->next == Nil) {
            P = Q;
            L.first = Nil;
        } else {
            while (Q->next->next != Nil)
                Q = Q->next;
            P = Q->next;
            Q->next = Nil;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) {
    int n = 0;
    for (address P = L.first; P != Nil; P = P->next) n++;
    return n;
}

void deleteList(List &L) {
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}

```
#### C. main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P;
    createList(L);

    int data[] = {2, 0, 8, 12, 9};
    for (int i = 0; i < 5; i++)
        insertFirst(L, alokasi(data[i]));

    printInfo(L); 

    deleteFirst(L, P);
    dealokasi(P);

    deleteLast(L, P);
    dealokasi(P);

    deleteAfter(L.first, P);
    dealokasi(P);

    printInfo(L); 
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}

```

### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan4_Modul4/output/Output-Unguided2-Modul4.png)

Penjelasan program di atas :
program ini lanjutan dari yang pertama, tapi fokusnya ke cara hapus data dari linked list. Programnya ngilangin node pertama pakai deleteFirst(), node terakhir pakai deleteLast(), dan node di tengah pakai deleteAfter(). Abis dihapus, program ngitung sisa node pakai nbList() terus semua node dihapus total pakai deleteList(). Akhirnya list-nya kosong lagi, alias semua data udah kehapus.


## Kesimpulan
1. **Singly Linked List** adalah struktur data dinamis yang memungkinkan pengelolaan data lebih efisien.  
2. Setiap node memiliki pointer yang menunjuk ke node berikutnya hingga `NULL`.  
3. Operasi seperti **insert**, **delete**, dan **traversal** merupakan inti dari manipulasi linked list.  
4. Pointer memegang peran penting dalam membangun koneksi antar-node di linked list.  

---

## Referensi
[1] Malik, D. S. (2018). *Data Structures Using C++*. Cengage Learning.  
[2] Indahyati, Uce & Rahmawati, Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Umsida Press.  
[3] Kurniawan, A., & Susanto, D. (2021). “Implementasi Linked List dalam Pengelolaan Data Dinamis.” *Jurnal Ilmiah Informatika*, vol. 7, no. 1.  
[4] Stroustrup, Bjarne. *The C++ Programming Language*, 4th Edition. Addison-Wesley, 2013.
