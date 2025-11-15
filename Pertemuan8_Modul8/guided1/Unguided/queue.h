#ifndef QUEUE_ALL_H
#define QUEUE_ALL_H

const int MAX = 5;
typedef int infotype;

struct QueueA1 {
    infotype info[MAX];
    int head;
    int tail;
};

void createA1(QueueA1 &Q);
bool emptyA1(QueueA1 Q);
bool fullA1(QueueA1 Q);
void enqueueA1(QueueA1 &Q, infotype x);
infotype dequeueA1(QueueA1 &Q);
void printA1(QueueA1 Q);

struct QueueA2 {
    infotype info[MAX];
    int head;
    int tail;
};

void createA2(QueueA2 &Q);
bool emptyA2(QueueA2 Q);
bool fullA2(QueueA2 Q);
void enqueueA2(QueueA2 &Q, infotype x);
infotype dequeueA2(QueueA2 &Q);
void printA2(QueueA2 Q);

struct QueueA3 {
    infotype info[MAX];
    int head;
    int tail;
    int count;
};

void createA3(QueueA3 &Q);
bool emptyA3(QueueA3 Q);
bool fullA3(QueueA3 Q);
void enqueueA3(QueueA3 &Q, infotype x);
infotype dequeueA3(QueueA3 &Q);
void printA3(QueueA3 Q);

#endif
