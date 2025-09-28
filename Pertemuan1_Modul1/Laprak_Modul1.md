# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Yossika Putra Erlangga - 103112430026</p>

## Dasar Teori
Bahasa pemrograman C++ merupakan salah satu dasar penting dalam pembelajaran algoritma karena mendukung paradigma prosedural dan berorientasi objek. C++ banyak digunakan untuk melatih kemampuan logika, pemrosesan input-output, serta pengelolaan struktur data [1].

Pada praktikum ini, soal pertama menekankan pada penggunaan tipe data float dan operator aritmatika untuk melakukan perhitungan matematis dasar [2]. Soal kedua melibatkan percabangan untuk mengonversi angka menjadi teks, yang umum diterapkan pada aplikasi keuangan maupun sistem pelaporan otomatis [3]. Sedangkan soal ketiga melatih penggunaan nested loop untuk membentuk pola, yang berguna pada pemrosesan data bertingkat [4].

## A. Dasar Pemrograman C++  

1. **Struktur Program C++**  
   Program C++ biasanya terdiri dari:  
   - `#include <iostream>` → library standar input-output  
   - `int main()` → fungsi utama yang pertama kali dijalankan  
   - `{ ... }` → blok kode perintah  

   Contoh:  
   ```cpp
   #include <iostream>
   using namespace std;

   int main() {
       cout << "Hello World!" << endl;
       return 0;
   }
   ```

2. **Tipe Data**  
   - `int` → bilangan bulat (contoh: 5, -10)  
   - `float` / `double` → bilangan desimal (contoh: 3.14, -2.5)  
   - `char` → karakter tunggal (contoh: 'A', 'z')  
   - `string` → teks (contoh: "Hello")  
   - `bool` → logika benar/salah (true/false)  

3. **Operator Aritmatika**  
   - Penjumlahan (`+`)  
   - Pengurangan (`-`)  
   - Perkalian (`*`)  
   - Pembagian (`/`)  
   - Modulus (`%`)  

---

## B. Input dan Output  

1. **Fungsi `cin` (input)**  
   Digunakan untuk membaca masukan dari pengguna.  
   ```cpp
   int angka;
   cin >> angka;
   ```

2. **Fungsi `cout` (output)**  
   Digunakan untuk menampilkan keluaran ke layar.  
   ```cpp
   cout << "Nilai: " << angka << endl;
   ```

3. **Kombinasi Input-Output**  
   Input dapat diproses lalu langsung ditampilkan.  
   ```cpp
   int x, y;
   cin >> x >> y;
   cout << "Hasil penjumlahan: " << x + y << endl;
   ```

---

## C. Percabangan  

1. **If–Else**  
   Digunakan untuk membuat keputusan berdasarkan kondisi.  
   ```cpp
   if (x > y) {
       cout << "x lebih besar" << endl;
   } else if (x < y) {
       cout << "y lebih besar" << endl;
   } else {
       cout << "x dan y sama" << endl;
   }
   ```

2. **Switch–Case**  
   Cocok digunakan jika banyak pilihan.  
   ```cpp
   int pilihan;
   cin >> pilihan;
   switch(pilihan) {
       case 1: cout << "Menu 1"; break;
       case 2: cout << "Menu 2"; break;
       default: cout << "Pilihan salah";
   }
   ```

---

## D. Perulangan  

1. **For Loop**  
   Digunakan jika jumlah iterasi sudah diketahui.  
   ```cpp
   for (int i = 1; i <= 5; i++) {
       cout << i << " ";
   }
   ```

2. **While Loop**  
   Digunakan jika perulangan berdasarkan kondisi.  
   ```cpp
   int j = 5;
   while (j > 0) {
       cout << j << " ";
       j--;
   }
   ```

3. **Do–While Loop**  
   Menjalankan perintah minimal sekali sebelum cek kondisi.  
   ```cpp
   int k = 1;
   do {
       cout << k << " ";
       k++;
   } while (k <= 5);
   ```


## Guided 

### 1. Praktikum belajar materi dasar Pengenalan Basic C++ dari Tutorial Install - Praktek Hello World

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello Telkom Jaya Jaya"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}

```
Guided 1 membahas cara membuat program basic Hello World

### 2. Mengerjakan Program Input Output

```C++
#include<iostream>
using namespace std;

int main()
{
    int angka;
    cout << "masukkan angka: ";
    cin >> angka;
    cout << "Angka yang dimasukkan: " << angka << endl;
    return 0;
}
```
Program Guided 2 ini diminta untuk memasukan input dan mengeluarkan output

### 3. Mengerjakan Program Operator Aritmatika

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "Hasil penjumlahan: " << angka1 + angka2 << endl;
    cout << "Hasil pengurangan: " << angka1 - angka2 << endl;
    cout << "Hasil perkalian: " << angka1 * angka2 << endl;
    cout << "Hasil pembagian: " << angka1 / angka2 << endl;
    cout << "Hasil modulus: " << angka1 % angka2 << endl;
    return 0;
    
}
```
Guided 3 di minta untuk mengerjakan program aritmatika yang dimana ada Penjumlahan, Pengurangan, Perkalian, Pembagian, dan Modulus

### 4. Mengerjakan Program Percabangan

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    if (angka1 > angka2) {
        cout << " kurang dari " << endl;
    } else if (angka1 < angka2) {
        cout << " lebih dari " << endl;
    }

    if (angka1 == angka2) {
        cout << " sama dengan " << endl;
    } else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "Menu" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. pengurangan" << endl;
    cout << "masukkan pilihan : " ;
    cin >> pilihan;
    
    switch (pilihan) {
        case 1:
        cout << "penjumlahan: " << angka1 + angka2 << endl;
        cout << endl;
        break;
        case 2:
        cout << "pengurangan: " << angka1 - angka2 << endl;
        cout << endl;
        break;
        default:
        cout << "pilihan salah" << endl;
    }

    return 0;
}
```
Guided 4 di minta untuk mengerjakan program percabangan yang dimana percabangan ini kita bisa menentukan hasil mana yang nantinya akan keluar, ada penjumlahan dan pengurangan

### 5. Mengerjakan Program Perulangan

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1;
    cout << "Masukkan angka: ";
    cin >> angka1;
    
    for (int i = 1; i <= angka1; i++) {
        cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1) {
        cout << j << " - ";
        j--;
    }

    cout << endl;
    int k = 10;
    do{
        cout << k << " - ";
    } while (k < angka1);

    return 0;
    
    }


```
Guided 5 di minta untuk mengerjakan program perulangan yang dimana kita bisa mengulang berapa banyak tergantung dari input user

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "Hasil Penjumlahan: " << a + b << endl;
    cout << "Hasil Pengurangan: " << a - b << endl;
    cout << "Hasil Perkalian: " << a * b << endl;
    if (b != 0)
        cout << "Hasil Pembagian: " << a / b << endl;
    else
        cout << "Pembagian tidak dapat dilakukan (b = 0)" << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan1_Modul1/output/Output-Unguided1-Modul1.png)


Program ini bertujuan menampilkan hasil perhitungan aritmetika dari dua angka bertipe float. Alurnya cukup mudah: pertama membaca input, lalu menjalankan empat operasi dasar (penjumlahan, pengurangan, perkalian, dan pembagian). Saat melakukan pembagian, program dilengkapi pengecekan sederhana agar tidak terjadi kesalahan jika penyebut bernilai nol.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.
Contoh: 79 → tujuh puluh sembilan

```C++
#include <iostream>
#include <string>
using namespace std;

string angkaSatuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", 
                        "enam", "tujuh", "delapan", "sembilan"};
string angkaBelasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", 
                         "empat belas", "lima belas", "enam belas", 
                         "tujuh belas", "delapan belas", "sembilan belas"};
string angkaPuluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", 
                         "lima puluh", "enam puluh", "tujuh puluh", 
                         "delapan puluh", "sembilan puluh"};

string terbilang(int n) {
    if (n < 10) return angkaSatuan[n];
    else if (n < 20) return angkaBelasan[n - 10];
    else if (n < 100) {
        int puluh = n / 10;
        int satuan = n % 10;
        if (satuan == 0) return angkaPuluhan[puluh];
        else return angkaPuluhan[puluh] + " " + angkaSatuan[satuan];
    } else if (n == 100) {
        return "seratus";
    }
    return "";
}

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;
    if (n >= 0 && n <= 100) {
        cout << n << " : " << terbilang(n) << endl;
    } else {
        cout << "Angka di luar jangkauan!" << endl;
    }
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan1_Modul1/output/Output-Unguided2-Modul1.png)


Program mengubah input bilangan bulat 0–100 menjadi teks dengan memanfaatkan array string sebagai penyimpan kata angka. Percabangan digunakan untuk membedakan kasus satuan, belasan, puluhan, hingga seratus.

### 3. Buatlah program yang dapat memberikan input dan output sebagai berikut.
Input: 3
Output:  
```
321 * 123
21 * 12
1 * 1
   *
```

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;
    cout << "output:\n";

    for (int i = n; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << " * ";
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }

    for (int spasi = 1; spasi <= n; spasi++) {
        cout << " ";
    }
    cout << "*" << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan1_Modul1/output/Output-Unguided3-Modul1.png))


Program menghasilkan pola angka simetris dengan simbol * di tengah. Angka di kiri menurun dari n ke 1, sedangkan di kanan naik dari 1 ke n, dan jumlahnya berkurang tiap baris hingga tersisa satu angka lalu ditutup dengan * di bagian bawah.

## Kesimpulan
Dari praktikum ini aku jadi lebih paham dasar-dasar C++ mulai dari input-output sederhana, operator aritmatika, sampai percabangan dan perulangan. Ternyata konsep-konsep dasar ini saling berkaitan, misalnya percabangan bisa digabung dengan perulangan untuk menghasilkan program yang lebih fleksibel. Soal-soal unguided juga lumayan membantu untuk mengasah logika, apalagi waktu bikin konversi angka ke teks dan pola angka pakai nested loop. Intinya, materi di modul ini benar-benar penting sebagai pondasi sebelum masuk ke topik C++ yang lebih lanjut.

## Referensi
[1] N. Josuttis, The C++ Programming Language: Concepts, Libraries, Tools, and Techniques. Springer, 2019.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] M. Aziz, A. Wicaksono, dan R. Rahim. (2021). "Implementasi Algoritma Konversi Angka ke Teks dalam Aplikasi Keuangan." Jurnal Teknologi dan Sistem Informasi, vol. 7, no. 2, hlm. 45–52.
<br>[4] A. Kurniawan dan D. Susanto. (2020). "Pemanfaatan Nested Loop dalam Algoritma Pengolahan Data." Jurnal Ilmiah Informatika, vol. 6, no. 1, hlm. 23–30.