#include "mll.h"

void createListParent(ListParent &LP) {
    LP.first = NULL;
    LP.last = NULL;
}

void createListChild(ListChild &LC) {
    LC.first = NULL;
    LC.last = NULL;
}

nodeParent* alokasiNodeParent(string id, string nama) {
    nodeParent *p = new nodeParent;
    p->IDGenre = id;
    p->namaGenre = nama;
    p->next = p->prev = NULL;
    createListChild(p->child);
    return p;
}

nodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    nodeChild *c = new nodeChild;
    c->IDFilm = id;
    c->judulFilm = judul;
    c->durasiFilm = durasi;
    c->tahunTayang = tahun;
    c->ratingFilm = rating;
    c->next = c->prev = NULL;
    return c;
}

void dealokasiNodeParent(nodeParent *p) {
    delete p;
}

void dealokasiNodeChild(nodeChild *c) {
    delete c;
}

void insertFirstParent(ListParent &LP, nodeParent *p) {
    if (LP.first == NULL) {
        LP.first = LP.last = p;
    } else {
        p->next = LP.first;
        LP.first->prev = p;
        LP.first = p;
    }
}

void insertLastChild(ListChild &LC, nodeChild *c) {
    if (LC.first == NULL) {
        LC.first = LC.last = c;
    } else {
        LC.last->next = c;
        c->prev = LC.last;
        LC.last = c;
    }
}

void hapusListChild(ListChild &LC) {
    nodeChild *c;
    while (LC.first != NULL) {
        c = LC.first;
        LC.first = c->next;
        dealokasiNodeChild(c);
    }
    LC.last = NULL;
}

void deleteAfterParent(ListParent &LP, string IDParent) {
    nodeParent *p = LP.first;
    while (p != NULL && p->IDGenre != IDParent) {
        p = p->next;
    }

    if (p != NULL && p->next != NULL) {
        nodeParent *hapus = p->next;
        hapusListChild(hapus->child);

        p->next = hapus->next;
        if (hapus->next != NULL)
            hapus->next->prev = p;
        else
            LP.last = p;

        dealokasiNodeParent(hapus);
    }
}

void searchFilmByRatingRange(ListParent LP, float min, float max) {
    nodeParent *p = LP.first;

    while (p != NULL) {
        nodeChild *c = p->child.first;

        while (c != NULL) {
            if (c->ratingFilm >= min && c->ratingFilm <= max) {
                cout << "Data Film ditemukan pada genre " << p->namaGenre << endl;
                cout << "Judul Film : " << c->judulFilm << endl;
                cout << "Durasi Film : " << c->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << c->tahunTayang << endl;
                cout << "Rating Film : " << c->ratingFilm << endl << endl;
            }
            c = c->next;
        }
        p = p->next;
    }
}

void printStrukturMLL(ListParent LP) {
    nodeParent *p = LP.first;
    int i = 1;

    while (p != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre : " << p->IDGenre << endl;
        cout << "Nama Genre : " << p->namaGenre << endl;

        nodeChild *c = p->child.first;
        int j = 1;
        while (c != NULL) {
            cout << "- Child " << j << endl;
            cout << "  ID Film : " << c->IDFilm << endl;
            cout << "  Judul Film : " << c->judulFilm << endl;
            cout << "  Durasi Film : " << c->durasiFilm << " menit" << endl;
            cout << "  Tahun Tayang : " << c->tahunTayang << endl;
            cout << "  Rating Film : " << c->ratingFilm << endl;
            c = c->next;
            j++;
        }
        cout << endl;
        p = p->next;
        i++;
    }
}