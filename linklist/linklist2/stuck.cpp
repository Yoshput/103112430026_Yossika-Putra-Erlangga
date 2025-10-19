#include <iostream>
#include <string>
using namespace std;

#define MAX 12

// Struktur data Buku
struct Buku {
    string judul;
    string penulis;
};

// Struktur data Stack (Rak Buku)
struct RakBuku {
    Buku data[MAX];
    int top;
};

// Membuat stack kosong
void createStack(RakBuku &S) {
    S.top = -1;
}

// Mengecek apakah stack kosong
bool isEmpty(RakBuku S) {
    return (S.top == -1);
}

// Mengecek apakah stack penuh
bool isFull(RakBuku S) {
    return (S.top == MAX - 1);
}

// Menambahkan buku ke rak
void Push(RakBuku &S, string judul, string penulis) {
    if (isFull(S)) {
        cout << " Rak penuh! Tidak dapat menambah buku baru.\n";
    } else {
        S.top++;
        S.data[S.top].judul = judul;
        S.data[S.top].penulis = penulis;
        cout << " Buku \"" << judul << "\" oleh " << penulis << " ditambahkan ke rak.\n";
    }
}

// Mengambil buku paling atas
void Pop(RakBuku &S, string &judul, string &penulis) {
    if (isEmpty(S)) {
        cout << " Rak kosong! Tidak ada buku untuk diambil.\n";
    } else {
        judul = S.data[S.top].judul;
        penulis = S.data[S.top].penulis;
        S.top--;
        cout << " Buku \"" << judul << "\" oleh " << penulis << " telah diambil dari rak.\n";
    }
}

// Mengambil buku dengan judul tertentu
void Get(RakBuku &S, string judulCari, string &namaPenulis) {
    RakBuku temp;
    createStack(temp);
    string judul, penulis;
    bool ditemukan = false;

    while (!isEmpty(S)) {
        Pop(S, judul, penulis);
        if (judul == judulCari) {
            namaPenulis = penulis;
            ditemukan = true;
            break;
        } else {
            Push(temp, judul, penulis);
        }
    }

    // Kembalikan buku dari stack sementara
    while (!isEmpty(temp)) {
        Pop(temp, judul, penulis);
        Push(S, judul, penulis);
    }

    if (ditemukan) {
        cout << " Penulis buku \"" << judulCari << "\" adalah " << namaPenulis << ".\n";
    } else {
        cout << " Buku \"" << judulCari << "\" tidak ditemukan di rak.\n";
    }
}

// Menampilkan seluruh isi rak
void TampilRak(RakBuku S) {
    cout << "\n=== Daftar Buku di Rak ===\n";
    if (isEmpty(S)) {
        cout << "Rak kosong.\n";
    } else {
        for (int i = S.top; i >= 0; i--) {
            cout << "- " << S.data[i].judul << " oleh " << S.data[i].penulis << endl;
        }
    }
    cout << "==========================\n";
}

int main() {
    RakBuku rak;
    createStack(rak);

    // Tambah beberapa buku
    Push(rak, "Algoritma dan Struktur Data", "Doni Pratama");
    Push(rak, "Pemrograman C++ Dasar", "Siti Aminah");
    Push(rak, "Sistem Operasi Modern", "Andi Saputra");

    // Tampilkan isi rak
    TampilRak(rak);

    // Ambil satu buku teratas
    string judul, penulis;
    Pop(rak, judul, penulis);

    // Tampilkan isi rak setelah pengambilan
    TampilRak(rak);

    // Cari penulis dari judul tertentu
    string namaPenulis;
    Get(rak, "Pemrograman C++ Dasar", namaPenulis);

    return 0;
}