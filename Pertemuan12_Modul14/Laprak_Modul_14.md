# Laporan Praktikum Modul 14 - Graph
<p align="center">Yossika Putra Erlangga - 103112430026</p>

---
## **Dasar Teori**

Pada praktikum **Modul 14**, materi yang dipelajari adalah **Graph**, salah satu struktur data non-linear yang digunakan untuk merepresentasikan hubungan antar data. Graph banyak digunakan dalam berbagai kasus nyata seperti peta jalan, jaringan komputer, hubungan sosial, dan penjadwalan proses.

### Pengertian Graph
Graph merupakan himpunan tidak kosong yang terdiri dari **node (vertex)** dan **edge (sisi)**. Node merepresentasikan objek, sedangkan edge merepresentasikan hubungan antar objek tersebut. Hubungan ini dapat memiliki arah atau tidak memiliki arah, tergantung pada jenis graph yang digunakan [2].

### Jenis-Jenis Graph
1. **Graph Berarah (Directed Graph)**  
   Graph berarah adalah graph yang setiap edge-nya memiliki arah tertentu dari satu node ke node lain. Jika terdapat edge dari node A ke node B, maka belum tentu terdapat edge dari B ke A.

2. **Graph Tidak Berarah (Undirected Graph)**  
   Graph tidak berarah adalah graph yang edge-nya tidak memiliki arah. Jika node A terhubung dengan node B, maka node B juga otomatis terhubung dengan node A.

### Representasi Graph
Graph dapat direpresentasikan dalam beberapa bentuk, antara lain:
- Matriks ketetanggaan (Adjacency Matrix)
- List ketetanggaan (Adjacency List)
- Multi Linked List

Pada praktikum ini, representasi graph menggunakan **Multi Linked List**, karena bersifat dinamis dan efisien dalam pengelolaan data graph [2].

---

## **Dasar Pemrograman**

### ADT Graph
Dalam pemrograman, Graph diimplementasikan menggunakan **Abstract Data Type (ADT)** yang terdiri dari node dan edge. Setiap node memiliki pointer ke edge pertama yang terhubung dengannya.

Struktur data utama pada Graph meliputi:
- **Node (Vertex)**: menyimpan informasi node
- **Edge**: menyimpan hubungan antar node
- **Visited**: penanda apakah node sudah dikunjungi

### Metode Penelusuran Graph

1. **Breadth First Search (BFS)**  
   BFS melakukan penelusuran graph berdasarkan level, dimulai dari node awal kemudian ke node tetangga terdekat terlebih dahulu menggunakan struktur data **queue**.

2. **Depth First Search (DFS)**  
   DFS melakukan penelusuran graph secara mendalam ke satu cabang terlebih dahulu sebelum berpindah ke cabang lain menggunakan **stack** atau rekursi.

Penelusuran BFS dan DFS sangat penting dalam berbagai aplikasi seperti pencarian jalur, deteksi siklus, dan analisis jaringan [2].

---

## **Guided - Implementasi Graph Tidak Berarah**

### **graph.h**
```cpp
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;


typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
   adrNode node;
   adrEdge next;
};

struct Graph{
    adrNode first;
};

void createGraph(Graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(Graph &G, infoGraph x);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```
### **graph_edge.cpp**
```cpp
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        else {
        P = P->next;
        }
    }
    return NULL;
}


void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);
    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge-> node = pEnd;
        newEdge->next = pStart->firstEdge;
        pStart->firstEdge = newEdge;
 }
}

```

### **graph_init.cpp**
```cpp
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

```

### **graph_print.cpp**
```cpp
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node" << P->info << "terhubung ke: ";
        adrEdge E = P -> firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
    cout << endl;
}```
### **main.cpp**
```cpp
#include <iostream>
#include "graph.h"
using namespace std;

int main(){
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "Isi graph:" << endl;
    printGraph(G);

    return 0;
}

```
### **Penjelasan Guided**
Program guided ini mengimplementasikan struktur data Graph menggunakan Multi Linked List. Graph direpresentasikan sebagai kumpulan node (vertex) yang saling terhubung melalui edge (sisi). Setiap node memiliki pointer ke edge pertama yang terhubung dengannya, sedangkan setiap edge menyimpan alamat node tujuan.

---

# **Unguided**
## Unguided 1 - ADT Graph Tidak Berarah

1. Buatlah ADT Graph tidak berarah file “graph.h”:
![Screenshot Alternatif 1 Output](output/output_soal1.png)
Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT 
pada file “main.cpp”.


![Screenshot Alternatif 1 Output](output/output_soal1_2.png)
graph.h
### graph.h
```cpp
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void PrintDFS(Graph &G, adrNode N);
void PrintBFS(Graph &G, adrNode N);

#endif


```

### graph.cpp
```cpp
#include "graph.h"
#include <queue>

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void PrintDFS(Graph &G, adrNode N) {
    if (N == NULL) return;
    
    cout << N->info << " ";
    N->visited = 1;
    
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        if (E->node->visited == 0) {
            PrintDFS(G, E->node);
        }
        E = E->next;
    }
}

void PrintBFS(Graph &G, adrNode N) {
    if (N == NULL) return;
    
    queue<adrNode> Q;
    Q.push(N);
    N->visited = 1;
    
    while (!Q.empty()) {
        adrNode curr = Q.front();
        Q.pop();
        cout << curr->info << " ";
        
        adrEdge E = curr->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}


```

### main.cpp
```cpp
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode Gg = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    cout << "Isi Graph:" << endl;
    PrintInfoGraph(G);

    cout << endl << "DFS : ";
    PrintDFS(G, A);

    cout << endl << "BFS : ";
    PrintBFS(G, A);

    return 0;
}


```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan12_Modul14/output/output_unguided1.png)
### Penjelasan:
Pada Unguided 1, kita mengimplementasikan struktur data Multi Linked List (MLL) yang terdiri dari dua level: parent list dan child list. Setiap parent node memiliki child nodes yang berhubungan langsung dengannya. Dalam kasus ini, parent merepresentasikan kategori hewan (misalnya Aves, Mamalia, Piscean, dll.), dan setiap parent memiliki beberapa anak yang mewakili spesies atau hewan tertentu. Program ini mencakup operasi dasar seperti insert, delete, search, dan print. Dalam Unguided 1, kita mengimplementasikan fungsi untuk menambahkan data ke dalam list parent dan child, kemudian mencetak struktur MLL yang dihasilkan, di mana setiap node anak memiliki atribut seperti nama hewan, habitat, dan bobot.

---

## Unguided 2 - Penelusuran DFS

1. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
### graph.h
```cpp
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void ResetVisited(Graph &G);

void PrintDFS(Graph &G, adrNode N);
void PrintBFS(Graph &G, adrNode N);

#endif



```

### graph.cpp
```cpp
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

void PrintDFS(Graph &G, adrNode N) {
    if (N != NULL && N->visited == 0) {
        cout << N->info << " ";
        N->visited = 1;
        adrEdge E = N->firstEdge;
        while (E != NULL) {
            PrintDFS(G, E->node);
            E = E->next;
        }
    }
}

void PrintBFS(Graph &G, adrNode N) {
    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}



```

### main.cpp
```cpp
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode Gg = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    cout << "DFS : ";
    PrintDFS(G, A);

    ResetVisited(G);

    cout << endl << "BFS : ";
    PrintBFS(G, A);

    return 0;
}



```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan12_Modul14/output/output_unguided2&3.png)
#### Penjelasan
BFS menelusuri graph secara melebar berdasarkan level menggunakan queue. Metode ini efektif untuk mencari jalur terpendek pada graph tidak berbobot.

---

### **Unguided 3 – Penerapan Graph pada Studi Kasus**

3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.

prosedur PrintBFS (Graph G, adrNode N);

#### Kode Program Tambahan di graph.cpp
```cpp
void PrintBFS(Graph &G, adrNode N) {
    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}

```

#### Kode Program Tambahan di main.cpp
```cpp
cout << endl << "BFS : ";
    PrintBFS(G, A);
```
#### Output
![Screenshot Output Unguided 1_1](https://github.com/Yoshput/103112430026_Yossika-Putra-Erlangga/blob/main/Pertemuan12_Modul14/output/output_unguided2&3.png)

#### Penjelasan
Pada unguided ini, graph digunakan untuk merepresentasikan hubungan antar node sederhana. Program menunjukkan bagaimana node saling terhubung dan ditampilkan dalam bentuk adjacency list.

---

## **Kesimpulan**

Pada **Modul 14 – Graph**, dapat disimpulkan bahwa Graph merupakan struktur data yang sangat fleksibel dan powerful untuk merepresentasikan hubungan antar data. Implementasi Graph menggunakan Multi Linked List memudahkan pengelolaan node dan edge secara dinamis. Metode BFS dan DFS menjadi teknik fundamental dalam penelusuran graph yang memiliki banyak aplikasi nyata.

---

## **Referensi**

1. Goodrich, M., Tamassia, R., Goldwasser, M. (2014). *Data Structures & Algorithms in C++*. Wiley.
2. Modul Praktikum Struktur Data. **Modul 14 – Graph**, Telkom University, 2025.
3. Malik, D. S. (2018). *Data Structures Using C++*. Cengage Learning.
4. Wikipedia. (2024). *Graph (Data Structure)*.

