#include "Unguided3_ListAngka.h"

int main() {
    linkedList L;
    createList(L);

    // Data hasil update dari Unguided 1
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

    cout << "List: ";
    printList(L);

    cout << "\nPenjumlahan data: " << sumList(L) << endl;
    cout << "Pengurangan data: " << subList(L) << endl;
    cout << "Perkalian data: " << mulList(L) << endl;

    return 0;
}
