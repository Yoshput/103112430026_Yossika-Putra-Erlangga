# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Yossika Putra Erlangga - 103112430026</p>

## Dasar Teori
Bahasa pemrograman **C++** merupakan bahasa tingkat menengah yang dikembangkan oleh **Bjarne Stroustrup** pada awal 1980-an sebagai pengembangan dari bahasa C dengan fitur **class** dan **object** [1]. C++ mendukung paradigma pemrograman prosedural, modular, maupun berorientasi objek [2].

Struktur program C++ secara umum terdiri dari **header file**, **fungsi utama (`main()`)**, serta blok kode instruksi. Beberapa konsep dasar yang penting dipahami, antara lain:

1. **Variabel dan Tipe Data**  
   Variabel menyimpan nilai tertentu, sementara tipe data menentukan jenis nilai yang dapat ditampung (misalnya `int`, `float`, `char`, `string`) [3].

2. **Operator**  
   Operator digunakan untuk melakukan operasi terhadap data, seperti operator aritmatika (`+`, `-`, `*`, `/`), relasi (`<`, `>`, `==`), logika (`&&`, `||`, `!`), serta assignment (`=`) [2].

3. **Struktur Kontrol**  
   Struktur kontrol digunakan untuk mengatur alur eksekusi program, seperti percabangan (`if`, `if-else`, `switch`) maupun perulangan (`for`, `while`, `do-while`) [3].

4. **Fungsi**  
   Fungsi merupakan blok kode terpisah yang dapat dipanggil ulang. Dengan fungsi, program menjadi modular dan mudah dipelihara [1].

5. **Array**  
   Array adalah struktur data yang menyimpan sekumpulan elemen bertipe sama dan diakses dengan indeks [4].

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

### 1. Praktikum belajar tentang array1 dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }

    int j = 0;
    while (j < 5) {
        cout << "Isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }

    return 0;
}

```
Guided 1 membahas cara membuat program array1 dimensi

### 2. Mengerjakan Program array2 dimensi

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan :" << endl;
    tampilkanHasil(arrC);

    cout << endl;

    //perkalian matriks 2x2
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arrD[i][j] = 0; 
            for(int k = 0; k < 2; k++){
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian :" << endl;
    tampilkanHasil(arrD);

    return 0;
}

```
Program di atas diminta untuk melakukan operasi matriks 2x2, penjumlahan dan perkalian

### 3. Mengerjakan Program Arrnpointer

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Pointer menunjuk ke elemen pertama

    // Cetak menggunakan pointer
    for (int i = 0; i < 5; ++i) {
        cout << "Elemen array ke-" << i + 1  << " menggunakan pointer: " << *(ptr + i) 
        << endl;
    }

    // Cetak menggunakan indeks
    for (int i = 0; i < 5; ++i) {
        cout << "Elemen array ke-" << i + 1 <<"menggunakan indeks:" << arr[i] 
        << endl;
    }

    return 0;
}

```
Guided 3 di minta untuk memperlihatkan perbedaan (tapi hasil sama) antara akses array lewat pointer dan lewat indeks.

### 4. Mengerjakan Program Fungsi Prosedur

```C++
#include <iostream>
using namespace std;

// Fungsi untuk mencari nilai maksimum dalam array
int cariMax(int arr[], int ukuran) {
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > MAX) {
            MAX = arr[i];
        }
    }
    return MAX;
}

// Prosedur untuk menghitung total penjumlahan
void operasiAritmatika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "Total penjumlahan : " << totalJumlah << endl;
}

// Prosedur untuk menghitung total perkalian
void operasiPerkalian(int arr[], int ukuran) {
    int totalKali = 1;
    for (int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "Total perkalian   : " << totalKali << endl;
}

int main() {
    const int ukuran = 5;
    int arr[ukuran];

    // Input elemen array
    for (int i = 0; i < ukuran; i++) {
        cout << "Masukan nilai array ke-" << i + 1 << " : ";
        cin >> arr[i];
    }

    cout <<endl;
    cout << "nilai terbesar dalam array : " << cariMax(arr, ukuran) << endl;
   
    operasiAritmatika(arr, ukuran);
    return 0;
}

```
Guided 4 di minta untuk membaca 5 data dari user, mencari nilai terbesar, menghitung jumlah semua elemen, dan menampilkannya di output.


## Unguided 

### Soal 1 : Operasi Matriks 3x3

### Deskripsi
Diketahui 2 buah matriks 3x3 berikut:

\[
A = 
\begin{bmatrix}
7 & 12 & 22 \\
31 & 6 & 41 \\
15 & 19 & 36
\end{bmatrix}
\quad
B = 
\begin{bmatrix}
11 & 34 & 7 \\
3 & 25 & 41 \\
5 & 18 & 33
\end{bmatrix}
\]

Buatlah program yang dapat melakukan operasi:
1. Penjumlahan matriks  
2. Pengurangan matriks  
3. Perkalian matriks  

Menggunakan prosedur:
- `jumlahMatriks()`
- `kurangMatriks()`
- `kaliMatriks()`

Program dijalankan dengan **menu switch-case** seperti berikut:

```
--- Menu Program Matriks ---
1. Penjumlahan matriks
2. Pengurangan matriks
3. Perkalian matriks
4. Keluar
```


```C++
#include <iostream>
using namespace std;

const int N = 3;

void jumlahMatriks(int A[N][N], int B[N][N]) {
    cout << "Hasil Penjumlahan Matriks:\n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << A[i][j] + B[i][j] << " ";
        }
        cout << endl;
    }
}

void kurangMatriks(int A[N][N], int B[N][N]) {
    cout << "Hasil Pengurangan Matriks:\n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << A[i][j] - B[i][j] << " ";
        }
        cout << endl;
    }
}

void kaliMatriks(int A[N][N], int B[N][N]) {
    cout << "Hasil Perkalian Matriks:\n";
    int C[N][N] = {0};
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matriksA[N][N] = {{7,12,22},{31,6,41},{15,19,36}};
    int matriksB[N][N] = {{11,34,7},{3,25,41},{5,18,33}};
    int pilihan;

    do {
        cout << "\n--- Menu Program Matriks ---\n";
        cout << "1. Penjumlahan Matriks\n";
        cout << "2. Pengurangan Matriks\n";
        cout << "3. Perkalian Matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: jumlahMatriks(matriksA, matriksB); break;
            case 2: kurangMatriks(matriksA, matriksB); break;
            case 3: kaliMatriks(matriksA, matriksB); break;
        }
    } while(pilihan != 4);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan2_Modul2/output/Output-Unguided1-Modul1.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan2_Modul2/output/Output-Unguided1.2-Modul1.png)

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan2_Modul2/output/Output-Unguided1.3-Modul1.png)

##### Output 4
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan2_Modul2/output/Output-Unguided1.4-Modul1.png)

Program di atas dibuat untuk mengolah dua buah matriks berukuran 3x3. Operasi yang bisa dilakukan adalah penjumlahan, pengurangan, dan perkalian matriks. Setiap operasi dikerjakan melalui prosedur khusus, lalu dipanggil menggunakan menu pilihan berbasis switch-case. Dengan cara ini, pengguna cukup memilih menu yang tersedia untuk langsung melihat hasil perhitungan matriks tanpa perlu menghitung manual.

### Soal 2 : Pointer, Luas, dan Keliling Persegi Panjang

### Deskripsi
Buat program menghitung **luas dan keliling persegi panjang** dengan proses perhitungan menggunakan **pointer**.

Ketentuan:
1. Variabel awal:  
   - `panjang = 10`  
   - `lebar = 5`  
   - `luas = 0`  
2. Pointer:  
   - `ptrPanjang → panjang`  
   - `ptrLebar → lebar`  
3. Hitung luas dan keliling melalui pointer.  
4. Cetak hasil.  
5. Ubah nilai panjang = 12 dan lebar = 6 lewat pointer.  
6. Cetak ulang hasil setelah perubahan.  

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
![Screenshot Output Unguided 2_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan2_Modul2/output/Output-Unguided2-Modul2.png)


Program di atas digunakan untuk menghitung luas dan keliling persegi panjang dengan bantuan pointer. Pertama-tama program menampilkan nilai panjang dan lebar awal, lalu menghitung luas serta keliling dari nilai tersebut. Setelah itu, nilai panjang dan lebar diubah langsung melalui pointer, kemudian program menghitung ulang luas dan keliling berdasarkan nilai yang baru. Tujuannya supaya kita bisa memahami bagaimana pointer bisa dipakai untuk mengakses dan mengubah data di memori secara langsung.

## Kesimpulan
Dari kedua soal praktikum ini dapat disimpulkan bahwa penggunaan prosedur dan pointer sangat penting dalam pemrograman C++. Prosedur membantu program menjadi lebih rapi, terstruktur, dan mudah dipahami saat melakukan operasi seperti pada matriks. Sementara pointer memberikan fleksibilitas untuk mengakses serta mengubah data secara langsung, yang berguna dalam perhitungan maupun pengelolaan memori. Dengan memahami kedua konsep ini, mahasiswa dapat menyusun program yang lebih efisien dan mudah dikembangkan.

## Referensi
[1] N. Josuttis, The C++ Programming Language: Concepts, Libraries, Tools, and Techniques. Springer, 2019.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] M. Aziz, A. Wicaksono, dan R. Rahim. (2021). "Implementasi Algoritma Konversi Angka ke Teks dalam Aplikasi Keuangan." Jurnal Teknologi dan Sistem Informasi, vol. 7, no. 2, hlm. 45–52.
<br>[4] A. Kurniawan dan D. Susanto. (2020). "Pemanfaatan Nested Loop dalam Algoritma Pengolahan Data." Jurnal Ilmiah Informatika, vol. 6, no. 1, hlm. 23–30.