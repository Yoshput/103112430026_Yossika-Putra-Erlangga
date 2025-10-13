#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

// Definisi tipe data ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Fungsi untuk membuat data pelajaran baru
pelajaran create_pelajaran(string namapel, string kodepel);

// Prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif
