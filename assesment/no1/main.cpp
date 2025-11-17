#include "SLLInventory.h"

int main(){
    List L;
    createList(L);

    infotype A = {"Pulpen", "A001", 20, 2500, 0};
    infotype B = {"Buku Tulis", "A002", 15, 5000, 10};
    infotype C = {"Penghapus", "A003", 30, 1500, 0};

    insertLast(L, createElement(A));
    insertLast(L, createElement(B));
    insertLast(L, createElement(C));

    cout << "\nList Awal:\n";
    show(L);

    Node* X;
    deleteFirst(L, X);

    cout << "\nSetelah deleteFirst:\n";
    show(L);

    infotype baru = {"Stabilo", "A010", 40, 8000, 5};
    updateAtPosition(L, 2, baru);

    cout << "\nSetelah Update Posisi 2:\n";
    show(L);

    cout << "\nHasil Searching HargaAkhir 2000–7000:\n";
    searchHargaAkhir(L, 2000, 7000);

    return 0;
}