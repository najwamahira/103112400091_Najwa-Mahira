#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

typedef int infotype;

struct Node {
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;

/* Alokasi node baru */
address alokasi(infotype x);

/* Insert node ke BST */
void insertNode(address &root, infotype x);

/* Mencari node */
address findNode(address root, infotype x);

/* Traversal In-order */
void InOrder(address root);

/* Traversal Pre-order */
void PreOrder(address root);

/* Traversal Post-order */
void PostOrder(address root);

/* Latihan 2 */
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int depth);

#endif
