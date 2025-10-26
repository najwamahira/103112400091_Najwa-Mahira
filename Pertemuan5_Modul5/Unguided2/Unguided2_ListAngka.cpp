#include "Unguided2_ListAngka.h"

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
    cout << " ->" << endl;
}

void searchByData(linkedList L, dataAngka x) {
    Node* temp = L.first;
    int posisi = 1;
    bool found = false;

    while (temp != NULL) {
        if (temp->angka == x) {
            cout << "Data " << x << " ditemukan pada posisi ke-" << posisi << "!" << endl;
            found = true;
            break;
        }
        posisi++;
        temp = temp->next;
    }

    if (!found)
        cout << "Node dengan data " << x << " tidak ditemukan!" << endl;
    cout << endl;
}

void searchByAddress(linkedList L, Node* alamat) {
    Node* temp = L.first;
    int posisi = 1;
    bool found = false;

    while (temp != NULL) {
        if (temp == alamat) {
            cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
            cout << "Alamat node : " << temp << endl;
            found = true;
            break;
        }
        posisi++;
        temp = temp->next;
    }

    if (!found)
        cout << "Node dengan alamat " << alamat << " tidak ditemukan dalam list!" << endl;
    cout << endl;
}

void searchByRange(linkedList L, dataAngka nilaiMin) {
    Node* temp = L.first;
    int posisi = 1;
    cout << "--- Data diatas nilai " << nilaiMin << " : ---" << endl;

    while (temp != NULL) {
        if (temp->angka >= nilaiMin) {
            cout << "---------------------------------------------" << endl;
            cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << temp->angka << endl;
        }
        posisi++;
        temp = temp->next;
    }
    cout << "---------------------------------------------" << endl;
    cout << endl;
}
