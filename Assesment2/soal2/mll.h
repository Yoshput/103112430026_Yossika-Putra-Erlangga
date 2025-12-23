#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

// Forward declaration
struct nodeChild;
typedef struct nodeParent *adrParent;
typedef struct nodeChild *adrChild;

struct nodeParent {
    string IDGenre;
    string namaGenre;
    adrParent next;
    adrParent prev;
    adrChild firstChild;
    adrChild lastChild;
};

struct nodeChild {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    adrChild next;
    adrChild prev;
};

struct ListParent {
    adrParent first;
    adrParent last;
};

// Prototipe Method sesuai ketentuan soal
void createListParent(ListParent &L);
adrParent alokasiNodeParent(string id, string nama);
adrChild alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
void dealokasiNodeParent(adrParent &P);
void dealokasiNodeChild(adrChild &C);
void insertFirstParent(ListParent &L, adrParent P);
void insertLastChild(adrParent P, adrChild C);
void hapusListChild(adrParent P);
void deleteAfterParent(ListParent &L, adrParent prevNode, adrParent &P);
void searchFilmByRatingRange(ListParent L, float minR, float maxR);
void printStrukturMLL(ListParent L);

#endif