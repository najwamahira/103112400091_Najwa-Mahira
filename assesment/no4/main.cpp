#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;
    do {
        cout << "\n--- Komaniya Express ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket (deQueue)\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;

        if (pilihan == 1) {
            Paket P;
            cout << "Kode Resi     : "; cin >> P.KodeResi;
            cout << "Nama Pengirim : "; cin >> P.NamaPengirim;
            cout << "Berat Barang  : "; cin >> P.BeratBarang;
            cout << "Tujuan        : "; cin >> P.Tujuan;
            enQueue(Q, P);
        }

        else if (pilihan == 2) {
            deQueue(Q);
        }

        else if (pilihan == 3) {
            viewQueue(Q);
        }

        else if (pilihan == 4) {
            int total = TotalBiayaPengiriman(Q);
            cout << "Total Biaya Pengiriman : Rp " << total << endl;
        }

    } while (pilihan != 0);

    return 0;
}