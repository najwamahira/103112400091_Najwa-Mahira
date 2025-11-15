# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center">Najwa Mahira - 103112400091</p>

## Dasar Teori
Queue berbasis linked list merupakan implementasi antrean yang memanfaatkan node-node dinamis sebagai penyimpan data, di mana setiap node berisi informasi dan pointer menuju node berikutnya. Karena strukturnya dinamis, ukuran queue dapat menyesuaikan kebutuhan tanpa batasan kapasitas awal. Queue ini memiliki dua pointer penting, yaitu head sebagai penanda elemen terdepan yang akan dihapus, dan tail sebagai penanda elemen terakhir tempat elemen baru ditambahkan. Keunggulan utama queue berbasis linked list adalah efisiensinya dalam melakukan operasi enqueue dan dequeue tanpa memerlukan pergeseran elemen seperti pada array. Menurut Wibowo (2020), linked list queue sangat cocok digunakan pada sistem yang membutuhkan pengelolaan data dinamis karena kompleksitas waktu setiap operasi tetap konstan atau O(1) [2].
### A. Queue Berbasis Linked List<br/>
Queue berbasis linked list merupakan implementasi antrean yang memanfaatkan node-node dinamis sebagai penyimpan data, di mana setiap node berisi informasi dan pointer menuju node berikutnya. Karena strukturnya dinamis, ukuran queue dapat menyesuaikan kebutuhan tanpa batasan kapasitas awal. Queue ini memiliki dua pointer penting, yaitu head sebagai penanda elemen terdepan yang akan dihapus, dan tail sebagai penanda elemen terakhir tempat elemen baru ditambahkan. Keunggulan utama queue berbasis linked list adalah efisiensinya dalam melakukan operasi enqueue dan dequeue tanpa memerlukan pergeseran elemen seperti pada array. Menurut Wibowo (2020), linked list queue sangat cocok digunakan pada sistem yang membutuhkan pengelolaan data dinamis karena kompleksitas waktu setiap operasi tetap konstan atau O(1) [2].
#### 1. Struktur Node pada Linked List Queue
Struktur node pada linked list terdiri dari dua bagian, yaitu info sebagai wadah data dan next sebagai pointer yang menghubungkan node tersebut dengan node berikutnya. Dalam queue, struktur ini dihubungkan secara sekuensial sehingga membentuk rantai data mulai dari head hingga tail. Dengan adanya pointer next, struktur ini tidak membutuhkan indeks seperti array, sehingga penyimpanan data dapat dilakukan secara fleksibel di memori. Pointer head menunjuk node pertama yang akan keluar dari antrean, dan pointer tail menunjuk node terakhir yang baru masuk. Struktur seperti ini memungkinkan pemb
#### 2. Operasi Enqueue pada Linked List Queue
Operasi enqueue dilakukan dengan membuat node baru dan menautkannya ke bagian belakang antrean melalui pointer tail. Prosesnya dimulai dengan mengalokasikan node baru, mengisi nilai informasi, serta mengatur pointer next bernilai NULL. Jika queue kosong, maka head dan tail langsung menunjuk node tersebut. Namun, jika sudah terdapat elemen, pointer tail->next diarahkan ke node baru kemudian tail dipindahkan ke node tersebut. Tidak adanya proses pergeseran elemen membuat operasi ini sangat efisien. Kompleksitas waktunya tetap O(1) karena hanya melibatkan perubahan satu pointer tanpa traversal.
#### 3. Operasi Dequeue pada Linked List Queue
Operasi dequeue dilakukan dengan mengambil node pada bagian head. Pointer head dipindahkan ke node berikutnya, sementara node yang dihapus diputuskan keterkaitannya sehingga dapat di-dealokasi. Jika setelah penghapusan head bernilai NULL, maka tail juga disetel menjadi NULL untuk menandakan queue kosong. Operasi ini juga memiliki kompleksitas O(1) karena tidak perlu memindahkan data atau menggeser elemen. Efisiensi dequeue pada linked list menjadikannya sangat ideal untuk aplikasi seperti penjadwalan proses, BFS, dan sistem antrean yang membutuhkan respons cepat.

### B. Queue Berbasis Array<br/>
Queue berbasis array menggunakan struktur tabel berindeks yang kapasitasnya ditentukan sejak awal. Meskipun tidak sefleksibel linked list, representasi array sering dipilih karena implementasinya sederhana dan mudah dipahami. Modul 8 menjelaskan tiga mekanisme pengelolaan head dan tail pada queue array, yaitu Alternatif 1, Alternatif 2, dan Alternatif 3 (Circular Queue). Ketiganya memiliki perbedaan dalam cara menangani pergerakan indeks sehingga mempengaruhi efisiensi operasi. Menurut Sari dan Rahman (2022), representasi circular queue yang memanfaatkan operasi modulo merupakan teknik paling efisien karena menghilangkan kebutuhan shifting dan memaksimalkan penggunaan ruang array [3].
#### 1. Alternatif 1 – Head Tetap, Tail Bergerak
Pada mekanisme ini, head selalu berada pada indeks awal ketika queue tidak kosong, sementara tail bergerak maju setiap kali ada operasi enqueue. Ketika elemen dihapus, elemen setelah head harus digeser ke depan untuk mempertahankan posisi head tetap pada indeks pertama. Meskipun mudah dipahami, mekanisme ini tidak efisien dalam skala besar karena shifting memiliki kompleksitas O(n). Pendekatan ini paling cocok digunakan dalam pembelajaran dasar untuk memahami prinsip FIFO sebelum beralih ke mekanisme yang lebih optimal.
#### 2. Alternatif 2 – Head Bergerak, Tail Bergerak
Mekanisme ini memperbaiki kelemahan Alternatif 1 dengan membiarkan head dan tail bergerak sesuai operasi enqueue dan dequeue. Elemen tidak perlu digeser setiap kali ada penghapusan sehingga lebih efisien. Namun, masalah muncul ketika tail mencapai indeks maksimum sedangkan masih ada ruang kosong di bagian awal array, yang disebut kondisi queue penuh semu. Dalam kondisi tersebut, shifting tetap dibutuhkan sehingga kompleksitas bisa meningkat. Meski begitu, Alternatif 2 lebih efisien dari Alternatif 1 dalam mayoritas kasus.
#### 3. Alternatif 3 – Circular Queue
Circular queue merupakan mekanisme paling efisien karena membuat head dan tail berputar secara melingkar menggunakan operasi modulo. Ketika tail mencapai indeks terakhir, ia dapat kembali ke indeks pertama selama ruang masih tersedia. Tidak adanya shifting membuat operasi enqueue dan dequeue tetap memiliki kompleksitas O(1). Circular queue digunakan secara luas pada sistem buffer data, antrean jaringan, dan antrian streaming karena memanfaatkan array secara penuh serta mempertahankan efisiensi tinggi meskipun proses enqueue–dequeue terjadi secara terus menerus.

## Guided 1

### 1. queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```
Header ini mendefinisikan struktur dan fungsi-fungsi dasar untuk membangun queue berbasis linked list, termasuk deklarasi node, penanda head–tail, serta operasi seperti menambah, menghapus, mengecek, menampilkan, dan mengosongkan queue.

### 2. queue.cpp

```C++
#include "queue.h"
using namespace std;

void createQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```
Kode ini mengimplementasikan seluruh operasi queue berbasis linked list—mulai dari membuat antrean, menambah data di belakang, menghapus data dari depan, menampilkan seluruh isi antrean, hingga mengosongkannya—dengan memanfaatkan pointer head dan tail untuk menjaga alur FIFO.

### 3. main.cpp

```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q; 
    createQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```
Fungsi `main` ini menjalankan seluruh proses antrean dengan menambahkan beberapa nama ke dalam queue, menampilkan isinya, kemudian menghapus beberapa elemen terdepan sesuai konsep FIFO, dan akhirnya membersihkan seluruh antrean sebelum program selesai.

## Guided 2

### 1. queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void createQueue(queue &Q); // terbentuk queue dengan head = -1 dan tail = -1
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```
Header ini mendefinisikan struktur queue berbasis array berukuran tetap beserta fungsi-fungsi untuk membuat queue, mengecek penuh atau kosong, menambah data, menghapus data, dan menampilkan isinya.

### 2. queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```
Kode ini mengatur cara kerja queue berbasis array dengan berbagai model implementasi—mulai dari enqueue, dequeue, mengecek penuh atau kosong, hingga menampilkan isi antrean—serta menyediakan tiga versi perilaku queue (linear head diam, linear head bergerak, dan circular) dengan hanya satu yang diaktifkan sesuai kebutuhan.

### 3. main.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    createQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Program ini membuat sebuah queue berbasis array, menambahkan beberapa nama ke dalamnya, menampilkan isi antrean, kemudian menghapus beberapa elemen terdepan sesuai urutan FIFO, dan akhirnya menampilkan kembali kondisi queue setelah proses penghapusan.

## Unguided 

### 1. queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

### 2. queue.cpp

```C++
#include "queue.h"
using namespace std;

void createQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

### 3. main.cpp

```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q; 
    createQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan8_Modul8/image8/Output-Unguided1-Modul8-1.png)

penjelasan unguided 1 
Program di atas mengimplementasikan struktur data **queue menggunakan linked list**, di mana setiap elemen disimpan dalam node yang berisi nama dan pointer ke node berikutnya. Fungsi `createQueue` menginisialisasi antrean dalam keadaan kosong, sementara `enQueue` menambahkan data baru ke bagian belakang queue dengan membuat node baru dan menghubungkannya ke tail. Sebaliknya, `deQueue` menghapus elemen paling depan (node head) sehingga sesuai konsep FIFO (First In First Out); jika setelah penghapusan antrean menjadi kosong, maka head dan tail diset kembali ke `nullptr`. Fungsi `viewQueue` digunakan untuk menampilkan isi antrean secara berurutan mulai dari head hingga tail, dan `clearQueue` menghapus seluruh isi queue satu per satu. Pada `main`, beberapa nama dimasukkan ke antrean, kemudian sebagian dihapus, sehingga terlihat perubahan isi queue sebelum dan sesudah operasi enQueue serta deQueue dijalankan.

## Kesimpulan
Pada praktikum Modul 8 ini dapat disimpulkan bahwa queue merupakan struktur data linier yang bekerja dengan prinsip FIFO (First In First Out), di mana elemen yang pertama masuk menjadi elemen pertama yang keluar. Queue dapat diimplementasikan menggunakan linked list maupun array, dan masing-masing memiliki karakteristik serta keunggulan yang berbeda. Queue berbasis linked list bersifat dinamis sehingga ukuran antrean dapat menyesuaikan kebutuhan tanpa batasan kapasitas awal, serta mendukung operasi enqueue dan dequeue secara efisien dengan kompleksitas O(1) karena hanya memanipulasi pointer. Sementara itu, queue berbasis array bersifat statis namun lebih sederhana dalam implementasi, dengan tiga pendekatan berbeda—Alternatif 1, Alternatif 2, dan Alternatif 3 (Circular Queue). Alternatif 1 mudah dipahami tetapi kurang efisien karena memerlukan shifting elemen saat penghapusan, sedangkan Alternatif 2 memperbaiki sebagian keterbatasan tersebut dengan menggerakkan head dan tail. Circular Queue sebagai Alternatif 3 menjadi representasi paling efisien karena memanfaatkan seluruh ruang array secara melingkar tanpa perlu pergeseran elemen. Melalui praktikum ini, mahasiswa mampu memahami perbedaan mendasar dari berbagai implementasi queue, kelebihan dan kekurangannya, serta relevansinya dalam kasus nyata seperti sistem buffer, antrian layanan, dan penjadwalan proses. Dengan pemahaman konsep dan implementasi yang benar, queue dapat menjadi struktur data yang sangat efektif dalam pengelolaan data berurutan.

## Referensi
<br>[1] Fikri, M. (2021). Implementasi Struktur Data Queue pada Sistem Antrian Berbasis Komputer. Jurnal Teknik Informatika, Universitas BSI.
<br>[2] Wibowo, A. (2020). Analisis Kinerja Linked List Queue dalam Manajemen Proses. Jurnal Informatika Amikom Yogyakarta.
<br>[3] Sari, D. P., & Rahman, F. (2022). Efisiensi Circular Queue dalam Implementasi Buffer Sistem. Jurnal Teknologi dan Sistem Informasi, Universitas Telkom.
