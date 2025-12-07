#ifndef MULTILL_H_INCLUDED
#define MULTILL_H_INCLUDED

#include <iostream>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

// FUNGSI & PROSEDUR
bool isEmptyParent(listParent L);
bool isEmptyChild(listChild L);

void createListParent(listParent &L);
void createListChild(listChild &L);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &P);
void deallocNodeChild(NodeChild &C);

void insertFirstParent(listParent &L, NodeParent newNode);
void insertLastParent(listParent &L, NodeParent newNode);
void deleteFirstParent(listParent &L);
void deleteAfterParent(listParent &L, NodeParent NPrev);

void insertFirstChild(listChild &L, NodeChild newNode);
void insertLastChild(listChild &L, NodeChild newNode);
void deleteFirstChild(listChild &L);
void deleteAfterChild(listChild &L, NodeChild NPrev);

void deleteListChild(listChild &L);

void printMLLStructure(listParent L);
void searchHewanByEkor(listParent L, bool tail);

#endif
