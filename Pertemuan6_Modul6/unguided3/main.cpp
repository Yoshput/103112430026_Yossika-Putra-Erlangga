#include <iostream>
#include <string>
#include "doublylist3.h" 
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

    // Input data kendaraan
    while (count < jumlahInput) {
        infotype x;
        cout << "Masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "Masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (cekDuplikat(L, x.nopol)) {
            cout << "Nomor polisi sudah terdaftar!\n";
            continue; // tidak menambah count
        }

        address P = alokasi(x);
        insertLast(L, P);
        count++; // hanya naik kalau data berhasil disimpan
    }

    // Setelah loop selesai, tampilkan hasil
    cout << "\n=== Daftar Kendaraan Terdaftar ===\n";
    printInfo(L);

    // Fitur pencarian kendaraan berdasarkan nomor polisi
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


    return 0;
}
