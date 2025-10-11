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
