#include "QueuePengiriman.h"

bool isEmpty(QueueEkspedisi Q) {
    return Q.Tail == -1;
}

bool isFull(QueueEkspedisi Q) {
    return Q.Tail == MAX - 1;
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q, Paket data) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
    } else {
        if (isEmpty(Q)) {
            Q.Head = Q.Tail = 0;
        } else {
            Q.Tail++;
        }
        Q.dataPaket[Q.Tail] = data;
    }
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
    } else {
        for (int i = Q.Head; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }
        Q.Tail--;

        if (Q.Tail < Q.Head)
            createQueue(Q);
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
    } else {
        cout << "--- Data Paket dalam Queue ---\n";
        for (int i = Q.Head; i <= Q.Tail; i++) {
            cout << "Kode Resi     : " << Q.dataPaket[i].KodeResi << endl;
            cout << "Nama Pengirim : " << Q.dataPaket[i].NamaPengirim << endl;
            cout << "Berat Barang  : " << Q.dataPaket[i].BeratBarang << " kg" << endl;
            cout << "Tujuan        : " << Q.dataPaket[i].Tujuan << endl;
            cout << "-----------------------------\n";
        }
    }
}

// ---------------- BAGIAN B -------------------
int TotalBiayaPengiriman(QueueEkspedisi Q) {
    int totalKg = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        totalKg += Q.dataPaket[i].BeratBarang;
    }
    return totalKg * 8250;   // biaya per kg
}