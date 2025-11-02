#include <iostream>
#include "Doublylist.h"
using std::cin; using std::cout; using std::endl;

int main() {
    List L; CreateList(L);

    const int JUMLAH = 4;
    for (int i = 0; i < JUMLAH; ++i) {
        infotype k;
        cout << "masukkan nomor polisi : "; cin >> k.nopol;
        cout << "masukkan warna kendaraan: "; cin >> k.warna;
        cout << "masukkan tahun kendaraan: "; cin >> k.thnBuat;
        cout << "\n";
        if (findElm(L, k.nopol) != nullptr) {
            cout << "nomor polisi sudah terdaftar\n\n";
            continue;
        }
        insertFirst(L, alokasi(k));
    }

    printInfo(L);
    return 0;
}
