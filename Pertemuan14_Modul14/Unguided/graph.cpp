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
