#include <iostream>
#include "queue.h"
using namespace std;

void createA1(QueueA1 &Q){
    Q.head = 0;
    Q.tail = -1;
}

bool emptyA1(QueueA1 Q){
    return Q.tail < Q.head;
}

bool fullA1(QueueA1 Q){
    return Q.tail == MAX - 1;
}

void enqueueA1(QueueA1 &Q, infotype x){
    if(!fullA1(Q)){
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeueA1(QueueA1 &Q){
    if(emptyA1(Q)) return -1;
    infotype x = Q.info[Q.head];
    for(int i = Q.head; i < Q.tail; i++)
        Q.info[i] = Q.info[i+1];
    Q.tail--;
    return x;
}

void printA1(QueueA1 Q){
    if(emptyA1(Q)) cout << "Kosong\n";
    else{
        for(int i=Q.head; i<=Q.tail; i++)
            cout << Q.info[i] << " ";
        cout << endl;
    }
}

void createA2(QueueA2 &Q){
    Q.head = 0;
    Q.tail = -1;
}

bool emptyA2(QueueA2 Q){
    return Q.tail < Q.head;
}

bool fullA2(QueueA2 Q){
    return Q.tail == MAX - 1;
}

void enqueueA2(QueueA2 &Q, infotype x){
    if(fullA2(Q)){
        int j = 0;
        for(int i = Q.head; i <= Q.tail; i++)
            Q.info[j++] = Q.info[i];
        Q.head = 0;
        Q.tail = j - 1;
    }
    if(!fullA2(Q)){
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeueA2(QueueA2 &Q){
    if(emptyA2(Q)) return -1;
    infotype x = Q.info[Q.head];
    Q.head++;
    if(Q.head > Q.tail) createA2(Q);
    return x;
}

void printA2(QueueA2 Q){
    if(emptyA2(Q)) cout << "Kosong\n";
    else{
        for(int i=Q.head; i<=Q.tail; i++)
            cout << Q.info[i] << " ";
        cout << endl;
    }
}

void createA3(QueueA3 &Q){
    Q.head = 0;
    Q.tail = -1;
    Q.count = 0;
}

bool emptyA3(QueueA3 Q){
    return Q.count == 0;
}

bool fullA3(QueueA3 Q){
    return Q.count == MAX;
}

void enqueueA3(QueueA3 &Q, infotype x){
    if(!fullA3(Q)){
        Q.tail = (Q.tail + 1) % MAX;
        Q.info[Q.tail] = x;
        Q.count++;
    }
}

infotype dequeueA3(QueueA3 &Q){
    if(emptyA3(Q)) return -1;
    infotype x = Q.info[Q.head];
    Q.head = (Q.head + 1) % MAX;
    Q.count--;
    return x;
}

void printA3(QueueA3 Q){
    if(emptyA3(Q)) cout << "Kosong\n";
    else{
        int idx = Q.head;
        for(int i=0; i < Q.count; i++){
            cout << Q.info[idx] << " ";
            idx = (idx + 1) % MAX;
        }
        cout << endl;
    }
}
