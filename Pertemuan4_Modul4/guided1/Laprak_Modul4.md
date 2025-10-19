# <h1 align="center">Laporan Praktikum Modul 4 -  SINGLY LINKED LIST (BAGIAN PERTAМА)</h1>
<p align="center">Najwa Mahira - 103112400091</p>

## Dasar Teori
Struktur data merupakan cara mengelola dan menyimpan data agar dapat diakses serta dimodifikasi secara efisien. Salah satu struktur data yang banyak digunakan karena sifatnya dinamis adalah Linked List.

### A. Pengertian Singly Linked List<br/>
Singly Linked List adalah struktur data dinamis yang terdiri dari rangkaian node, di mana setiap node berisi data dan pointer ke node berikutnya. Berbeda dengan array, linked list tidak membutuhkan memori berurutan dan dapat berubah ukurannya secara fleksibel [1].
#### 1. Struktur Node
Setiap node memiliki dua bagian, yaitu data dan pointer next yang menunjuk ke node berikutnya.
#### 2. Head dan Tail
Head menunjuk ke node pertama, sedangkan Tail menunjuk ke NULL sebagai akhir dari list.
#### 3. Operasi Dasar
Operasi utama meliputi penambahan (insert), penghapusan (delete), dan penelusuran (traversal) node dalam list.

### B. Operasi pada Singly Linked List<br/>
Singly Linked List memiliki beberapa operasi dasar yang digunakan untuk memanipulasi node di dalamnya [2].
#### 1. Insert
Menambahkan node baru ke dalam list, baik di bagian awal, tengah, maupun akhir list.
#### 2. Delete
Menghapus node tertentu dari list, misalnya di posisi awal, tengah, atau akhir.
#### 3. Traversal
Menelusuri seluruh node dari head hingga NULL untuk menampilkan isi list.

## Guided 1

### 1. list.h

```C++
// Header guard digunakan untuk mencegah file header yang sama 
// di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; // Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node* address;    // Mendefinisikan alias address sebagai pointer ke struct node

struct node { // Node untuk isi dari linked list-nya, isi setiap node adalah data & pointer next
    dataMahasiswa isiData;
    address next;
};

// Ini struct untuk linked list-nya
struct linkedList {
    address first;
};

// Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

#endif
```
Program ini menunjukkan cara menyimpan dan menampilkan data mahasiswa menggunakan Singly Linked List secara dinamis di C++.

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isiData.nama = nama;
    nodeBaru->isiData.nim = nim; 
    nodeBaru->isiData.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isiData.nama << ", NIM : " << nodeBantu->isiData.nim 
            << ", Usia : " << nodeBantu->isiData.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
Program ini berisi implementasi fungsi dan prosedur untuk Linked List Mahasiswa.
Tujuannya agar data mahasiswa (nama, NIM, umur) bisa disimpan dan dikelola secara dinamis menggunakan singly linked list.

### 3. main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program ini membuat dan menampilkan daftar mahasiswa menggunakan Singly Linked List, di mana setiap node berisi data nama, NIM, dan umur.

## Guided 2

### 1. list.h

```C++
// Header guard digunakan untuk mencegah file header yang sama 
// di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; // Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node* address;    // Mendefinisikan alias address sebagai pointer ke struct node

struct node { // Node untuk isi dari linked list-nya, isi setiap node adalah data & pointer next
    dataMahasiswa isiData;
    address next;
};

struct linkedList { // Ini linked list-nya
    address first;
};

// semua function & prosedur yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
```
File ini berfungsi sebagai kerangka dasar (blueprint) dari program Linked List Mahasiswa, berisi struktur dan deklarasi fungsi sebelum diimplementasikan di file .cpp.

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isiData.nama = nama;
    nodeBaru->isiData.nim = nim; 
    nodeBaru->isiData.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isiData.nama << ", NIM : " << nodeBantu->isiData.nim << ", Usia : " << nodeBantu->isiData.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
Program ini berisi implementasi lengkap operasi pada Singly Linked List Mahasiswa, yaitu cara membuat, menambah, menghapus, dan menampilkan data mahasiswa dalam list.

### 3. main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program ini memperlihatkan cara kerja operasi dasar Singly Linked List pada data mahasiswa, mulai dari pembuatan hingga penghapusan total list secara dinamis menggunakan pointer di C++.

## Unguided 

### 1. soal Unguided 1

Buatlah ADT Singly Linked List dengan ketentuan seperti di bawah ini:
File header : Singlylist.h
File implementasi : Singlylist.cpp
File utama : main.cpp

Buatlah ADT Singly Linked List dengan ketentuan seperti di bawah ini:
File header : Singlylist.h
File implementasi : Singlylist.cpp
File utama : main.cpp

Output yang diharapkan :
Isi Linked List : 9 12 8 0 2

### 1. Singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;
};

// Prosedur dan fungsi
void createList(List& L);
void insertFirst(List& L, int nilai);
void insertAfter(Node* prevNode, int nilai);
void insertLast(List& L, int nilai);
void deleteFirst(List& L);
void deleteAfter(Node* prevNode);
void deleteLast(List& L);
void printInfo(List L);
int nbList(List L);
void deleteList(List& L);

#endif
```

Header file ini berfungsi untuk mendeklarasikan struktur data dan fungsi-fungsi ADT Singly Linked List, supaya bisa dipanggil dari file Singlylist.cpp dan main.cpp.

### 2. Singlylist.cpp

```C++
#include "Singlylist.h"

// Membuat list kosong
void createList(List& L) {
    L.first = NULL;
}

// Menambah node di awal
void insertFirst(List& L, int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = L.first;
    L.first = baru;
}

// Menambah node setelah node tertentu
void insertAfter(Node* prevNode, int nilai) {
    if (prevNode != NULL) {
        Node* baru = new Node;
        baru->data = nilai;
        baru->next = prevNode->next;
        prevNode->next = baru;
    }
}

// Menambah node di akhir
void insertLast(List& L, int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (L.first == NULL) {
        L.first = baru;
    } else {
        Node* temp = L.first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// Menghapus node pertama
void deleteFirst(List& L) {
    if (L.first != NULL) {
        Node* hapus = L.first;
        L.first = L.first->next;
        delete hapus;
    }
}

// Menghapus node setelah node tertentu
void deleteAfter(Node* prevNode) {
    if (prevNode != NULL && prevNode->next != NULL) {
        Node* hapus = prevNode->next;
        prevNode->next = hapus->next;
        delete hapus;
    }
}

// Menghapus node terakhir
void deleteLast(List& L) {
    if (L.first == NULL) return;
    if (L.first->next == NULL) {
        delete L.first;
        L.first = NULL;
    } else {
        Node* temp = L.first;
        Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
    }
}

// Menampilkan isi list
void printInfo(List L) {
    Node* temp = L.first;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Menghitung jumlah node
int nbList(List L) {
    int count = 0;
    Node* temp = L.first;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Menghapus semua node
void deleteList(List& L) {
    Node* temp = L.first;
    while (temp != NULL) {
        Node* hapus = temp;
        temp = temp->next;
        delete hapus;
    }
    L.first = NULL;
}
```

Kode ini membuat ADT Singly Linked List, yaitu struktur data berisi node yang saling terhubung satu arah.

### 3. main.cpp

```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    // Unguided 1 - Membuat linked list
    insertFirst(L, 2);
    insertFirst(L, 9);
    insertFirst(L, 5);
    insertFirst(L, 12);
    insertAfter(L.first->next, 8); // Menambah node setelah 9

    cout << "Isi Linked List: ";
    printInfo(L);

    // Unguided 2 - Penghapusan dan hitung jumlah node
    cout << "\n--- Operasi Penghapusan ---" << endl;
    deleteFirst(L);        // Hapus node 9
    deleteLast(L);         // Hapus node 2
    deleteAfter(L.first);  // Hapus node 8

    cout << "Isi Linked List Setelah Penghapusan: ";
    printInfo(L);

    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

Program ini membuat, menampilkan, menghapus, dan menghitung elemen pada **Singly Linked List** menggunakan fungsi insert, delete, dan count.

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan4_Modul4/image4/Output-Unguided1-Modul4-1.png)

Program Unguided 1 ini bertujuan untuk membuat dan menampilkan Singly Linked List dengan data 12, 5, 9, 8, dan 2 menggunakan fungsi `createList()`, `insertFirst()`, `insertAfter()`, dan `insertLast()`, kemudian menampilkan seluruh isi list dengan `printInfo()`.

### 2. soal Unguided 2

Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter().
Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

Output yang diharapkan :
12 9
Jumlah node : 2
- List Berhasil Terhapus -
Jumlah node : 0

### 1. Singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List& L);
void insertFirst(List& L, int nilai);
void insertAfter(Node* prevNode, int nilai);
void insertLast(List& L, int nilai);
void deleteFirst(List& L);
void deleteAfter(Node* prevNode);
void deleteLast(List& L);
void printInfo(List L);
int nbList(List L);
void deleteList(List& L);

#endif
```

Kode ini mendefinisikan **struktur dan deklarasi fungsi** untuk ADT *Singly Linked List*, yang berisi node dengan data dan pointer `next`, serta fungsi untuk membuat, menambah, menghapus, menampilkan, menghitung, dan menghapus seluruh isi list.

### 2. Singlylist.cpp

```C++
#include "Singlylist.h"

// Membuat list kosong
void createList(List& L) {
    L.first = NULL;
}

// Menambah node di awal
void insertFirst(List& L, int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = L.first;
    L.first = baru;
}

// Menambah node setelah node tertentu
void insertAfter(Node* prevNode, int nilai) {
    if (prevNode != NULL) {
        Node* baru = new Node;
        baru->data = nilai;
        baru->next = prevNode->next;
        prevNode->next = baru;
    }
}

// Menambah node di akhir
void insertLast(List& L, int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (L.first == NULL) {
        L.first = baru;
    } else {
        Node* temp = L.first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// Menghapus node pertama
void deleteFirst(List& L) {
    if (L.first != NULL) {
        Node* hapus = L.first;
        L.first = L.first->next;
        delete hapus;
    }
}

// Menghapus node setelah node tertentu
void deleteAfter(Node* prevNode) {
    if (prevNode != NULL && prevNode->next != NULL) {
        Node* hapus = prevNode->next;
        prevNode->next = hapus->next;
        delete hapus;
    }
}

// Menghapus node terakhir
void deleteLast(List& L) {
    if (L.first == NULL) return;
    if (L.first->next == NULL) {
        delete L.first;
        L.first = NULL;
    } else {
        Node* temp = L.first;
        Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
    }
}

// Menampilkan isi list
void printInfo(List L) {
    Node* temp = L.first;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Menghitung jumlah node
int nbList(List L) {
    int count = 0;
    Node* temp = L.first;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Menghapus semua node
void deleteList(List& L) {
    Node* temp = L.first;
    while (temp != NULL) {
        Node* hapus = temp;
        temp = temp->next;
        delete hapus;
    }
    L.first = NULL;
}
```

Kode ini berisi **implementasi fungsi-fungsi ADT Singly Linked List** untuk membuat list, menambah node (di awal, tengah, akhir), menghapus node, menampilkan isi list, menghitung jumlah node, dan menghapus seluruh list secara dinamis menggunakan pointer.

### 3. main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    // Membuat linked list dari soal latihan pertama
    insertFirst(L, 2);
    insertFirst(L, 9);
    insertFirst(L, 5);
    insertFirst(L, 12);
    insertAfter(L.first->next, 8); // Node 8 setelah node 9

    // --- Penghapusan sesuai instruksi soal ---
    deleteFirst(L);        // Hapus node 9
    deleteLast(L);         // Hapus node 2
    deleteAfter(L.first);  // Hapus node 8 (setelah node 12)

    // --- Tampilkan hasil setelah penghapusan ---
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    // --- Hapus semua node ---
    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

Program ini membuat **Singly Linked List**, menambah data 12, 5, 9, 8, dan 2, lalu menghapus beberapa node sesuai instruksi soal menggunakan fungsi delete, menampilkan isi list serta jumlah node, dan akhirnya menghapus seluruh list.

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan4_Modul4/image4/Output-Unguided2-Modul4-1.png)

Program Unguided 2 ini bertujuan untuk mengimplementasikan operasi penghapusan pada Singly Linked List, yaitu menghapus node pertama dengan `deleteFirst()`, node terakhir dengan `deleteLast()`, dan node tertentu (setelah node pertama) dengan `deleteAfter()`. Setelah penghapusan, program menampilkan isi list yang tersisa serta jumlah node menggunakan `nbList()`, kemudian menghapus seluruh elemen dalam list menggunakan `deleteList()` agar list kembali kosong.

## Kesimpulan
Singly Linked List merupakan struktur data dinamis yang memungkinkan efisiensi tinggi dalam penambahan dan penghapusan data. Operasi insert dan delete dapat dilakukan di berbagai posisi tanpa perlu menggeser data. Struktur ini cocok digunakan untuk sistem yang membutuhkan perubahan data secara fleksibel seperti sistem antrian, rekomendasi, maupun simulasi berbasis data dinamis.

## Referensi
[1] Wijoyo, A., Prasetiyo, A. R., Salsabila, A. A., Nife, K., & Nadapdap, P. B. (2024). “Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian.” JRIIN: Jurnal Riset Informatika dan Inovasi, 1(12).
[2] Chrismono, A., & Ningsih, D. H. U. (2023). “Single Linked List Method for Selection of SMA/SMK di Semarang (Implementasi Zona).” JEEEU: Jurnal Elektronika, Elektro dan Energi UMSIDA.
[3] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti, L. (2023). “Perbandingan Struktur Linked List dan Array dalam Manajemen Memori.” JRIIN: Jurnal Riset Informatika dan Inovasi, 1(10).
[4] Jurnal Sains Informatika Terapan (JSIT). (2025). “Analisis Struktur Data Linked List Dalam Pengolahan Data Mahasiswa.” Vol. 4 No. 2, RCF Indonesia.
[5] Puspitasari, D., & Rahmawati, A. (2023). “Implementasi Linked List pada Interaksi Antar Marker Augmented Reality untuk Operand dan Operator Aritmetika.” J-PTIIK Universitas Brawijaya.
<br>...
