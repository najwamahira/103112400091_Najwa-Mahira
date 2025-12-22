#include "graphKota.h"

int main() {
    GraphKota G;
    createGraph(G);

    insertNode(G, "Bogor");
    insertNode(G, "Bekasi");
    insertNode(G, "Jakarta");
    insertNode(G, "Depok");
    insertNode(G, "Tangerang");

    connectNode(G, "Bogor", "Bekasi", 60);
    connectNode(G, "Bogor", "Jakarta", 42);
    connectNode(G, "Bogor", "Depok", 22);

    connectNode(G, "Depok", "Bekasi", 25);
    connectNode(G, "Depok", "Tangerang", 30);
    connectNode(G, "Depok", "Jakarta", 21);

    connectNode(G, "Jakarta", "Bekasi", 16);
    connectNode(G, "Jakarta", "Tangerang", 24);

    connectNode(G, "Bekasi", "Tangerang", 45);

    printGraph(G);
    cout << endl;

    deleteNode(G, "Depok");
    printGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL BFS & DFS ===" << endl;
    printBFS(G, "Tangerang");
    printDFS(G, "Tangerang");

    return 0;
}