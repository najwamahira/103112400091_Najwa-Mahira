#include "DLLPlaylist.h"

float getPopularity(int play, float rating){
    return 0.8 * play + 20.0 * rating;
}

void createList(List &L){
    L.first = NULL;
    L.last = NULL;
}

elmList* allocate(Song x){
    elmList *P = new elmList;
    x.PopularityScore = getPopularity(x.PlayCount, x.Rating);
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertLast(List &L, elmList *P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void printList(List L){
    elmList *P = L.first;
    int i = 1;
    while(P != NULL){
        cout << i << ". " << P->info.Title 
             << " | Artist: " << P->info.Artist
             << " | Play: " << P->info.PlayCount
             << " | Rating: " << P->info.Rating
             << " | Popularity: " << P->info.PopularityScore 
             << endl;
        P = P->next;
        i++;
    }
}

void deleteLast(List &L){
    if(L.first == NULL) return;
    if(L.first == L.last){
        delete L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        elmList *del = L.last;
        L.last = del->prev;
        L.last->next = NULL;
        delete del;
    }
}

elmList* findElmByPosition(List L, int pos){
    elmList *P = L.first;
    int i = 1;
    while(P != NULL && i < pos){
        P = P->next;
        i++;
    }
    return P;
}

void updateAtPosition(List &L, int pos, Song x){
    elmList *P = findElmByPosition(L, pos);
    if(P != NULL){
        x.PopularityScore = getPopularity(x.PlayCount, x.Rating);
        P->info = x;
    }
}

// ------------------- BEFORE OPS -------------------
void insertBefore(List &L, int pos, Song x){
    elmList *Q = findElmByPosition(L, pos);
    if(Q == NULL) return;

    elmList *P = allocate(x);
    if(Q->prev == NULL){
        P->next = Q;
        Q->prev = P;
        L.first = P;
    } else {
        P->next = Q;
        P->prev = Q->prev;
        Q->prev->next = P;
        Q->prev = P;
    }
}

void updateBefore(List &L, int pos, Song x){
    elmList *Q = findElmByPosition(L, pos);
    if(Q == NULL || Q->prev == NULL) return;
    elmList *P = Q->prev;
    x.PopularityScore = getPopularity(x.PlayCount, x.Rating);
    P->info = x;
}

void deleteBefore(List &L, int pos){
    elmList *Q = findElmByPosition(L, pos);
    if(Q == NULL || Q->prev == NULL) return;
    elmList *del = Q->prev;

    if(del->prev == NULL){
        L.first = Q;
        Q->prev = NULL;
    } else {
        del->prev->next = Q;
        Q->prev = del->prev;
    }
    delete del;
}

void searchPopularity(List L, float minS, float maxS){
    elmList *P = L.first;
    while(P != NULL){
        if(P->info.PopularityScore >= minS && P->info.PopularityScore <= maxS){
            cout << P->info.Title << " | Pop: " << P->info.PopularityScore << endl;
        }
        P = P->next;
    }
}