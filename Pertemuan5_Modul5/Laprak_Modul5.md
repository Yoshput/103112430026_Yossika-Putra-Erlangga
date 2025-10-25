# Laporan Praktikum Modul 5 – Singly Linked List (Bagian Kedua)
<p align="center">Yossika Putra Erlangga - 103112430026</p>

---

## Dasar Teori
Struktur data *Linked List* merupakan kumpulan elemen data yang saling terhubung melalui pointer.  
Berbeda dengan array yang bersifat statis, *Linked List* bersifat dinamis karena ukuran memorinya dapat berubah sesuai kebutuhan [1].  
Setiap elemen di *Linked List* disebut **node**, yang terdiri dari dua bagian utama yaitu:  
1. **Data** — berisi nilai atau informasi yang disimpan.  
2. **Pointer (next)** — menunjuk ke node berikutnya dalam list.  

Pada Modul 5 ini, dipelajari operasi lanjutan pada *Singly Linked List*, meliputi **insert**, **delete**, **update**, dan **search**.  
Konsep ini memungkinkan manipulasi data secara fleksibel tanpa harus menggeser elemen seperti pada array [2].  

Selain itu, algoritma **Linear Search** dan **Binary Search** juga diterapkan pada *Linked List*.  
- *Linear Search* mencari data dengan menelusuri setiap node dari awal hingga ditemukan.  
- *Binary Search* membutuhkan list yang terurut, kemudian melakukan pembagian list untuk mempercepat pencarian [3].  


## Dasar Pemrograman
Pemrograman pada *Singly Linked List* menggunakan konsep **struktur data dinamis** yang berbasis pada pointer. Dalam bahasa C++, pointer digunakan untuk menunjuk alamat memori dari suatu variabel atau objek lain. Konsep ini sangat penting karena setiap node dalam *linked list* terhubung melalui pointer yang menunjuk ke node berikutnya.

Struktur dasar *linked list* terdiri dari **struct** yang menyimpan data dan pointer ke node berikutnya. Operasi seperti **insert**, **delete**, dan **update** memerlukan manipulasi pointer agar hubungan antar-node tetap terjaga.  
Pemrograman dilakukan menggunakan beberapa konsep dasar berikut:

1. **Deklarasi Struct dan Typedef**  
   - `struct node` digunakan untuk merepresentasikan satu elemen dalam list.  
   - `typedef` mempermudah penamaan tipe data seperti `address` atau `linkedlist`.

2. **Pointer dan Alokasi Dinamis**  
   - Operator `new` digunakan untuk membuat node baru di memori heap.  
   - Operator `delete` (atau fungsi `dealokasi()`) digunakan untuk menghapus node yang tidak lagi digunakan agar tidak terjadi *memory leak*.

3. **Fungsi Modular**  
   - Program dibagi menjadi beberapa fungsi seperti `insertFirst()`, `delLast()`, dan `updateAfter()`.  
   - Hal ini memudahkan debugging dan menjaga agar kode tetap rapi dan terstruktur.

4. **Pemrosesan dengan Fungsi Rekursif atau Iteratif**  
   - Traversal atau penelusuran list dilakukan dengan perulangan (`while`) sampai `NULL` tercapai, menandakan akhir list.

5. **Implementasi Searching**  
   - *Linear Search* menelusuri node satu per satu.  
   - *Binary Search* diterapkan secara iteratif dengan bantuan fungsi `getMiddle()` untuk menentukan node tengah, namun hanya efektif pada list yang sudah terurut.

Dasar pemrograman ini menekankan pemahaman terhadap **manajemen memori**, **penggunaan pointer**, serta **struktur kontrol (loop dan kondisi)** dalam bahasa C++. Pemahaman yang kuat terhadap aspek-aspek tersebut menjadi fondasi untuk mengembangkan algoritma struktur data yang efisien dan aman.


---

## Guided 1 – Program List Buah

### listbuah.h
```cpp
#ifndef LISTBUAH_H
#define LISTBUAH_H

#define Nil NULL
#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address;

struct node {
    dataBuah isidata;
    address next;
};

struct linkedlist {
    address first;
};

// ==== DEKLARASI / PROTOTYPE ====
bool isEmpty(linkedlist List);
void createList(linkedlist &List);

address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void printList(linkedlist List);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// === Fungsi update data ===
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address nodePrev);

#endif
```

### listbuah.cpp
```cpp
#include "listbuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//dealokasi node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//insert node
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

//delete node
void delFirst(linkedlist &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//print list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama Buah : " << nodeBantu->isidata.nama
                 << ", Jumlah : " << nodeBantu->isidata.jumlah
                 << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function jumlah node
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//hapus semua node
void deleteList(linkedlist &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

//update data node
void updateFirst(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node "
                 << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

### main.cpp
```cpp
#include "listBuah.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"--- ISI LIST SETELAH DILAKUKAN INSERT---" << endl;
    printList(List);
    cout <<"jumlah node:" << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout <<"--- ISI LIST SETELAH DILAKUKAN UPDATE---" << endl;
    printList(List);
    cout << "jumlah node:" << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

**Penjelasan:**  
Program ini mengimplementasikan operasi dasar *singly linked list* yang menyimpan data buah.  
Fungsi insertFirst, insertLast, dan insertAfter digunakan untuk menambahkan node baru.  Sedangkan updateFirst, updateLast, dan updateAfter digunakan untuk memperbarui isi data buah.  Program ini memperlihatkan bagaimana manajemen memori dinamis digunakan untuk membangun dan memodifikasi list secara langsung.

---

## Guided 2 – Searching pada Linked List

### binnary.cpp
```cpp
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

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    Node* result = binarySearch(head, 40);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```

### linear.cpp
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return nullptr;
}

void append(Node* &head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;
    append(head, 10); append(head, 20); append(head, 30);
    Node* result = linearSearch(head, 30);
    cout << (result ? "Found" : "Not Found") << endl;
    return 0;
}
```

**Penjelasan:**  
Guided ini menjelaskan dua metode pencarian data pada *linked list*.  
linearSearch() menelusuri setiap node secara berurutan hingga menemukan data yang dicari.  
Sedangkan binarySearch() membagi list menjadi dua bagian untuk mempercepat pencarian, namun hanya berlaku pada list yang sudah terurut naik.  

---

## Unguided 1 – Binary Search pada Linked List

**Tugas 1.**  
Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:

1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan binary search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir

**Petunjuk Tugas 1:**

- Gunakan struktur Node dengan data integer dan pointer next
- Implementasikan fungsi append() untuk menambah node
- Implementasikan fungsi binarySearch() yang mengembalikan pointer ke node yang ditemukan
- Data dalam linked list harus terurut (ascending) untuk binary search bekerja dengan benar
- Tampilkan langkah-langkah pencarian dan posisi tengah setiap iterasi
- Program utama harus membuat linked list dengan minimal 5 elemen dan melakukan pencarian

Ekspektasi Output: 
Jangan berekspektasi sama manusia, takutnya dikecewakan. Berekspektasilah pada diri sendiri yang mau berjuang. 

```
(base) PS D:\ASPRAK STRUKDAT\RPL\Modul 5\output> & .\tugasbinary.exe' 
BINARY SEARCH PADA LINKED LIST 
Linked list yang dibuat: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL 
Mencari nilai: 40 
Proses Pencarian: 
Iterasi 1: Mid = 40 (indeks tengah) - DITEMUKAN! 
Hasil: Nilai 40 DITEMUKAN pada linked list! 
Alamat node: 0x212e2253a30 
Data node: 40 
Node berikutnya: 50 
Mencari nilai: 25 
Proses Pencarian: 
Iterasi 1: Mid = 40 (indeks tengah) -> 
Cari di bagian kiri Iterasi 2: Mid = 20 (indeks tengah) -> Cari di bagian kanan Tidak ada elemen tersisa Hasil: Nilai 25 TIDAK DITEMUKAN dalam linked list!


```
#### A. binnary.h
```C++
#ifndef BINNARY_H
#define BINNARY_H

#include <iostream>
using namespace std;

// Struktur node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Prototipe fungsi
Node* createNode(int value);
void append(Node* &head, int value);
void printList(Node* head);
Node* getMiddle(Node* start, Node* end);
Node* binarySearch(Node* head, int key);

#endif


```

#### B. binnary.cpp
```C++
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


```
#### C. main.cpp
```C++
#include "binnary.h"
#include <iostream>
using namespace std;

int main() {
    Node* head = NULL;

    cout << "BINARY SEARCH PADA LINKED LIST" << endl;

    // Buat linked list terurut
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    printList(head);

    // Pencarian pertama
    int cari1 = 40;
    cout << "Mencari nilai: " << cari1 << endl;
    binarySearch(head, cari1);

    cout << "\n------------------------------------------\n" << endl;

    // Pencarian kedua
    int cari2 = 25;
    cout << "Mencari nilai: " << cari2 << endl;
    binarySearch(head, cari2);

    return 0;
}


```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan5_Modul5/output/Output-Unguided1-Modul5.png)

Program ini keren sekali karena berhasil menerapkan Binary Search pada Linked List. Kunci utamanya ada di struktur Node yang harus terurut datanya. Jadi, programnya punya fungsi append() buat nambahin data dan getMiddle() buat nemuin node tengah, mirip kayak kita nyari di array tapi ini pakai pointer. Intinya, di fungsi binarySearch(), kita selalu membandingkan nilai yang dicari dengan nilai di node tengah. Kalau belum ketemu, dia langsung tahu harus lanjut nyari ke bagian kiri atau ke bagian kanan list. Proses pencariannya detail banget ditampilkan per iterasi. Begitu ketemu, semua info node akan ditampilkan (alamat, data, dan nilai node selanjutnya), tapi kalau datanya memang enggak ada, ya muncul deh notifikasi kalau data itu 'tidak ditemukan' di list kita.


---
## Unguided 2 – Linear Search pada Linked List

Tugas 2 – Linear Search pada Linked List
**Deskripsi Tugas:**  
Implementasikan program C++ yang menggunakan algoritma **Linear Search** pada **Linked List** untuk mencari elemen tertentu. Program harus mampu:

1. Membuat linked list dengan menambahkan node di akhir.
2. Mengimplementasikan linear search pada linked list.
3. Menampilkan detail proses pencarian dan hasil akhir.

**Petunjuk Tugas:**

- Gunakan struktur `Node` dengan **data integer** dan pointer `next`.
- Implementasikan fungsi `append()` untuk menambah node di akhir linked list.
- Implementasikan fungsi `linearSearch()` yang **mengembalikan pointer** ke node yang ditemukan.
- Data dalam linked list **tidak perlu terurut** untuk linear search.
- Tampilkan **setiap langkah pencarian** dan node yang sedang diperiksa.
- Program utama harus membuat linked list dengan **minimal 3 elemen** dan melakukan pencarian.

---

#### Ekspektasi Output

```
Dulu pernah berekspektasi pada seseorang, tapi hasilnya dikecewakan.
Jadinya hanya bisa berekspektasi atas kerja keras diri sendiri.

● LINEAR SEARCH PADA LINKED LIST
Linked list yang dibuat: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

Mencari nilai: 30
Proses Pencarian:
Memeriksa node 1: 10 (tidak sama)
Memeriksa node 2: 20 (tidak sama)
Memeriksa node 3: 30 (SAMA) - DITEMUKAN!
Hasil: Nilai 30 DITEMUKAN pada linked list!
Alamat node: 0x23c50148890
Data node: 30
Node berikutnya: 40

Mencari nilai: 25
Proses Pencarian:
Memeriksa node 1: 10 (tidak sama)
Memeriksa node 2: 20 (tidak sama)
Memeriksa node 3: 30 (tidak sama)
Memeriksa node 4: 40 (tidak sama)
Memeriksa node 5: 50 (tidak sama)
Tidak ada nilai lagi yang tersisa
Hasil: Nilai 25 TIDAK DITEMUKAN dalam linked list!
```

#### A. linear.h
```C++
#ifndef LINEAR_H
#define LINEAR_H

#include <iostream>
using namespace std;

// Struktur Node Linked List
struct Node {
    int data;
    Node* next;
};

// Fungsi dasar
Node* createNode(int value);
void append(Node* &head, int value);
void printList(Node* head);
Node* linearSearch(Node* head, int key);

#endif

```

#### B. linear.cpp
```C++
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

```
#### C. main.cpp
```C++
#include "linear.h"
#include <iostream>
using namespace std;

int main() {
    Node* head = NULL;

    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;

    // Membuat linked list (tidak harus terurut)
    append(head, 45);
    append(head, 20);
    append(head, 60);
    append(head, 10);
    append(head, 30);

    printList(head);

    // Pencarian pertama (ditemukan)
    int cari1 = 60;
    cout << "Mencari nilai: " << cari1 << endl;
    linearSearch(head, cari1);

    cout << "\n------------------------------------------\n" << endl;

    // Pencarian kedua (tidak ditemukan)
    int cari2 = 25;
    cout << "Mencari nilai: " << cari2 << endl;
    linearSearch(head, cari2);

    return 0;
}


```

### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan5_Modul5/output/Output-Unguided2-Modul5.png)

Program Unguided 2 ini menunjukkan cara termudah mencari data, yaitu Linear Search, dan ini cocok banget untuk Linked List yang datanya belum terurut. Kita cuma perlu telusuri satu per satu (data dan next) mulai dari node pertama (head) sampai ketemu atau sampai list-nya habis (NULL). Fungsi linearSearch() akan menampilkan detail setiap langkah yang diambil nilai data dan alamat memori sehingga kita bisa lihat prosesnya secara transparan. Kalau datanya ketemu, program langsung kasih tahu alamat dan datanya; kalau tidak ada, ya muncul pesan penolakan. Intinya, metode ini simpel dan enggak ribet kayak Binary Search yang harus bagi data, tapi konsekuensinya ya harus 'mengunjungi' setiap node sampai tujuan tercapai.

---

## Kesimpulan
Pada Modul 5 ini, mahasiswa memahami implementasi lanjutan dari *Singly Linked List* meliputi operasi **insert**, **delete**, **update**, dan **search**.  
Perbedaan utama antara **Linear Search** dan **Binary Search** adalah pada cara penelusuran datanya: linear dilakukan satu per satu, sedangkan binary membutuhkan data yang terurut agar dapat mempercepat pencarian.  
Pemahaman pointer menjadi kunci dalam penerapan seluruh operasi pada *Linked List*.

---

## Referensi
1. Malik, D.S. (2018). *Data Structures Using C++*. Cengage Learning.  
2. Indahyati, U. & Rahmawati, Y. (2020). *Algoritma dan Pemrograman dalam Bahasa C++*. Umsida Press.  
3. Kurniawan, A. & Susanto, D. (2021). “Implementasi Linked List dalam Pengelolaan Data Dinamis.” *Jurnal Ilmiah Informatika*, 7(1).  
4. Stroustrup, B. (2013). *The C++ Programming Language* (4th Edition). Addison-Wesley.  
