#include "Unguided2_ListAngka.h"

int main() {
    linkedList L;
    createList(L);

    Node* A = alokasi(50);
    Node* B = alokasi(20);
    Node* C = alokasi(25);
    Node* D = alokasi(29);
    Node* E = alokasi(45);

    insertLast(L, A);
    insertLast(L, B);
    insertLast(L, C);
    insertLast(L, D);
    insertLast(L, E);

    printList(L);
    cout << endl;

    searchByData(L, 20);
    searchByData(L, 55);
    searchByAddress(L, B);
    searchByAddress(L, A);
    searchByRange(L, 40);
    return 0;
}
