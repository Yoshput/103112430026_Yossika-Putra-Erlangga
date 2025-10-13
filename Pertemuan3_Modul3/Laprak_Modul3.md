# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Yossika Putra Erlangga - 103112430026</p>

---

## Dasar Teori

**Abstract Data Type (ADT)** merupakan model atau konsep data yang mendefinisikan **apa yang dapat dilakukan oleh suatu tipe data**, tanpa menjelaskan **bagaimana cara kerjanya di dalam**.  
Dengan kata lain, ADT hanya berfokus pada **spesifikasi data dan operasi** yang bisa dilakukan, bukan pada implementasinya (Indahyati & Rahmawati, 2020) [2].

Dalam pemrograman C++, ADT biasanya diwujudkan melalui:
- **`struct` atau `class`** sebagai wadah data,
- **fungsi (operasi)** untuk memanipulasi data tersebut,
- serta **pemisahan file** antara *header* (`.h`) dan *implementasi* (`.cpp`).

### Tujuan ADT:
1. **Memisahkan spesifikasi dan implementasi** agar kode lebih mudah dipahami.  
2. **Modularitas**, memungkinkan pengembangan terpisah.  
3. **Reusability**, bagian kode bisa digunakan kembali.  
4. **Kemudahan perawatan**, karena perubahan di satu modul tidak memengaruhi keseluruhan program (Indahyati & Rahmawati, 2020) [2].

### Ciri-Ciri ADT:
- Memiliki **definisi data** (misal `struct mahasiswa`).
- Memiliki **operasi** untuk mengolah data tersebut (`inputMhs`, `rata2`).
- Detail implementasi **disembunyikan** dari pengguna.

---

## Dasar Pemrograman

### 1. Struktur File ADT
Implementasi ADT di C++ umumnya dibagi menjadi tiga file:
| Jenis File | Fungsi | Contoh |
|-------------|---------|--------|
| Header (`.h`) | Berisi deklarasi struct dan fungsi | mahasiswa.h |
| Implementasi (`.cpp`) | Berisi realisasi fungsi | mahasiswa.cpp |
| Program utama (`main.cpp`) | Menjalankan fungsi-fungsi dari ADT | main.cpp |

---

### Penjelasan Program
- Struct `mahasiswa` merepresentasikan tipe data abstrak (ADT) dengan atribut `nim`, `nilai1`, dan `nilai2`.
- Fungsi `inputMhs()` digunakan untuk **mengisi data mahasiswa**.
- Fungsi `rata2()` digunakan untuk **menghitung rata-rata nilai**.
- `main()` hanya memanggil operasi dari ADT, tanpa tahu cara kerja internalnya — inilah esensi dari konsep ADT.

---

## Guided

## Guided 1 – Pengenalan ADT Mahasiswa
## File: `mahasiswa.h`
```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif

```
## File: `mahasiswa.cpp`
```cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```
## File: `main.cpp`
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);
    cout << "Rata-rata nilai adalah: " << rata2(mhs) << endl;

    return 0;
}

```
## Guided2 - Mahasiswa2.cpp - versi sederhana tidak perlu pemisahan file

```C++
#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m) {
    cout << "Masukkan nama mahasiswa : ";
    cin >> m.nama;
    cout << "Masukkan nilai 1 : ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2 : ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return float (m.nilai1 + m.nilai2) / 2;
}

int main() {
    mahasiswa mhs;   
    inputMhs(mhs);   
    cout << "Rata-rata : " << rata2(mhs) << endl;   
    return 0;
}

```

---

### Unguided
## Soal1
Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus:

0.3 * uts + 0.4 * uas + 0.3 * tugas

---
#### File: `Unguided1.cpp`

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilai_akhir;
};

// Fungsi untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

// Prosedur untuk menampilkan data mahasiswa
void tampilkanData(Mahasiswa mhs[], int jumlah) {
    cout << "\nDaftar Nilai Mahasiswa:\n";
    cout << left << setw(15) << "Nama"
         << setw(15) << "NIM"
         << setw(10) << "UTS"
         << setw(10) << "UAS"
         << setw(10) << "Tugas"
         << setw(15) << "Nilai Akhir" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(15) << mhs[i].nama
             << setw(15) << mhs[i].nim
             << setw(10) << mhs[i].uts
             << setw(10) << mhs[i].uas
             << setw(10) << mhs[i].tugas
             << setw(15) << fixed << setprecision(2) << mhs[i].nilai_akhir
             << endl;
    }
}

int main() {
    Mahasiswa mhs[10];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlah;

    if (jumlah > 10) jumlah = 10;

    // Input data mahasiswa
    for (int i = 0; i < jumlah; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin >> mhs[i].nama;
        cout << "NIM    : ";
        cin >> mhs[i].nim;
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;

        // Hitung nilai akhir
        mhs[i].nilai_akhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    // Tampilkan hasil data mahasiswa
    tampilkanData(mhs, jumlah);

    return 0;
}

```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan3_Modul3/output/Output-Unguided1-Modul3.png)
---
Program di atas adalah program C++ untuk menghitung dan menampilkan nilai akhir mahasiswa. Data yang dimasukkan meliputi nama, NIM, nilai UTS, UAS, dan tugas. Nilai akhir dihitung dengan rumus 30% UTS, 40% UAS, dan 30% tugas. Setelah semua data dimasukkan, program menampilkan hasilnya dalam bentuk tabel yang rapi di layar.

---
## Soal2
Buatlah ADT pelajaran sebagai berikut di dalam file **“pelajaran.h”**:

tipe `pelajaran`
<  
 namaMapel : string  
 kodeMapel : string  
>

Function `create_pelajaran(namapel : string, kodepel : string) → pelajaran`  
Procedure `tampil_pelajaran(input pel : pelajaran)`  

---

Buatlah implementasi ADT pelajaran pada file **“pelajaran.cpp”**  
Cobalah hasil implementasi ADT pada file **“main.cpp”**



### Contoh Output Hasil
```
nama pelajaran : Struktur Data
nilai : STD
```

```C++
using namespace std;
int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
---

```
#### File: `Main.cpp`

```cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
Progam di atas hanya berisi pemanggilan fungsi dari ADT, tanpa detail implementasi — sesuai konsep abstraksi pada ADT.

#### File: `pelajaran.cpp`

```cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
Progran di atas merupakan bagian implementasi dari ADT, artinya seluruh logika dari fungsi yang dideklarasikan di header ada di sini.

#### File: `pelajaran.h`

```cpp
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif

```
jadi Program di atas hanya berisi definisi tipe data dan deklarasi fungsi, belum ada isi programnya.
Inilah ciri khas ADT — memisahkan spesifikasi (header) dari implementasi (cpp).

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan3_Modul3/output/Output-Unguided2-Modul3.png)
---
Program ketiga ini intinya nunjukin cara pakai konsep **ADT (Abstract Data Type)** di C++. Jadi, programnya dibagi jadi tiga file biar rapi: `pelajaran.h` buat ngedefinisiin struktur data dan nama fungsi, `pelajaran.cpp` buat isinya (cara kerja fungsi), dan `main.cpp` buat ngejalanin programnya. Di sini ada tipe data `pelajaran` yang nyimpen nama dan kode mapel, terus ada fungsi `create_pelajaran()` buat bikin datanya dan `tampil_pelajaran()` buat nampilin hasilnya. Program utamanya cuma manggil fungsi itu tanpa tahu dalemannya kayak gimana. Tujuannya biar kodenya gampang dibaca, diubah, dan keliatan lebih teratur — sesuai banget sama konsep ADT di Modul 3 [2].

## Soal3

Buatlah program dengan ketentuan:

*2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer*

*Fungsi/prosedur yang menampilkan isi sebuah array integer 2D*

*Fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu*

*Fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer*

---

#### File: `Unguided3.cpp`

```cpp
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int x = 10, y = 20;
    int *ptrX = &x;
    int *ptrY = &y;

    cout << "Array A sebelum pertukaran:\n";
    tampilArray(A);
    cout << "\nArray B sebelum pertukaran:\n";
    tampilArray(B);

    tukarPosisi(A, B, 1, 2);

    cout << "\nArray A setelah pertukaran elemen [1][2]:\n";
    tampilArray(A);
    cout << "\nArray B setelah pertukaran elemen [1][2]:\n";
    tampilArray(B);

    cout << "\nNilai sebelum ditukar (x dan y):\n";
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(ptrX, ptrY);

    cout << "Nilai setelah ditukar:\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}


```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan3_Modul3/output/Output-Unguided3-Modul3.png)
---
Program ini intinya nunjukin gimana cara kerja array 2 dimensi dan pointer di C++. Di dalamnya ada dua array 3x3 yang isinya bisa ditukar di posisi tertentu, dan ada dua pointer yang juga bisa saling tukar nilai yang mereka tunjuk. Ada fungsi buat nampilin isi array, biar keliatan bedanya sebelum dan sesudah ditukar. Jadi, lewat program ini kita bisa lihat gimana cara ngatur data di memori pake array dan pointer dengan cara yang sederhana, sesuai pembahasan di Modul 3 [2].


## Kesimpulan
1. **Abstract Data Type (ADT)** membantu pemrograman menjadi modular dan terorganisasi.  
2. ADT hanya mendeskripsikan **apa yang dilakukan** suatu tipe data, bukan **bagaimana cara melakukannya**.  
3. Dengan ADT, kode program lebih mudah dikelola, diuji, dan digunakan kembali tanpa perlu memahami detail implementasi di dalamnya.

---

## Referensi
[1] Stroustrup, Bjarne. *The C++ Programming Language*, 4th Edition. Addison-Wesley, 2013.  
[2] Indahyati, Uce & Rahmawati, Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Umsida Press.  
[3] Kurniawan, A., & Susanto, D. (2021). “Penerapan Abstraksi Data dalam Pengembangan Sistem Modular.” *Jurnal Ilmiah Informatika*, vol. 6, no. 2.  
[4] Josuttis, N. (2019). *The C++ Programming Language: Concepts, Libraries, Tools, and Techniques*. Springer.

