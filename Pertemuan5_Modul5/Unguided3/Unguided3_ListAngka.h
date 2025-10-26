#ifndef UNGUIDED3_LISTANGKA_H
#define UNGUIDED3_LISTANGKA_H
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

// fungsi dasar
void createList(linkedList &L);
Node* alokasi(dataAngka x);
void insertLast(linkedList &L, Node* p);
void printList(linkedList L);

// operasi aritmatika
int sumList(linkedList L);
int subList(linkedList L);
int mulList(linkedList L);

#endif
