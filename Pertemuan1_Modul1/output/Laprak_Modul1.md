# Laporan Praktikum Modul 1  
**Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)**  
Yossika Putra Erlangga - 103112430026  

---

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

---

## Kesimpulan  
Dari praktikum ini dipelajari dasar-dasar pemrograman C++: struktur program, tipe data, input-output, operator, percabangan, dan perulangan. Semua konsep ini saling terkait dan menjadi pondasi sebelum melangkah ke materi C++ yang lebih kompleks.  

## Referensi  
1. N. Josuttis, *The C++ Programming Language: Concepts, Libraries, Tools, and Techniques*. Springer, 2019.  
2. Indahyati, Uce., Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Umsida Press.  
3. M. Aziz, A. Wicaksono, dan R. Rahim. (2021). "Implementasi Algoritma Konversi Angka ke Teks dalam Aplikasi Keuangan." *Jurnal Teknologi dan Sistem Informasi*, vol. 7, no. 2.  
4. A. Kurniawan dan D. Susanto. (2020). "Pemanfaatan Nested Loop dalam Algoritma Pengolahan Data." *Jurnal Ilmiah Informatika*, vol. 6, no. 1.  
