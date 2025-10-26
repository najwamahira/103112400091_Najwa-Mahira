#include "Unguided1_ListAngka.h"

int main() {
    linkedList L;
    createList(L);

    Node* A = alokasi(40);
    Node* B = alokasi(18);
    Node* C = alokasi(25);
    Node* D = alokasi(8);
    Node* E = alokasi(33);

    insertLast(L, A);
    insertLast(L, B);
    insertLast(L, C);
    insertLast(L, D);
    insertLast(L, E);

    cout << "List awal: ";
    printList(L);

    cout << endl;
    updateFirst(L);      // ubah 40 -> 50
    updateAfter(C);      // ubah 8 -> 29
    updateLast(L);       // ubah 33 -> 45
    updateAfter(L.first);// ubah 18 -> 20

    cout << "List setelah update: ";
    printList(L);
    return 0;
}
