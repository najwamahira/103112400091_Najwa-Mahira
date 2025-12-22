#include "mll.h"

int main() {
    ListParent LP;
    createListParent(LP);

    insertFirstParent(LP, alokasiNodeParent("G004", "Romance"));
    insertFirstParent(LP, alokasiNodeParent("G003", "Horror"));
    insertFirstParent(LP, alokasiNodeParent("G002", "Comedy"));
    insertFirstParent(LP, alokasiNodeParent("G001", "Action"));

    insertLastChild(LP.first->child,
        alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));

    insertLastChild(LP.first->next->child,
        alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(LP.first->next->child,
        alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));

    insertLastChild(LP.first->next->next->child,
        alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));

    insertLastChild(LP.last->child,
        alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(LP.last->child,
        alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    printStrukturMLL(LP);

    searchFilmByRatingRange(LP, 8.0, 8.5);

    deleteAfterParent(LP, "G001");

    printStrukturMLL(LP);

    return 0;
}