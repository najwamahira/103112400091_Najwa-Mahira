#include <iostream>
#include "Doublylist2.h"
using std::cout;

void CreateList(List &L){L.first=nullptr;L.last=nullptr;}
address alokasi(const infotype &x){address P=new ElmList;P->info=x;P->next=nullptr;P->prev=nullptr;return P;}
void dealokasi(address &P){delete P;P=nullptr;}

void insertLast(List &L,address P){
    if(!L.first){L.first=P;L.last=P;}
    else{L.last->next=P;P->prev=L.last;L.last=P;}
}

void printInfo(const List &L){
    cout<<"\nDATA LIST 1\n\n";
    address P=L.first;
    while(P){cout<<"Nomer Polisi : "<<P->info.nopol<<"\n";cout<<"Warna        : "<<P->info.warna<<"\n";cout<<"Tahun        : "<<P->info.thnBuat<<"\n\n";P=P->next;}
}

address findElm(const List &L,const string &nopol){address P=L.first;while(P){if(P->info.nopol==nopol)return P;P=P->next;}return nullptr;}
