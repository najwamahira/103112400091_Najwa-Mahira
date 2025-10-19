#include "Singlylist.h"

// Membuat list kosong
void createList(List& L) {
    L.first = NULL;
}

// Menambah node di awal
void insertFirst(List& L, int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = L.first;
    L.first = baru;
}

// Menambah node setelah node tertentu
void insertAfter(Node* prevNode, int nilai) {
    if (prevNode != NULL) {
        Node* baru = new Node;
        baru->data = nilai;
        baru->next = prevNode->next;
        prevNode->next = baru;
    }
}

// Menambah node di akhir
void insertLast(List& L, int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (L.first == NULL) {
        L.first = baru;
    } else {
        Node* temp = L.first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// Menghapus node pertama
void deleteFirst(List& L) {
    if (L.first != NULL) {
        Node* hapus = L.first;
        L.first = L.first->next;
        delete hapus;
    }
}

// Menghapus node setelah node tertentu
void deleteAfter(Node* prevNode) {
    if (prevNode != NULL && prevNode->next != NULL) {
        Node* hapus = prevNode->next;
        prevNode->next = hapus->next;
        delete hapus;
    }
}

// Menghapus node terakhir
void deleteLast(List& L) {
    if (L.first == NULL) return;
    if (L.first->next == NULL) {
        delete L.first;
        L.first = NULL;
    } else {
        Node* temp = L.first;
        Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
    }
}

// Menampilkan isi list
void printInfo(List L) {
    Node* temp = L.first;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Menghitung jumlah node
int nbList(List L) {
    int count = 0;
    Node* temp = L.first;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Menghapus semua node
void deleteList(List& L) {
    Node* temp = L.first;
    while (temp != NULL) {
        Node* hapus = temp;
        temp = temp->next;
        delete hapus;
    }
    L.first = NULL;
}
