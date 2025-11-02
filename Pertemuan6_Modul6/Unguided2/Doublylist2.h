#ifndef DOUBLYLIST2_H
#define DOUBLYLIST2_H

#include <string>
using std::string;

struct Kendaraan { string nopol; string warna; int thnBuat; };
typedef Kendaraan infotype;
struct ElmList; typedef ElmList* address;
struct ElmList { infotype info; address prev; address next; };
struct List { address first; address last; };

void CreateList(List &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(const List &L);
address findElm(const List &L, const string &nopol);

#endif // DOUBLYLIST2_H
