#ifndef LISTANGKA_H
#define LISTANGKA_H
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
void updateFirst(linkedList &L);
void updateAfter(Node* prec);
void updateLast(linkedList &L);

#endif
