#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#include <iostream>
#include <string>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
    float PopularityScore;
};

struct elmList {
    Song info;
    elmList *next;
    elmList *prev;
};

struct List {
    elmList *first;
    elmList *last;
};

void createList(List &L);
elmList* allocate(Song x);
void insertLast(List &L, elmList *P);
void printList(List L);
void deleteLast(List &L);
elmList* findElmByPosition(List L, int pos);
void updateAtPosition(List &L, int pos, Song dataBaru);

void insertBefore(List &L, int pos, Song x);
void updateBefore(List &L, int pos, Song x);
void deleteBefore(List &L, int pos);

void searchPopularity(List L, float minScore, float maxScore);

#endif