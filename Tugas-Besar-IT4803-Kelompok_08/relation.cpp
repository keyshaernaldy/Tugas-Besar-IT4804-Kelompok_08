#include "relation.h"
#include <iostream>
using namespace std;

void createRelasiList(RelasiList &L){
    L.first = L.last = nullptr;
}

adrRel createRelasiElm(adrDev d, adrCli c, string project){
    adrRel R = new RelasiElm;
    R->dev = d;
    R->client = c;
    R->projectName = project;
    R->prev = nullptr;
    R->next = nullptr;
    return R;
}

void insertRelasi(RelasiList &L, adrRel R){
    if (L.first == nullptr) {
        L.first = L.last = R;
    } else {
        L.last->next = R;
        R->prev = L.last;
        L.last = R;
    }
}

void deleteRelasi(RelasiList &L, adrRel R){
    if (!R) {
        return;
    }
    if (R == L.first && R == L.last){
        L.first = L.last = nullptr;
    }else if (R == L.first){
        L.first = R->next;
        L.first->prev = nullptr;
    }else if (R == L.last){
        L.last = R->prev;
        L.last->next = nullptr;
    }else {
        R->prev->next = R->next;
        R->next->prev = R->prev;
    }
    delete R;
}

void deleteRelasiByIds(RelasiList &L, string devID, string clientID){
    adrRel R = findRelasiByIds(L, devID, clientID);
    deleteRelasi(L, R);
}

void deleteRelasiByClient(RelasiList &RL, string cID){
    adrRel p = RL.first;
    adrRel next;

    while (p != nullptr) {
        next = p->next;
        if (p->client->info.id == cID){
            deleteRelasi(RL, p);
        }
        p = next;
    }
}

adrRel findRelasiByIds(RelasiList &L, string devID, string clientID){
    adrRel r = L.first;
    while (r != nullptr) {
        if (r->dev->info.id == devID &&
            r->client->info.id == clientID){
            return r;
        }
        r = r->next;
    }
    return nullptr;
}

bool clientHasDeveloper(RelasiList &L, string clientID){
    adrRel r = L.first;
    while (r != nullptr){
        if (r->client->info.id == clientID)
            return true;
        r = r->next;
    }
    return false;
}

void showClientWithoutDeveloper(RelasiList RL, ClientList CL){
    adrCli c = CL.first;
    int jumlah = 0;

    cout << "Daftar Client tanpa Developer:" << endl;

    while (c != nullptr){
        bool punyaDev = false;

        adrRel r = RL.first;
        while (r != nullptr){
            if (r->client == c){
                punyaDev = true;
                break;
            }
            r = r->next;
        }

        if (!punyaDev){
            jumlah++;
            cout << "- ID   : " << c->info.id << endl;
            cout << "  Nama : " << c->info.name << endl;
        }

        c = c->next;
    }
    cout<< "Jumlah client tanpa developer: " << jumlah << endl;
}


void showRelasiByDev(RelasiList &L, string devID){
    adrRel r = L.first;
    cout<< "Relasi Developer "<< devID<< ": "<< endl;
    while (r != nullptr){
        if (r->dev->info.id == devID){
            cout<< "- Client: "<< r->client->info.name;
            cout<< " | Project: " << r->projectName<< endl;
        }
        r = r->next;
    }
}

void showRelasiByClient(RelasiList &L, string clientID){
    adrRel r = L.first;
    bool found = false;

    while (r != nullptr){
        if (r->client->info.id == clientID){
            if (!found) {
                cout << "Relasi Client " << clientID << ":" << endl;
                found = true;
            }
            cout << "- Developer : " << r->dev->info.name << endl;
            cout << "  Project   : " << r->projectName << endl;
            cout << "------------------------" << endl;
        }
        r = r->next;
    }

    if (!found){
        cout << "Client tidak memiliki project dengan developer" << endl;
    }
}


void showAllRelasi(RelasiList &L){
    adrRel r;
    r = L.first;
    Developer d;
    cout<< "=== DAFTAR PROJECT ==="<< endl;
    while (r != nullptr){
        cout<< d.id << r->dev->info.name<< " --> ";
        cout<< r->client->info.name<< endl;
        cout<< "Project: "<< r->projectName << endl;
        cout<< endl;
        r = r->next;
    }
}

int countChildOfDev(RelasiList &L, string devID){
    int count = 0;
    adrRel r = L.first;
    while (r != nullptr){
        if (r->dev->info.id == devID)
            count++;
        r = r->next;
    }
    return count;
}

int countParentOfClient(RelasiList &L, string clientID){
    int count = 0;
    adrRel r = L.first;
    while (r != nullptr) {
        if (r->client->info.id == clientID)
            count++;
        r = r->next;
    }
    return count;
}

int countClientWithoutParent(RelasiList &L, ClientList &CL){
    int count = 0;
    adrCli c = CL.first;
    while (c != nullptr) {
        if (!clientHasDeveloper(L, c->info.id))
            count++;
        c = c->next;
    }
    return count;
}

int countDevWithoutChild(RelasiList &L, DevList &DL){
    int count = 0;
    adrDev d = DL.first;
    while (d != nullptr){
        if (countChildOfDev(L, d->info.id) == 0)
            count++;
        d = d->next;
    }
    return count;
}

void showDevWithoutClient(RelasiList &RL, DevList &DL){
    if (DL.first == nullptr) {
        cout << "Data developer kosong"<< endl;
        return;
    }

    int count = 0;
    adrDev D = DL.first;

    cout << "=== Developer tanpa Client ==="<< endl;

    while (D != nullptr) {
        bool punyaClient = false;
        adrRel r = RL.first;
        while (r != nullptr){
            if (r->dev == D){
                punyaClient = true;
                break;
            }
            r = r->next;
        }

        if (!punyaClient) {
            cout << "ID   : " << D->info.id << endl;
            cout << "Nama : " << D->info.name << endl;
            cout << "------------------------"<< endl;
            count++;
        }
        D = D->next;
    }
}

bool editRelasiChangeChild(RelasiList &L,
                           string devID,
                           string oldClientID,
                           string newClientID,
                           ClientList &CL){
    adrRel r = findRelasiByIds(L, devID, oldClientID);
    if (!r) return false;

    adrCli newClient = findClient(CL, newClientID);
    if (!newClient) return false;

    if (clientHasDeveloper(L, newClientID)) return false;

    r->client = newClient;
    return true;
}

bool editRelasiChangeParent(RelasiList &L,
                            string clientID,
                            string oldDevID,
                            string newDevID,
                            DevList &DL) {
    adrRel r = findRelasiByIds(L, oldDevID, clientID);
    if (!r) return false;

    adrDev newDev = findDev(DL, newDevID);
    if (!newDev) return false;

    r->dev = newDev;
    return true;
}

bool developerHasClient(RelasiList RL, string devID) {
    adrRel p = RL.first;
    while (p != nullptr) {
        if (p->dev->info.id == devID) {
            return true; // developer udh punya client
        }
        p = p->next;
    }
    return false; // developer blm punya client
}
