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
