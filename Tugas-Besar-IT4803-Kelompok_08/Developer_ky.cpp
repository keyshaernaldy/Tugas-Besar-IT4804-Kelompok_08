#include "developer.h"
#include <iostream>
using namespace std;

void createDevList(DevList &L) {
    L.first = L.last = nullptr;
}

adrDev createDevNode(Developer &x) {
    adrDev P = new DevElm;
    P->info = x;
    P->prev = P->next = nullptr;
    return P;
}

void insertDev(DevList &L, adrDev P) {
    if (!L.first) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

adrDev findDev(DevList L, const string &id){
    adrDev p;
    p = L.first;
    while (p != nullptr){
        if (p->info.id == id)
            return p;
        p = p->next;
    }
    return nullptr;
}

void deleteFirstDev(DevList &L){
    adrDev P;
    if (P->prev == nullptr){
        P = L.first;
        L.first = L.first->next;
        P->next = nullptr;
    }

}

void deleteLastDev(DevList &L){
    adrDev P;
    if (P->next == nullptr){
        P = L.last;
        L.last = L.last->next;
        P->prev = nullptr;
        L.first = L.last = nullptr;
    }
}

void deleteAfterDev(DevList &L, adrDev P){
    if (P == nullptr) {
        return;
    }

    P->prev->next = P->next;
    P->next->prev = P->prev;

    delete P;
}

void deleteDev(DevList &L, adrDev P){
    if (L.first == nullptr){
        cout<< "Tidak ada developer yang bisa dihapus"<< endl;
        return;
    }else if(P == nullptr){
        cout<< "Developer tidak ditemukan, Masukan ID lain!"<< endl;
        return;
    }else if(P == L.first){
        deleteFirstDev(L);
    }else if (P == L.last){
        deleteLastDev(L);
    }else{
        deleteAfterDev(L, P);
    }

    cout << "Developer berhasil dihapusss"<< endl;
}

void deleteDevById(DevList &L, const string &id){
    adrDev p;
    p = findDev(L, id);
    deleteDev(L, p);
}

void showAllDev(DevList &L){
    adrDev p = L.first;
    cout<< "=== LIST DEVELOPER ==="<< endl;
    while (p){
        cout<< endl;
        cout<< "ID: " << p->info.id<< endl;
        cout<< "Nama: "<< p->info.name<< endl;
        p = p->next;
    }
}
