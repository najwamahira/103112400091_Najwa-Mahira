#ifndef MLL_H
#define MLL_H

#include <iostream>
using namespace std;

struct nodeChild {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    nodeChild *next;
    nodeChild *prev;
};

struct ListChild {
    nodeChild *first;
    nodeChild *last;
};

struct nodeParent {
    string IDGenre;
    string namaGenre;
    nodeParent *next;
    nodeParent *prev;
    ListChild child;
};

struct ListParent {
    nodeParent *first;
    nodeParent *last;
};

void createListParent(ListParent &LP);
void createListChild(ListChild &LC);

nodeParent* alokasiNodeParent(string id, string nama);
nodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);

void dealokasiNodeParent(nodeParent *p);
void dealokasiNodeChild(nodeChild *c);

void insertFirstParent(ListParent &LP, nodeParent *p);
void insertLastChild(ListChild &LC, nodeChild *c);

void hapusListChild(ListChild &LC);
void deleteAfterParent(ListParent &LP, string IDParent);

void searchFilmByRatingRange(ListParent LP, float min, float max);
void printStrukturMLL(ListParent LP);

#endif