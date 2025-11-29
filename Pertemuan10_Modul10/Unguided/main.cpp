#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    cout << "In-order: ";
    InOrder(root);

    cout << "\nPre-order: ";
    PreOrder(root);

    cout << "\nPost-order: ";
    PostOrder(root);

    cout << "\n\nKedalaman Tree: " << hitungKedalaman(root, 0);
    cout << "\nJumlah Node: " << hitungJumlahNode(root);
    cout << "\nTotal Info: " << hitungTotalInfo(root);

    return 0;
}
