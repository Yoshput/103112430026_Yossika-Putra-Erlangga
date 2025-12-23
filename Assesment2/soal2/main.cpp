#include "mll.h"

int main() {
    ListParent L;
    createListParent(L);

    insertFirstParent(L, alokasiNodeParent("G004", "Romance"));
    insertFirstParent(L, alokasiNodeParent("G003", "Horror"));
    insertFirstParent(L, alokasiNodeParent("G002", "Comedy"));
    insertFirstParent(L, alokasiNodeParent("G001", "Action"));

    adrParent P = L.first;
    insertLastChild(P, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));

    P = P->next;
    insertLastChild(P, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(P, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));

    P = P->next;
    insertLastChild(P, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));

    P = P->next;
    insertLastChild(P, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(P, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    printStrukturMLL(L);
    cout << endl;
    searchFilmByRatingRange(L, 8.0, 8.5);
    cout << endl;

    adrParent deleted;
    deleteAfterParent(L, L.first, deleted);
    if (deleted != NULL) dealokasiNodeParent(deleted);

    printStrukturMLL(L);

    return 0;
}