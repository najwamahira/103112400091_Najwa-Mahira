#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

const int MAX_STACK = 20;

struct Stack {
    int info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, int x);
int pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x); // kalau sudah ada dari soal 2
void getInputStream(Stack &S);        // <-- tambah ini

#endif

