#include <iostream>
#include "DLLPlaylist.h"
using namespace std;

int main(){
    List L;
    createList(L);

    Song s1 = {"Senja di Kota", "Nona Binar", 370, 1500, 4.2};
    Song s2 = {"Lengkapimu", "D'Masiv", 185, 320, 4.0};
    Song s3 = {"Hujan Minggu", "Aria", 240, 90, 3.9};

    insertLast(L, allocate(s1));
    insertLast(L, allocate(s2));
    insertLast(L, allocate(s3));

    cout << "\n== LIST AWAL ==\n";
    printList(L);

    deleteLast(L);

    cout << "\n== SETELAH deleteLast ==\n";
    printList(L);

    Song upd = {"Pelita", "Rafanda", 200, 250, 4.3};
    updateAtPosition(L, 2, upd);

    cout << "\n== SETELAH UPDATE POS 2 ==\n";
    printList(L);

    Song before1 = {"Melamundu", "Hendra", 175, 120, 4.1};
    insertBefore(L, 2, before1);

    cout << "\n== SETELAH INSERT BEFORE POS 2 ==\n";
    printList(L);

    Song upBefore = {"Melody", "Helena", 199, 210, 4.0};
    updateBefore(L, 2, upBefore);

    cout << "\n== UPDATE BEFORE POS 2 ==\n";
    printList(L);

    deleteBefore(L, 3);
    cout << "\n== DELETE BEFORE POS 3 ==\n";
    printList(L);

    cout << "\n== HASIL SEARCH POPULARITY 160 - 300 ==\n";
    searchPopularity(L, 160, 300);

    return 0;
}