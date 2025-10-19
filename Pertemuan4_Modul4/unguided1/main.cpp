#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    // Unguided 1 - Membuat linked list
    insertFirst(L, 2);
    insertFirst(L, 9);
    insertFirst(L, 5);
    insertFirst(L, 12);
    insertAfter(L.first->next, 8); // Menambah node setelah 9

    cout << "Isi Linked List: ";
    printInfo(L);

    // Unguided 2 - Penghapusan dan hitung jumlah node
    cout << "\n--- Operasi Penghapusan ---" << endl;
    deleteFirst(L);        // Hapus node 9
    deleteLast(L);         // Hapus node 2
    deleteAfter(L.first);  // Hapus node 8

    cout << "Isi Linked List Setelah Penghapusan: ";
    printInfo(L);

    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
