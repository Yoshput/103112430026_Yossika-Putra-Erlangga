#include "mll.h"

void createListParent(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
}

adrParent alokasiNodeParent(string id, string nama) {
    adrParent P = new nodeParent;
    P->IDGenre = id;
    P->namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    P->firstChild = NULL;
    P->lastChild = NULL;
    return P;
}

adrChild alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    adrChild C = new nodeChild;
    C->IDFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void dealokasiNodeParent(adrParent &P) {
    delete P;
    P = NULL;
}

void dealokasiNodeChild(adrChild &C) {
    delete C;
    C = NULL;
}

void insertFirstParent(ListParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(adrParent P, adrChild C) {
    if (P->firstChild == NULL) {
        P->firstChild = C;
        P->lastChild = C;
    } else {
        C->prev = P->lastChild;
        P->lastChild->next = C;
        P->lastChild = C;
    }
}

void hapusListChild(adrParent P) {
    adrChild C = P->firstChild;
    while (C != NULL) {
        adrChild temp = C;
        C = C->next;
        dealokasiNodeChild(temp);
    }
    P->firstChild = NULL;
    P->lastChild = NULL;
}

void deleteAfterParent(ListParent &L, adrParent prevNode, adrParent &P) {
    if (prevNode != NULL && prevNode->next != NULL) {
        P = prevNode->next;
        hapusListChild(P); 
        
        prevNode->next = P->next;
        if (P->next != NULL) {
            P->next->prev = prevNode;
        } else {
            L.last = prevNode;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void searchFilmByRatingRange(ListParent L, float minR, float maxR) {
    adrParent P = L.first;
    int pPos = 1;
    while (P != NULL) {
        adrChild C = P->firstChild;
        int cPos = 1;
        while (C != NULL) {
            if (C->ratingFilm >= minR && C->ratingFilm <= maxR) {
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre << " pada posisi ke-" << cPos << "!" << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << cPos << endl;
                cout << "ID Film : " << C->IDFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << P->IDGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << pPos << endl;
                cout << "Nama Genre : " << P->namaGenre << endl;
                cout << "==============================" << endl;
            }
            C = C->next;
            cPos++;
        }
        P = P->next;
        pPos++;
    }
}

void printStrukturMLL(ListParent L) {
    adrParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre : " << P->IDGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;
        adrChild C = P->firstChild;
        int j = 1;
        while (C != NULL) {
            cout << "  - Child " << j << " :" << endl;
            cout << "    ID Film : " << C->IDFilm << endl;
            cout << "    Judul Film : " << C->judulFilm << endl;
            cout << "    Durasi Film : " << C->durasiFilm << " menit" << endl;
            cout << "    Tahun Tayang : " << C->tahunTayang << endl;
            cout << "    Rating Film : " << C->ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << "--------------------------" << endl;
        P = P->next;
        i++;
    }
}