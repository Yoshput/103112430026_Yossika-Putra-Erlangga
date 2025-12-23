#include <iostream>
#include <string>

using namespace std;

struct Edge;
typedef struct Node *adrNode; 
typedef struct Edge *adrEdge;

struct Node {
    char namaKota;
    bool isLockdown; 
    bool visited;    
    adrNode nextNode;
    adrEdge firstEdge;
};

struct Edge {
    adrNode tujuan;
    adrEdge nextEdge;
};

struct Graph {
    adrNode first;
};


void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode alokasiNode(char X) {
    adrNode P = new Node;
    P->namaKota = X;
    P->isLockdown = false;
    P->visited = false;
    P->nextNode = NULL;
    P->firstEdge = NULL;
    return P;
}

void insertNode(Graph &G, char X) {
    adrNode P = alokasiNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode last = G.first;
        while (last->nextNode != NULL) last = last->nextNode;
        last->nextNode = P;
    }
}

adrNode findNode(Graph G, char X) {
    adrNode P = G.first;
    while (P != NULL && P->namaKota != X) P = P->nextNode;
    return P;
}

void addEdge(Graph &G, char asal, char tujuan) {
    adrNode P = findNode(G, asal);
    adrNode Q = findNode(G, tujuan);
    if (P != NULL && Q != NULL) {
        adrEdge E = new Edge;
        E->tujuan = Q;
        E->nextEdge = P->firstEdge;
        P->firstEdge = E;
    }
}

void hubungkanKota(Graph &G, char a, char b) {
    addEdge(G, a, b);
    addEdge(G, b, a);
}


void resetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = false;
        P = P->nextNode;
    }
}

void DFS(adrNode P, int &count) {
    P->visited = true;
    count++;
    adrEdge E = P->firstEdge;
    while (E != NULL) {
        if (!E->tujuan->visited && !E->tujuan->isLockdown) {
            DFS(E->tujuan, count);
        }
        E = E->nextEdge;
    }
}

int countActiveNodes(Graph G) {
    int total = 0;
    adrNode P = G.first;
    while (P != NULL) {
        if (!P->isLockdown) total++;
        P = P->nextNode;
    }
    return total;
}

void analisisKotaKritis(Graph &G) {
    cout << "\nAnalisis Kota Kritis (Single Point of Failure)" << endl;
    adrNode P = G.first;
    
    while (P != NULL) {
        resetVisited(G);
        
        P->isLockdown = true; 
        
        adrNode startNode = G.first;
        if (startNode == P) startNode = startNode->nextNode;
        
        int reachableCount = 0;
        if (startNode != NULL) {
            DFS(startNode, reachableCount);
        }
        
        int activeNodes = countActiveNodes(G);
        
        if (reachableCount < activeNodes) {
            cout << "[PERINGATAN] Kota " << P->namaKota << " adalah KOTA KRITIS!" << endl;
            cout << "-> Jika " << P->namaKota << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "Kota " << P->namaKota << " aman (redundansi oke)." << endl;
        }
        
        P->isLockdown = false;
        P = P->nextNode;
    }
}

void printJaringan(Graph G) {
    cout << "Membangun Jaringan Distribusi Vaksin" << endl;
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->namaKota << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->tujuan->namaKota << " ";
            E = E->nextEdge;
        }
        cout << endl;
        P = P->nextNode;
    }
}

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');

    hubungkanKota(G, 'A', 'B');
    hubungkanKota(G, 'B', 'E');
    hubungkanKota(G, 'B', 'C');
    hubungkanKota(G, 'C', 'D');

    printJaringan(G);
    analisisKotaKritis(G);

    return 0;
}