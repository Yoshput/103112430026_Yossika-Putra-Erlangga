# Laporan Praktikum Modul 7 – Stack
<p align="center">Yossika Putra Erlangga - 103112430026</p>

---
## Dasar Teori

**Stack** adalah struktur data linear yang mengikuti prinsip **LIFO (Last In First Out)**, yaitu elemen yang terakhir masuk merupakan elemen pertama yang akan dikeluarkan [2]. Konsep ini mirip seperti tumpukan buku: buku yang berada paling atas adalah yang dapat diambil terlebih dahulu.

Stack memiliki satu pointer utama yaitu **TOP**, yang menunjuk ke elemen paling atas dari stack. Dua operasi utama dalam stack adalah:

1. **Push** – menambahkan elemen baru ke bagian atas stack.
2. **Pop** – menghapus elemen teratas dari stack.

Stack dapat direpresentasikan menggunakan:
- **Pointer (linked list)** – bersifat dinamis, ukuran dapat berubah sesuai alokasi memori.
- **Array (tabel)** – ukuran tetap, menggunakan indeks untuk berpindah antar elemen [5].

Komponen dasar stack:
- **TOP → pointer atau indeks yang menunjuk elemen paling atas**
- **Info → nilai yang disimpan dalam elemen stack**

Struktur data stack banyak digunakan pada:
- proses *undo-redo* aplikasi,
- sistem pemanggilan fungsi (*call stack*),
- evaluasi ekspresi aritmatika,
- parsing dalam compiler,
- navigasi web (back-forward) [6].

---

## Dasar Pemrograman

Dalam pemrograman C++, stack dapat dibuat menggunakan struktur pointer maupun array.

### 1. Stack dengan Pointer
Menggunakan node dinamis dengan pointer `next`. Operasi push sama dengan menyisipkan node di awal linked list, sedangkan pop menghapus node pertama.

Struktur dasar:
```cpp
struct elmStack {
    infotype info;
    address next;
};

struct stack {
    address Top;
};
```
Operasi yang diimplementasikan meliputi:
- `createStack()` – membuat stack kosong dengan Top = NULL.
- `push()` – menambahkan elemen di atas stack.
- `pop()` – mengambil elemen teratas.
- `isEmpty()` – memeriksa apakah stack kosong.
- operasi pendukung lainnya seperti `alokasi()`, `dealokasi()`.

### 2. Stack dengan Array
Menggunakan indeks untuk menunjuk elemen, dengan batasan kapasitas tertentu.
```cpp
struct Stack {
    int info[20];
    int Top;
};
```
Pada operasi push: `Top = Top + 1`,
Pada pop: `Top = Top - 1`.

Alasan penggunaan array:
- Implementasi sederhana,
- Tidak memerlukan pointer,
- Kontrol alokasi memori lebih mudah.

Namun array bersifat statis sehingga ukuran stack terbatas [2].

---

## Guided 1 – Implementasi Stack Pointer (Push & Pop)

### stack.h
```cpp
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

### stack.cpp
```cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

### main.cpp
```cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

```

```

### Penjelasan

Pada unguided 3, fungsi **getInputStream** digunakan untuk membaca input karakter satu per satu dari pengguna hingga menekan tombol ENTER. Setiap karakter yang dimasukkan langsung didorong ke dalam stack. Karena stack bekerja secara LIFO, saat data ditampilkan, karakter yang terakhir diketik muncul pertama. Untuk menampilkan dalam urutan asli, fungsi **balikStack** digunakan sehingga karakter ditampilkan sesuai urutan ketika pengguna mengetiknya.

---

## Guided 2 – Stack Array (push, pop, balikStack)

### stack.h
```cpp
#ifndef STACK_H

#define MaxEl 20
#define Nil -1

#include <iostream>
using namespace std;

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

### stack.cpp
```cpp
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```

### main.cpp
```cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
### Penjelasan
Pada guided 2 ini, stack dibuat menggunakan array dengan batasan ukuran tertentu. Variabel `Top` digunakan sebagai penanda posisi elemen teratas. Saat melakukan **push**, nilai baru dimasukkan ke indeks `Top`, kemudian indeks dinaikkan satu. Saat melakukan **pop**, indeks `Top` diturunkan dan nilai pada indeks tersebut dikembalikan. Fungsi **balikStack** bekerja dengan membuat stack sementara untuk membalik urutan elemen, sehingga elemen terbawah menjadi teratas sesuai proses pemindahan satu per satu.
Tuliskan penjelasan Anda tentang cara kerja stack berbasis array: bagaimana indeks TOP berubah, bagaimana proses pembalikan stack, dan bagaimana data disimpan serta diambil.

---

# UNGUIDED

## Unguided 1 – ADT Stack Array

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file "stack.h":
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan7_Modul7/output/Soal1_unguided1.png)

### Buatlah implementasi ADT Stack menggunakan Array pada file "stack.cpp" dan "main.cpp"

![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan7_Modul7/output/Soal2_unguided1.png)


### stack.h
```cpp
#ifndef STACK_H
#define STACK_H

const int MAX = 20;
typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

// Prosedur dasar
void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif


```

### stack.cpp
```cpp
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

bool isEmpty(Stack S) {
    return S.top == 0;
}

bool isFull(Stack S) {
    return S.top == MAX;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.info[S.top] = x;
        S.top++;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        S.top--;
        return S.info[S.top];
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}

```

### main.cpp
```cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan7_Modul7/output/output-Unguided1-Modul7.png)
### Penjelasan :

Pada unguided 1, program mengimplementasikan stack menggunakan array berukuran tetap sebagai media penyimpanan. Setiap data dimasukkan menggunakan fungsi **push**, yang menempatkan nilai pada indeks `Top` lalu menaikkan nilai `Top`. Sebaliknya, **pop** akan menurunkan `Top` dan mengembalikan elemen teratas sesuai prinsip LIFO. Setelah beberapa operasi push dan pop dilakukan, fungsi **printInfo** digunakan untuk menampilkan isi stack dari elemen paling atas ke bawah. Lalu fungsi **balikStack** dipanggil untuk membalik urutan stack dengan bantuan stack sementara, sehingga urutan elemennya terbalik dari sebelumnya. Program ini menunjukkan pemahaman dasar mengenai manajemen data menggunakan stack berbasis array.

---

## Unguided 2 – pushAscending

### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)
![Screenshot Output Unguided 2_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan7_Modul7/output/Soal2_unguided2.png)

```cpp
void pushAscending(Stack &S, int x){
    Stack Temp;
    createStack(Temp);

    while(S.Top != 0 && S.info[S.Top-1] > x)
        push(Temp, pop(S));

    push(S, x);

    while(Temp.Top != 0)
        push(S, pop(Temp));
}
```

Main:
```cpp
pushAscending(S,3);
pushAscending(S,4);
pushAscending(S,8);
pushAscending(S,2);
pushAscending(S,3);
pushAscending(S,9);
printInfo(S);
```
##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan7_Modul7/output/output_Unguided2_Modul7.png)
### Penjelasan :
Pada unguided 2, fungsi **pushAscending** dibuat agar data yang dimasukkan tetap tersimpan dalam keadaan terurut dari kecil ke besar. Karena stack tidak mendukung penyisipan di tengah, maka digunakan stack sementara untuk menyimpan elemen yang lebih besar dari nilai yang akan dimasukkan. Setelah menemukan posisi yang tepat, nilai baru dimasukkan ke stack utama lalu seluruh elemen dari stack sementara dikembalikan ke stack awal sehingga tatanan ascending tetap terjaga. Dengan teknik ini, stack dapat dikelola seperti struktur terurut meskipun secara alami hanya mendukung operasi push dan pop di bagian atas.

---

## Unguided 3 – getInputStream

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

![Screenshot Output Unguided 3_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan7_Modul7/output/Soal3_unguided3.png)

### Kode C++(Stack)

```cpp
void getInputStream(Stack &S){
    char ch;
    cout << "Masukkan karakter, ENTER untuk berhenti: ";
    while(true){
        ch = cin.get();
        if(ch == '
') break;
        push(S, ch);
    }
}
```

Main:
```cpp
getInputStream(S);
printInfo(S);
balikStack(S);
printInfo(S);
```

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan7_Modul7/output/output-Unguided3-Modul7.png)
### Penjelasan :
Pada unguided 3, program membaca input karakter dari pengguna satu per satu melalui fungsi **getInputStream**, kemudian setiap karakter langsung dimasukkan ke stack. Karena stack menerapkan prinsip LIFO, karakter terakhir yang dimasukkan akan berada di posisi teratas sehingga saat stack ditampilkan urutannya menjadi terbalik dari input asli. Untuk mengembalikan urutan seperti saat pengguna mengetik, digunakan fungsi **balikStack** yang memindahkan elemen-elemen ke stack sementara sehingga urutannya dibalik kembali. Program ini memperlihatkan bagaimana stack dapat digunakan untuk memanipulasi urutan data berbasis input pengguna.

---
## Kesimpulan
Pada modul ini mahasiswa memahami konsep **Stack** sebagai struktur data LIFO, serta implementasinya dalam dua bentuk: pointer dan array. Operasi utama seperti `push`, `pop`, dan manipulasi stack seperti `balikStack`, `pushAscending`, serta input stream telah dipraktikkan. Pemahaman stack sangat penting karena digunakan luas pada call stack, parsing, algoritma, dan aplikasi sehari-hari.

---

## Referensi
1. GeeksforGeeks. (2024). *Stack Data Structure*.
2. Goodrich, M., Tamassia, R., Goldwasser, M. (2014). *Data Structures & Algorithms in C++*.
3. Malik, D. S. (2018). *Data Structures Using C++*.
4. Kurniawan, A. (2021). *Struktur Data dalam Bahasa C++*.
5. Modul Praktikum Struktur Data. **Modul 07 – Stack**, Telkom University, 2025.

