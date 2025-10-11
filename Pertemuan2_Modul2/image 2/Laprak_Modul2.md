# <h1 align="center">Laporan Praktikum Modul 2 -  PENGENALAN BAHASA C++ (BAGIAN KEDUA)</h1>
<p align="center">Najwa Mahira - 103112400091</p>

## Dasar Teori
Bahasa C++ adalah bahasa pemrograman yang banyak digunakan dalam pembelajaran dasar algoritma karena mendukung pemrograman prosedural sekaligus berorientasi objek. C++ memungkinkan mahasiswa berlatih logika pemrograman melalui materi fundamental seperti array, string, dan fungsi. Pemanfaatan compiler C++ dalam pembelajaran berbasis discovery learning terbukti membantu meningkatkan keterampilan logis dan sistematis mahasiswa [1].

### A. Array<br/>
#### 1. Definisi Array
Array adalah struktur data statis yang menyimpan elemen dengan tipe data sama pada lokasi memori berurutan, dan setiap elemen diakses melalui indeks. Dengan array, data dapat dikelola lebih efisien dibandingkan mendeklarasikan variabel satu per satu [2].
#### 2. Kegunaan Array
Array sering digunakan untuk perhitungan matematis seperti rata-rata, pencarian nilai tertinggi, dan penyimpanan data. Pemanfaatan array dalam aplikasi pembelajaran berbasis C++ terbukti dapat meningkatkan kompetensi kognitif mahasiswa karena memudahkan representasi data yang banyak dan berulang [2].
#### 3. Peran Array dalam Pendidikan
Array merupakan dasar dari struktur data yang lebih kompleks seperti matriks, stack, queue, dan linked list. Oleh karena itu, penguasaan array menjadi pondasi penting bagi mahasiswa dalam mempelajari struktur data lanjutan [2].

### B. Pointer<br/>
#### 1. Definisi Pointer
Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Dengan pointer, programmer dapat mengakses serta memanipulasi data secara langsung melalui alamat memori [1].
#### 2. Kegunaan Pointer
Pointer digunakan untuk pengelolaan memori dinamis, pengaksesan array, hingga membangun struktur data kompleks seperti linked list. Dalam linked list, pointer digunakan untuk menghubungkan antar simpul data sehingga membentuk struktur yang saling terhubung [3].
#### 3. Peran Pointer dalam PendidikanPeran Pointer dalam Pendidikan
Pemahaman tentang pointer membantu mahasiswa memahami bagaimana komputer bekerja dengan memori. Hal ini melatih logika pemrograman dan keterampilan problem solving karena mahasiswa belajar menghubungkan antara data, alamat, dan cara pemanggilannya [3].

### C. Fungsi<br/>
#### 1. Definisi Fungsi
Fungsi adalah blok kode program yang dapat dipanggil untuk melakukan tugas tertentu. Dalam C++, fungsi dapat berupa fungsi pustaka yang sudah tersedia maupun fungsi buatan pengguna (user-defined function) [1].
#### 2. Kegunaan Fungsi
Fungsi menjadikan program lebih modular, mudah dibaca, dan efisien karena memungkinkan penggunaan kembali kode (code reusability). Dengan fungsi, perintah yang sama tidak perlu ditulis berulang-ulang [2].
#### 3. Peran Fungsi dalam Pendidikan
Menurut penelitian, fungsi membantu mahasiswa membagi permasalahan besar menjadi bagian kecil sehingga lebih mudah dipecahkan. Hal ini melatih keterampilan berpikir sistematis dan mendukung pembelajaran berbasis problem solving [3].

## Guided 

### 1. Array

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i < 5; i++){
        cout << "masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }

    int j = 0;
    while(j < 5){
        cout << "isi indekss ke-" << j << " ; " << arr[j] << endl;
        j++;
    }

    return 0;
}
```
penjelasan singkat guided 1

Program Guided 1 ini digunakan untuk menginput dan menampilkan isi array berukuran 5 elemen menggunakan perulangan for saat input dan while saat output.

### 2. Array 2 Dimensi

```C++
#include<iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    //perkalian matriks 2x2
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
penjelasan singkat guided 2

Program Guided 2 ini melakukan operasi penjumlahan dan perkalian pada dua matriks 2x2, lalu menampilkan hasilnya menggunakan fungsi `tampilkanHasil()`.

### 3. Pointer

```C++
#include<iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 20, b = 30;
    int  *ptr;

    ptr = &a;

    cout << "value of a : " << a  << endl;
    cout << "addres of a : " << &a  << endl;
    cout << "value stored in ptr (addres of a) : " << ptr  << endl;
    cout << "value pointed to by ptr : " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a=" << a << "and b=" << b << endl;

    return 0;
}
```
penjelasan singkat guided 3

Program Guided 3 ini menjelaskan penggunaan pointer untuk mengakses alamat dan nilai variabel, serta menggunakan fungsi `tukar()` untuk menukar nilai dua variabel melalui pointer.

### 4. Function

```C++
#include<iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmetika(int arr[], int ukuran){
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "total penjumalahan : " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++){
        totalKali =  arr[i];
    }
    cout << "Total perkalian : " << totalKali << endl
    ;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmetika(arr, ukuran);
    return 0;
}
```
penjelasan singkat guided 4

Program Guided 4 ini digunakan untuk mencari nilai maksimum dalam array serta menghitung total penjumlahan dan perkalian elemen array menggunakan fungsi dan prosedur.


### 5. Procedur

```C++
#include<iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a : " << a  << endl;
    cout << "alamat a (&a) : " << &a  << endl;
    cout << "Nilai ref (alias a) : " << ref  << endl;
    cout << "Almat ref (&ref) : " << &ref << endl;

    //menukar nilai a lewat reference
    ref = 50;
    cout << "\nsetelah ref = 50;" << a  << endl;
    cout << "Nilai a : " << a  << endl;
    cout << "Nilai ref : " << ref  << endl;
    

    tukar(a, b);
    cout << "After swapping, value of a=" << a << "and b=" << b << endl;

    return 0;
}
```
penjelasan singkat guided 5

Program Guided 5 ini menunjukkan penggunaan reference sebagai alias variabel serta fungsi `tukar()` untuk menukar nilai dua variabel menggunakan parameter reference.

## Unguided 

### 1. soal Unguided 1

Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan
perkalian matriks 3x3

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];
    int i, j;

    cout << "Masukkan elemen matriks A (3x3):\n";
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cin >> A[i][j];

    cout << "\nMasukkan elemen matriks B (3x3):\n";
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cin >> B[i][j];

    cout << "\nHasil Penjumlahan Matriks (A + B):\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan Matriks (A - B):\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian Matriks (A * B):\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++)
                C[i][j] += A[i][k] * B[k][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```
penjelasan unguided 1

Program ini melakukan operasi penjumlahan, pengurangan, dan perkalian pada dua matriks 3x3 menggunakan perulangan bersarang.

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/najwamahira/103112400091_Najwa-Mahira./blob/main/Pertemuan2_Modul2/image2/Output-Unguided1-Modul2-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/najwamahira/103112400091_Najwa-Mahira./blob/main/Pertemuan2_Modul2/image2/Output-Unguided1-Modul2-2.png)

penjelasan unguided 1 

Program ini melakukan operasi penjumlahan, pengurangan, dan perkalian pada dua matriks 3x3 menggunakan perulangan bersarang.

### 2. Soal Unguided 2

Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat
menukar nilai dari 3 variabel

```C++
#include <iostream>
using namespace std;

// Fungsi tukar 3 variabel pakai pointer
void tukar3Pointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

// Fungsi tukar 3 variabel pakai reference
void tukar3Reference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "=== Sebelum swap ===" << endl;
    cout << "a=" << a << " b=" << b << " c=" << c << endl;

    // Swap menggunakan pointer
    tukar3Pointer(&a, &b, &c);
    cout << "\n=== Setelah swap pakai pointer ===" << endl;
    cout << "a=" << a << " b=" << b << " c=" << c << endl;

    // Swap menggunakan reference
    tukar3Reference(a, b, c);
    cout << "\n=== Setelah swap pakai reference ===" << endl;
    cout << "a=" << a << " b=" << b << " c=" << c << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/najwamahira/103112400091_Najwa-Mahira./blob/main/Pertemuan2_Modul2/image2/Output-Unguided2-Modul2-1.png)

penjelasan unguided 2

Pointer adalah variabel yang menyimpan alamat memori variabel lain sehingga nilainya dapat diubah melalui dereference, sedangkan reference adalah alias dari variabel asli yang memungkinkan nilai variabel diubah langsung tanpa dereference, keduanya dapat digunakan untuk menukar nilai variabel, dengan pointer lebih fleksibel dan reference lebih aman.

### 3. Soal Unguided 3

Diketahui sebuah array 1 dimensi sebagai berikut :
arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari
array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan
function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur
hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan
menu switch-case seperti berikut ini :
--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata

```C++
#include <iostream>
using namespace std;

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maks)
            maks = arr[i];
    return maks;
}

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

void hitungRataRata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    cout << "Nilai rata-rata: " << total / n << endl;
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < 10; i++) cout << arrA[i] << " ";
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, 10) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, 10) << endl;
                break;
            case 4:
                hitungRataRata(arrA, 10);
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira./blob/main/Pertemuan2_Modul2/image2/Output-Unguided3-Modul2-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/najwamahira/103112400091_Najwa-Mahira./blob/main/Pertemuan2_Modul2/image2/Output-Unguided3-Modul2-2.png)

penjelasan unguided 3

Program ini menampilkan isi array serta mencari nilai maksimum, minimum, dan rata-rata menggunakan fungsi dan menu switch-case.

## Kesimpulan
Praktikum Modul 2 membahas dasar-dasar pengelolaan data menggunakan array, pointer, dan fungsi dalam C++. Penggunaan array mempermudah pengelolaan data sejenis, pointer memberikan kontrol langsung atas memori, dan fungsi meningkatkan modularitas serta keterbacaan program. Pemahaman ketiga konsep ini sangat penting untuk membangun program C++ yang efisien dan terstruktur.

## Referensi
[1] Mita Anda Rista, Bambang Sujatmiko. (2022). Pemanfaatan Compiler C++ Online dalam Pengembangan Aplikasi Berbasis Web untuk Mengukur Pengaruh Pembelajaran Discovery Learning. IT-Edu: Jurnal Information Technology and Education, Universitas Negeri Surabaya.
[2] Ilmi Ramadhana, Bambang Sujatmiko. (2018). Pengembangan Aplikasi Kamus Bahasa Pemrograman C++ Berbasis Android untuk Meningkatkan Kompetensi Kognitif Mata Kuliah Struktur Data. IT-Edu: Jurnal Information Technology and Education, Universitas Negeri Surabaya.
[3] Sugiyo, Fajar Septian. (2021). Model Pembelajaran Pemrograman Bahasa C++ untuk Tunanetra dengan Metode Problem Based Learning. Jurnal Maklumatika, Universitas Muhammadiyah Purwokerto.
<br>...
