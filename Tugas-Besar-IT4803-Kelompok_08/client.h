#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

// TIPE B - Child = SLL

typedef struct ClientElm *adrCli;

struct Client {
    string id;
    string name;
};

struct ClientElm {
    Client info;
    adrCli next;
};

struct ClientList {
    adrCli first;
};

void createClientList(ClientList &L);
adrCli createClientNode(Client &x);
// Farida Syafa – Insert element child
void insertClient(ClientList &L, adrCli P);
// Farida Syafa – Find element child
adrCli findClient(ClientList &L, string &id);
// Farida Syafa – Delete element child
void deleteClientByElm(ClientList &L, adrCli P);
void deleteClientById(ClientList &L, string &id);
// Farida Syafa – Show all data di List Child
void showAllClient(ClientList &L);
bool isEmptyCli(ClientList CL);
// Farida Syafa – 8. Count jumlah child
int countAllChild(ClientList &CL);
// Farida Syafa – 9. Count element child tertentu (0 / 1)
int countSpecificChild(ClientList &CL, string &clientID);

#endif // CLIENT_H_INCLUDED
