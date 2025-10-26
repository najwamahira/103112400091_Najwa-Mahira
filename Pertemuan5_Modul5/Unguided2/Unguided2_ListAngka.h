#ifndef UNGUIDED2_LISTANGKA_H
#define UNGUIDED2_LISTANGKA_H
#include <iostream>
using namespace std;

typedef int dataAngka;

struct Node {
    dataAngka angka;
    Node* next;
};

struct linkedList {
    Node* first;
};

void createList(linkedList &L);
Node* alokasi(dataAngka x);
void insertLast(linkedList &L, Node* p);
void printList(linkedList L);
void searchByData(linkedList L, dataAngka x);
void searchByAddress(linkedList L, Node* alamat);
void searchByRange(linkedList L, dataAngka nilaiMin);

#endif
