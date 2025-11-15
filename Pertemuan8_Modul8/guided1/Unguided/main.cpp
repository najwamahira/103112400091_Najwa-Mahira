#include <iostream>
#include "queue.h"
using namespace std;

int main(){
    int pilihan;
    do{
        cout << "\nMENU\n";
        cout << "1. Queue Alternatif 1\n";
        cout << "2. Queue Alternatif 2\n";
        cout << "3. Queue Alternatif 3\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if(pilihan == 1){
            QueueA1 Q;
            createA1(Q);
            enqueueA1(Q,5); printA1(Q);
            enqueueA1(Q,2); printA1(Q);
            enqueueA1(Q,7); printA1(Q);
            dequeueA1(Q); printA1(Q);
            enqueueA1(Q,4); printA1(Q);

        } else if(pilihan == 2){
            QueueA2 Q;
            createA2(Q);
            enqueueA2(Q,5); printA2(Q);
            enqueueA2(Q,2); printA2(Q);
            enqueueA2(Q,7); printA2(Q);
            dequeueA2(Q); printA2(Q);
            enqueueA2(Q,4); printA2(Q);

        } else if(pilihan == 3){
            QueueA3 Q;
            createA3(Q);
            enqueueA3(Q,5); printA3(Q);
            enqueueA3(Q,2); printA3(Q);
            enqueueA3(Q,7); printA3(Q);
            dequeueA3(Q); printA3(Q);
            enqueueA3(Q,4); printA3(Q);
        }

    } while(pilihan != 0);

    return 0;
}
