#include "BST.h"

int main() {
    BST tree;

    // 1. Input data
    tree.insertNode(50, "Monitor LED", 10);
    tree.insertNode(30, "Keyboard RGB", 20);
    tree.insertNode(70, "Mouse Gaming", 15);
    tree.insertNode(20, "Kabel HDMI", 50);
    tree.insertNode(40, "Headset 7.1", 12);
    tree.insertNode(60, "Webcam HD", 8);
    tree.insertNode(80, "Speaker BT", 5);

    // 2
    tree.inOrder();
    tree.preOrder();
    tree.postOrder();

    // 3–6
    tree.searchById(40);
    tree.searchById(99);
    tree.searchByProduct("Webcam HD");
    tree.searchByProduct("Printer");

    // 7
    tree.findMin();
    tree.findMax();

    // 8–15
    tree.deleteNode(20);
    tree.inOrder();

    tree.deleteNode(30);
    tree.inOrder();

    tree.deleteNode(50);
    tree.inOrder();

    tree.deleteTree();
    tree.inOrder();

    return 0;
}
