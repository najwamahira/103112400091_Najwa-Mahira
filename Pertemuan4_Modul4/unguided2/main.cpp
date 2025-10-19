#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    // Membuat linked list dari soal latihan pertama
    insertFirst(L, 2);
    insertFirst(L, 9);
    insertFirst(L, 5);
    insertFirst(L, 12);
    insertAfter(L.first->next, 8); // Node 8 setelah node 9

    // --- Penghapusan sesuai instruksi soal ---
    deleteFirst(L);        // Hapus node 9
    deleteLast(L);         // Hapus node 2
    deleteAfter(L.first);  // Hapus node 8 (setelah node 12)

    // --- Tampilkan hasil setelah penghapusan ---
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    // --- Hapus semua node ---
    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
