#include "Unguided1_ListAngka.h"

void createList(linkedList &L) { L.first = NULL; }

Node* alokasi(dataAngka x) {
    Node* p = new Node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void insertLast(linkedList &L, Node* p) {
    if (L.first == NULL) L.first = p;
    else {
        Node* temp = L.first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
}

void printList(linkedList L) {
    Node* temp = L.first;
    while (temp != NULL) {
        cout << temp->angka;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

void updateFirst(linkedList &L) {
    if (L.first == NULL) return;
    cout << "Masukkan update data node pertama : ";
    int x; cin >> x;
    L.first->angka = x;
    cout << "Data Berhasil Diupdate!\n" << endl;
}

void updateAfter(Node* prec) {
    if (prec != NULL && prec->next != NULL) {
        cout << "Masukkan update data node setelah node " << prec->angka << " : ";
        int x; cin >> x;
        prec->next->angka = x;
        cout << "Data Berhasil Diupdate!\n" << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.first == NULL) return;
    Node* temp = L.first;
    while (temp->next != NULL)
        temp = temp->next;
    cout << "Masukkan update data node terakhir : ";
    int x; cin >> x;
    temp->angka = x;
    cout << "Data Berhasil Diupdate!\n" << endl;
}
