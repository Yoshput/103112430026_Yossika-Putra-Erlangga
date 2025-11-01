# Laporan Praktikum Modul 6 – Singly Linked List (Bagian Kedua)
<p align="center">Yossika Putra Erlangga - 103112430026</p>

---

## Dasar Teori

**Doubly Linked List** merupakan struktur data dinamis yang terdiri dari serangkaian elemen (*node*) yang saling terhubung dua arah. Setiap *node* memiliki tiga bagian utama, yaitu **data**, **pointer ke elemen sebelumnya (prev)**, dan **pointer ke elemen berikutnya (next)** [5].

Berbeda dengan *Singly Linked List* yang hanya dapat ditelusuri satu arah (maju), *Doubly Linked List* memungkinkan proses traversal dua arah: maju (dari `first` ke `last`) dan mundur (dari `last` ke `first`). Hal ini memberikan fleksibilitas lebih dalam operasi **insert**, **delete**, dan **search**, karena akses terhadap elemen dapat dilakukan dari dua arah [2].

Komponen utama dalam *Doubly Linked List* adalah:

1. **First** → menunjuk ke elemen pertama dalam list.
2. **Last** → menunjuk ke elemen terakhir dalam list.
3. **Next** → menunjuk ke elemen sesudahnya.
4. **Prev** → menunjuk ke elemen sebelumnya.

Struktur ini banyak digunakan pada sistem yang membutuhkan navigasi dua arah, seperti implementasi *undo-redo* pada aplikasi teks, manajemen memori, serta representasi antrian data yang fleksibel [6].

---

## Dasar Pemrograman

Pemrograman *Doubly Linked List* dalam bahasa **C++** menggunakan konsep **struktur data dinamis** berbasis **pointer**. Setiap *node* dibuat menggunakan `struct` yang berisi data dan dua pointer (`next` dan `prev`).

Operasi dasar yang umum dilakukan meliputi:

1. **CreateList()** – Menginisialisasi list kosong dengan `first` dan `last` bernilai `NULL`.
2. **Alokasi dan Dealokasi** – `alokasi()` membuat *node* baru menggunakan operator `new`, sedangkan `dealokasi()` membebaskan memori dengan `delete` agar tidak terjadi *memory leak* [3].
3. **Insert dan Delete** – Dapat dilakukan di awal (*first*), di akhir (*last*), maupun di tengah list. Karena terdapat dua pointer (`prev` dan `next`), hubungan antar-elemen dapat dipertahankan dengan mudah meskipun terjadi penghapusan atau penyisipan data.
4. **FindElm() / Search** – Menelusuri elemen berdasarkan data tertentu, misalnya nomor polisi kendaraan. Proses ini biasanya dilakukan secara linear.
5. **PrintInfo()** – Menampilkan isi list dari depan ke belakang atau sebaliknya.

Keunggulan utama *Doubly Linked List* dibanding *Singly Linked List* adalah kemampuannya untuk melakukan traversal dua arah dan kemudahan penghapusan elemen tanpa perlu mengetahui elemen sebelumnya secara eksplisit [5][7].


---

## Guided 1 – Program List Makanan

### listmakanan.h
```cpp
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

### listmakanan.cpp
```cpp
#include "listMakanan.h"
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
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```

### main.cpp
```cpp
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```

**Penjelasan:**  
Program ini mengimplementasikan **Doubly Linked List** untuk menyimpan dan memanipulasi data makanan yang memiliki atribut nama, jenis, harga, dan rating. Setiap node terhubung dua arah melalui pointer `next` dan `prev`, memungkinkan operasi penyisipan dan pembaruan dilakukan dari berbagai posisi list. Fungsi `insertFirst`, `insertLast`, `insertAfter`, dan `insertBefore` digunakan untuk menambahkan data di awal, akhir, atau posisi tertentu, sedangkan fungsi `updateFirst`, `updateLast`, `updateBefore`, dan `updateAfter` memperbarui isi node sesuai posisi yang ditentukan. Melalui implementasi ini, program menunjukkan cara kerja hubungan dua arah antar-node serta bagaimana perubahan data dilakukan tanpa memutus koneksi dalam list, mencerminkan prinsip dasar dari struktur data *Doubly Linked List* [5].


---

## Guided 2 – Doublylist - Kendaraan

### Doublylist.h
```cpp
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 
```

### Doublylist.cpp
```cpp
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```

### main.cpp
```cpp
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}

```


**Penjelasan:**  
Program ini mengimplementasikan ADT DoublyList yang menyimpan data kendaraan berupa nomor polisi, warna, dan tahun pembuatan, menggunakan tiga file utama (Doublylist.h, Doublylist.cpp, dan main.cpp). Fungsi utama yang digunakan meliputi pembuatan list kosong (CreateList), alokasi dan dealokasi node, penambahan data di akhir list (insertLast), pencarian elemen berdasarkan nomor polisi (findElm), penghapusan data tertentu (deleteByNopol), serta penampilan seluruh isi list (printInfo). Melalui program ini, mahasiswa memahami bagaimana pointer prev dan next berperan dalam menghubungkan node dua arah, sehingga operasi penyisipan, pencarian, dan penghapusan data dapat dilakukan secara efisien tanpa memutus hubungan antar-elemen [5].

---

## Unguided 1 – Binary Search pada Linked List

### Soal – Latihan Doubly Linked List Kendaraan

Buat ADT Doubly Linked List yang menyimpan data kendaraan (`nopol`, `warna`, `thnBuat`). Implementasikan fungsi berikut:
- `CreateList()`  
- `insertLast()`  
- `findElm()` (mencari berdasarkan nomor polisi)  
- `deleteFirst()`, `deleteLast()`, dan `deleteAfter()`

#### Doublylist.h
```cpp
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using namespace std;

struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef Kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);

#endif

```
#### Doublylist.cpp
```cpp
#include <iostream>
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    if (L.First == nullptr) {
        cout << "List kosong.\n";
        return;
    }

    address P = L.Last; // tampil mundur seperti contoh modul
    cout << "\nDATA LIST 1\n";
    while (P != nullptr) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

```
#### main.cpp
```cpp
#include <iostream>
#include <string>
#include "Doublylist.h"
using namespace std;

// Fungsi untuk memeriksa duplikat nomor polisi
bool cekDuplikat(List L, string nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol)
            return true;
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    CreateList(L);

    int jumlahInput = 3;  // jumlah kendaraan yang diinginkan
    int count = 0;        // penghitung data yang berhasil disimpan

    while (count < jumlahInput) {
        infotype x;
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (cekDuplikat(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar\n";
            continue; // tidak menambah count
        }

        address P = alokasi(x);
        insertLast(L, P);
        count++; // hanya naik kalau data berhasil disimpan
    }

    // setelah loop selesai, tampilkan hasil
    printInfo(L);

    return 0;
}


```

### Output Unguided 1 :
##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan6_Modul6/output/Output-Unguided1-Modul6.png)

Program ini menggunakan struktur data **Doubly Linked List** untuk menyimpan data kendaraan yang terdiri dari nomor polisi, warna, dan tahun pembuatan. Setiap node memiliki dua pointer (`next` dan `prev`) agar data dapat diakses maju maupun mundur. Proses utamanya dimulai dengan membuat list kosong, lalu pengguna diminta memasukkan tiga data kendaraan. Sebelum data dimasukkan, program memeriksa apakah nomor polisi sudah pernah terdaftar untuk menghindari duplikasi. Setelah semua data valid dimasukkan menggunakan fungsi `insertLast()`, seluruh isi list kemudian ditampilkan dengan fungsi `printInfo()` yang menelusuri data dari belakang ke depan. Melalui program ini, mahasiswa dapat memahami bagaimana _Doubly Linked List_ bekerja dalam menambah dan menampilkan data secara dinamis.


---
## Unguided 2 – Fungsi Pencarian (`findElm`)
### Deskripsi
Menambahkan fitur pencarian data kendaraan berdasarkan **nomor polisi** menggunakan fungsi `findElm()`.

### Program Tambahan Doublylist.cpp :
```cpp
address findElm(List L, string nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol)
            return P;
        P = P->next;
    }
    return nullptr;
}


```
### Tambahan di Doublylist.h
```cpp
address findElm(List L, string nopol);

```
### Tambahan di main.cpp:
```cpp
string cari;
cout << "\nMasukkan Nomor Polisi yang dicari : ";
cin >> cari;

address hasil = findElm(L, cari);
if (hasil != nullptr) {
    cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
    cout << "Warna        : " << hasil->info.warna << endl;
    cout << "Tahun        : " << hasil->info.thnBuat << endl;
} else {
    cout << "\nData dengan nomor polisi " << cari << " tidak ditemukan.\n";
}

```
Output yang dinginkan:
```cpp
Masukkan Nomor Polisi yang dicari : D001
Nomor Polisi : D001
Warna        : hitam
Tahun        : 90

```

### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan6_Modul6/output/Output-Unguided2-Modul6.png)

#### Penjelasan Program:
Program di atas sama dengan program di unguided 1, hanya menambahkan fitur pencarian data kendaraan berdasarkan **nomor polisi** menggunakan fungsi `findElm()`



### Unguided 3 – Menghapus Elemen (deleteFirst, deleteLast, deleteAfter)

### Deskripsi

Menambahkan fitur untuk **menghapus kendaraan berdasarkan nomor polisi** menggunakan 3 prosedur delete.
#### Tambahan di Doublylist.h
```cpp
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

```
#### Tambahan di Doublylist.cpp
```cpp
void deleteFirst(List &L, address &P) {
    if (L.First == nullptr)
        P = nullptr;
    else if (L.First == L.Last) {
        P = L.First;
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        P = L.First;
        L.First = L.First->next;
        L.First->prev = nullptr;
        P->next = nullptr;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == nullptr)
        P = nullptr;
    else if (L.First == L.Last) {
        P = L.Last;
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        P = L.Last;
        L.Last = L.Last->prev;
        L.Last->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec == nullptr || Prec->next == nullptr)
        P = nullptr;
    else {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr)
            P->next->prev = Prec;
        P->next = nullptr;
        P->prev = nullptr;
    }
}


```
### Tambahkan logika hapus di main.cpp
```cpp
string hapus;
cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
cin >> hapus;

address target = findElm(L, hapus);
if (target == nullptr) {
    cout << "Data dengan nomor polisi " << hapus << " tidak ditemukan.\n";
} else {
    address P;
    if (target == L.First)
        deleteFirst(L, P);
    else if (target == L.Last)
        deleteLast(L, P);
    else
        deleteAfter(target->prev, P);

    cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus.\n";
    delete P; // dealokasi
}

cout << "\nDATA LIST 1\n";
printInfo(L);

```

### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan6_Modul6/output/Output-Unguided3-Modul6.png)

#### Penjelasan Program:
program di atas seperti biasa sama saja seperti program utama yang ada di unguided 1, hanya menambahkan fitur untuk menghapus kendaraan berdasarkan nomor polisi menggunakan 3 prosedur delete.

---
## Kesimpulan
Pada Modul 6 ini, mahasiswa mempelajari penerapan struktur data **Doubly Linked List** menggunakan bahasa **C++**. Berbeda dengan _Singly Linked List_, setiap node pada struktur ini memiliki dua pointer, yaitu `next` dan `prev`, yang memungkinkan proses penelusuran dilakukan ke dua arah sekaligus. Hal tersebut memudahkan pelaksanaan operasi seperti **penyisipan (insert)**, **penghapusan (delete)**, dan **pencarian (search)** data.

Melalui kegiatan guided dan unguided, mahasiswa dilatih untuk mengelola memori secara dinamis, menjaga keterhubungan antar-node, serta melakukan modifikasi data tanpa memutus relasi antar-elemen. Oleh karena itu, _Doubly Linked List_ menjadi dasar penting dalam pengembangan struktur data yang lebih efisien dan mudah dikembangkan di berbagai aplikasi pemrograman.

---

## Referensi
1. GeeksforGeeks. (2024). [_Doubly Linked List in C++_](https://www.geeksforgeeks.org/doubly-linked-list/)
2. Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). _Data Structures and Algorithms in C++_. Wiley.
3. Indahyati, U., & Rahmawati, Y. (2020). _Algoritma dan Pemrograman dalam Bahasa C++_. Umsida Press.
4. Kurniawan, A., & Susanto, D. (2021). “Implementasi Linked List dalam Pengelolaan Data Dinamis.” _Jurnal Ilmiah Informatika_, 7(1).
5. Malik, D. S. (2018). _C++ Programming: From Problem Analysis to Program Design_. Cengage Learning.
6. Malik, D. S. (2018). _Data Structures Using C++_. Cengage Learning.
7. Modul Praktikum Struktur Data. **Modul 06 – Doubly Linked List (Bagian Pertama)**, Telkom University, 2025.
8. Stroustrup, B. (2013). _The C++ Programming Language_ (4th Edition). Addison-Wesley.
9. TutorialsPoint. (2024). [_C++ Doubly Linked List_](https://www.tutorialspoint.com/cplusplus/cpp_doubly_linked_list.htm)