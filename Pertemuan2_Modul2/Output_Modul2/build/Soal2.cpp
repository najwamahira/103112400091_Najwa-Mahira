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
