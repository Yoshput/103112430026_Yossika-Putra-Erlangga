#include "Singlylist.h"

int main() {
    List L;
    address P;
    createList(L);

    int data[] = {2, 0, 8, 12, 9};
    for (int i = 0; i < 5; i++)
        insertFirst(L, alokasi(data[i]));

    printInfo(L); 

    deleteFirst(L, P);
    dealokasi(P);

    deleteLast(L, P);
    dealokasi(P);

    deleteAfter(L.first, P);
    dealokasi(P);

    printInfo(L); 
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}