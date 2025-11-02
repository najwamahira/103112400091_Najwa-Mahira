#include <iostream>
#include "Doublylist2.h"
using std::cout; using std::cin;

int main(){
    List L; CreateList(L);

    // isi contoh awal (sesuai modul)
    insertLast(L, alokasi({ "D001", "hitam", 2010 }));
    insertLast(L, alokasi({ "D003", "putih", 2015 }));
    insertLast(L, alokasi({ "D004", "kuning", 2018 }));

    printInfo(L);

    string cari;
    cout << "Masukkan Nomor Polisi yang dicari : "; cin >> cari;
    address f = findElm(L, cari);
    if (f){
        cout << "\nNomor Polisi : " << f->info.nopol << "\n";
        cout << "Warna        : " << f->info.warna << "\n";
        cout << "Tahun        : " << f->info.thnBuat << "\n";
    } else cout << "Data tidak ditemukan\n";

    return 0;
}
