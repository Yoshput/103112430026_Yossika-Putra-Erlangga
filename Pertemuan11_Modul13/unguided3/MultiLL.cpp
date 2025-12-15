#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent &LParent) {
    return LParent.first == nullptr;
}

bool isEmptyChild(listChild &LChild) {
    return LChild.first == nullptr;
}

void createListParent(listParent &LParent) {
    LParent.first = LParent.last = nullptr;
}

void createListChild(listChild &LChild) {
    LChild.first = LChild.last = nullptr;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent newNode = new nodeParent;
    newNode->isidata.idGolongan = idGol;
    newNode->isidata.namaGolongan = namaGol;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    createListChild(newNode->L_Child);
    return newNode;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot) {
    NodeChild newNode = new nodeChild;
    newNode->isidata.idHewan = idHwn;
    newNode->isidata.namaHewan = namaHwn;
    newNode->isidata.habitat = habitat;
    newNode->isidata.ekor = ekor;
    newNode->isidata.bobot = bobot;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void deallocNodeParent(NodeParent &NParent) {
    if (NParent != nullptr) {
        NParent->next = NParent->prev = nullptr;
        delete NParent;
        NParent = nullptr;
    }
}

void deallocNodeChild(NodeChild &NChild) {
    if (NChild != nullptr) {
        NChild->next = NChild->prev = nullptr;
        delete NChild;
        NChild = nullptr;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent temp = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = LParent.last = nullptr;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = nullptr;
        }
        deallocNodeParent(temp);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != nullptr && NPrev->next != nullptr) {
        NodeParent temp = NPrev->next;
        NPrev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        deallocNodeParent(temp);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild temp = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = LChild.last = nullptr;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = nullptr;
        }
        deallocNodeChild(temp);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != nullptr && NPrev->next != nullptr) {
        NodeChild temp = NPrev->next;
        NPrev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = NPrev;
        } else {
            LChild.last = NPrev;
        }
        deallocNodeChild(temp);
    }
}

void deleteNodeParent(listParent &LParent, string idGol) {
    NodeParent temp = LParent.first;
    while (temp != nullptr) {
        if (temp->isidata.idGolongan == idGol) {
          
            NodeChild tempChild = temp->L_Child.first;
            while (tempChild != nullptr) {
                NodeChild toDelete = tempChild;
                tempChild = tempChild->next;
                deallocNodeChild(toDelete);
            }
            deleteAfterParent(LParent, temp); 
            break;
        }
        temp = temp->next;
    }
}

void printMLLStructure(listParent &LParent) {
    NodeParent tempParent = LParent.first;
    while (tempParent != nullptr) {
        cout << "=== Parent ===" << endl;
        cout << "ID Golongan: " << tempParent->isidata.idGolongan << endl;
        cout << "Nama Golongan: " << tempParent->isidata.namaGolongan << endl;

        if (isEmptyChild(tempParent->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild tempChild = tempParent->L_Child.first;
            int childCount = 1;
            while (tempChild != nullptr) {
                cout << "  --> Child " << childCount++ << " :" << endl;
                cout << "      ID Hewan: " << tempChild->isidata.idHewan << endl;
                cout << "      Nama Hewan: " << tempChild->isidata.namaHewan << endl;
                cout << "      Habitat: " << tempChild->isidata.habitat << endl;
                cout << "      Ekor: " << (tempChild->isidata.ekor ? "True" : "False") << endl;
                cout << "      Bobot: " << tempChild->isidata.bobot << endl;
                tempChild = tempChild->next;
            }
        }

        cout << "--------------------" << endl;
        tempParent = tempParent->next;
    }
}
