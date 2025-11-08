# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>
<p align="center">Najwa Mahira - 103112400091</p>

## Dasar Teori
Stack merupakan struktur data linear yang menerapkan prinsip Last In First Out (LIFO), artinya elemen terakhir yang dimasukkan ke dalam stack akan menjadi elemen pertama yang dikeluarkan [1]. Struktur ini banyak digunakan dalam berbagai bidang ilmu komputer karena efisien untuk proses yang memerlukan penyimpanan data sementara, seperti pemanggilan fungsi rekursif dan pengelolaan memori program [2].

Struktur data stack termasuk dalam kategori Abstract Data Type (ADT), yaitu tipe data yang mendefinisikan perilaku operasi tanpa memperlihatkan detail implementasinya [3]. Dalam konteks pemrograman, stack dapat diimplementasikan menggunakan array atau linked list tergantung pada kebutuhan efisiensi memori dan fleksibilitas ukuran data [4].

### A. Konsep Dasar Stack<br/>
Stack merupakan salah satu struktur data dasar yang berfungsi menyimpan sekumpulan elemen secara terurut dengan metode LIFO (Last In First Out) [1]. Dalam penerapannya, elemen baru selalu ditambahkan di bagian atas tumpukan, sedangkan elemen yang dikeluarkan juga berasal dari posisi yang sama. Prinsip ini memungkinkan kontrol penuh terhadap urutan data yang dimasukkan dan dikeluarkan.
#### 1. Definisi
Secara konseptual, stack dapat diibaratkan seperti tumpukan piring, di mana piring terakhir yang diletakkan di atas adalah yang pertama kali diambil. Dalam pemrograman, struktur ini digunakan untuk menyimpan data sementara, alamat fungsi, atau ekspresi yang sedang diproses [2]. Stack menjadi bagian penting dalam alur kerja sistem komputer karena kemampuannya mengelola urutan data secara efisien dan logis.
#### 2. Fungsi
Fungsi utama stack adalah mengatur data yang memiliki urutan pengaksesan terbalik. Contohnya, dalam pemanggilan fungsi bersarang (nested function), setiap fungsi yang dipanggil akan disimpan di stack, lalu dieksekusi secara berurutan ketika fungsi sebelumnya selesai. Stack juga berperan dalam pemrosesan ekspresi matematika, seperti konversi infix ke postfix dan evaluasi hasil perhitungan [3]. Selain itu, dalam sistem operasi, stack membantu menyimpan konteks program saat terjadi interupsi, sehingga proses dapat dilanjutkan dari titik terakhir tanpa kehilangan data.
#### 3. Karakteristik
Stack memiliki beberapa karakteristik penting [4]:
1. Data hanya dapat ditambah atau dihapus melalui satu ujung (top).
2. Elemen pertama yang masuk menjadi elemen terakhir yang keluar.
3. Terdapat kondisi overflow (penuh) dan underflow (kosong).
4. Bersifat tertutup, karena tidak dapat diakses secara acak seperti array biasa.
Karakteristik ini menjadikan stack efisien dalam proses yang memerlukan pelacakan data secara berurutan dan sistematis.

### B. Representasi Stack<br/>
Stack dapat diimplementasikan menggunakan dua bentuk utama, yaitu berbasis array (statis) dan berbasis pointer (dinamis). Keduanya memiliki kelebihan dan kekurangan masing-masing dalam hal efisiensi memori, kompleksitas, dan kecepatan akses [2].
#### 1. Representasi Array
Stack yang diimplementasikan dengan array bersifat statis karena ukuran maksimum sudah ditentukan sejak awal [4]. Setiap elemen disimpan di dalam indeks array, dengan variabel Top menunjukkan posisi elemen paling atas [1]. Kelebihan metode ini terletak pada kemudahan pengaksesan data dan kecepatan operasi, namun kelemahannya adalah tidak fleksibel dalam hal kapasitas [2].

Selain itu, penggunaan array sangat cocok pada sistem yang memerlukan struktur sederhana dan kapasitas data tetap seperti evaluasi ekspresi postfix [3].
#### 2. Representasi Pointer (Linked List)
Pada representasi ini, stack dibentuk dari simpul-simpul (node) yang saling terhubung menggunakan pointer [4]. Setiap simpul berisi nilai data (info) dan penunjuk (next) ke simpul berikutnya [1]. Keuntungan representasi ini adalah kapasitasnya yang dinamis karena dapat menyesuaikan jumlah elemen selama program berjalan [2]. Namun, pengelolaan memori lebih kompleks dibandingkan implementasi berbasis array [3].

### C. Operasi Utama Stack<br/>
Stack memiliki beberapa operasi dasar yang menjadi pondasi utama dalam pengelolaan datanya. Operasi-operasi ini dirancang untuk menjaga prinsip LIFO dan memastikan integritas data selama proses berlangsung [1].
#### 1. Push
Operasi push digunakan untuk menambahkan elemen baru ke bagian atas stack. Sebelum elemen dimasukkan, program harus memeriksa apakah stack masih memiliki ruang kosong. Jika stack sudah penuh, maka akan terjadi kondisi overflow [2]. Proses push biasanya dilakukan dengan menaikkan nilai top lalu menyimpan data baru pada posisi tersebut.
#### 2. Pop
Operasi pop digunakan untuk menghapus elemen dari bagian atas stack dan mengembalikannya sebagai hasil keluaran [3]. Sebelum melakukan pop, sistem akan memeriksa apakah stack kosong. Jika tidak ada elemen sama sekali, maka terjadi kondisi underflow. Operasi ini sering digunakan dalam proses pembatalan (undo) atau backtracking.
#### 3. Peek
Operasi peek atau top digunakan untuk melihat isi elemen paling atas tanpa menghapusnya [4]. Fungsi ini berguna ketika program hanya perlu memeriksa nilai terakhir yang dimasukkan tanpa memengaruhi susunan data di dalam stack.
#### 4. Balik Stack
Operasi ini digunakan untuk membalik urutan seluruh elemen dalam stack. Biasanya menggunakan satu stack tambahan sebagai penampung sementara. Setelah semua elemen dipindahkan, urutannya menjadi terbalik sempurna [1]. Operasi ini sering digunakan pada pemrosesan teks, seperti membalikkan urutan huruf atau kata.
Selain operasi dasar di atas, banyak varian lain yang dapat ditambahkan sesuai kebutuhan, misalnya clear() untuk menghapus seluruh isi stack atau size() untuk menghitung jumlah elemen yang tersimpan.

### D. Penerapan Stack<br/>
Stack merupakan salah satu struktur data yang paling banyak diaplikasikan dalam dunia pemrograman modern [2]. Karena kemampuannya dalam mengatur urutan data, stack digunakan untuk menyelesaikan berbagai masalah logika dan algoritma.
#### 1. Pemanggilan Fungsi Rekursif
Dalam sistem rekursif, setiap kali sebuah fungsi memanggil dirinya sendiri, alamat pengembalian (return address) disimpan di stack [1]. Setelah fungsi selesai, sistem akan kembali ke alamat tersebut dan melanjutkan proses sesuai urutan semula. Tanpa stack, sistem tidak akan mampu melacak urutan pemanggilan fungsi dengan benar.
#### 2. Evaluasi Ekspresi Postfix
Stack digunakan dalam konversi dan evaluasi ekspresi matematika dari bentuk infix ke postfix. Proses ini memungkinkan komputer mengeksekusi perhitungan tanpa perlu memperhatikan prioritas operator secara manual [3].
#### 3. Fitur Undo/Redo
Dalam aplikasi seperti Microsoft Word atau Photoshop, setiap tindakan pengguna disimpan di dalam stack. Ketika tombol Undo ditekan, aplikasi mengambil data terakhir dari stack untuk mengembalikan keadaan sebelumnya [2]. Dengan prinsip LIFO, perubahan terbaru selalu menjadi yang pertama dibatalkan.
#### 4. Navigasi Browser
Stack juga digunakan pada sistem navigasi web. Ketika pengguna membuka halaman baru, halaman sebelumnya disimpan dalam stack. Tombol Back akan mengambil halaman terakhir yang dikunjungi, sedangkan Forward akan mengembalikannya jika pengguna maju kembali [4].
Dengan berbagai penerapan tersebut, stack terbukti menjadi salah satu struktur data paling fundamental yang mendukung efisiensi pemrosesan, keteraturan data, dan kestabilan algoritma dalam pengembangan perangkat lunak.

## Guided 1

### 1. stack.h

```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```
Guided 1 menjelaskan implementasi **stack berbasis linked list** yang terdiri dari node dinamis dengan operasi dasar seperti membuat stack, menambah (push), menghapus (pop), menampilkan, memperbarui, dan mencari data pada tumpukan secara terurut dari elemen teratas.

### 2. stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
Kode ini mengimplementasikan ADT **stack** berbasis linked list lengkap dengan fungsi inisialisasi, pengecekan kosong, alokasi/dealokasi node, operasi `push`/`pop`, pembaruan nilai pada posisi tertentu, penampilan isi stack, dan pencarian data—serta menampilkan pesan status setiap operasi.

### 3. main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program **Guided 1** ini berfungsi untuk *mendemonstrasikan penggunaan operasi stack berbasis linked list*, yaitu proses **push (menambah data ke atas stack)**, **pop (menghapus data teratas)**, **update (mengubah isi node pada posisi tertentu)**, **view (menampilkan isi stack)**, dan **searchData (mencari nilai dalam stack)** secara berurutan untuk menunjukkan cara kerja prinsip **LIFO (Last In, First Out)** pada struktur stack.

## Guided 2

### 1. stack.h

```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```
Guided 2 ini berisi **deklarasi struktur dan fungsi stack berbasis array statis**, di mana elemen-elemen disimpan dalam *array berukuran tetap (`MAX`)* dengan penanda posisi puncak data (`top`); header ini menyiapkan operasi dasar seperti **membuat stack, menambah (push), menghapus (pop), memperbarui (update), menampilkan (view), dan mencari data (searchData)** untuk mengelola data secara **LIFO (Last In, First Out)** menggunakan indeks array.

### 2. stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    if(s.top == -1){
        return true;
    } else {
        return false;
    }
    //return s.top == -1;
}

bool isFull(stackTable s){
    if(s.top == MAX - 1){
        return true;
    } else {
        return false;
    }
    //return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s) == true){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    
    }
    if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
            return;
    }

    //indek = top - (posisi + 1)
    int idx = s.top - (posisi - 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << "tidak valid!" << endl;
        return;
    }

    cout << "update data pposisi ke- " << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; i--){
            cout << "Posisi " << (s.top - i + 1) << " : " << s.data[i] << endl;
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari data " << data << " dalam stack..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; i--){
         if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << (s.top - i + 1) << endl;
            found = true;
            break;
            }
            posisi++;
        }

        if(!found){
            cout << "Data " << data << " tidak ditemukan dalam stack!" << endl;
            cout << endl;
        }
    }
```
Program **Guided 2** ini mengimplementasikan struktur data **stack berbasis array statis** yang menggunakan variabel `top` sebagai penanda elemen teratas; program menyediakan fungsi-fungsi utama seperti **`push`** untuk menambah data ke puncak stack, **`pop`** untuk menghapus data teratas, **`update`** untuk mengubah nilai pada posisi tertentu, **`view`** untuk menampilkan isi stack dari atas ke bawah, dan **`searchData`** untuk mencari nilai dalam stack, semuanya bekerja mengikuti prinsip **LIFO (Last In, First Out)**.

### 3. main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    //posisi dihitung dari Top (1-based)

    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
Program **Guided 2 (main.cpp)** ini berfungsi untuk **mendemonstrasikan operasi stack berbasis array**, yaitu menambah data ke puncak stack dengan `push`, menghapus dua elemen teratas menggunakan `pop`, memperbarui nilai pada posisi tertentu dengan `update`, menampilkan isi stack menggunakan `view`, dan mencari data tertentu menggunakan `searchData`, sehingga memperlihatkan cara kerja prinsip **LIFO (Last In, First Out)** secara berurutan.

## Unguided 1

### 1. stack.h

```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

const int MAX_STACK = 20;

struct Stack {
    int info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, int x);
int pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

Unguided 1 ini mendefinisikan **struktur data stack menggunakan array statis** berkapasitas tetap (`MAX_STACK = 20`) dengan variabel `top` sebagai penanda elemen teratas, serta menyediakan fungsi dasar seperti **`createStack`** untuk inisialisasi, **`push`** untuk menambah data, **`pop`** untuk menghapus data teratas, **`printInfo`** untuk menampilkan isi stack, dan **`balikStack`** untuk membalik urutan elemen stack sesuai konsep **LIFO (Last In, First Out)**.

### 2. stack.cpp

```C++
#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

bool isEmpty(Stack S) {
    return S.top == 0;
}

bool isFull(Stack S) {
    return S.top == MAX_STACK;
}

void push(Stack &S, int x) {
    if (!isFull(S)) {
        S.info[S.top++] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

int pop(Stack &S) {
    if (!isEmpty(S)) {
        return S.info[--S.top];
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
```

Program **Unguided 1** ini mengimplementasikan operasi dasar pada **stack berbasis array**, di mana data dikelola menggunakan indeks `top` sebagai penanda posisi teratas; fungsi `push` menambah elemen baru, `pop` menghapus elemen paling atas, `printInfo` menampilkan isi stack dari atas ke bawah, dan `balikStack` membalik urutan elemen menggunakan stack sementara — semuanya bekerja mengikuti prinsip **LIFO (Last In, First Out)**.

### 3. main.cpp

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan7_Modul7/image7/Output-Unguided1-Modul7-1.png)

Program **Unguided 1 (main.cpp)** ini berfungsi untuk **mendemonstrasikan cara kerja stack berbasis array**, di mana beberapa elemen ditambahkan dengan `push`, sebagian dihapus dengan `pop`, lalu seluruh isi stack ditampilkan menggunakan `printInfo` dan dibalik urutannya memakai `balikStack`, sehingga memperlihatkan secara langsung prinsip **LIFO (Last In, First Out)** dalam penyimpanan dan pengambilan data.

## Unguided 2

### 1. stack.h

```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

const int MAX_STACK = 20;

struct Stack {
    int info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, int x);
int pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x); // Tambahan prosedur baru

#endif
```

Unguided 2 ini mendefinisikan struktur **stack berbasis array statis** yang dilengkapi dengan fungsi dasar seperti `push`, `pop`, `printInfo`, dan `balikStack`, serta menambahkan prosedur baru **`pushAscending`** yang berfungsi untuk **memasukkan elemen ke dalam stack secara berurutan menaik (ascending)** sehingga setiap data yang ditambahkan akan otomatis ditempatkan sesuai urutan nilainya tanpa melanggar prinsip dasar **LIFO (Last In, First Out)**.

### 2. stack.cpp

```C++
#include "stack.h"

void createStack(Stack &S) { S.top = 0; }
bool isEmpty(Stack S) { return S.top == 0; }
bool isFull(Stack S) { return S.top == MAX_STACK; }

void push(Stack &S, int x) {
    if (!isFull(S)) {
        S.info[S.top++] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

int pop(Stack &S) {
    if (!isEmpty(S)) {
        return S.info[--S.top];
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

// Prosedur tambahan untuk menambah elemen dengan urutan ascending
void pushAscending(Stack &S, int X) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top - 1] > X) {
        push(temp, pop(S));
    }

    push(S, X);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
```

Kode ini mengimplementasikan stack di C++ dengan operasi dasar seperti inisialisasi, pengecekan kosong/penuh, menambah (`push`) dan menghapus (`pop`) elemen, menampilkan isi stack, membalik urutannya, serta prosedur tambahan `pushAscending` yang menambahkan elemen sambil menjaga agar elemen tetap terurut menaik dari bawah ke atas.

### 3. main.cpp

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan7_Modul7/image7/Output-Unguided2-Modul7-1.png)

Program ini membuat sebuah stack kosong, kemudian menambahkan beberapa elemen menggunakan prosedur `pushAscending` sehingga elemen tetap terurut secara menaik dari bawah ke atas, menampilkan isi stack dari atas ke bawah, membalik urutan seluruh elemen stack menggunakan `balikStack`, dan akhirnya menampilkan kembali isi stack yang sudah dibalik sehingga urutan elemen berubah dari yang awalnya ascending menjadi descending dari atas ke bawah.

## Unguided 3

### 1. stack.h

```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

const int MAX_STACK = 20;

struct Stack {
    int info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, int x);
int pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x); // kalau sudah ada dari soal 2
void getInputStream(Stack &S);        // <-- tambah ini

#endif
```

Header ini mendefinisikan struktur stack dengan kapasitas maksimum, serta prototipe fungsi untuk operasi dasar stack, menambahkan elemen secara ascending, membalik stack, menampilkan isi, dan mengambil input dari pengguna.

### 2. stack.cpp

```C++
#include "stack.h"
#include <sstream>   // untuk istringstream

void createStack(Stack &S) { S.top = 0; }
bool isEmpty(Stack S) { return S.top == 0; }
bool isFull(Stack S) { return S.top == MAX_STACK; }

void push(Stack &S, int x) {
    if (!isFull(S)) {
        S.info[S.top++] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

int pop(Stack &S) {
    if (!isEmpty(S)) {
        return S.info[--S.top];
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void pushAscending(Stack &S, int X) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S) && S.info[S.top - 1] > X) {
        push(temp, pop(S));
    }
    push(S, X);
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

// Implementasi getInputStream: baca satu baris, parse integer per token, push ke stack
void getInputStream(Stack &S) {
    cout << "Masukkan angka (pisahkan dengan spasi), lalu Enter: ";
    string line;
    getline(cin, line);
    if (line.size() == 0) return; // tidak ada input
    istringstream iss(line);
    int val;
    while (iss >> val) {
        if (isFull(S)) {
            cout << "Stack penuh, sisa input diabaikan." << endl;
            break;
        }
        push(S, val);
    }
}
```

Kode ini mengimplementasikan semua fungsi dasar stack termasuk push, pop, cetak, balik, pushAscending, dan tambahan `getInputStream` yang membaca satu baris angka dari pengguna, mem-parse, dan menambahkannya ke stack sampai penuh.

### 3. main.cpp

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    // Demo getInputStream sesuai soal
    getInputStream(S);    // user mengetik: 5 7 2 9  (misal)
    cout << "Isi stack setelah input (sebelum dibalik):" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Isi stack setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/najwamahira/103112400091_Najwa-Mahira/blob/main/Pertemuan7_Modul7/image7/Output-Unguided3-Modul7-1.png)

Program ini membuat sebuah stack kosong, kemudian menggunakan fungsi `getInputStream` untuk meminta pengguna memasukkan satu baris angka yang dipisahkan spasi dan menambahkannya ke stack, setelah itu menampilkan isi stack dari atas ke bawah sebelum dibalik, membalik urutan seluruh elemen stack menggunakan `balikStack`, dan akhirnya menampilkan kembali isi stack yang sudah dibalik sehingga urutan elemen berubah dari input awal menjadi terbalik dari atas ke bawah.

## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa stack merupakan struktur data linear dengan prinsip kerja Last In First Out (LIFO), di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dikeluarkan. Melalui penerapan berbagai operasi seperti push, pop, dan balikStack, stack dapat digunakan untuk mengelola data secara efisien terutama pada proses yang membutuhkan urutan terbalik.

Implementasi stack berbasis array memberikan kemudahan dalam pengelolaan data dengan akses indeks yang cepat, sedangkan stack berbasis pointer menawarkan fleksibilitas ukuran yang lebih dinamis.

Selain itu, pengembangan fungsi seperti pushAscending dan getInputStream memperluas kemampuan stack agar tidak hanya berfungsi sebagai tempat penyimpanan sementara, tetapi juga dapat mengatur data secara terurut dan menerima masukan secara dinamis. Dengan memahami konsep dasar serta implementasi praktisnya, mahasiswa diharapkan mampu menerapkan struktur data stack dalam berbagai konteks pemrograman dan penyelesaian masalah logika komputasi.

## Referensi
<br>[1] Susanti, R. (2021). Analisis Implementasi Struktur Data Stack dalam Pengolahan Data Rekursif. Jurnal Teknologi dan Sistem Informasi Indonesia, 10(2).
<br>[2] Ramadhan, D., & Fadhilah, A. (2022). Implementasi Struktur Data Stack pada Aplikasi Undo/Redo Menggunakan Bahasa C++. Jurnal Ilmiah Informatika dan Komputer, 8(1).
<br>[3] Setiawan, M. (2023). Pemanfaatan Struktur Data Stack untuk Evaluasi Ekspresi Postfix. Jurnal Sistem dan Teknologi Informasi, 9(3).
<br>[4] Wulandari, S., & Hartono, Y. (2020). Penerapan Struktur Data Stack untuk Optimasi Algoritma Depth First Search (DFS). Jurnal Sains Komputer Indonesia, 7(4).
