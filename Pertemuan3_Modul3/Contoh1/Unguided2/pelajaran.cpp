#include "pelajaran.h"
#include <iostream>
using namespace std;

Pelajaran create_pelajaran(const string& nama, const string& kode) {
    Pelajaran pel;
    pel.nama = nama;
    pel.kode = kode;
    return pel;
}

void tampil_pelajaran(const Pelajaran& pel) {
    cout << "Nama Pelajaran: " << pel.nama << endl;
    cout << "Kode Pelajaran: " << pel.kode << endl;
}
