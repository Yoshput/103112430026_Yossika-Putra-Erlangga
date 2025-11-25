#include <iostream>
#include <iomanip>
#include "Stackmahasiswa.h"


using namespace std;

bool isEmpty(const StackMahasiswa &S)
{
    return S.Top == -1;
}

bool isFull(const StackMahasiswa &S)
{
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S)
{
    S.Top = -1;
}


void Push(StackMahasiswa &S, const Mahasiswa &m)
{
    if (isFull(S)) {
        cout << "Stack penuh. Tidak dapat melakukan push." << endl;
        return;
    }
    S.Top++;
    S.dataMahasiswa[S.Top] = m;
}

bool Pop(StackMahasiswa &S, Mahasiswa &m)
{
    if (isEmpty(S))
        return false;
    m = S.dataMahasiswa[S.Top];
    S.Top--;
    return true;
}


bool Update(StackMahasiswa &S, int posisi, const Mahasiswa &m)
{
    if (posisi < 1 || posisi > S.Top + 1)
        return false;
    int idx = posisi - 1;
    S.dataMahasiswa[idx] = m;
    return true;
}

void View(const StackMahasiswa &S)
{
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }

    cout << fixed << setprecision(1);
    cout << "Menampilkan stack (dari TOP ke BAWAH):" << endl;
    for (int i = S.Top; i >= 0; --i) {
        int posisi = i + 1;
        const Mahasiswa &m = S.dataMahasiswa[i];
        float akhir = HitungNilaiAkhir(m);
        cout << "Posisi " << posisi << ": " << m.Nama << " (NIM: " << m.NIM << ") - "
             << "Tugas=" << m.NilaiTugas << ", UTS=" << m.NilaiUTS << ", UAS=" << m.NilaiUAS
             << ", NilaiAkhir=" << akhir << endl;
    }
}

float HitungNilaiAkhir(const Mahasiswa &m)
{
    return 0.2f * m.NilaiTugas + 0.4f * m.NilaiUTS + 0.4f * m.NilaiUAS;
}


int SearchNilaiAkhir(const StackMahasiswa &S, float NilaiAkhirMin, float NilaiAkhirMax)
{
    if (isEmpty(S))
        return 0;

    int count = 0;
    for (int i = 0; i <= S.Top; ++i) {
        float akhir = HitungNilaiAkhir(S.dataMahasiswa[i]);
        if (akhir >= NilaiAkhirMin && akhir <= NilaiAkhirMax) {
            count++;
            cout << "  " << count << ". " << S.dataMahasiswa[i].Nama << " (NIM: " << S.dataMahasiswa[i].NIM
                 << ") - NilaiAkhir=" << fixed << setprecision(1) << akhir << endl;
        }
    }

    if (count == 0)
        cout << "  Tidak ada data dalam rentang tersebut." << endl;

    return count;
}

void MaxNilaiAkhir(const StackMahasiswa &S, float &maxNilai, int &posisi)
{
    maxNilai = -1.0f;
    posisi = -1;
    if (isEmpty(S))
        return;

    for (int i = 0; i <= S.Top; ++i) {
        float akhir = HitungNilaiAkhir(S.dataMahasiswa[i]);
        if (akhir > maxNilai) {
            maxNilai = akhir;
            posisi = i + 1;
        }
    }
}