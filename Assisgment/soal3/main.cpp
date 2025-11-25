#include <iostream>
#include <iomanip>
#include "Stackmahasiswa.h"

using namespace std;

int main()
{
    StackMahasiswa S;
    createStack(S);

    Mahasiswa m1{"Venti", "11111", 75.7f, 82.1f, 65.5f};
    Mahasiswa m2{"Xiao", "22222", 87.4f, 88.9f, 81.9f};
    Mahasiswa m3{"Kazuha", "33333", 92.3f, 88.8f, 82.4f};
    Mahasiswa m4{"Wanderer", "44444", 95.5f, 85.5f, 90.5f};
    Mahasiswa m5{"Lynette", "55555", 77.7f, 65.4f, 79.9f};
    Mahasiswa m6{"Chasca", "66666", 99.9f, 93.6f, 87.3f};

    Push(S, m1);
    Push(S, m2);
    Push(S, m3);
    Push(S, m4);
    Push(S, m5);
    Push(S, m6);

    cout << "\nSTEP 3: Tampilkan stack setelah push 6 data:" << endl;
    View(S);

    cout << "\nSTEP 4: Pop 1x" << endl;
    Mahasiswa popped;
    if (Pop(S, popped)) {
        cout << "Data yang di-pop: " << popped.Nama << " (NIM: " << popped.NIM << ")" << endl;
    } else {
        cout << "Pop gagal: stack kosong" << endl;
    }

    cout << "\nSTEP 5: Tampilkan stack setelah 1x pop:" << endl;
    View(S);

    Mahasiswa heizou{"Heizou", "77777", 99.9f, 88.8f, 77.7f};
    bool ok = Update(S, 3, heizou);
    cout << "\nSTEP 6: Update posisi ke-3: ";
    if (ok)
        cout << "Berhasil." << endl;
    else
        cout << "Gagal (posisi tidak valid)." << endl;

    cout << "\nSTEP 7: Tampilkan stack setelah update:" << endl;
    View(S);

    cout << "\nSTEP 8: Searching NilaiAkhir antara 85.5 dan 95.5:" << endl;
    SearchNilaiAkhir(S, 85.5f, 95.5f);

    float maxNilai;
    int pos;
    MaxNilaiAkhir(S, maxNilai, pos);
    cout << "\nBAGIAN B: Max NilaiAkhir = ";
    if (pos == -1)
        cout << "(tidak ada data)" << endl;
    else
        cout << fixed << setprecision(1) << maxNilai << " pada posisi " << pos << endl;

    return 0;
}