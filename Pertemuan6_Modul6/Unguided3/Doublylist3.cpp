#include <iostream>
#include "Doublylist3.h"
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

address findElm(const List &L,const string &nopol){address P=L.first;while(P){if(P->info.nopol==nopol) return P;P=P->next;}return nullptr;}

void deleteFirst(List &L,address &P){
    if(!L.first){P=nullptr;return;}
    P = L.first;
    if(L.first==L.last){L.first=L.last=nullptr;}
    else { L.first = P->next; L.first->prev = nullptr; P->next = nullptr; }
}

void deleteLast(List &L,address &P){
    if(!L.last){P=nullptr;return;}
    P = L.last;
    if(L.first==L.last){L.first=L.last=nullptr;}
    else { L.last = P->prev; L.last->next = nullptr; P->prev = nullptr; }
}

void deleteAfter(List &L,address Prec,address &P){
    if(!Prec){P=nullptr;return;}
    P = Prec->next;
    if(!P) return;
    address R = P->next;
    Prec->next = R;
    if(R) R->prev = Prec;
    else L.last = Prec;
    P->next = nullptr; P->prev = nullptr;
}
