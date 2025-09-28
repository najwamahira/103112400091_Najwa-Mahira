# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Najwa Mahira - 103112400091</p>

## Dasar Teori
Bahasa C++ merupakan salah satu bahasa pemrograman tingkat menengah yang mendukung paradigma pemrograman prosedural dan berorientasi objek. Bahasa ini banyak digunakan dalam dunia pendidikan karena sintaksnya cukup dekat dengan bahasa mesin namun tetap mudah dipahami mahasiswa [1].

### A. Pengenalan C++<br/>
Bahasa C++ adalah bahasa pemrograman tingkat menengah yang mendukung pemrograman prosedural maupun berorientasi objek. Menurut Suryadi & Kurniawan (2019), C++ sering digunakan dalam pembelajaran dasar pemrograman karena sintaksnya yang sistematis dan strukturnya yang membantu mahasiswa memahami logika algoritmik [3]. Selain itu, C++ memiliki keunggulan dalam efisiensi penggunaan memori dan kecepatan eksekusi program, sehingga masih relevan digunakan dalam dunia pendidikan maupun industri [3].
#### 1. Variabel dan Tipe Data
    Variabel adalah tempat penyimpanan data yang memiliki tipe tertentu, seperti int, float, atau string. Pemilihan tipe data yang tepat akan mempengaruhi efisiensi memori dan kecepatan program [2].
#### 2. Input dan Output
    C++ menggunakan cin untuk menerima input dari pengguna dan cout untuk menampilkan output ke layar. Objek ini didefinisikan dalam header <iostream> [3].
#### 3. Operator
    Operator digunakan untuk melakukan operasi aritmatika, logika, maupun relasi. Contoh: +, -, *, /, %, &&, ||, ==, dan lain-lain.

### B. IDE Code::Blocks<br/>
Code::Blocks adalah sebuah Integrated Development Environment (IDE) yang digunakan untuk menulis, mengompilasi, dan menjalankan program C++. Menurut Suhartono (2018), Code::Blocks merupakan media pembelajaran pemrograman yang sederhana, interaktif, dan mudah digunakan, sehingga dapat membantu mahasiswa memahami konsep dasar pemrograman secara lebih efektif [1]. Selain itu, Hidayat & Sari (2020) menjelaskan bahwa Code::Blocks mempermudah proses pembelajaran algoritma dan pemrograman karena telah terintegrasi dengan compiler GNU GCC, sehingga mahasiswa dapat langsung mengeksekusi program tanpa harus melakukan konfigurasi manual [2]. Dengan sifatnya yang open source, ringan, serta ramah pengguna, Code::Blocks menjadi IDE yang banyak digunakan di lingkungan pendidikan untuk mendukung pembelajaran pemrograman dasar [1][2].
#### 1. Fungsi IDE
    Code::Blocks menyediakan lingkungan pengembangan terintegrasi untuk menulis dan menjalankan kode dengan mudah.
#### 2. Compiler
    Compiler yang umum digunakan bersama Code::Blocks adalah GNU GCC Compiler. Compiler ini berfungsi menerjemahkan kode C++ ke dalam bahasa mesin.
#### 3. Keunggulan
    Code::Blocks bersifat open source, ringan, dan multiplatform sehingga banyak dipakai di lingkungan pendidikan [1].

## Guided 

### 1. Program Hello World

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```

Guided 1 membahas Pengenalan Struktur Dasar Program C++ dan Cara Menampilkan Output dengan cout.

### 2. Program Input Output

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan sebuah angka: ";
    cin >> angka;
    cout << "Angka yang dimasukkan: " << angka << endl;
    return 0;
}
```

Guided 2 membahas Cara Menggunakan cin untuk Input dan cout untuk Output dalam Program C++.

### 3. Program Operasi Aritmatika

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai;
    cout << "Masukkan nilai: ";
    cin >> nilai;

    if (nilai >= 60) {
        cout << "Lulus" << endl;
    } else {
        cout << "Tidak Lulus" << endl;
    }
    return 0;
}
```

Guided 3 membahas Penggunaan Percabangan if-else untuk Menentukan Keputusan Berdasarkan Kondisi dalam C++.

## Unguided 

### 1. soal Unguided 1

Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian
memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua
bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "Hasil Penjumlahan: " << a + b << endl;
    cout << "Hasil Pengurangan: " << a - b << endl;
    cout << "Hasil Perkalian  : " << a * b << endl;
    if (b != 0) {
        cout << "Hasil Pembagian  : " << a / b << endl;
    } else {
        cout << "Pembagian tidak dapat dilakukan (pembagi = 0)" << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan1_Modul1/Output-Unguided1-Modul1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan1_Modul1/Output-Unguided1-Modul1-2.png)

penjelasan unguided 1 

Program ini membahas tentang operator aritmatika dasar dalam C++ (+, -, *, /) untuk dua buah bilangan bertipe float.

### 2. Soal Unguided 2

Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai
angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat
positif mulai dari 0 s.d 100
contoh: 79: tujuh puluh Sembilan

```C++
#include <iostream>
using namespace std;

string angkaKeTulisan(int n) {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", 
                       "enam", "tujuh", "delapan", "sembilan", "sepuluh", 
                       "sebelas"};
    if (n < 12) return satuan[n];
    else if (n < 20) return satuan[n-10] + " belas";
    else if (n < 100) {
        int puluhan = n / 10;
        int sisa = n % 10;
        string hasil = satuan[puluhan] + " puluh";
        if (sisa > 0) hasil += " " + satuan[sisa];
        return hasil;
    } else if (n == 100) return "seratus";
    return "di luar jangkauan";
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;
    cout << angka << " : " << angkaKeTulisan(angka) << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan1_Modul1/Output-Unguided2-Modul1-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan1_Modul1/Output-Unguided2-Modul1-2.png)

penjelasan unguided 2

Program ini membahas tentang pengolahan kondisi (if-else) untuk mengubah input bilangan bulat menjadi bentuk terbilang bahasa Indonesia.

### 3. soal unguided 3

Buatlah program yang dapat memberikan input dan output sbb.
input: 3
output:
3 2 1 * 1 2 3
  2 1 * 1 2
    1 * 1
      *    

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        // Bagian kiri
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // Tanda *
        cout << "* ";

        // Bagian kanan
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    // Baris terakhir hanya bintang
    cout << "*" << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan1_Modul1/Output-Unguided3-Modul1-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan1_Modul1/Output-Unguided3-Modul1-2.png)

penjelasan unguided 3

Program ini membahas tentang nested loop (perulangan bersarang) untuk mencetak pola angka berbentuk cermin (mirror pattern).

## Kesimpulan
Pada praktikum ini dipelajari dasar penggunaan IDE Code::Blocks serta pemrograman C++ dasar meliputi input-output, operasi aritmatika, struktur percabangan, dan perulangan. Hasil praktikum menunjukkan bahwa pemahaman sintaks dasar C++ sangat penting sebelum mempelajari struktur data maupun algoritma yang lebih kompleks.

## Referensi
[1] Suhartono, Dwi. (2018). "Pengembangan Media Pembelajaran Bahasa Pemrograman C++ dengan Software Code::Blocks." Jurnal Teknologi Informasi dan Pendidikan, 11(2), 45–52.
[2] Hidayat, R., & Sari, D. (2020). "Implementasi Code::Blocks dalam Pembelajaran Algoritma dan Pemrograman Dasar." Jurnal Teknologi dan Sistem Informasi, 6(1), 12–19.
[3] Suryadi, A., & Kurniawan, R. (2019). "Pembelajaran Dasar Bahasa Pemrograman C++ untuk Mahasiswa Informatika." Prosiding Seminar Nasional Teknologi Informasi, Universitas Negeri Semarang.
<br>...
