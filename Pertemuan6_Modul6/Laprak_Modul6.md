# <h1 align="center">Laporan Praktikum Modul 6 -  DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Najwa Mahira - 1031112400091</p>

## Dasar Teori
Struktur data merupakan komponen utama dalam pengolahan data komputer yang berfungsi untuk menyimpan, mengatur, dan mengelola data secara efisien. Salah satu bentuk struktur data dinamis yang banyak digunakan adalah linked list, yaitu kumpulan node atau simpul yang saling terhubung melalui pointer. Setiap node menyimpan data dan penunjuk (alamat memori) ke node lain dalam urutan tertentu, sehingga memudahkan operasi penyisipan dan penghapusan data tanpa perlu menggeser elemen seperti pada array[1].
### A. Konsep Dasar Doubly Linked Lis<br/>
Doubly linked list adalah pengembangan dari singly linked list yang memungkinkan setiap node memiliki dua pointer, yaitu next (menuju node berikutnya) dan prev (menuju node sebelumnya). Dengan adanya dua arah hubungan ini, struktur data dapat ditelusuri dari depan ke belakang maupun sebaliknya dengan lebih fleksibel[2]. Dalam implementasi C++, doubly linked list didefinisikan menggunakan tipe data struct yang berisi tiga komponen utama: informasi data (info), pointer next, dan pointer prev.

Struktur list juga biasanya menyertakan dua pointer utama, yaitu first yang menunjuk ke node pertama dan last yang menunjuk ke node terakhir. Pada saat list baru dibuat, kedua pointer tersebut bernilai NULL karena belum ada elemen di dalamnya. Ketika node baru ditambahkan melalui operasi seperti insertFirst() atau insertLast(), pointer-pointer tersebut akan diperbarui agar hubungan antar node tetap terjaga dengan baik[3].
#### 1. Kelebihan Doubly Linked List
Kelebihan utama doubly linked list adalah kemampuannya untuk melakukan penelusuran data dua arah sehingga memudahkan operasi pencarian, penyisipan, maupun penghapusan elemen dari dua sisi list. Selain itu, struktur ini sangat efisien digunakan pada aplikasi yang memerlukan navigasi dua arah seperti sistem undo–redo, playlist musik, dan browser history[4].
#### 2.Kekurangan Doubly Linked List
Meskipun efisien dari sisi fleksibilitas, doubly linked list membutuhkan ruang memori lebih besar karena setiap node menyimpan dua pointer. Kesalahan dalam mengatur pointer juga dapat menimbulkan masalah seperti memory leak atau kesalahan akses memori. Oleh karena itu, pengelolaan pointer harus dilakukan secara hati-hati untuk menjaga stabilitas program[5].
#### 3. Perbandingan dengan Singly Linked List
Perbedaan utama antara singly dan doubly linked list terletak pada arah hubungan antar node. Pada singly linked list, pointer hanya mengarah ke elemen berikutnya, sedangkan pada doubly linked list, pointer mengarah ke dua arah (prev dan next). Dengan demikian, doubly linked list lebih unggul dalam hal navigasi data, meskipun membutuhkan memori lebih besar[2].

### B. Operasi pada Doubly Linked List<br/>
Operasi utama pada doubly linked list terdiri dari penyisipan (insert), penghapusan (delete), pencarian (search), dan penelusuran (traversal). Setiap operasi ini melibatkan pengaturan pointer antar node agar hubungan dua arah tetap konsisten.
#### 1. Insert (Penyisipan Data)
Operasi penyisipan digunakan untuk menambahkan node baru ke dalam list. Penyisipan dapat dilakukan di awal list (insert first), di akhir list (insert last), atau setelah node tertentu (insert after). Ketika node baru dimasukkan, pointer prev dan next perlu diperbarui agar node baru terhubung dengan benar pada posisi yang diinginkan. Fungsi insertFirst() dan insertLast() pada C++ digunakan untuk mengimplementasikan operasi ini secara efisien[3].
#### 2. Delete (Penghapusan Data)
Operasi penghapusan digunakan untuk menghapus node dari list, baik di awal, akhir, maupun di tengah. Setelah node dihapus, pointer next dan prev dari node di sekitarnya diperbarui agar tetap terhubung. Selain itu, memori yang digunakan node harus dilepaskan kembali menggunakan fungsi dealokasi() agar tidak terjadi memory leak[4].
#### 3. Searching, Viewing, dan Update
Operasi search dilakukan dengan menelusuri list untuk menemukan node dengan data tertentu. Proses viewing digunakan untuk menampilkan seluruh isi list, sementara update berfungsi mengubah data pada node tertentu tanpa mengubah strukturnya. Traversal dapat dilakukan dari first ke last maupun sebaliknya, menjadikan doubly linked list lebih fleksibel dibanding singly linked list[5].

## Guided 1

### 1. ListMakanan.h

```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```
Pada Guided 1, file listmakanan.h berisi deklarasi struktur data dan fungsi untuk membangun doubly linked list yang menyimpan data makanan. Struct makanan digunakan untuk menyimpan atribut seperti nama, jenis, harga, dan rating. Struct node merepresentasikan setiap elemen dalam list yang memiliki pointer next dan prev, sehingga data bisa ditelusuri dua arah.

Struct linkedlist menyimpan dua pointer penting, yaitu first dan last, untuk menandai elemen pertama dan terakhir dalam list. File ini juga mendeklarasikan berbagai fungsi seperti createList untuk inisialisasi, alokasi dan dealokasi untuk pengaturan memori, serta insert dan update untuk menambah atau memperbarui data.

Secara keseluruhan, Guided 1 ini membuat kerangka awal dari doubly linked list yang modular dan memudahkan proses implementasi pada file berikutnya.

### 2. ListMakanan.cpp

```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
Pada Guided 1, program berisi implementasi dari fungsi-fungsi yang dideklarasikan di listMakanan.h. Fungsi isEmpty dan createList digunakan untuk memeriksa serta menginisialisasi list. Fungsi alokasi membuat node baru berisi data makanan, sedangkan dealokasi menghapus node dari memori.

Fungsi insertFirst, insertLast, insertAfter, dan insertBefore menambahkan data ke posisi tertentu dalam list dengan mengatur pointer next dan prev. Fungsi printList menampilkan seluruh isi list, sedangkan updateFirst, updateLast, updateAfter, dan updateBefore memperbarui data berdasarkan posisi node.

Secara keseluruhan, Guided 1 menjelaskan cara kerja doubly linked list dalam menambah, menampilkan, dan memperbarui data secara dua arah.

### 3. main.cpp

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
} 
```
Program ini membuat sebuah linked list yang berisi data makanan, mulai dari inisialisasi list kosong dan pembuatan beberapa node yang masing-masing menyimpan informasi tentang nama makanan, jenis, harga, dan rating. Setelah itu, node-node tersebut dimasukkan ke dalam list dengan posisi yang berbeda-beda, seperti di awal, di akhir, sebelum atau setelah node tertentu. Program kemudian menampilkan isi list untuk melihat urutan dan data node-node yang telah dimasukkan. Selanjutnya, program melakukan pembaruan data pada beberapa node, termasuk node pertama, node terakhir, node sebelum tertentu, dan node setelah tertentu, sehingga informasi pada node-node tersebut bisa diubah sesuai kebutuhan. Terakhir, program menampilkan kembali isi list setelah dilakukan update untuk memastikan perubahan telah diterapkan.

## Guided 2

### 1. ListMakanan.h

```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```
File header `listMakanan.h` ini digunakan untuk mendefinisikan struktur data dan fungsi-fungsi yang dibutuhkan untuk mengelola linked list yang menyimpan data makanan. Di dalamnya terdapat definisi struct `makanan` yang menyimpan informasi seperti nama, jenis, harga, dan rating makanan, serta typedef `dataMakanan` untuk mempermudah penggunaan data tersebut di node. Setiap node didefinisikan dalam struct `node` yang memiliki pointer `next` dan `prev`, sehingga list ini merupakan **doubly linked list**, dan struct `linkedlist` yang menyimpan pointer ke node pertama (`first`) dan terakhir (`last`). Header ini juga mendeklarasikan berbagai fungsi, mulai dari operasi dasar seperti `isEmpty`, `createList`, `alokasi`, dan `dealokasi`, hingga operasi insert (`insertFirst`, `insertLast`, `insertAfter`, `insertBefore`), update (`updateFirst`, `updateLast`, `updateAfter`, `updateBefore`), pencarian (`findByName`, `findByJenis`, `findByMinRating`), serta penghapusan node (`deleteFirst`, `deleteLast`, `deleteAfter`, `deleteBefore`, `deleteNode`, `deleteByName`). Semua fungsi ini memungkinkan program untuk membuat, menampilkan, mengubah, mencari, dan menghapus node dalam linked list dengan mudah dan terstruktur.

### 2. ListMakanan.cpp

```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```
Program ini mengimplementasikan doubly linked list untuk menyimpan data makanan, termasuk nama, jenis, harga, dan rating. Fungsi-fungsinya memungkinkan untuk memeriksa list kosong, membuat list baru, menambahkan node di awal, akhir, sebelum, atau setelah node tertentu, menampilkan seluruh list, mengubah data node tertentu, mencari node berdasarkan nama, jenis, atau rating, serta menghapus node dari berbagai posisi. Setiap operasi memastikan pointer `next` dan `prev` diatur dengan benar dan node yang dihapus dibebaskan dari memori.

### 3. main.cpp

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```
Program ini membuat linked list yang menyimpan data makanan, lalu menambahkan lima node dengan posisi berbeda sehingga membentuk urutan `D - A - C - E - B`. Setelah itu, program menampilkan list, melakukan update pada beberapa node (node pertama, terakhir, sebelum C, dan setelah A), kemudian menampilkan list yang sudah diperbarui. Selanjutnya, program mencoba mencari node dengan nama "Nasgor", menghapus node tersebut jika ditemukan, menghapus node pertama, serta menghapus node sebelum `nodeE`. Terakhir, program menampilkan list setelah beberapa operasi penghapusan untuk melihat perubahan isi list.

## Unguided 1

### 1. Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using std::string;

struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef Kendaraan infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address prev;
    address next;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void printInfo(const List &L);
void insertFirst(List &L, address P);
address findElm(const List &L, const string &nopol);

#endif // DOUBLYLIST_H
```

File header `DOUBLYLIST_H` digunakan untuk mendefinisikan struktur data dan fungsi-fungsi dasar pada **doubly linked list** yang menyimpan informasi kendaraan. Struktur `Kendaraan` menyimpan data kendaraan berupa nomor polisi (`nopol`), warna, dan tahun pembuatan (`thnBuat`), dengan alias `infotype` untuk mempermudah penggunaan dalam node. Setiap node didefinisikan dalam struct `ElmList` yang memiliki pointer `prev` dan `next` sehingga membentuk **doubly linked list**, dan struct `List` menyimpan pointer ke node pertama (`first`) dan terakhir (`last`). Header ini juga mendeklarasikan fungsi-fungsi utama seperti `CreateList` untuk membuat list kosong, `alokasi` untuk membuat node baru, `dealokasi` untuk membebaskan memori node, `printInfo` untuk menampilkan seluruh isi list, `insertFirst` untuk menambahkan node di awal list, dan `findElm` untuk mencari node berdasarkan nomor polisi. Fungsi-fungsi ini memungkinkan pengelolaan list kendaraan secara dinamis dengan operasi dasar insert, print, pencarian, dan penghapusan memori. 

### 2. Doublylist.cpp

```C++
#include <iostream>
#include "Doublylist.h"
using std::cout;

void CreateList(List &L) { L.first = nullptr; L.last = nullptr; }

address alokasi(const infotype &x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) { delete P; P = nullptr; }

void printInfo(const List &L) {
    cout << "\nDATA LIST 1\n\n";
    address P = L.first;
    if (!P) { cout << "List kosong\n"; return; }
    while (P) {
        cout << "Nomer Polisi : " << P->info.nopol << "\n";
        cout << "Warna        : " << P->info.warna << "\n";
        cout << "Tahun        : " << P->info.thnBuat << "\n\n";
        P = P->next;
    }
}

void insertFirst(List &L, address P) {
    if (!L.first) { L.first = P; L.last = P; }
    else { P->next = L.first; L.first->prev = P; L.first = P; }
}

address findElm(const List &L, const string &nopol) {
    address P = L.first;
    while (P) { if (P->info.nopol == nopol) return P; P = P->next; }
    return nullptr;
}
```

Kode ini mengimplementasikan fungsi-fungsi dasar untuk **doubly linked list** yang menyimpan data kendaraan. Fungsi `CreateList` digunakan untuk menginisialisasi list kosong dengan menyetel pointer `first` dan `last` menjadi `nullptr`. Fungsi `alokasi` membuat node baru di memori, mengisi data kendaraan, dan mengatur pointer `next` dan `prev` menjadi `nullptr`, sedangkan `dealokasi` membebaskan memori node. Fungsi `printInfo` menampilkan seluruh isi list mulai dari node pertama, menampilkan nomor polisi, warna, dan tahun pembuatan setiap kendaraan, atau memberi pesan jika list kosong. Fungsi `insertFirst` menambahkan node baru di awal list dan mengatur pointer `prev` dan `next` agar list tetap terhubung dengan benar. Terakhir, fungsi `findElm` mencari node berdasarkan nomor polisi dan mengembalikan alamat node jika ditemukan, atau `nullptr` jika tidak ditemukan. Secara keseluruhan, kode ini memungkinkan pembuatan, penambahan, pencarian, penampilan, dan penghapusan memori node pada doubly linked list secara aman.

### 3. main.cpp

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan6_Modul6/image6/Output-Unguided1-Modul6-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan6_Modul6/image6/Output-Unguided1-Modul6-2.png)

Program ini membuat sebuah **doubly linked list** untuk menyimpan data kendaraan, termasuk nomor polisi, warna, dan tahun pembuatan. Pertama, list diinisialisasi kosong menggunakan fungsi `CreateList`. Kemudian program meminta pengguna untuk memasukkan data empat kendaraan. Sebelum menambahkan kendaraan baru ke list, program mengecek apakah nomor polisi sudah ada menggunakan fungsi `findElm`; jika sudah ada, program menampilkan pesan dan melewatkan input tersebut. Jika nomor polisi belum ada, data kendaraan dimasukkan ke list di posisi awal menggunakan `insertFirst` dan dialokasikan memori baru dengan `alokasi`. Setelah semua input selesai, fungsi `printInfo` menampilkan seluruh isi list, termasuk nomor polisi, warna, dan tahun setiap kendaraan, sehingga pengguna dapat melihat daftar kendaraan yang tersimpan.

## Unguided 2

### 1. Doublylist2.h

```C++
#ifndef DOUBLYLIST2_H
#define DOUBLYLIST2_H

#include <string>
using std::string;

struct Kendaraan { string nopol; string warna; int thnBuat; };
typedef Kendaraan infotype;
struct ElmList; typedef ElmList* address;
struct ElmList { infotype info; address prev; address next; };
struct List { address first; address last; };

void CreateList(List &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(const List &L);
address findElm(const List &L, const string &nopol);

#endif // DOUBLYLIST2_H
```

File header `DOUBLYLIST2_H` digunakan untuk mendefinisikan struktur data dan fungsi dasar pada **doubly linked list** yang menyimpan informasi kendaraan. Struktur `Kendaraan` menyimpan data berupa nomor polisi (`nopol`), warna, dan tahun pembuatan (`thnBuat`), dengan alias `infotype` agar lebih mudah digunakan pada node. Setiap node didefinisikan dalam struct `ElmList` yang memiliki pointer `prev` dan `next` untuk membentuk **doubly linked list**, dan struct `List` menyimpan pointer ke node pertama (`first`) dan terakhir (`last`). Header ini juga mendeklarasikan fungsi-fungsi utama seperti `CreateList` untuk membuat list kosong, `alokasi` untuk membuat node baru di memori, `dealokasi` untuk membebaskan memori node, `insertLast` untuk menambahkan node di akhir list, `printInfo` untuk menampilkan seluruh isi list, dan `findElm` untuk mencari node berdasarkan nomor polisi. Fungsi-fungsi ini memungkinkan pengelolaan data kendaraan secara dinamis, termasuk penambahan, pencarian, penampilan, dan penghapusan node.

### 2. Doublylist2.cpp

```C++
#include <iostream>
#include "Doublylist2.h"
using std::cout;

void CreateList(List &L){L.first=nullptr;L.last=nullptr;}
address alokasi(const infotype &x){address P=new ElmList;P->info=x;P->next=nullptr;P->prev=nullptr;return P;}
void dealokasi(address &P){delete P;P=nullptr;}

void insertLast(List &L,address P){
    if(!L.first){L.first=P;L.last=P;}
    else{L.last->next=P;P->prev=L.last;L.last=P;}
}

void printInfo(const List &L){
    cout<<"\nDATA LIST 1\n\n";
    address P=L.first;
    while(P){cout<<"Nomer Polisi : "<<P->info.nopol<<"\n";cout<<"Warna        : "<<P->info.warna<<"\n";cout<<"Tahun        : "<<P->info.thnBuat<<"\n\n";P=P->next;}
}

address findElm(const List &L,const string &nopol){address P=L.first;while(P){if(P->info.nopol==nopol)return P;P=P->next;}return nullptr;}
```
### Output Unguided 2 :

Kode ini mengimplementasikan fungsi-fungsi dasar untuk doubly linked list yang menyimpan data kendaraan. Fungsi `CreateList` digunakan untuk menginisialisasi list kosong dengan menyetel pointer `first` dan `last` menjadi `nullptr`. Fungsi `alokasi` membuat node baru di memori, mengisi data kendaraan, dan mengatur pointer `next` dan `prev` menjadi `nullptr`, sedangkan `dealokasi` membebaskan memori node. Fungsi `insertLast` menambahkan node baru di akhir list dan mengatur pointer `next` dan `prev` agar node tetap terhubung dengan benar. Fungsi `printInfo` menampilkan seluruh isi list mulai dari node pertama hingga terakhir, mencetak nomor polisi, warna, dan tahun kendaraan. Terakhir, fungsi `findElm` mencari node berdasarkan nomor polisi dan mengembalikan alamat node jika ditemukan atau `nullptr` jika tidak ada. Secara keseluruhan, kode ini memungkinkan pembuatan, penambahan, pencarian, penampilan, dan penghapusan node dalam doubly linked list secara aman.

### 3. main2.cpp

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan6_Modul6/image6/Output-Unguided2-Modul6-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan6_Modul6/image6/Output-Unguided2-Modul6-2.png)

Program ini membuat sebuah **doubly linked list** untuk menyimpan data kendaraan, termasuk nomor polisi, warna, dan tahun pembuatan. Pertama, list diinisialisasi kosong menggunakan fungsi `CreateList`. Kemudian program menambahkan tiga node kendaraan ke list di posisi akhir menggunakan `insertLast`, sehingga membentuk urutan list dengan data awal. Fungsi `printInfo` digunakan untuk menampilkan seluruh isi list, termasuk nomor polisi, warna, dan tahun setiap kendaraan. Setelah itu, program meminta pengguna memasukkan nomor polisi yang ingin dicari, kemudian menggunakan `findElm` untuk mencari node yang sesuai. Jika node ditemukan, data kendaraan ditampilkan; jika tidak, program memberi pesan bahwa data tidak ditemukan. Dengan demikian, program ini menunjukkan operasi dasar pada doubly linked list: penambahan node, pencarian, dan penampilan data.

## Unguided 3

### 1. Doublylist3.h

```C++
#ifndef DOUBLYLIST3_H
#define DOUBLYLIST3_H

#include <string>
using std::string;

struct Kendaraan{ string nopol; string warna; int thnBuat; };
typedef Kendaraan infotype;
struct ElmList; typedef ElmList* address;
struct ElmList{ infotype info; address prev; address next; };
struct List{ address first; address last; };

void CreateList(List &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void insertLast(List &L,address P);
void printInfo(const List &L);
address findElm(const List &L,const string &nopol);
void deleteFirst(List &L,address &P);
void deleteLast(List &L,address &P);
void deleteAfter(List &L,address Prec,address &P);

#endif // DOUBLYLIST3_H
```

File header `DOUBLYLIST3_H` digunakan untuk mendefinisikan struktur data dan fungsi-fungsi dasar pada **doubly linked list** yang menyimpan informasi kendaraan. Struktur `Kendaraan` menyimpan data berupa nomor polisi (`nopol`), warna, dan tahun pembuatan (`thnBuat`), dengan alias `infotype` agar lebih mudah digunakan di node. Setiap node didefinisikan dalam struct `ElmList` yang memiliki pointer `prev` dan `next` untuk membentuk **doubly linked list**, dan struct `List` menyimpan pointer ke node pertama (`first`) dan terakhir (`last`). Header ini mendeklarasikan fungsi-fungsi utama seperti `CreateList` untuk membuat list kosong, `alokasi` untuk membuat node baru di memori, `dealokasi` untuk membebaskan memori node, `insertLast` untuk menambahkan node di akhir list, `printInfo` untuk menampilkan seluruh isi list, dan `findElm` untuk mencari node berdasarkan nomor polisi. Selain itu, terdapat fungsi penghapusan node seperti `deleteFirst`, `deleteLast`, dan `deleteAfter` yang memungkinkan pengguna menghapus node dari berbagai posisi dalam list. Secara keseluruhan, header ini menyediakan semua operasi dasar yang diperlukan untuk membuat, menampilkan, mencari, menambahkan, dan menghapus node pada doubly linked list kendaraan.

### 2. Doublylist2.cpp

```C++
#include <iostream>
#include "Doublylist3.h"
using std::cout;

void CreateList(List &L){L.first=nullptr;L.last=nullptr;}
address alokasi(const infotype &x){address P=new ElmList;P->info=x;P->next=nullptr;P->prev=nullptr;return P;}
void dealokasi(address &P){delete P;P=nullptr;}

void insertLast(List &L,address P){
    if(!L.first){L.first=P;L.last=P;}
    else{L.last->next=P;P->prev=L.last;L.last=P;}
}

void printInfo(const List &L){
    cout<<"\nDATA LIST 1\n\n";
    address P=L.first;
    while(P){cout<<"Nomer Polisi : "<<P->info.nopol<<"\n";cout<<"Warna        : "<<P->info.warna<<"\n";cout<<"Tahun        : "<<P->info.thnBuat<<"\n\n";P=P->next;}
}

address findElm(const List &L,const string &nopol){address P=L.first;while(P){if(P->info.nopol==nopol) return P;P=P->next;}return nullptr;}

void deleteFirst(List &L,address &P){
    if(!L.first){P=nullptr;return;}
    P = L.first;
    if(L.first==L.last){L.first=L.last=nullptr;}
    else { L.first = P->next; L.first->prev = nullptr; P->next = nullptr; }
}

void deleteLast(List &L,address &P){
    if(!L.last){P=nullptr;return;}
    P = L.last;
    if(L.first==L.last){L.first=L.last=nullptr;}
    else { L.last = P->prev; L.last->next = nullptr; P->prev = nullptr; }
}

void deleteAfter(List &L,address Prec,address &P){
    if(!Prec){P=nullptr;return;}
    P = Prec->next;
    if(!P) return;
    address R = P->next;
    Prec->next = R;
    if(R) R->prev = Prec;
    else L.last = Prec;
    P->next = nullptr; P->prev = nullptr;
}
```

Kode ini mengimplementasikan fungsi-fungsi dasar untuk **doubly linked list** yang menyimpan data kendaraan, termasuk nomor polisi, warna, dan tahun pembuatan. Fungsi `CreateList` digunakan untuk menginisialisasi list kosong dengan menyetel pointer `first` dan `last` menjadi `nullptr`. Fungsi `alokasi` membuat node baru di memori, mengisi data kendaraan, dan mengatur pointer `next` dan `prev` menjadi `nullptr`, sedangkan `dealokasi` membebaskan memori node. Fungsi `insertLast` menambahkan node di akhir list dan memastikan pointer `next` dan `prev` tetap terhubung dengan benar. Fungsi `printInfo` menampilkan seluruh isi list mulai dari node pertama hingga terakhir, mencetak nomor polisi, warna, dan tahun kendaraan. Fungsi `findElm` digunakan untuk mencari node berdasarkan nomor polisi dan mengembalikan alamat node jika ditemukan, atau `nullptr` jika tidak ada. Selain itu, terdapat fungsi penghapusan node seperti `deleteFirst`, `deleteLast`, dan `deleteAfter`, yang memungkinkan pengguna menghapus node dari awal list, akhir list, atau setelah node tertentu, sambil menjaga pointer `next` dan `prev` tetap konsisten. Secara keseluruhan, kode ini menyediakan semua operasi dasar untuk membuat, menambahkan, menampilkan, mencari, dan menghapus node pada doubly linked list kendaraan secara aman.

### 3. main3.cpp

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan6_Modul6/image6/Output-Unguided3-Modul6-1.png)

Program ini membuat sebuah **doubly linked list** untuk menyimpan data kendaraan, termasuk nomor polisi, warna, dan tahun pembuatan. Pertama, list diinisialisasi kosong menggunakan `CreateList`, kemudian tiga node kendaraan dimasukkan ke list di posisi akhir menggunakan `insertLast` sehingga membentuk urutan data awal. Fungsi `printInfo` digunakan untuk menampilkan seluruh isi list. Selanjutnya, program mencari node dengan nomor polisi "D003" menggunakan `findElm`. Jika node ditemukan, program akan menghapusnya sesuai posisinya: jika node adalah node pertama, menggunakan `deleteFirst`; jika node terakhir, menggunakan `deleteLast`; jika node di tengah, menggunakan `deleteAfter` dengan pointer node sebelumnya. Setelah node dihapus, memori node dibebaskan dengan `dealokasi`. Terakhir, program menampilkan kembali isi list setelah penghapusan, sehingga terlihat perubahan urutan list. Program ini menunjukkan operasi dasar doubly linked list: penambahan node, pencarian, penghapusan node dari berbagai posisi, dan penampilan data.

## Kesimpulan
Dari praktikum Modul 6 mengenai Doubly Linked List (Bagian Pertama) dapat disimpulkan bahwa doubly linked list merupakan salah satu struktur data dinamis yang memiliki kemampuan untuk menyimpan dan menghubungkan data secara dua arah melalui pointer prev dan next. Struktur ini memudahkan proses pengaksesan data baik dari awal maupun dari akhir list, sehingga operasi seperti penyisipan (insert), penghapusan (delete), pencarian (search), maupun pembaruan (update) dapat dilakukan dengan lebih efisien dibandingkan dengan singly linked list.

Selain itu, implementasi doubly linked list dalam bahasa pemrograman C++ menuntut pemahaman yang baik terhadap pengelolaan pointer, alokasi, dan dealokasi memori agar tidak terjadi kesalahan seperti memory leak. Melalui praktikum ini, mahasiswa dapat memahami cara kerja dan penerapan fungsi-fungsi penting seperti insertFirst, insertLast, deleteFirst, deleteLast, serta findElm, yang semuanya berperan dalam manipulasi data pada struktur list.

Dengan demikian, praktikum ini memberikan pemahaman mendalam tentang pentingnya penguasaan struktur data dinamis, khususnya doubly linked list, dalam pengembangan program yang memerlukan navigasi data dua arah, seperti sistem browser history, media playlist, serta fitur undo–redo pada berbagai aplikasi komputer.
## Referensi
<br>[1] Rahmadani, D., & Fitri, Y. (2020). Analisis Struktur Data Linked List dalam Pengelolaan Data Dinamis Menggunakan Bahasa C++. Jurnal KomtekInfo, 7(2), 45–52. [Tersedia di: Garuda Ristekdikti]
<br>[2] Wibowo, A., & Setiawan, A. (2022). Implementasi Struktur Data Linked List Ganda pada Sistem Manajemen Data. Jurnal Teknologi dan Sistem Informasi (JTSI), 10(3), 180–188.
<br>[3] Nugroho, A., & Lestari, M. (2021). Implementasi Operasi CRUD pada Doubly Linked List menggunakan C++. Jurnal Riset Informatika dan Komputer, 6(2), 65–73.
<br>[4] Siregar, F., & Putri, D. (2020). Evaluasi Efisiensi Struktur Data Linked List terhadap Penggunaan Memori. Jurnal Teknologi dan Informasi, 7(4), 88–96.
<br>[5] Rahman, A. (2023). Analisis Kinerja Doubly Linked List terhadap Operasi Traversal Dua Arah. Jurnal Ilmiah Teknologi Informasi Terapan, 9(1), 55–63.
