# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (BAGIAN KEDUA)</h1>
<p align="center">Najwa Mahira - 103112400091</p>

## Dasar Teori
Singly Linked List atau senarai berantai tunggal merupakan struktur data dinamis yang terdiri atas sekumpulan node yang saling terhubung melalui pointer. Setiap node memiliki dua bagian utama, yaitu bagian data untuk menyimpan nilai dan pointer yang menunjuk ke node berikutnya. Berbeda dengan array yang memiliki ukuran tetap dan elemen bersebelahan di memori, linked list memungkinkan penambahan atau penghapusan elemen tanpa perlu menggeser data lain, sehingga lebih efisien dalam pengelolaan memori [1].

Dalam penerapannya, singly linked list memiliki satu pointer utama yang disebut head atau first yang menunjuk ke node pertama, sementara node terakhir menunjuk ke NULL sebagai penanda akhir list. Struktur ini mendukung berbagai operasi seperti pembuatan list, penyisipan data (insert), penghapusan data (delete), pembaruan data (update), serta pencarian data (search). Selain itu, linked list juga dapat dikembangkan untuk melakukan operasi tambahan seperti pencarian berdasarkan alamat memori, pencarian berdasarkan nilai tertentu, dan perhitungan aritmatika terhadap seluruh elemen data [2].

Singly linked list banyak digunakan dalam implementasi algoritma dan sistem karena kemampuannya dalam mengelola data secara fleksibel dan efisien. Struktur ini sangat berguna pada program yang membutuhkan manipulasi data secara dinamis tanpa batasan ukuran, meskipun waktu akses ke elemen tertentu lebih lambat dibandingkan array karena harus melalui proses penelusuran node secara berurutan [3].

### A. Konsep Dasar Singly Linked List<br/>
Singly Linked List merupakan salah satu struktur data dinamis yang digunakan untuk menyimpan data secara berurutan dengan menggunakan pointer.
Setiap elemen dalam linked list disebut node, yang terdiri atas dua bagian utama, yaitu data untuk menyimpan nilai dan pointer (next) untuk menunjuk ke node berikutnya.
Berbeda dengan array yang bersifat statis, linked list bersifat dinamis sehingga ukurannya dapat berubah selama program berjalan [1].
#### 1. Pengertian Node
Node merupakan unit dasar pada linked list. Node pertama disebut head, dan node terakhir memiliki pointer bernilai NULL sebagai penanda akhir list.
Struktur dasar node biasanya ditulis dalam bahasa C++ menggunakan struct yang memuat data dan pointer next.
#### 2. Pointer dan Keterhubungan Data
Pointer berfungsi menghubungkan setiap node dengan node berikutnya.
Dengan adanya pointer, setiap elemen tidak perlu disimpan berurutan di memori. Hal ini memberikan fleksibilitas tinggi karena penambahan atau penghapusan data tidak memerlukan pergeseran elemen [2].
#### 3. Kelebihan dan Kekurangan
Kelebihan utama linked list adalah kemampuannya untuk menambah dan menghapus data secara efisien tanpa alokasi memori tetap.
Namun, kekurangannya terletak pada waktu akses yang lebih lama karena pencarian data harus dilakukan secara berurutan dari node pertama hingga node terakhir [1].

### B. Operasi Dasar pada Singly Linked<br/>
Operasi dasar pada singly linked list meliputi pembuatan list (createList), penyisipan node (insert), penghapusan node (delete), pembaruan data (update), serta pencarian data (search). Semua operasi dilakukan dengan memanipulasi pointer agar hubungan antar node tetap terjaga [1]. Selain itu, linked list juga dapat dikembangkan untuk operasi tambahan seperti pencarian berdasarkan alamat memori, pencarian berdasarkan rentang nilai, dan perhitungan aritmatika terhadap seluruh elemen data [2].
Struktur ini banyak digunakan pada sistem yang memerlukan manajemen data dinamis karena efisiensi dalam penggunaan memori serta kemudahan dalam menambah dan menghapus elemen. Meskipun waktu aksesnya lebih lambat dibanding array karena harus ditelusuri secara berurutan, linked list tetap unggul dalam fleksibilitas dan efisiensi manipulasi data [3].
#### 1. Operasi Penyisipan (Insert)
Operasi insert digunakan untuk menambahkan node baru ke dalam list. Proses penyisipan dapat dilakukan di awal list (mengubah posisi head), di tengah list (setelah node tertentu), maupun di akhir list (menambahkan node baru di bagian akhir). Dalam setiap penyisipan, pointer next dari node sebelumnya akan diatur agar menunjuk ke node baru. Proses ini membuat linked list mampu menampung data baru tanpa harus menggeser elemen lainnya, menjadikannya efisien dalam manipulasi data dinamis [1].
#### 2. Operasi Penghapusan (Delete)
Operasi delete dilakukan untuk menghapus node dari list. Jika node yang dihapus adalah node pertama, maka pointer head akan diarahkan ke node berikutnya. Jika node berada di tengah atau akhir, maka pointer dari node sebelumnya akan diubah agar melewati node yang dihapus. Operasi ini memerlukan ketelitian dalam mengatur pointer agar struktur list tetap terhubung dengan benar dan tidak terjadi kehilangan referensi data [2].
#### 3. Operasi Penelusuran dan Pencarian (Traversal dan Search)
Traversal dilakukan dengan menelusuri node satu per satu mulai dari head hingga NULL untuk menampilkan seluruh isi list. Sedangkan operasi search digunakan untuk mencari nilai tertentu dengan cara membandingkan data pada setiap node. Proses ini bersifat linear, artinya waktu pencarian bergantung pada jumlah node yang ada dalam list. Walaupun aksesnya tidak secepat array, traversal dan search pada linked list memberikan fleksibilitas tinggi untuk mengolah data yang jumlahnya tidak tetap [3].

## Guided 

### 1. ListBuah.h

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

File listBuah.h berisi deklarasi struktur data dan fungsi untuk mengelola singly linked list berisi data buah.
Struktur buah menyimpan nama, jumlah, dan harga; node menyimpan data buah serta pointer ke node berikutnya; dan linkedlist menyimpan alamat node pertama.
File ini juga mendeklarasikan berbagai fungsi, mulai dari operasi dasar (create, insert, delete, print), hingga operasi lanjutan seperti update dan searching.
Dengan adanya file header ini, program menjadi lebih terstruktur, efisien, dan mudah dikembangkan.

### 2. ListBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

File `listBuah.cpp` berisi implementasi fungsi-fungsi untuk mengelola struktur data *Singly Linked List* yang menyimpan data buah. Di dalamnya terdapat operasi dasar seperti membuat list, menambah dan menghapus node, menampilkan isi list, serta menghitung jumlah node. Selain itu, terdapat fitur lanjutan seperti *update* data pada node tertentu dan *searching* data berdasarkan nama buah, alamat node, maupun rentang harga. Program ini menunjukkan cara penggunaan pointer untuk mengatur hubungan antar node secara dinamis dalam memori.

### 3. main.cpp

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

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

File `main.cpp` berfungsi sebagai program utama yang menjalankan seluruh operasi pada *Singly Linked List* data buah. Program ini membuat list baru, menambahkan beberapa data buah menggunakan prosedur *insert*, lalu menampilkan hasilnya. Setelah itu dilakukan proses *update* pada node pertama, terakhir, dan node tertentu, dilanjutkan dengan pencarian data menggunakan nama, alamat, dan rentang harga. Program juga menampilkan hasil penghapusan node di awal, tengah, dan akhir list menggunakan prosedur *delete*, serta menghapus seluruh isi list dengan `deleteList()`. Program ini menunjukkan penerapan lengkap operasi dasar, update, dan searching pada struktur data *linked list* di C++.

## Unguided 1

### 1. ListAngka.h

```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H
#include <iostream>
using namespace std;

typedef int dataAngka;

struct Node {
    dataAngka angka;
    Node* next;
};

struct linkedList {
    Node* first;
};

void createList(linkedList &L);
Node* alokasi(dataAngka x);
void insertLast(linkedList &L, Node* p);
void printList(linkedList L);
void updateFirst(linkedList &L);
void updateAfter(Node* prec);
void updateLast(linkedList &L);

#endif
```

File ListAngka.h berisi deklarasi struktur data dan fungsi untuk mengelola Singly Linked List bertipe data integer. Struktur Node menyimpan satu data bilangan (angka) dan pointer next yang menunjuk ke node berikutnya, sedangkan struktur linkedList menyimpan pointer first sebagai penanda node awal. File ini juga mendeklarasikan beberapa fungsi utama, yaitu membuat list baru (createList), mengalokasikan node (alokasi), menambah node di akhir list (insertLast), menampilkan isi list (printList), serta memperbarui data pada node pertama, terakhir, dan node tertentu (updateFirst, updateAfter, updateLast). File ini menjadi dasar pengelolaan data dinamis dalam linked list di C++.

### 2. ListAngka.cpp

```C++
#include "Unguided1_ListAngka.h"

void createList(linkedList &L) { L.first = NULL; }

Node* alokasi(dataAngka x) {
    Node* p = new Node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void insertLast(linkedList &L, Node* p) {
    if (L.first == NULL) L.first = p;
    else {
        Node* temp = L.first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
}

void printList(linkedList L) {
    Node* temp = L.first;
    while (temp != NULL) {
        cout << temp->angka;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

void updateFirst(linkedList &L) {
    if (L.first == NULL) return;
    cout << "Masukkan update data node pertama : ";
    int x; cin >> x;
    L.first->angka = x;
    cout << "Data Berhasil Diupdate!\n" << endl;
}

void updateAfter(Node* prec) {
    if (prec != NULL && prec->next != NULL) {
        cout << "Masukkan update data node setelah node " << prec->angka << " : ";
        int x; cin >> x;
        prec->next->angka = x;
        cout << "Data Berhasil Diupdate!\n" << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.first == NULL) return;
    Node* temp = L.first;
    while (temp->next != NULL)
        temp = temp->next;
    cout << "Masukkan update data node terakhir : ";
    int x; cin >> x;
    temp->angka = x;
    cout << "Data Berhasil Diupdate!\n" << endl;
}
```

File Unguided1_ListAngka.cpp berisi implementasi fungsi-fungsi dasar untuk mengelola Singly Linked List bertipe data integer. Di dalamnya terdapat fungsi untuk membuat list baru (createList), mengalokasikan node baru (alokasi), menambah node di akhir list (insertLast), serta menampilkan seluruh isi list (printList). Selain itu, terdapat tiga prosedur update yaitu updateFirst, updateAfter, dan updateLast yang digunakan untuk memperbarui nilai data pada node pertama, node setelah node tertentu, dan node terakhir. Seluruh fungsi ini bekerja dengan konsep pointer untuk mengatur hubungan antar node secara dinamis dalam memori.

### 3. main.cpp

```C++
#include "Unguided1_ListAngka.h"

int main() {
    linkedList L;
    createList(L);

    Node* A = alokasi(40);
    Node* B = alokasi(18);
    Node* C = alokasi(25);
    Node* D = alokasi(8);
    Node* E = alokasi(33);

    insertLast(L, A);
    insertLast(L, B);
    insertLast(L, C);
    insertLast(L, D);
    insertLast(L, E);

    cout << "List awal: ";
    printList(L);

    cout << endl;
    updateFirst(L);      // ubah 40 -> 50
    updateAfter(C);      // ubah 8 -> 29
    updateLast(L);       // ubah 33 -> 45
    updateAfter(L.first);// ubah 18 -> 20

    cout << "List setelah update: ";
    printList(L);
    return 0;
}
```

File Unguided1_main.cpp berfungsi sebagai program utama untuk menjalankan operasi update pada Singly Linked List bertipe data integer. Program ini membuat list baru, menambahkan beberapa data ke dalam list menggunakan insertLast, kemudian menampilkan list awal. Selanjutnya dilakukan proses pembaruan nilai pada node pertama (updateFirst), node setelah node tertentu (updateAfter), dan node terakhir (updateLast). Setelah semua perubahan dilakukan, program menampilkan hasil akhir list yang sudah diperbarui. Program ini memperlihatkan penerapan konsep update node dalam struktur data linked list secara dinamis di C++.

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan5_Modul5/image5/Output-Unguided1_Modul5-1.png)

Program Unguided 1 berfungsi untuk mengelola Singly Linked List sederhana bertipe data integer dengan fokus pada operasi update data. Program diawali dengan pembuatan list baru dan penambahan beberapa node menggunakan prosedur insertLast, kemudian menampilkan isi list awal. Selanjutnya dilakukan pembaruan data pada node pertama, node terakhir, serta node setelah node tertentu menggunakan fungsi updateFirst, updateLast, dan updateAfter. Setelah semua perubahan dilakukan, program menampilkan hasil akhir list yang telah diperbarui. Program ini menunjukkan cara memperbarui isi node dalam linked list secara dinamis menggunakan pointer di C++.

## Unguided 2

### 1. ListAngka.h

```C++
#ifndef UNGUIDED2_LISTANGKA_H
#define UNGUIDED2_LISTANGKA_H
#include <iostream>
using namespace std;

typedef int dataAngka;

struct Node {
    dataAngka angka;
    Node* next;
};

struct linkedList {
    Node* first;
};

void createList(linkedList &L);
Node* alokasi(dataAngka x);
void insertLast(linkedList &L, Node* p);
void printList(linkedList L);
void searchByData(linkedList L, dataAngka x);
void searchByAddress(linkedList L, Node* alamat);
void searchByRange(linkedList L, dataAngka nilaiMin);

#endif
```

File Unguided2_ListAngka.h berisi deklarasi struktur data dan fungsi yang digunakan untuk melakukan operasi searching pada Singly Linked List bertipe data integer. Struktur Node menyimpan nilai data (angka) dan pointer next yang menunjuk ke node berikutnya, sedangkan struktur linkedList berfungsi menyimpan pointer first sebagai penanda node awal. File ini juga mendeklarasikan fungsi-fungsi utama seperti pembuatan list (createList), pembuatan node baru (alokasi), penambahan node di akhir list (insertLast), penampilan isi list (printList), serta tiga fungsi pencarian yaitu searchByData untuk mencari nilai data, searchByAddress untuk mencari berdasarkan alamat node, dan searchByRange untuk menampilkan data yang nilainya lebih besar dari batas tertentu.

### 2. ListAngka.cpp

```C++
#include "Unguided2_ListAngka.h"

void createList(linkedList &L) { L.first = NULL; }

Node* alokasi(dataAngka x) {
    Node* p = new Node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void insertLast(linkedList &L, Node* p) {
    if (L.first == NULL) L.first = p;
    else {
        Node* temp = L.first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
}

void printList(linkedList L) {
    Node* temp = L.first;
    while (temp != NULL) {
        cout << temp->angka;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << " ->" << endl;
}

void searchByData(linkedList L, dataAngka x) {
    Node* temp = L.first;
    int posisi = 1;
    bool found = false;

    while (temp != NULL) {
        if (temp->angka == x) {
            cout << "Data " << x << " ditemukan pada posisi ke-" << posisi << "!" << endl;
            found = true;
            break;
        }
        posisi++;
        temp = temp->next;
    }

    if (!found)
        cout << "Node dengan data " << x << " tidak ditemukan!" << endl;
    cout << endl;
}

void searchByAddress(linkedList L, Node* alamat) {
    Node* temp = L.first;
    int posisi = 1;
    bool found = false;

    while (temp != NULL) {
        if (temp == alamat) {
            cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
            cout << "Alamat node : " << temp << endl;
            found = true;
            break;
        }
        posisi++;
        temp = temp->next;
    }

    if (!found)
        cout << "Node dengan alamat " << alamat << " tidak ditemukan dalam list!" << endl;
    cout << endl;
}

void searchByRange(linkedList L, dataAngka nilaiMin) {
    Node* temp = L.first;
    int posisi = 1;
    cout << "--- Data diatas nilai " << nilaiMin << " : ---" << endl;

    while (temp != NULL) {
        if (temp->angka >= nilaiMin) {
            cout << "---------------------------------------------" << endl;
            cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << temp->angka << endl;
        }
        posisi++;
        temp = temp->next;
    }
    cout << "---------------------------------------------" << endl;
    cout << endl;
}
```

File Unguided2_ListAngka.cpp berisi implementasi fungsi-fungsi untuk melakukan pencarian data pada Singly Linked List bertipe integer. Di dalamnya terdapat fungsi dasar seperti membuat list baru (createList), mengalokasikan node (alokasi), menambahkan node di akhir list (insertLast), dan menampilkan isi list (printList). Selain itu, terdapat tiga fungsi utama untuk pencarian data, yaitu searchByData untuk mencari node berdasarkan nilai data, searchByAddress untuk mencari node berdasarkan alamat memorinya, dan searchByRange untuk menampilkan semua node dengan nilai data di atas batas tertentu. Seluruh fungsi bekerja menggunakan metode traversal, yaitu menelusuri node dari awal hingga akhir list.

### 3. main.cpp

```C++
#include "Unguided2_ListAngka.h"

int main() {
    linkedList L;
    createList(L);

    Node* A = alokasi(50);
    Node* B = alokasi(20);
    Node* C = alokasi(25);
    Node* D = alokasi(29);
    Node* E = alokasi(45);

    insertLast(L, A);
    insertLast(L, B);
    insertLast(L, C);
    insertLast(L, D);
    insertLast(L, E);

    printList(L);
    cout << endl;

    searchByData(L, 20);
    searchByData(L, 55);
    searchByAddress(L, B);
    searchByAddress(L, A);
    searchByRange(L, 40);
    return 0;
}
```

File Unguided2_main.cpp berfungsi sebagai program utama yang menampilkan penerapan proses pencarian pada Singly Linked List bertipe data integer. Program ini membuat list baru, menambahkan beberapa data ke dalam list menggunakan insertLast, lalu menampilkan seluruh isi list. Selanjutnya dilakukan proses pencarian data berdasarkan nilai tertentu dengan searchByData, pencarian berdasarkan alamat node dengan searchByAddress, serta pencarian data dengan nilai lebih besar dari batas tertentu menggunakan searchByRange. Program ini menunjukkan cara kerja operasi searching dalam struktur data linked list menggunakan penelusuran node satu per satu.

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](ttps://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan5_Modul5/image5/Output-Unguided2_Modul5-1.png)


##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program Unguided 2 berfungsi untuk menerapkan operasi searching atau pencarian data pada Singly Linked List bertipe data integer. Program diawali dengan pembuatan list baru dan penambahan beberapa data ke dalam list menggunakan fungsi insertLast, kemudian menampilkan isi list. Setelah itu dilakukan pencarian berdasarkan nilai data (searchByData), pencarian berdasarkan alamat node (searchByAddress), serta pencarian data dengan nilai di atas batas tertentu (searchByRange). Hasil pencarian akan menampilkan posisi data di dalam list beserta informasi terkait. Program ini menggambarkan cara menelusuri dan menemukan data pada struktur linked list secara dinamis menggunakan pointer.

## Unguided 3

### 1. ListAngka.h

```C++
#ifndef UNGUIDED3_LISTANGKA_H
#define UNGUIDED3_LISTANGKA_H
#include <iostream>
using namespace std;

typedef int dataAngka;

struct Node {
    dataAngka angka;
    Node* next;
};

struct linkedList {
    Node* first;
};

// fungsi dasar
void createList(linkedList &L);
Node* alokasi(dataAngka x);
void insertLast(linkedList &L, Node* p);
void printList(linkedList L);

// operasi aritmatika
int sumList(linkedList L);
int subList(linkedList L);
int mulList(linkedList L);

#endif
```

File `Unguided2_main.cpp` berfungsi sebagai program utama yang menampilkan penerapan proses pencarian pada *Singly Linked List* bertipe data integer. Program ini membuat list baru, menambahkan beberapa data ke dalam list menggunakan `insertLast`, lalu menampilkan seluruh isi list. Selanjutnya dilakukan proses pencarian data berdasarkan nilai tertentu dengan `searchByData`, pencarian berdasarkan alamat node dengan `searchByAddress`, serta pencarian data dengan nilai lebih besar dari batas tertentu menggunakan `searchByRange`. Program ini menunjukkan cara kerja operasi *searching* dalam struktur data *linked list* menggunakan penelusuran node satu per satu.


### 2. ListAngka.cpp

```C++
#include "Unguided3_ListAngka.h"

void createList(linkedList &L) { L.first = NULL; }

Node* alokasi(dataAngka x) {
    Node* p = new Node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void insertLast(linkedList &L, Node* p) {
    if (L.first == NULL) L.first = p;
    else {
        Node* temp = L.first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
}

void printList(linkedList L) {
    Node* temp = L.first;
    while (temp != NULL) {
        cout << temp->angka;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

// -------------------------
// Operasi Aritmatika
// -------------------------

int sumList(linkedList L) {
    int sum = 0;
    Node* temp = L.first;
    while (temp != NULL) {
        sum += temp->angka;
        temp = temp->next;
    }
    return sum;
}

int subList(linkedList L) {
    if (L.first == NULL) return 0;
    int hasil = L.first->angka;
    Node* temp = L.first->next;
    while (temp != NULL) {
        hasil -= temp->angka;
        temp = temp->next;
    }
    return hasil;
}

int mulList(linkedList L) {
    int hasil = 1;
    Node* temp = L.first;
    while (temp != NULL) {
        hasil *= temp->angka;
        temp = temp->next;
    }
    return hasil;
}
```

File Unguided3_ListAngka.cpp berisi implementasi fungsi-fungsi untuk melakukan operasi aritmatika pada Singly Linked List bertipe data integer. Di dalamnya terdapat fungsi dasar seperti membuat list (createList), mengalokasikan node baru (alokasi), menambahkan node di akhir list (insertLast), dan menampilkan isi list (printList). Selain itu, terdapat tiga fungsi aritmatika yaitu sumList untuk menghitung total penjumlahan seluruh elemen, subList untuk menghitung hasil pengurangan data secara berurutan, dan mulList untuk menghitung hasil perkalian semua nilai pada list. Program ini memperlihatkan penerapan operasi matematis dengan menelusuri node satu per satu menggunakan konsep pointer dalam linked list.

### 3. main.cpp

```C++
#include "Unguided3_ListAngka.h"

int main() {
    linkedList L;
    createList(L);

    // Data hasil update dari Unguided 1
    Node* A = alokasi(50);
    Node* B = alokasi(20);
    Node* C = alokasi(25);
    Node* D = alokasi(29);
    Node* E = alokasi(45);

    insertLast(L, A);
    insertLast(L, B);
    insertLast(L, C);
    insertLast(L, D);
    insertLast(L, E);

    cout << "List: ";
    printList(L);

    cout << "\nPenjumlahan data: " << sumList(L) << endl;
    cout << "Pengurangan data: " << subList(L) << endl;
    cout << "Perkalian data: " << mulList(L) << endl;

    return 0;
}
```

File Unguided3_main.cpp berfungsi sebagai program utama yang menampilkan penerapan operasi aritmatika pada Singly Linked List bertipe data integer. Program ini membuat list baru, menambahkan beberapa data ke dalam list hasil dari Unguided 1, lalu menampilkan isi list menggunakan printList. Setelah itu, dilakukan tiga operasi perhitungan yaitu sumList untuk menghitung total penjumlahan data, subList untuk menghitung hasil pengurangan secara berurutan, dan mulList untuk menghitung hasil perkalian seluruh elemen dalam list. Program ini menunjukkan cara menerapkan operasi matematika pada data dinamis menggunakan struktur linked list di C++.

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](ttps://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan5_Modul5/image5/Output-Unguided3_Modul5-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program Unguided 3 berfungsi untuk melakukan operasi aritmatika pada Singly Linked List bertipe data integer. Program diawali dengan pembuatan list baru dan penambahan beberapa node menggunakan insertLast, lalu menampilkan isi list. Selanjutnya dilakukan tiga operasi utama yaitu sumList untuk menghitung total penjumlahan seluruh elemen, subList untuk menghitung hasil pengurangan data secara berurutan, dan mulList untuk menghitung hasil perkalian semua data dalam list. Program ini menunjukkan penerapan operasi matematis pada struktur linked list menggunakan proses penelusuran node satu per satu dengan konsep pointer.

## Kesimpulan
Dari hasil praktikum ini, dapat disimpulkan bahwa Singly Linked List adalah struktur data yang sangat fleksibel dan efisien untuk pengelolaan data dinamis.
Berbagai operasi seperti penyisipan, penghapusan, dan pencarian data dapat dilakukan dengan mudah melalui pengaturan pointer.
Penelitian [1][2] mendukung bahwa linked list unggul dalam efisiensi memori serta cocok diterapkan pada sistem yang datanya sering berubah.

## Referensi
[1] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan Struktur Linked List dan Array dalam Manajemen Memori. JRIIN: Jurnal Riset Informatika dan Inovasi. 
<br>[2] Mbejo, M. T., Nopa, L. A., Putri, J. S., & Risky, M. (2025). Analisis Struktur Data Linked List dalam Pengolahan Data Mahasiswa. Jurnal Sains Informatika Terapan, Vol. 4 No. 2. 
<br>[3] Syafrial, R., & Ramadhan, T. (2021). Analisis Struktur Data Linked List dalam Efisiensi Manajemen Memori. Jurnal Informatika dan Sistem Cerdas, Vol. 3 No. 2. 
