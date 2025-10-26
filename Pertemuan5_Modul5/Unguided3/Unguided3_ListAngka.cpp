#include "Unguided3_ListAngka.h"

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

// -------------------------
// Operasi Aritmatika
// -------------------------

int sumList(linkedList L) {
    int sum = 0;
    Node* temp = L.first;
    while (temp != NULL) {
        sum += temp->angka;
        temp = temp->next;
    }
    return sum;
}

int subList(linkedList L) {
    if (L.first == NULL) return 0;
    int hasil = L.first->angka;
    Node* temp = L.first->next;
    while (temp != NULL) {
        hasil -= temp->angka;
        temp = temp->next;
    }
    return hasil;
}

int mulList(linkedList L) {
    int hasil = 1;
    Node* temp = L.first;
    while (temp != NULL) {
        hasil *= temp->angka;
        temp = temp->next;
    }
    return hasil;
}
