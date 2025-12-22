#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int idProduk;
    string namaProduk;
    int stok;
    Node *left;
    Node *right;
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int id, string nama, int stok);
    Node* deleteNode(Node* node, int id);
    Node* findMinNode(Node* node);
    void inOrder(Node* node);
    void preOrder(Node* node);
    void postOrder(Node* node);
    void deleteTree(Node* node);
    Node* searchById(Node* node, int id);
    void searchByProduct(Node* node, string nama, bool &found);

public:
    BST();
    void insertNode(int id, string nama, int stok);
    void inOrder();
    void preOrder();
    void postOrder();
    void deleteNode(int id);
    void deleteTree();
    void searchById(int id);
    void searchByProduct(string nama);
    void findMin();
    void findMax();
};

#endif
