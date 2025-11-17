#include "SLLInventory.h"

void createList(List &L){
    L.first = NULL;
}

Node* createElement(infotype x){
    Node* P = new Node;
    x.HargaAkhir = hitungHargaAkhir(x.HargaSatuan, x.DiskonPersen);
    P->info = x;
    P->next = NULL;
    return P;
}

bool isEmpty(List L){
    return L.first == NULL;
}

void insertFirst(List &L, Node* P){
    P->next = L.first;
    L.first = P;
}

void insertLast(List &L, Node* P){
    if(isEmpty(L)){
        insertFirst(L, P);
    } else {
        Node* Q = L.first;
        while(Q->next != NULL) Q = Q->next;
        Q->next = P;
    }
}

void insertAfter(List &L, Node* Prec, Node* P){
    if(Prec != NULL){
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(List &L, Node* &P){
    if(!isEmpty(L)){
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void deleteLast(List &L, Node* &P){
    if(!isEmpty(L)){
        Node* Q = L.first;
        if(Q->next == NULL){
            deleteFirst(L, P);
        } else {
            while(Q->next->next != NULL) Q = Q->next;
            P = Q->next;
            Q->next = NULL;
        }
    }
}

void deleteAfter(List &L, Node* Prec, Node* &P){
    if(Prec != NULL && Prec->next != NULL){
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}

float hitungHargaAkhir(float harga, float diskon){
    return harga * (1 - (diskon / 100));
}

void show(List L){
    Node* P = L.first;
    int i = 1;
    while(P != NULL){
        cout << i << ". " << P->info.Nama
             << " | SKU: " << P->info.SKU
             << " | Jumlah: " << P->info.Jumlah
             << " | Satuan: " << P->info.HargaSatuan
             << " | Diskon: " << P->info.DiskonPersen
             << " | HargaAkhir: " << P->info.HargaAkhir
             << endl;
        P = P->next;
        i++;
    }
}

void updateAtPosition(List &L, int pos, infotype dataBaru){
    Node* P = L.first;
    int idx = 1;
    while(P != NULL && idx < pos){
        P = P->next;
        idx++;
    }
    if(P != NULL){
        dataBaru.HargaAkhir = hitungHargaAkhir(dataBaru.HargaSatuan, dataBaru.DiskonPersen);
        P->info = dataBaru;
    }
}

void searchHargaAkhir(List L, float min, float max){
    Node* P = L.first;
    while(P != NULL){
        if(P->info.HargaAkhir >= min && P->info.HargaAkhir <= max){
            cout << P->info.Nama << " | HargaAkhir: " << P->info.HargaAkhir << endl;
        }
        P = P->next;
    }
}