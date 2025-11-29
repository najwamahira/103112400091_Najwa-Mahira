# <h1 align="center">Laporan Praktikum Modul 10 - TREE (BAGIAN PERTAMA)</h1>
<p align="center">Najwa Mahira - 103112400091</p>

## Dasar Teori
Pada modul ini dibahas mengenai konsep fungsi rekursif serta implementasinya pada struktur data Tree, khususnya Binary Search Tree (BST). Kedua konsep ini memiliki hubungan yang kuat karena banyak operasi pada tree seperti traversal, pencarian, dan penghapusan node sangat bergantung pada pola pemanggilan berulang yang mengikuti struktur hirarki tree. Teknik rekursif membantu menyederhanakan proses tersebut karena setiap subtree pada dasarnya merupakan permasalahan dengan struktur yang sama tetapi berukuran lebih kecil. Dengan memahami rekursif dan tree secara bersamaan, mahasiswa dapat melihat bagaimana data non-linear dapat dikelola secara efisien menggunakan pendekatan pemrograman yang bersifat bertingkat [1][2].

### A. Rekursif<br/>
Rekursif adalah teknik pemrograman di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan bagian dari masalah yang bentuknya serupa dengan masalah utama. Pendekatan ini mempermudah penulisan algoritma yang memiliki pola berulang, seperti perhitungan matematis dan penelusuran struktur data bertingkat. Dengan adanya pemecahan masalah menjadi bentuk yang lebih kecil, rekursif memungkinkan implementasi logika yang lebih ringkas dan mendekati ekspresi matematikanya. Namun, penggunaan rekursif juga perlu diperhatikan karena setiap pemanggilan akan menambah beban memori dan waktu eksekusi akibat penyimpanan stack frame yang terus bertambah [3].
#### 1. Karakteristik Rekursif
Karakteristik utama dari rekursif adalah adanya base case dan recursive call. Base case berfungsi sebagai kondisi penghentian agar pemanggilan fungsi tidak berjalan tanpa batas. Base case ini harus selalu menghasilkan nilai pasti tanpa memanggil fungsi yang sama lagi. Sementara itu, recursive call merupakan bagian fungsi yang melakukan pemanggilan diri sendiri untuk menyelesaikan bagian masalah yang lebih kecil. Dengan adanya kedua elemen ini, proses rekursif dapat berjalan secara bertahap mulai dari pemecahan masalah menjadi bagian-bagian kecil sampai akhirnya kembali menyatukan hasilnya ketika proses unwinding dilakukan. Pola demikian membuat struktur rekursif sangat cocok untuk persoalan yang bentuk penyelesaiannya bersifat berulang dan menurun secara bertingkat. [1]
#### 2. Kelebihan Rekursif
Kelebihan utama rekursif terletak pada kemampuan menyederhanakan struktur kode. Banyak algoritma yang secara matematis atau logis memang memiliki pola yang berulang dan rekursif, sehingga menerapkannya langsung dalam bentuk rekursif membuat program menjadi jauh lebih ringkas dan mudah dipahami. Representasi ini juga sangat membantu dalam algoritma yang menelusuri struktur bertingkat seperti tree, fractal, atau perhitungan kombinatorial. Selain itu, pola rekursif memungkinkan programmer menulis solusi yang bersih tanpa perlu mengelola banyak variabel perulangan atau kondisi rumit yang biasanya ditemui pada pendekatan iteratif. [2]
#### 3. Kekurangan Rekursif
Walaupun sederhana secara penulisan, rekursif memiliki kelemahan pada penggunaan memori dan waktu eksekusi. Setiap kali fungsi memanggil dirinya sendiri, komputer harus menyimpan informasi fungsi sebelumnya di dalam stack frame. Semakin banyak pemanggilan rekursif, semakin besar pula memori yang dipakai. Selain itu, proses keluar-masuk fungsi yang dilakukan berkali-kali menyebabkan eksekusi lebih lambat dibanding pendekatan iteratif yang hanya menggunakan perulangan. Pada kasus tertentu yang membutuhkan efisiensi tinggi, rekursif harus dipertimbangkan dengan hati-hati agar tidak menimbulkan stack overflow atau pemborosan sumber daya. [3]

### B. Tree<br/>
Tree adalah struktur data non-linear dengan bentuk hierarki yang terdiri dari node-node yang saling terhubung melalui relasi parent–child. Struktur seperti ini memungkinkan data tersusun dalam bentuk bertingkat yang tidak dapat direpresentasikan secara efektif menggunakan struktur linear seperti array atau linked list biasa. Setiap node dalam tree dapat memiliki satu atau lebih anak, dan node yang tidak memiliki anak disebut leaf. Tree digunakan dalam banyak aplikasi komputasi seperti sistem file, struktur indeks, dan algoritma pencarian karena kemampuannya mengatur data secara terstruktur dan mudah diakses [4][5].
#### 1. Binary Tree
Binary Tree merupakan struktur yang membatasi setiap node hanya memiliki maksimal dua anak, yaitu left child dan right child. Batasan ini membuat struktur tree menjadi lebih teratur dan memudahkan dalam penerapan berbagai algoritma seperti traversal dan pencarian. Bentuknya yang terstruktur secara dua arah membuat proses penelusuran lebih mudah diatur dibanding tree umum yang bisa memiliki banyak cabang dalam satu node. Selain itu, binary tree menjadi dasar dari banyak struktur data penting lainnya seperti Binary Search Tree, Heap, dan AVL Tree. [4]
#### 2. Binary Search Tree (BST)
Binary Search Tree menerapkan aturan khusus pada setiap node, di mana nilai pada anak kiri harus lebih kecil daripada nilai parent, sedangkan nilai pada anak kanan harus lebih besar. Aturan sederhana ini menghasilkan struktur tree yang secara alami terurut, sehingga operasi pencarian dapat dilakukan jauh lebih cepat karena setiap perbandingan memungkinkan kita langsung membuang setengah kemungkinan pencarian. Dengan demikian, BST mampu memberikan performa pencarian yang lebih efisien dibanding struktur linear yang harus memeriksa elemen satu per satu. Selain pencarian, operasi penyisipan dan penghapusan juga mengikuti aturan ini sehingga struktur terurut tetap terjaga. [5]
#### 3. Traversal Tree
Traversal pada tree dilakukan untuk membaca atau mengunjungi setiap node dalam urutan tertentu. Tiga metode utama—pre-order, in-order, dan post-order—menghasilkan urutan pembacaan yang berbeda sesuai kebutuhan. Pada pre-order, tree dibaca mulai dari root sehingga cocok untuk menyalin struktur tree. Pada in-order, pembacaan dilakukan dari subtree kiri, kemudian root, lalu subtree kanan, sehingga bila diterapkan pada BST akan menghasilkan data yang terurut. Sedangkan post-order membaca anak terlebih dahulu baru root, sehingga metode ini umum digunakan untuk operasi penghapusan karena memastikan seluruh subtree sudah dihapus sebelum node induknya. [6]

## Guided 

### 1. bst.h

```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node;   // alias pointer = node

struct BST {                // nama struct nya BST
    int angka;
    node left;
    node right;
};

typedef node BinTree;       // alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void deAlokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```
Bagian awal file ini mendefinisikan struktur dan fungsi yang digunakan untuk membangun dan mengelola sebuah Binary Search Tree. Pertama, dibuat sebuah alias bernama node yang merupakan pointer menuju struct BST. Struktur BST sendiri berisi tiga elemen, yaitu sebuah nilai bertipe integer sebagai data utama, serta dua pointer yang menunjuk ke anak kiri dan anak kanan. Agar lebih mudah digunakan, pointer tersebut juga diberi alias baru bernama BinTree, yang mewakili root dari keseluruhan pohon.

Selanjutnya, terdapat sejumlah deklarasi fungsi. Fungsi isEmpty digunakan untuk memeriksa apakah tree masih kosong. Fungsi createTree berfungsi menginisialisasi tree dengan nilai awal kosong. Kemudian, fungsi alokasi membuat node baru dengan data tertentu, sementara fungsi deAlokasi bertugas menghapus node dari memori.

Fungsi insertNode digunakan untuk memasukkan node baru ke dalam tree sesuai aturan Binary Search Tree. Fungsi searchByData dipakai untuk mencari data tertentu di dalam tree. Tiga fungsi traversal yaitu preOrder, inOrder, dan postOrder berperan untuk menelusuri dan menampilkan isi tree dalam urutan yang berbeda.

Selain itu, terdapat fungsi deleteNode yang digunakan untuk menghapus node berdasarkan nilai tertentu. Fungsi mostRight dan mostLeft digunakan untuk menemukan node paling kanan atau paling kiri, biasanya dibutuhkan ketika proses penghapusan node berlangsung. Fungsi deleteTree akan menghapus seluruh isi tree secara rekursif. Terakhir, fungsi size digunakan untuk menghitung jumlah seluruh node dalam tree, dan fungsi height berfungsi menentukan tinggi atau kedalaman tree dari root sampai ke node terdalam.

### 2. bst.cpp

```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```
File ini berisi seluruh implementasi fungsi yang digunakan untuk mengelola Binary Search Tree. Fungsi isEmpty digunakan untuk mengecek apakah tree kosong, sedangkan createTree berfungsi menginisialisasi tree agar bernilai kosong. Fungsi alokasi membuat node baru dengan nilai tertentu, dan dealokasi menghapus node dari memori ketika sudah tidak diperlukan.

Fungsi insertNode menangani proses memasukkan node baru ke dalam tree sesuai aturan BST, yaitu nilai yang lebih kecil menuju anak kiri dan nilai lebih besar menuju anak kanan. Fungsi searchByData digunakan untuk mencari sebuah angka di dalam tree, sekaligus menampilkan informasi seperti parent, sibling, dan child dari node yang ditemukan.

Tiga fungsi traversal—pre-order, in-order, dan post-order—digunakan untuk menampilkan isi tree dalam urutan yang berbeda. Selanjutnya, fungsi deleteNode berfungsi menghapus node berdasarkan nilai yang dicari dengan menangani empat kemungkinan kasus: leaf, memiliki satu child kiri, satu child kanan, atau dua child. Fungsi mostLeft dan mostRight mencari node paling kiri atau kanan yang diperlukan ketika penghapusan kasus dua child terjadi.

Fungsi deleteTree menghapus seluruh node secara rekursif. Fungsi size menghitung jumlah node dalam tree, sedangkan height menentukan tinggi atau level terdalam dari tree.

### 3. main.cpp

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
File ini berfungsi sebagai program utama yang menjalankan seluruh operasi Binary Search Tree. Di awal program, sebuah tree dibuat dalam keadaan kosong menggunakan fungsi createTree. Selanjutnya, program menampilkan menu interaktif yang memungkinkan pengguna memilih berbagai operasi seperti memasukkan node, menghapus node, mencari data, menampilkan traversal, serta melihat ukuran dan tinggi tree.

Ketika pengguna memilih memasukkan data, program akan meminta angka lalu memasukkannya ke dalam tree melalui fungsi insertNode. Jika pengguna ingin menghapus data, program memanggil deleteNode dan menampilkan apakah proses penghapusan berhasil atau tidak. Untuk pencarian data, program menggunakan searchByData dan menunjukkan informasi lengkap mengenai node yang ditemukan.

Program juga menyediakan fitur untuk menampilkan tree dalam urutan pre-order, in-order, dan post-order. Selain itu, terdapat menu untuk menampilkan jumlah node, tinggi tree, node paling kanan, node paling kiri, serta menghapus seluruh isi tree menggunakan fungsi deleteTree. Program akan terus berulang hingga pengguna memilih opsi keluar.

## Unguided 

### 1. bstree.h

```C++
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

typedef int infotype;

struct Node {
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;

/* Alokasi node baru */
address alokasi(infotype x);

/* Insert node ke BST */
void insertNode(address &root, infotype x);

/* Mencari node */
address findNode(address root, infotype x);

/* Traversal In-order */
void InOrder(address root);

/* Traversal Pre-order */
void PreOrder(address root);

/* Traversal Post-order */
void PostOrder(address root);

/* Latihan 2 */
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int depth);

#endif
```

File bstree.h berfungsi sebagai header file yang berisi semua deklarasi yang dibutuhkan oleh program utama dan file implementasi. Di dalamnya terdapat definisi struktur data Node, yang dipakai untuk membentuk Binary Search Tree. Selain itu, file ini juga berisi daftar prototype atau deklarasi fungsi‐fungsi seperti fungsi insert, pencarian, traversal, perhitungan jumlah node, kedalaman, dan lainnya. Dengan adanya header ini, file lain seperti main.cpp dan bstree.cpp bisa saling terhubung tanpa harus menuliskan ulang deklarasi. File ini memastikan struktur program tetap rapi dan semua komponen BST dikenali oleh compiler.

### 2. bstree.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    } 
}

address findNode(address root, infotype x) {
    if (root == Nil)
        return Nil;
    else if (x == root->info)
        return root;
    else if (x < root->info)
        return findNode(root->left, x);
    else
        return findNode(root->right, x);
}

void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

void PreOrder(address root) {
    if (root != Nil) {
        cout << root->info << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(address root) {
    if (root != Nil) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->info << " ";
    }
}

/* Latihan 2 */

int hitungJumlahNode(address root) {
    if (root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == Nil) return 0;
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int depth) {
    if (root == Nil) return depth - 1;
    int leftDepth  = hitungKedalaman(root->left, depth + 1);
    int rightDepth = hitungKedalaman(root->right, depth + 1);
    return max(leftDepth, rightDepth);
}
```

File bstree.cpp berisi implementasi lengkap dari seluruh fungsi yang sudah dideklarasikan dalam bstree.h. Semua logika program seperti memasukkan data ke tree, menelusuri node, menghitung total informasi, mengukur kedalaman tree, maupun menjalankan traversal in-order, pre-order, dan post-order, semuanya ditulis di file ini. Dengan memisahkan implementasi ke file khusus, program menjadi lebih terstruktur, mudah dibaca, dan lebih mudah dikelola. File ini juga kemudian dikompilasi bersama main.cpp agar seluruh fungsi BST dapat dijalankan.

### 3. main.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    cout << "In-order: ";
    InOrder(root);

    cout << "\nPre-order: ";
    PreOrder(root);

    cout << "\nPost-order: ";
    PostOrder(root);

    cout << "\n\nKedalaman Tree: " << hitungKedalaman(root, 0);
    cout << "\nJumlah Node: " << hitungJumlahNode(root);
    cout << "\nTotal Info: " << hitungTotalInfo(root);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan10_Modul10/image10/Output-Unguided1-Modul10-1.png)

File main.cpp merupakan bagian program yang menjalankan keseluruhan operasi BST yang sudah dibuat. Di dalamnya, root tree dibuat dan beberapa nilai dimasukkan menggunakan fungsi insert. Setelah itu, berbagai fungsi seperti traversal in-order, pre-order, dan post-order dipanggil untuk menampilkan isi tree sesuai urutan tertentu. Pada bagian ini juga dilakukan pemanggilan fungsi untuk menghitung jumlah node, total nilai di dalam tree, serta kedalamannya. File main.cpp berfungsi sebagai pengontrol utama untuk menguji dan menampilkan hasil dari semua fungsi yang berada pada bstree.cpp.

## Kesimpulan
Pada praktikum ini dipelajari penerapan konsep rekursif dalam struktur data Tree, terutama Binary Search Tree. Rekursif digunakan pada operasi seperti penyisipan, pencarian, penghapusan, dan traversal. BST memiliki aturan pengurutan alami sehingga mampu memberikan efisiensi pada proses pencarian data. Melalui modul ini, pemahaman mengenai pembentukan tree, peran rekursif, serta teknik traversal semakin kuat untuk diaplikasikan pada permasalahan yang melibatkan struktur data hierarki.

## Referensi
<br>[1] Y. Feng, et al. 2021. Recursive Function Optimization in Programming. Journal of Computer Science Research.
<br>[2] Sedgewick, R. & Wayne, K. 2014. Algorithms (4th Edition). Addison-Wesley.
<br>[3] Knuth, D. 1998. The Art of Computer Programming Volume 1: Fundamental Algorithms. Addison-Wesley.
<br>[4] Aho, A., Hopcroft, J., & Ullman, J. 2019. Data Structures and Algorithms. Pearson.
<br>[5] Weiss, M.A. 2012. Data Structures and Algorithm Analysis in C++. Pearson.
