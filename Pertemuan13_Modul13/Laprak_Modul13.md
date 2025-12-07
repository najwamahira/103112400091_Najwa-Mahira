# <h1 align="center">Laporan Praktikum Modul 13 -  MULTI LINKED LIST</h1>
<p align="center">Najwa Mahira - 103112400091</p>

## Dasar Teori
Multi Linked List adalah struktur data yang memungkinkan satu elemen pada list memiliki list lain di dalamnya, sehingga membentuk hubungan hierarkis (induk–anak). Struktur ini digunakan untuk mengelola data yang memiliki relasi satu ke banyak, misalnya satu kategori memiliki banyak item, atau satu pegawai memiliki banyak data turunan. Keunggulan Multi Linked List adalah fleksibilitas dalam pengelompokan data dan efisiensi operasi insert-delete karena tiap bagian data terpisah dalam list-nya masing-masing [1][2].

### A. Multi Linked List<br/>
Multi Linked List bekerja dengan konsep bahwa setiap node induk memiliki pointer menuju list anak. Struktur ini mempermudah pengelompokan data berdasarkan induknya, sehingga data yang berhubungan tidak tercampur dalam satu list yang panjang [3].
#### 1. Struktur List Induk
List induk biasanya disusun menggunakan doubly linked list, di mana setiap elemen berisi info, pointer ke elemen sebelum, pointer ke elemen berikutnya, dan pointer ke list anak. Dengan model ini, proses berpindah antar node lebih cepat dan operasi penyisipan serta penghapusan lebih efisien [1].
#### 2. Struktur List Anak
List anak juga dibangun menggunakan doubly linked list, namun berada dalam ruang lingkup satu induk. Setiap anak menyimpan info dan pointer next serta prev. Bentuk ini membantu menjaga agar setiap induk memiliki kumpulan anak yang terpisah dan tidak tercampur dengan induk lain [2].
#### 3. Hubungan Induk–Anak
Relasi induk–anak dibentuk melalui pointer list anak yang berada pada elemen induk. Anak hanya bisa dimasukkan setelah induknya ditemukan. Dengan pendekatan ini, data tetap rapi dan terstruktur karena setiap anak pasti milik induk tertentu [3].

### B. Operasi pada Multi Linked List<br/>
Operasi pada multi linked list mirip dengan operasi linked list biasa, tetapi harus memperhatikan hubungan induk–anak agar struktur tetap konsisten.
#### 1. Operasi Insert
Insert induk dilakukan seperti pada linked list umumnya (di awal, akhir, atau setelah node tertentu). Sementara itu, insert anak hanya bisa dilakukan setelah menemukan induk yang tepat, barulah anak ditambahkan ke list anak milik induk tersebut [1].
#### 2. Operasi Delete
Delete anak dilakukan dengan menghapus elemen anak dari list anak milik induk tertentu. Jika induk dihapus, maka semua anak dari induk tersebut harus ikut dihapus untuk menghindari memory leak dan memastikan tidak ada anak tanpa induk [2].
#### 3. Traversal Data
Traversal dilakukan dengan membaca seluruh elemen induk, kemudian untuk tiap induk, program membaca seluruh list anaknya. Dengan cara ini, struktur hierarki dapat ditampilkan secara lengkap dan berurutan [3].

## Guided 

### 1. mll.h

```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```
Pada Guided 1 ini dibuat rancangan dasar Multi Linked List yang terdiri dari list induk (kategori makanan) dan list anak (data makanan). File MLL.h mendefinisikan bentuk struct untuk kategori dan makanan, lalu membuat node parent yang menyimpan data kategori sekaligus membawa list anak di dalamnya. Node child digunakan untuk menyimpan data makanan dan tersusun dalam double linked list.

Selain itu, header ini juga berisi deklarasi fungsi-fungsi penting seperti membuat list, alokasi node, insert, delete, mencari data, mengubah data, dan menampilkan struktur Multi Linked List. Intinya, Guided 1 mempersiapkan semua kerangka yang diperlukan sebelum implementasi di file .cpp.

### 2. mll.cpp

```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```
Pada Guided 1 ini, program mulai mengimplementasikan semua fungsi dasar yang sebelumnya sudah dideklarasikan di file header. Bagian pertama berisi pengecekan list kosong dan inisialisasi list, yaitu mengatur pointer first dan last menjadi NULL agar list siap digunakan. Setelah itu dibuat fungsi alokasi node parent dan child, yaitu membuat node baru, mengisi datanya, serta mengatur pointer agar siap dimasukkan ke dalam list. Fungsi dealokasi juga disiapkan untuk menghapus node dari memori dan mencegah memory leak.

Selanjutnya, program mengisi fungsi-fungsi operasi pada parent seperti insert di awal, akhir, atau setelah node tertentu. Semua proses insert sudah memperhatikan kondisi list kosong maupun list yang sudah berisi. Fungsi delete pada parent juga dilengkapi dengan penghapusan seluruh child dari parent tersebut sebelum node parent dihapus. Fungsi pencarian dan update parent berdasarkan ID juga sudah dibuat untuk memudahkan akses data.

Untuk bagian child, fungsinya mirip dengan parent, yaitu insert, delete, find, dan update namun dilakukan di dalam list anak milik tiap parent. Karena setiap parent memiliki list anak sendiri, pencarian child harus dilakukan dengan menelusuri setiap parent terlebih dahulu.

Di akhir, program menyediakan fungsi untuk menampilkan seluruh struktur Multi Linked List, termasuk setiap parent dan semua child yang ada di dalamnya. Selain itu juga ada fungsi untuk menghapus seluruh isi list, baik list induk maupun list anak. Secara keseluruhan, Guided 1 ini berisi implementasi lengkap semua operasi dasar Multi Linked List sehingga list benar-benar bisa digunakan pada bagian guided selanjutnya.

### 3. main.cpp

```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```
Pada Guided 1 ini, program mulai menggunakan seluruh fungsi Multi Linked List yang telah dibuat sebelumnya. Pertama, program membuat sebuah list induk yang berisi kategori makanan. Setelah list dibuat, tiga kategori dimasukkan ke dalamnya, yaitu Makanan Berat, Minuman, dan Dessert. Ketiganya dimasukkan menggunakan berbagai jenis operasi insert seperti insert pertama, insert setelah node tertentu, dan insert terakhir agar semua bentuk operasi bisa dicoba.

Setelah parent terbentuk, program menambahkan data child ke dalam kategori masing-masing. Misalnya, kategori Makanan Berat diisi dua menu, Nasi Goreng Spesial dan Ayam Bakar Madu. Kategori Minuman diisi dengan Es Teh Manis dan Jus Alpukat, sedangkan kategori Dessert berisi Puding Coklat. Proses insert child juga menggunakan kombinasi insertFirst dan insertLast untuk mencoba semua jenis operasi.

Berikutnya, program menampilkan struktur Multi Linked List secara lengkap untuk melihat apakah semua parent dan child sudah masuk dengan benar. Lalu dilakukan pengujian fungsi pencarian, baik mencari parent berdasarkan ID maupun mencari child di dalam setiap parent. Program juga menampilkan contoh pencarian yang gagal agar terlihat bahwa fungsi pencarian bekerja dengan benar.

Program juga melakukan proses update, yaitu mengubah nama kategori Dessert menjadi Makanan Penutup, dan mengubah data menu Nasi Goreng Spesial menjadi Nasgor Gila dengan harga baru. Setelah update, list induk dan list anak ditampilkan lagi untuk memastikan perubahan sudah berhasil.

Di bagian akhir, program menguji operasi delete. Pertama menghapus salah satu child pada kategori Minuman, lalu menghapus kategori terakhir (K03) beserta seluruh anaknya. Setelah semua operasi selesai, program kembali menampilkan struktur Multi Linked List untuk melihat hasil akhir setelah penghapusan.

## Unguided 

### 1. MultiLL.h

```C++
#ifndef MULTILL_H_INCLUDED
#define MULTILL_H_INCLUDED

#include <iostream>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

// FUNGSI & PROSEDUR
bool isEmptyParent(listParent L);
bool isEmptyChild(listChild L);

void createListParent(listParent &L);
void createListChild(listChild &L);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &P);
void deallocNodeChild(NodeChild &C);

void insertFirstParent(listParent &L, NodeParent newNode);
void insertLastParent(listParent &L, NodeParent newNode);
void deleteFirstParent(listParent &L);
void deleteAfterParent(listParent &L, NodeParent NPrev);

void insertFirstChild(listChild &L, NodeChild newNode);
void insertLastChild(listChild &L, NodeChild newNode);
void deleteFirstChild(listChild &L);
void deleteAfterChild(listChild &L, NodeChild NPrev);

void deleteListChild(listChild &L);

void printMLLStructure(listParent L);
void searchHewanByEkor(listParent L, bool tail);

#endif
```

Pada Unguided 1 ini, program membuat struktur Multi Linked List untuk mengelompokkan hewan berdasarkan golongannya. Bagian parent berisi data golongan hewan seperti ID dan nama golongan. Setiap parent memiliki list child yang berisi data hewan lengkap, seperti ID hewan, nama, habitat, apakah punya ekor, dan bobot.

Program menyediakan fungsi‐fungsi dasar seperti mengecek apakah list kosong, membuat list parent dan child, mengalokasikan node baru untuk parent maupun child, serta dealokasi saat node dihapus. Untuk parent disediakan operasi insert pertama, insert terakhir, dan delete setelah parent tertentu. Untuk child juga ada insert pertama, insert terakhir, dan delete setelah child tertentu.

Selain itu, terdapat fungsi untuk menghapus seluruh list anak dari sebuah parent, menampilkan struktur lengkap MLL (semua parent beserta anak-anaknya), serta fungsi pencarian hewan berdasarkan kondisi apakah hewan tersebut memiliki ekor atau tidak.

Secara keseluruhan, Unguided 1 berfokus pada membangun kerangka MLL yang siap dipakai untuk pengolahan data hewan dalam kelompoknya.

### 2. MultiLL.cpp

```C++
#include "MultiLL.h"

// CEK KOSONG
bool isEmptyParent(listParent L) {
    return (L.first == NULL);
}

bool isEmptyChild(listChild L) {
    return (L.first == NULL);
}

// CREATE LIST
void createListParent(listParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

// ALOKASI
NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &P) { delete P; }
void deallocNodeChild(NodeChild &C) { delete C; }

// INSERT PARENT
void insertFirstParent(listParent &L, NodeParent newNode) {
    if (isEmptyParent(L)) {
        L.first = L.last = newNode;
    } else {
        newNode->next = L.first;
        L.first->prev = newNode;
        L.first = newNode;
    }
}

void insertLastParent(listParent &L, NodeParent newNode) {
    if (isEmptyParent(L)) {
        insertFirstParent(L, newNode);
    } else {
        L.last->next = newNode;
        newNode->prev = L.last;
        L.last = newNode;
    }
}

// DELETE PARENT
void deleteFirstParent(listParent &L) {
    if (!isEmptyParent(L)) {
        NodeParent del = L.first;

        deleteListChild(del->L_Child);

        if (L.first == L.last) {
            L.first = L.last = NULL;
        } else {
            L.first = del->next;
            L.first->prev = NULL;
        }
        deallocNodeParent(del);
    }
}

void deleteAfterParent(listParent &L, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent del = NPrev->next;

        deleteListChild(del->L_Child);

        NPrev->next = del->next;
        if (del->next != NULL)
            del->next->prev = NPrev;
        else
            L.last = NPrev;

        deallocNodeParent(del);
    }
}

// INSERT CHILD
void insertFirstChild(listChild &L, NodeChild newNode) {
    if (isEmptyChild(L)) {
        L.first = L.last = newNode;
    } else {
        newNode->next = L.first;
        L.first->prev = newNode;
        L.first = newNode;
    }
}

void insertLastChild(listChild &L, NodeChild newNode) {
    if (isEmptyChild(L)) {
        insertFirstChild(L, newNode);
    } else {
        L.last->next = newNode;
        newNode->prev = L.last;
        L.last = newNode;
    }
}

// DELETE CHILD
void deleteFirstChild(listChild &L) {
    if (!isEmptyChild(L)) {
        NodeChild del = L.first;
        if (L.first == L.last) {
            L.first = L.last = NULL;
        } else {
            L.first = del->next;
            L.first->prev = NULL;
        }
        deallocNodeChild(del);
    }
}

void deleteAfterChild(listChild &L, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild del = NPrev->next;
        NPrev->next = del->next;

        if (del->next != NULL)
            del->next->prev = NPrev;
        else
            L.last = NPrev;

        deallocNodeChild(del);
    }
}

void deleteListChild(listChild &L) {
    while (!isEmptyChild(L)) {
        deleteFirstChild(L);
    }
}

// PRINT STRUCTURE
void printMLLStructure(listParent L) {
    NodeParent P = L.first;
    while (P != NULL) {
        cout << "Golongan: " << P->isidata.idGolongan
             << " - " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        while (C != NULL) {
            cout << "   > " << C->isidata.idHewan
                 << " | " << C->isidata.namaHewan
                 << " | Habitat: " << C->isidata.habitat
                 << " | Ekor: " << (C->isidata.ekor ? "True" : "False")
                 << " | Bobot: " << C->isidata.bobot << endl;
            C = C->next;
        }
        cout << endl;
        P = P->next;
    }
}

// SEARCH HEWAN TANPA EKOR
void searchHewanByEkor(listParent L, bool tail) {
    cout << "HASIL PENCARIAN HEWAN DENGAN EKOR = "
         << (tail ? "TRUE" : "FALSE") << endl;

    NodeParent P = L.first;
    while (P != NULL) {
        NodeChild C = P->L_Child.first;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << C->isidata.idHewan
                     << " | " << C->isidata.namaHewan
                     << " | " << C->isidata.habitat
                     << " | Bobot: " << C->isidata.bobot << endl;
            }
            C = C->next;
        }
        P = P->next;
    }
    cout << endl;
}
```

Pada Unguided 1 ini, program membangun struktur Multi Linked List untuk mengelompokkan hewan berdasarkan golongannya. Bagian parent menyimpan data golongan hewan seperti ID dan nama golongan, sementara child menyimpan data hewan lengkap seperti nama hewan, habitat, ada ekor atau tidak, dan bobot.

Program menyediakan fungsi dasar untuk membuat list parent/child, mengecek apakah list kosong, serta alokasi node baru untuk parent dan child. Untuk operasi parent, program menyediakan insert di awal, insert di akhir, dan delete setelah node tertentu. Child juga memiliki operasi yang sama, sehingga setiap parent bisa memiliki list hewan masing-masing.

Selain itu, ada fungsi untuk menghapus seluruh child milik satu parent ketika parent dihapus. Program juga memiliki fitur untuk mencetak struktur MLL sehingga semua golongan dan hewan di dalamnya bisa terlihat. Terakhir, disediakan fungsi pencarian hewan berdasarkan kondisi punya ekor atau tidak (true/false), sehingga user bisa melihat daftar hewan yang memenuhi kriteria tersebut.

Secara keseluruhan, Unguided 1 ini fokus pada pembuatan struktur dasar MLL hewan lengkap dengan insert, delete, print, dan pencarian.

### 3. Main.cpp

```C++
#include "MultiLL.h"

int main() {
    listParent L;
    createListParent(L);

    // --- INSERT PARENT ---
    insertLastParent(L, allocNodeParent("G001", "Aves"));
    insertLastParent(L, allocNodeParent("G002", "Mamalia"));
    insertLastParent(L, allocNodeParent("G003", "Pisces"));
    insertLastParent(L, allocNodeParent("G004", "Amfibi"));
    insertLastParent(L, allocNodeParent("G005", "Reptil"));

    // POINTER PARENT
    NodeParent P = L.first;

    // G001
    insertLastChild(P->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    // G002
    P = P->next;
    insertLastChild(P->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(P->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(P->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    // G003 -> kosong

    // G004
    P = P->next->next;
    insertLastChild(P->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    // CETAK STRUKTUR AWAL
    cout << "=== PRINT AWAL ===" << endl;
    printMLLStructure(L);

    // SEARCH HEWAN TANPA EKOR
    searchHewanByEkor(L, false);

    // DELETE G004
    cout << "=== DELETE G004 ===" << endl;
    P = L.first->next->next; // G001 -> G002 -> G003 -> G004
    deleteAfterParent(L, P);

    // CETAK SETELAH DELETE
    printMLLStructure(L);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan13_Modul13/image13/Output-Unguided1-Modul13-1.png)

Pada program Unguided ini, kita membuat struktur Multi Linked List yang berisi golongan hewan sebagai parent dan data hewan sebagai child. Program dimulai dengan membuat list parent kosong menggunakan createListParent().

Pertama, program memasukkan lima golongan hewan (Aves, Mamalia, Pisces, Amfibi, Reptil) sebagai node parent menggunakan insertLastParent(). Setelah itu, pointer parent (P) digunakan untuk mengisi setiap golongan dengan child­-nya masing-masing.
Misalnya golongan Aves diisi hewan “Cendrawasih” dan “Bebek”, Mamalia berisi Harimau, Gorila, dan Kucing, sedangkan Pisces dikosongkan. Golongan Amfibi diisi Kodok, sedangkan Reptil belum diisi.

Setelah data terisi, program mencetak seluruh struktur MLL menggunakan printMLLStructure(), sehingga semua golongan beserta hewannya tampil di layar. Setelah itu dilakukan pencarian hewan berdasarkan kondisi memiliki ekor atau tidak melalui fungsi searchHewanByEkor(L, false), untuk menampilkan hewan yang tidak memiliki ekor (misalnya Kodok atau Gorila).

Program juga menguji operasi penghapusan parent menggunakan deleteAfterParent(). Pada bagian ini, parent G004 (Amfibi) dihapus beserta seluruh child yang dimilikinya. Setelah penghapusan, struktur MLL dicetak kembali untuk memastikan node parent dan child yang terhapus benar-benar hilang.

Secara keseluruhan, program ini menunjukkan cara membuat, mengisi, mencari, dan menghapus data dalam Multi Linked List sesuai ketentuan modul.

## Kesimpulan
Pada praktikum modul ini, saya memahami bahwa Multi Linked List adalah struktur data yang digunakan untuk menangani hubungan induk–anak secara lebih teratur dan fleksibel. Setiap elemen induk dapat memiliki list anak sendiri, sehingga data yang saling berhubungan bisa tersimpan dengan rapi tanpa tercampur dengan data lain. Melalui implementasi insert, delete, dan traversal, saya belajar bagaimana mengelola struktur hierarki ini dengan pointer serta memastikan setiap operasi tetap konsisten.

Selain itu, dari latihan circular linked list, saya juga memahami cara membuat list yang elemen terakhirnya menunjuk kembali ke elemen pertama, sehingga proses traversal dapat berputar tanpa henti. Praktikum ini memberikan pengalaman langsung dalam membangun dan memodifikasi struktur data dinamis, sekaligus memperkuat pemahaman dasar manajemen memori dan penggunaan pointer pada C++.

## Referensi
<br>[1] Palimbo, M., Baharuddin, F., & Wijaya, A. (2021). Struktur Data: Konsep dan Implementasi. Jurnal Teknologi Informasi.
[2] Nugroho, S. A., & Rachmat, R. (2020). “Pemanfaatan Multi Linked List dalam Pengelolaan Data Hirarki.” Jurnal Sistem Informasi, 6(2).
[3] Shebani, R. G., et al. (2019). “Advanced Linked List Structures for Hierarchical Data.” IEEE Xplore.
