#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>

const int MAX = 6;

struct Mahasiswa {
	std::string Nama;
	std::string NIM;
	float NilaiTugas;
	float NilaiUTS;
	float NilaiUAS;
};

struct StackMahasiswa {
	Mahasiswa dataMahasiswa[MAX];
	int Top;
};

bool isEmpty(const StackMahasiswa &S);
bool isFull(const StackMahasiswa &S);
void createStack(StackMahasiswa &S);

void Push(StackMahasiswa &S, const Mahasiswa &m);
bool Pop(StackMahasiswa &S, Mahasiswa &m);
bool Update(StackMahasiswa &S, int posisi, const Mahasiswa &m);
void View(const StackMahasiswa &S);

int SearchNilaiAkhir(const StackMahasiswa &S, float NilaiAkhirMin, float NilaiAkhirMax);
void MaxNilaiAkhir(const StackMahasiswa &S, float &maxNilai, int &posisi);
float HitungNilaiAkhir(const Mahasiswa &m);

#endif // STACKMAHASISWA_H