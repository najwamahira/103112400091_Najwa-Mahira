#include "MultiLL.h"

// CEK KOSONG
bool isEmptyParent(listParent L) {
    return (L.first == NULL);
}

bool isEmptyChild(listChild L) {
    return (L.first == NULL);
}

// CREATE LIST
void createListParent(listParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

// ALOKASI
NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &P) { delete P; }
void deallocNodeChild(NodeChild &C) { delete C; }

// INSERT PARENT
void insertFirstParent(listParent &L, NodeParent newNode) {
    if (isEmptyParent(L)) {
        L.first = L.last = newNode;
    } else {
        newNode->next = L.first;
        L.first->prev = newNode;
        L.first = newNode;
    }
}

void insertLastParent(listParent &L, NodeParent newNode) {
    if (isEmptyParent(L)) {
        insertFirstParent(L, newNode);
    } else {
        L.last->next = newNode;
        newNode->prev = L.last;
        L.last = newNode;
    }
}

// DELETE PARENT
void deleteFirstParent(listParent &L) {
    if (!isEmptyParent(L)) {
        NodeParent del = L.first;

        deleteListChild(del->L_Child);

        if (L.first == L.last) {
            L.first = L.last = NULL;
        } else {
            L.first = del->next;
            L.first->prev = NULL;
        }
        deallocNodeParent(del);
    }
}

void deleteAfterParent(listParent &L, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent del = NPrev->next;

        deleteListChild(del->L_Child);

        NPrev->next = del->next;
        if (del->next != NULL)
            del->next->prev = NPrev;
        else
            L.last = NPrev;

        deallocNodeParent(del);
    }
}

// INSERT CHILD
void insertFirstChild(listChild &L, NodeChild newNode) {
    if (isEmptyChild(L)) {
        L.first = L.last = newNode;
    } else {
        newNode->next = L.first;
        L.first->prev = newNode;
        L.first = newNode;
    }
}

void insertLastChild(listChild &L, NodeChild newNode) {
    if (isEmptyChild(L)) {
        insertFirstChild(L, newNode);
    } else {
        L.last->next = newNode;
        newNode->prev = L.last;
        L.last = newNode;
    }
}

// DELETE CHILD
void deleteFirstChild(listChild &L) {
    if (!isEmptyChild(L)) {
        NodeChild del = L.first;
        if (L.first == L.last) {
            L.first = L.last = NULL;
        } else {
            L.first = del->next;
            L.first->prev = NULL;
        }
        deallocNodeChild(del);
    }
}

void deleteAfterChild(listChild &L, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild del = NPrev->next;
        NPrev->next = del->next;

        if (del->next != NULL)
            del->next->prev = NPrev;
        else
            L.last = NPrev;

        deallocNodeChild(del);
    }
}

void deleteListChild(listChild &L) {
    while (!isEmptyChild(L)) {
        deleteFirstChild(L);
    }
}

// PRINT STRUCTURE
void printMLLStructure(listParent L) {
    NodeParent P = L.first;
    while (P != NULL) {
        cout << "Golongan: " << P->isidata.idGolongan
             << " - " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        while (C != NULL) {
            cout << "   > " << C->isidata.idHewan
                 << " | " << C->isidata.namaHewan
                 << " | Habitat: " << C->isidata.habitat
                 << " | Ekor: " << (C->isidata.ekor ? "True" : "False")
                 << " | Bobot: " << C->isidata.bobot << endl;
            C = C->next;
        }
        cout << endl;
        P = P->next;
    }
}

// SEARCH HEWAN TANPA EKOR
void searchHewanByEkor(listParent L, bool tail) {
    cout << "HASIL PENCARIAN HEWAN DENGAN EKOR = "
         << (tail ? "TRUE" : "FALSE") << endl;

    NodeParent P = L.first;
    while (P != NULL) {
        NodeChild C = P->L_Child.first;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << C->isidata.idHewan
                     << " | " << C->isidata.namaHewan
                     << " | " << C->isidata.habitat
                     << " | Bobot: " << C->isidata.bobot << endl;
            }
            C = C->next;
        }
        P = P->next;
    }
    cout << endl;
}
