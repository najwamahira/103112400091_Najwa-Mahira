#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct Pelajaran {
    string nama;
    string kode;
};

// Fungsi untuk membuat data pelajaran
Pelajaran create_pelajaran(const string& nama, const string& kode);

// Fungsi untuk menampilkan data pelajaran
void tampil_pelajaran(const Pelajaran& pel);

#endif
