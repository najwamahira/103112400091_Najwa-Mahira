#include "stack.h"
#include <sstream>   // untuk istringstream

void createStack(Stack &S) { S.top = 0; }
bool isEmpty(Stack S) { return S.top == 0; }
bool isFull(Stack S) { return S.top == MAX_STACK; }

void push(Stack &S, int x) {
    if (!isFull(S)) {
        S.info[S.top++] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

int pop(Stack &S) {
    if (!isEmpty(S)) {
        return S.info[--S.top];
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void pushAscending(Stack &S, int X) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S) && S.info[S.top - 1] > X) {
        push(temp, pop(S));
    }
    push(S, X);
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

// Implementasi getInputStream: baca satu baris, parse integer per token, push ke stack
void getInputStream(Stack &S) {
    cout << "Masukkan angka (pisahkan dengan spasi), lalu Enter: ";
    string line;
    getline(cin, line);
    if (line.size() == 0) return; // tidak ada input
    istringstream iss(line);
    int val;
    while (iss >> val) {
        if (isFull(S)) {
            cout << "Stack penuh, sisa input diabaikan." << endl;
            break;
        }
        push(S, val);
    }
}
