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
