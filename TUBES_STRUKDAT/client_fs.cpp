#include "client.h"
#include "developer.h"
#include "relation.h"
#include <iostream>
using namespace std;

void createClientList(ClientList &L) {
    L.first = nullptr;
}

adrCli createClientNode(Client &x) {
    adrCli P = new ClientElm;
    P->info = x;
    P->next = nullptr;
    return P;
}

bool isEmptyCli(ClientList L){
    return (L.first == nullptr);
}

void insertClient(ClientList &L, adrCli P){
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

adrCli findClient(ClientList &L, string &id) {
    adrCli p = L.first;
    while (p != nullptr) {
        if (p->info.id == id){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void deleteClientByElm(ClientList &L, adrCli P) {
    if (!P) return;
    if (L.first == P) {
        L.first = P->next;
        delete P;
        return;
    }
    adrCli prev = L.first;
    while (prev != nullptr && prev->next != P) prev = prev->next;
    if (prev != nullptr) {
        prev->next = P->next;
        delete P;
    }
}

void deleteClientById(ClientList &L, string &id) {
    adrCli p = findClient(L, id);
    deleteClientByElm(L, p);
}

void showAllClient(ClientList &L) {
    adrCli p = L.first;
    cout << "=== Client List ===\n";
    while (p != nullptr) {
        cout << "ID: " << p->info.id << " | Name: " << p->info.name << '\n';
        p = p->next;
    }
}
