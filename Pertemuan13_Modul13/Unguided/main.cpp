#include "MultiLL.h"

int main() {
    listParent L;
    createListParent(L);

    // --- INSERT PARENT ---
    insertLastParent(L, allocNodeParent("G001", "Aves"));
    insertLastParent(L, allocNodeParent("G002", "Mamalia"));
    insertLastParent(L, allocNodeParent("G003", "Pisces"));
    insertLastParent(L, allocNodeParent("G004", "Amfibi"));
    insertLastParent(L, allocNodeParent("G005", "Reptil"));

    // POINTER PARENT
    NodeParent P = L.first;

    // G001
    insertLastChild(P->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    // G002
    P = P->next;
    insertLastChild(P->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(P->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(P->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    // G003 -> kosong

    // G004
    P = P->next->next;
    insertLastChild(P->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    // CETAK STRUKTUR AWAL
    cout << "=== PRINT AWAL ===" << endl;
    printMLLStructure(L);

    // SEARCH HEWAN TANPA EKOR
    searchHewanByEkor(L, false);

    // DELETE G004
    cout << "=== DELETE G004 ===" << endl;
    P = L.first->next->next; // G001 -> G002 -> G003 -> G004
    deleteAfterParent(L, P);

    // CETAK SETELAH DELETE
    printMLLStructure(L);

    return 0;
}
