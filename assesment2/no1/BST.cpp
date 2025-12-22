#include "BST.h"

BST::BST() {
    root = NULL;
}

Node* BST::insert(Node* node, int id, string nama, int stok) {
    if (node == NULL) {
        Node* baru = new Node;
        baru->idProduk = id;
        baru->namaProduk = nama;
        baru->stok = stok;
        baru->left = baru->right = NULL;
        return baru;
    }
    if (id < node->idProduk)
        node->left = insert(node->left, id, nama, stok);
    else
        node->right = insert(node->right, id, nama, stok);
    return node;
}

void BST::insertNode(int id, string nama, int stok) {
    root = insert(root, id, nama, stok);
}

void BST::inOrder(Node* node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->idProduk << " - " << node->namaProduk
             << " (" << node->stok << ")" << endl;
        inOrder(node->right);
    }
}

void BST::preOrder(Node* node) {
    if (node != NULL) {
        cout << node->idProduk << " - " << node->namaProduk
             << " (" << node->stok << ")" << endl;
        preOrder(node->left);
        preOrder(node->right);
    }
}

void BST::postOrder(Node* node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->idProduk << " - " << node->namaProduk
             << " (" << node->stok << ")" << endl;
    }
}

void BST::inOrder() {
    cout << "\nInOrder Traversal:\n";
    inOrder(root);
}

void BST::preOrder() {
    cout << "\nPreOrder Traversal:\n";
    preOrder(root);
}

void BST::postOrder() {
    cout << "\nPostOrder Traversal:\n";
    postOrder(root);
}

Node* BST::searchById(Node* node, int id) {
    if (node == NULL || node->idProduk == id)
        return node;
    if (id < node->idProduk)
        return searchById(node->left, id);
    return searchById(node->right, id);
}

void BST::searchById(int id) {
    Node* hasil = searchById(root, id);
    if (hasil != NULL)
        cout << "ID " << id << " ditemukan: "
             << hasil->namaProduk << " (" << hasil->stok << ")\n";
    else
        cout << "ID " << id << " tidak ditemukan\n";
}

void BST::searchByProduct(Node* node, string nama, bool &found) {
    if (node != NULL) {
        searchByProduct(node->left, nama, found);
        if (node->namaProduk == nama) {
            cout << "Produk ditemukan: " << node->idProduk
                 << " (" << node->stok << ")\n";
            found = true;
        }
        searchByProduct(node->right, nama, found);
    }
}

void BST::searchByProduct(string nama) {
    bool found = false;
    searchByProduct(root, nama, found);
    if (!found)
        cout << "Produk " << nama << " tidak ditemukan\n";
}

Node* BST::findMinNode(Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

void BST::findMin() {
    Node* min = findMinNode(root);
    if (min)
        cout << "ID terkecil: " << min->idProduk << endl;
}

void BST::findMax() {
    Node* node = root;
    while (node && node->right != NULL)
        node = node->right;
    if (node)
        cout << "ID terbesar: " << node->idProduk << endl;
}

Node* BST::deleteNode(Node* node, int id) {
    if (node == NULL) return node;

    if (id < node->idProduk)
        node->left = deleteNode(node->left, id);
    else if (id > node->idProduk)
        node->right = deleteNode(node->right, id);
    else {
        if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMinNode(node->right);
        node->idProduk = temp->idProduk;
        node->namaProduk = temp->namaProduk;
        node->stok = temp->stok;
        node->right = deleteNode(node->right, temp->idProduk);
    }
    return node;
}

void BST::deleteNode(int id) {
    root = deleteNode(root, id);
}

void BST::deleteTree(Node* node) {
    if (node != NULL) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void BST::deleteTree() {
    deleteTree(root);
    root = NULL;
    cout << "Tree berhasil dihapus\n";
}
