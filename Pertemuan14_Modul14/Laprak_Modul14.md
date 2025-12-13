# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
Graph merupakan salah satu struktur data non-linear yang digunakan untuk merepresentasikan hubungan antar objek atau data. Graph terdiri dari sekumpulan simpul (vertex) dan sisi (edge) yang menghubungkan antar simpul tersebut. Struktur data ini banyak digunakan dalam berbagai permasalahan nyata seperti jaringan komputer, peta jalan, media sosial, sistem rekomendasi, serta perancangan sistem basis data karena mampu memodelkan hubungan yang kompleks secara efisien [1].

Secara formal, graph dapat dinyatakan sebagai pasangan himpunan
𝐺 = (𝑉, 𝐸)
G=(V,E),
di mana 𝑉 adalah himpunan vertex yang merepresentasikan objek, dan 𝐸 adalah himpunan edge yang merepresentasikan hubungan antar vertex tersebut. Setiap edge dapat menghubungkan dua vertex yang berbeda dan dapat memiliki sifat tertentu seperti arah maupun bobot, tergantung pada jenis graph yang digunakan [2].

### A. Konsep Dasar Graph<br/>
Graph memiliki dua komponen utama, yaitu vertex dan edge. Vertex berfungsi sebagai representasi entitas atau objek, sedangkan edge berfungsi untuk menunjukkan hubungan atau keterkaitan antar entitas tersebut. Kombinasi kedua komponen ini membentuk struktur graph yang dapat digunakan untuk berbagai kebutuhan komputasi.
#### 1. Vertex (Simpul)
Vertex merupakan elemen dasar pada graph yang menyimpan informasi tertentu sesuai dengan kebutuhan aplikasi. Setiap vertex dapat berdiri sendiri atau terhubung dengan vertex lain melalui edge. Dalam implementasi struktur data, vertex biasanya direpresentasikan sebagai node yang memiliki pointer ke edge atau node lain [2].
#### 2. Edge (Sisi)
Edge merupakan garis penghubung antara dua vertex yang menunjukkan adanya hubungan di antara keduanya. Edge dapat bersifat berarah atau tidak berarah, serta dapat memiliki bobot yang merepresentasikan nilai tertentu seperti jarak, biaya, atau waktu. Keberadaan edge memungkinkan graph untuk memodelkan relasi antar data secara lebih realistis [3].
#### 3. Ketetanggaan (Adjacency)
Dua vertex dikatakan bertetangga apabila dihubungkan secara langsung oleh sebuah edge. Informasi ketetanggaan ini sangat penting dalam proses penelusuran graph seperti DFS dan BFS, karena menentukan vertex mana yang dapat dikunjungi dari suatu vertex tertentu. Konsep adjacency juga menjadi dasar dalam berbagai algoritma graph [1].

### B. Jenis-Jenis Graph<br/>
Graph dapat diklasifikasikan ke dalam beberapa jenis berdasarkan arah sisi (edge) dan karakteristik hubungan antar simpulnya. Pengelompokan ini penting karena setiap jenis graph memiliki kegunaan dan penerapan yang berbeda dalam pemecahan masalah komputasi.
#### 1. Graph Berarah (Directed Graph)
Graph berarah adalah graph yang setiap edge-nya memiliki arah tertentu dari satu vertex ke vertex lain. Hubungan ini bersifat satu arah, sehingga jika terdapat edge dari vertex A ke vertex B, belum tentu terdapat edge dari B ke A. Graph berarah sering digunakan untuk memodelkan hubungan sebab-akibat, alur proses, dan dependensi data [3].
#### 2. Graph Tidak Berarah (Undirected Graph)
Graph tidak berarah adalah graph yang edge-nya tidak memiliki arah. Jika terdapat hubungan antara vertex A dan vertex B, maka hubungan tersebut berlaku dua arah. Graph jenis ini sering digunakan untuk memodelkan hubungan timbal balik seperti jaringan pertemanan atau jalur dua arah.
#### 3. Representasi Graph
Graph dapat direpresentasikan dalam beberapa bentuk, antara lain matriks ketetanggaan (adjacency matrix) dan multilist. Matriks ketetanggaan cocok untuk graph berukuran kecil dan padat, sedangkan multilist lebih efisien untuk graph yang bersifat dinamis. Pada praktikum ini digunakan representasi multilist karena memudahkan pengelolaan node dan edge serta lebih hemat penggunaan memori [2].

## Guided 

### 1. graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;       // Menyimpan data node (misal: char/int)
    int visited;          // Penanda untuk traversal (0/1) (penanda apakah node sudah dikunjungi)
    adrEdge firstEdge;    // Pointer ke edge pertama yang terhubung
    adrNode Next;         // Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode node;         // Pointer yang menunjuk ke lokasi node tujuan.
    adrEdge next;         // Pointer ke edge berikutnya (jika satu node memiliki banyak cabang).
};

struct Graph {
    adrNode First;        // Pointer ke node pertama dalam list graph.
};

void CreateGraph(Graph &G); // Prosedur untuk mengeset First dari graph sebagai NULL
adrNode AlokasiNode(infoGraph data); // alokasi Node baru
adrEdge AlokasiEdge(adrNode nodeTujuan); // alokasi Edge baru

void InsertNode(Graph &G, infoGraph data); // Menambahkan Node ke dalam Graph
adrNode FindNode(Graph G, infoGraph data); // function untuk mencari alamat Node berdasarkan info
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); // prosedur untuk menghubungkan dua Node
void DisconnectNode(Graph &G, adrNode node1, adrNode node2); // prosedur untuk memutuskan hubungan dua Node
void DeleteNode(Graph &G, infoGraph X); // prosedur untuk menghapus Node X beserta semua edge yang terhubung

void PrintInfoGraph(Graph G); // Menampilkan isi Graph (Adjacency List)
void ResetVisited(Graph &G); // Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo); // Traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintDFS(Graph G, infoGraph StartInfo); // Traversal Depth First Search / DFS (Menggunakan Stack atau Rekursif)

#endif
```
Pada bagian unguided, graph diimplementasikan menggunakan struktur multilist yang terdiri dari node dan edge. Setiap node menyimpan informasi data serta status kunjungan yang digunakan saat proses traversal. Hubungan antar node direpresentasikan melalui edge yang saling terhubung.

Graph diinisialisasi dalam keadaan kosong menggunakan prosedur CreateGraph. Node baru ditambahkan ke dalam graph dengan InsertNode, sedangkan pencarian node dilakukan menggunakan FindNode. Hubungan antar node dibentuk dan dihapus menggunakan prosedur ConnectNode dan DisconnectNode. Penghapusan node beserta relasinya dilakukan melalui prosedur DeleteNode.

Penampilan isi graph dilakukan dengan PrintInfoGraph. Proses penelusuran graph menggunakan metode BFS dan DFS, yang masing-masing menelusuri graph secara melebar dan mendalam. Sebelum traversal dilakukan, status kunjungan setiap node direset menggunakan ResetVisited.

### 2. graph.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue>  // library queue untuk BFS
#include <stack>  // library stack untuk DFS
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    // hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');   //BFS
    PrintDFS(G, 'A');   //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');   //BFS
    PrintDFS(G, 'A');   //DFS

    return 0;
}
```
Program dimulai dengan membuat graph kosong, kemudian menambahkan node A sampai F ke dalam graph. Setelah itu, node-node tersebut dihubungkan satu sama lain menggunakan prosedur ConnectNode sehingga membentuk graph tidak berarah.

Graph ditampilkan dalam bentuk adjacency list, lalu dilakukan traversal menggunakan metode BFS dan DFS yang dimulai dari node A. Selanjutnya, node E dihapus dari graph dan keberhasilannya dicek menggunakan fungsi FindNode.

Terakhir, graph ditampilkan kembali dan traversal BFS serta DFS dijalankan ulang untuk melihat perubahan struktur graph setelah penghapusan node.

### 3. main.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue>  // library queue untuk BFS
#include <stack>  // library stack untuk DFS
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    // hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');   //BFS
    PrintDFS(G, 'A');   //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');   //BFS
    PrintDFS(G, 'A');   //DFS

    return 0;
}
```
Program ini membuat sebuah graph kosong, lalu menambahkan enam node yaitu A sampai F. Setelah itu, node-node tersebut dihubungkan sehingga membentuk graph tidak berarah sesuai dengan hubungan yang ditentukan.

Graph ditampilkan dalam bentuk adjacency list, kemudian dilakukan traversal menggunakan metode BFS dan DFS yang dimulai dari node A. Selanjutnya, node E dihapus dari graph dan dicek keberhasilannya.

Terakhir, graph ditampilkan kembali dan traversal BFS serta DFS dijalankan ulang untuk melihat perubahan struktur graph setelah penghapusan node.

## Unguided 

### 1. graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

/* Struktur Node (Vertex) */
struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

/* Struktur Edge */
struct ElmEdge {
    adrNode node;
    adrEdge next;
};

/* Struktur Graph */
struct Graph {
    adrNode first;
};

/* Prototype */
void CreateGraph(Graph &G);
adrNode CreateNode(infoGraph X);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```
Pada bagian ini dibuat sebuah header file graph.h yang berisi definisi struktur data graph menggunakan representasi adjacency list. Struktur ElmNode digunakan untuk merepresentasikan vertex yang menyimpan data, status kunjungan (visited), serta pointer ke edge dan node berikutnya.

Struktur ElmEdge digunakan untuk merepresentasikan hubungan antar node, sedangkan struktur Graph berfungsi sebagai pengelola keseluruhan graph dengan menunjuk ke node pertama. Selain itu, pada file ini juga dideklarasikan prototipe fungsi yang digunakan untuk membuat, menambah, menghubungkan, menelusuri, dan menampilkan graph.

### 2. graph.cpp

```C++
#include "graph.h"
#include <queue>

/* Membuat graph kosong */
void CreateGraph(Graph &G) {
    G.first = NULL;
}

/* Alokasi node */
adrNode CreateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

/* Menambah node ke graph */
void InsertNode(Graph &G, infoGraph X) {
    adrNode P = CreateNode(X);
    P->next = G.first;
    G.first = P;
}

/* Mencari node berdasarkan info */
adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NULL;
}

/* Menghubungkan dua node (tidak berarah) */
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

/* Menampilkan graph */
void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

/* Reset status visited */
void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

/* DFS */
void PrintDFS(Graph G, adrNode N) {
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

/* BFS */
void PrintBFS(Graph G, adrNode N) {
    queue<adrNode> Q;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        if (P->visited == 0) {
            cout << P->info << " ";
            P->visited = 1;

            adrEdge E = P->firstEdge;
            while (E != NULL) {
                Q.push(E->node);
                E = E->next;
            }
        }
    }
}
```
Kode ini berisi implementasi fungsi-fungsi graph menggunakan representasi adjacency list. Prosedur CreateGraph digunakan untuk menginisialisasi graph kosong, sedangkan CreateNode dan InsertNode berfungsi untuk membuat dan menambahkan node ke dalam graph.

Fungsi FindNode digunakan untuk mencari node berdasarkan data tertentu. Prosedur ConnectNode menghubungkan dua node secara tidak berarah dengan menambahkan edge pada masing-masing node.

Prosedur PrintInfoGraph menampilkan hubungan antar node dalam bentuk adjacency list. Fungsi ResetVisited digunakan untuk mengatur ulang status kunjungan sebelum traversal.

Traversal graph dilakukan menggunakan metode Depth First Search (DFS) melalui fungsi PrintDFS dan Breadth First Search (BFS) melalui fungsi PrintBFS, yang masing-masing menelusuri graph dengan cara yang berbeda.

### 3. main.cpp

```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    /* Membuat node */
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    /* Mengambil alamat node */
    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode Gg = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    /* Membentuk graph sesuai ilustrasi modul */
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

    cout << "Representasi Graph:" << endl;
    PrintInfoGraph(G);

    cout << "\nDFS : ";
    ResetVisited(G);
    PrintDFS(G, A);

    cout << "\n\nBFS : ";
    ResetVisited(G);
    PrintBFS(G, A);

    return 0;
}

```
### Output Unguided :

##### Output 
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan14_Modul14/image14/Output-Unguided1-Modul14-1.png)

Program ini membuat sebuah graph dengan delapan node, yaitu A sampai H. Setelah semua node ditambahkan, alamat masing-masing node diambil menggunakan fungsi FindNode untuk memudahkan proses penghubungan antar node.

Selanjutnya, node-node dihubungkan sesuai dengan ilustrasi pada Modul 14 sehingga membentuk graph tidak berarah. Graph yang terbentuk kemudian ditampilkan dalam bentuk adjacency list menggunakan prosedur PrintInfoGraph.

Setelah itu dilakukan traversal Depth First Search (DFS) dan Breadth First Search (BFS) yang dimulai dari node A. Sebelum traversal, fungsi ResetVisited digunakan untuk mengatur ulang status kunjungan agar proses penelusuran berjalan dengan benar.

## Kesimpulan
Dari praktikum Modul 14 ini dapat disimpulkan bahwa graph merupakan struktur data yang sangat fleksibel dan efektif dalam merepresentasikan hubungan antar data. Implementasi graph menggunakan multilist mempermudah pengelolaan data yang bersifat dinamis dan kompleks. Selain itu, metode penelusuran DFS dan BFS memiliki karakteristik yang berbeda sehingga dapat digunakan sesuai dengan kebutuhan permasalahan. Pemahaman konsep graph dan representasinya menjadi dasar penting dalam pengembangan algoritma dan sistem berbasis jaringan [1][2][3].

## Referensi
<br>[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
<br>[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). Data Structures and Algorithms in C++. Wiley.
<br>[3] Rosen, K. H. (2012). Discrete Mathematics and Its Applications. McGraw-Hill.
