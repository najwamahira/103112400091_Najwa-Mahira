#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using std::string;

struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef Kendaraan infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address prev;
    address next;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void printInfo(const List &L);
void insertFirst(List &L, address P);
address findElm(const List &L, const string &nopol);

#endif // DOUBLYLIST_H
