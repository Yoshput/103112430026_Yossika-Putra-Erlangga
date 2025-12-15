#include <iostream>
#include "MultiLL.h"

using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);

    NodeParent p1 = allocNodeParent("G001", "Aves");
    insertLastParent(LParent, p1);
    NodeParent p2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LParent, p2);
    NodeParent p3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LParent, p3);
    NodeParent p4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LParent, p4);
    NodeParent p5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LParent, p5);

    NodeChild c1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(p1->L_Child, c1);
    NodeChild c2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(p1->L_Child, c2);

    NodeChild c3 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertLastChild(p2->L_Child, c3);
    NodeChild c4 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertLastChild(p2->L_Child, c4);
    NodeChild c5 = allocNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(p2->L_Child, c5);

    NodeChild c6 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(p4->L_Child, c6);

    printMLLStructure(LParent);

    searchHewanByEkor(LParent, false);

    return 0;
}
