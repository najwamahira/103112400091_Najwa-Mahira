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
