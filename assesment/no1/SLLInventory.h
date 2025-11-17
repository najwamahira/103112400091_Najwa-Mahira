#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <iostream>
using namespace std;

struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;    
    float DiskonPersen;
    float HargaAkhir;     
};

typedef Product infotype;

struct Node {
    infotype info;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &L);
Node* createElement(infotype x);
bool isEmpty(List L);

void insertFirst(List &L, Node* P);
void insertLast(List &L, Node* P);
void insertAfter(List &L, Node* Prec, Node* P);

void deleteFirst(List &L, Node* &P);
void deleteLast(List &L, Node* &P);
void deleteAfter(List &L, Node* Prec, Node* &P);

void show(List L);

float hitungHargaAkhir(float harga, float diskon);
void updateAtPosition(List &L, int pos, infotype dataBaru);

void searchHargaAkhir(List L, float min, float max);

#endif