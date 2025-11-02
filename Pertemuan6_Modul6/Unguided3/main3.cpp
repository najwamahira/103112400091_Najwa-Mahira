#include <iostream>
#include "Doublylist3.h"
using std::cout;

int main(){
    List L; CreateList(L);

    // isi awal sesuai contoh modul (agar output mirip)
    insertLast(L, alokasi({ "D004", "kuning", 2018 }));
    insertLast(L, alokasi({ "D003", "putih", 2015 }));
    insertLast(L, alokasi({ "D001", "hitam", 2010 }));

    printInfo(L);

    // hapus D003 (seperti soal)
    const char* hapus = "D003";
    cout << "Masukkan Nomor Polisi yang akan dihapus : " << hapus << "\n";
    address del = findElm(L, hapus);
    if (!del) {
        cout << "Data dengan nomor polisi " << hapus << " tidak ditemukan.\n";
    } else {
        if (del == L.first) {
            address P; deleteFirst(L, P); dealokasi(P);
        } else if (del == L.last) {
            address P; deleteLast(L, P); dealokasi(P);
        } else {
            address prec = del->prev; address P; deleteAfter(L, prec, P); dealokasi(P);
        }
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus.\n";
    }

    printInfo(L);
    return 0;
}
