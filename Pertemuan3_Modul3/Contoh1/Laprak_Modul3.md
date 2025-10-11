# <h1 align="center">Laporan Praktikum Modul 3 - Modul 3 ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Najwa Mahira - 103112400091</p>

## Dasar Teori
Abstract Data Type (ADT) atau Tipe Data Abstrak adalah suatu model data yang mendefinisikan struktur logis dan operasi yang dapat dilakukan terhadap data tanpa menunjukkan detail implementasinya. Dalam ADT, pengguna hanya mengetahui apa yang dapat dilakukan, bukan bagaimana hal itu dilakukan [1]. 

### A. Konsep Dasar Abstract Data Type<br/>
#### 1. Definisi
ADT adalah tipe data yang didefinisikan oleh perilaku dan operasi yang dapat dilakukan terhadapnya tanpa memperhatikan detail penyimpanan dan representasi data di memori [1].
#### 2. Tujuan
Tujuan utama ADT adalah untuk meningkatkan modularitas, efisiensi, dan keamanan data, serta memudahkan pengembangan dan pemeliharaan perangkat lunak [2].
#### 3. Karakteristik
ADT memiliki tiga karakteristik utama: abstraksi data, enkapsulasi fungsi, dan pemisahan antara interface dan implementasi [3].

### B. Jenis dan Penerapan ADT<br/>
#### 1. Stack (Tumpukan)
Struktur data yang menerapkan prinsip Last In First Out (LIFO). Contohnya adalah operasi undo dalam editor teks [4].
#### 2. Queue (Antrian)
Struktur data dengan prinsip First In First Out (FIFO), digunakan dalam sistem antrian atau buffer data [3].
#### 3. List (Senarai)
Struktur data dinamis yang memungkinkan penyisipan dan penghapusan elemen di berbagai posisi dengan fleksibilitas tinggi [5].

## Guided 

### 1. pelajaran.h

```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```
Header `pelajaran.h` mendefinisikan **struct `pelajaran`** dengan atribut `namaMapel` dan `kodeMapel`, serta **deklarasi fungsi** `create_pelajaran` untuk membuat objek pelajaran dan `tampil_pelajaran` untuk menampilkan data pelajaran.

### 2. pelajaran

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
Kode ini **mendefinisikan fungsi-fungsi untuk struct `pelajaran`**: `create_pelajaran` membuat objek `pelajaran` baru dengan nama dan kode yang diberikan, sedangkan `tampil_pelajaran` menampilkan nama dan kode pelajaran ke layar menggunakan `cout`.

### 3. struct

```C++
#include<iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa m){
    cout << "Masukkan nama mahasiswa : ";
    cin >> m.nama;
    cout << "masukkan nilai 1 : ";
    cin >> m.nilai1;
    cout << "masukkan nilai 2 : ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return (m.nilai1 + m.nilai2)/2;
}

int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata rata : " << rata2(mhs);
    return 0;
}
```
Kode ini membuat struct `mahasiswa` untuk menyimpan nama dan dua nilai, meminta input dari user lewat fungsi `inputMhs` (namun tidak tersimpan karena pass-by-value), kemudian menghitung dan menampilkan rata-rata nilai lewat fungsi `rata2`.

## Unguided 

### 1. Soal Unguided 1

```C++
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

int main() {
    Mahasiswa mhs[10];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jumlah;
    cin.ignore();

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        getline(cin, mhs[i].nim);
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;
        cin.ignore();

        mhs[i].nilaiAkhir = (0.3 * mhs[i].uts) + (0.4 * mhs[i].uas) + (0.3 * mhs[i].tugas);
    }

    cout << "\n=== Daftar Nilai Mahasiswa ===" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "\nNama         : " << mhs[i].nama << endl;
        cout << "NIM          : " << mhs[i].nim << endl;
        cout << "Nilai Akhir  : " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan3_Modul3/image3/Output-Unguided1-Modul3-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan3_Modul3/image3/Output-Unguided1-Modul3-2.png)

Program ini membuat struct `Mahasiswa` untuk menyimpan data mahasiswa, meminta user memasukkan data nama, NIM, UTS, UAS, dan tugas, menghitung nilai akhir berdasarkan bobot 30% UTS, 40% UAS, dan 30% tugas, lalu menampilkan daftar nilai akhir semua mahasiswa yang diinput.

### 2. Soal Unguided 2

### pelajaran.h
```C++
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
```

### pelajaran.cpp
```C++
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
```
### main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    Pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan3_Modul3/image3/Output-Unguided2-Modul3-1.png)

Unguided 2 ini terdiri dari tiga file: `pelajaran.h` mendefinisikan struct pelajaran dan deklarasi fungsi, `pelajaran.cpp` mengimplementasikan fungsi untuk membuat dan menampilkan pelajaran, dan `main.cpp` membuat objek pelajaran dan menampilkan datanya ke layar.

### 3. (isi dengan soal unguided 3)

```C++
#include <iostream>
using namespace std;

const int BARIS = 3;
const int KOLOM = 3;

// Fungsi menampilkan isi array 2D
void tampilArray(int arr[BARIS][KOLOM]) {
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi menukar isi dua variabel integer menggunakan pointer
void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi menukar elemen dari dua array 2D pada posisi tertentu
void tukarArray(int arr1[BARIS][KOLOM], int arr2[BARIS][KOLOM], int baris, int kolom) {
    int *p1 = &arr1[baris][kolom];
    int *p2 = &arr2[baris][kolom];
    tukarPointer(p1, p2);
}

int main() {
    int A[BARIS][KOLOM] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[BARIS][KOLOM] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    // Menukar elemen array pada posisi [1][1]
    tukarArray(A, B, 1, 1);

    cout << "\nArray A sesudah ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sesudah ditukar:\n";
    tampilArray(B);

    // Menukar dua variabel menggunakan pointer
    int x = 10, y = 20;
    int *px = &x, *py = &y;

    cout << "\nSebelum ditukar:\n";
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(px, py);

    cout << "Sesudah ditukar:\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan3_Modul3/image3/Output-Unguided3-Modul3-1.png)

Kode ini membuat dua array 2D dan menampilkan isinya, kemudian menukar elemen tertentu antar array menggunakan pointer lewat fungsi `tukarArray` dan `tukarPointer`, serta menukar dua variabel `x` dan `y` menggunakan pointer, lalu menampilkan hasilnya sebelum dan sesudah penukaran.

## Kesimpulan
Abstract Data Type (ADT) merupakan konsep penting yang mendasari pembentukan struktur data dan pengembangan perangkat lunak modern. Berdasarkan hasil praktikum dan referensi jurnal [1]–[5], ADT terbukti mampu meningkatkan modularitas, efisiensi, keamanan data, serta kemudahan pemeliharaan program. Implementasi ADT di C++ dapat dilakukan menggunakan struct maupun class dengan prinsip abstraction dan encapsulation.

## Referensi
[1] Sugiarto, D., & Permana, R. (2021). Penerapan Konsep Abstract Data Type pada Pembelajaran Struktur Data Menggunakan Bahasa C++. Jurnal Teknologi dan Sistem Komputer (JTSK), 9(2), 67–74.
[2] Kusuma, A., & Prasetyo, F. (2022). Analisis Implementasi ADT dalam Bahasa Pemrograman Berorientasi Objek. Jurnal Rekayasa Teknologi Informasi, 10(1), 44–53.
[3] Nugraha, I., & Wahyuni, D. (2023). Efektivitas Abstract Data Type dalam Pengembangan Struktur Data Dinamis. Jurnal Informatika dan Komputasi (JIKOM), 8(3), 120–129.
[4] Rizaldi, A., Putri, M., & Rahman, S. (2021). Pengaruh Penerapan ADT terhadap Pemahaman Struktur Data Mahasiswa. Jurnal Pendidikan Teknologi Informasi, 6(1), 35–42.
[5] Wicaksono, T., & Hartati, E. (2020). Konsep Modularitas dan Abstraksi pada Struktur Data Berbasis ADT Menggunakan C++. Jurnal Sains dan Teknologi Komputer, 5(4), 88–96.
<br>...

