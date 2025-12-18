#include "client.h"
#include <iostream>

using namespace std;

void createClientList(ClientList &L){
    L.first = nullptr;
}

adrCli createClientNode(Client &x){
    adrCli P = new ClientElm;
    P->info = x;
    P->next = nullptr;
    return P;
}

bool isEmptyCli(ClientList CL) {
    return (CL.first == nullptr);
}

// Farida Syafa – Insert element child
void insertClient(ClientList &L, adrCli P){
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

// Farida Syafa – Find element child
adrCli findClient(ClientList &L, string &id){
    adrCli p = L.first;
    while (p != nullptr) {
        if (p->info.id == id) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

// Farida Syafa – Delete element child
void deleteClientByElm(ClientList &L, adrCli P){
    if (P == nullptr || L.first == nullptr){
        return;
    }

    if (L.first == P){
        L.first = P->next;
        delete P;
        return;
    }

    adrCli prev = L.first;
    while (prev->next != nullptr && prev->next != P){
        prev = prev->next;
    }

    if (prev->next == P){
        prev->next = P->next;
        delete P;
    }
}

// Farida Syafa – Delete element child (by ID)
void deleteClientById(ClientList &L, string &id){
    adrCli P = findClient(L, id);
    deleteClientByElm(L, P);
}

// Farida Syafa – Show all data di List Child
void showAllClient(ClientList &L){
    adrCli p = L.first;
    cout << "=== LIST CLIENT ===" << endl;
    while (p != nullptr) {
        cout << "ID   : " << p->info.id << endl;
        cout << "Nama : " << p->info.name << endl;
        cout << "------------------" << endl;
        p = p->next;
    }
}

// Farida Syafa – 8. Count jumlah child
int countAllChild(ClientList &CL){
    int count = 0;
    adrCli p = CL.first;
    while (p != nullptr){
        count++;
        p = p->next;
    }
    return count;
}

// Farida Syafa – 9. Count element child tertentu
int countSpecificChild(ClientList &CL, string &clientID){
    adrCli p = findClient(CL, clientID);
    if (p != nullptr){
        return 1;
    }
    else{
        return 0;
    }
}
