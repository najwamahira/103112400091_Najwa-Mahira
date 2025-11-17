#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main() {

    StackMahasiswa S;
    createStack(S);

    cout << "Stack dibuat.\n";

    Mahasiswa M;

    M = {"Venti", 11111, 75.7, 89.5, 90.5};
    push(S, M);

    M = {"Xiao", 22222, 87.4, 92.8, 91.6};
    push(S, M);

    M = {"Lynette", 55555, 77.7, 79.4, 78.9};
    push(S, M);

    M = {"Chasca", 66666, 99.8, 99.3, 97.5};
    push(S, M);

    printStack(S);

    Mahasiswa temp;
    pop(S, temp);

    cout << "\nSetelah 1x Pop:\n";
    printStack(S);

    M = {"Heizou", 77777, 89.9, 95.5, 87.0};
    updateAtPosition(S, 3, M);

    cout << "\nSetelah Update posisi ke-3:\n";
    printStack(S);

    searchNilaiAkhir(S, 85.5, 95.5);

    return 0;
}