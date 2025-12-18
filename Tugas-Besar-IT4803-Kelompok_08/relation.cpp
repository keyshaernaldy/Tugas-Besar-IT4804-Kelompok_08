#include "relation.h"
#include <iostream>
using namespace std;

// ===== BASIC =====
void createRelasiList(RelasiList &L) {
    L.first = L.last = nullptr;
}

adrRel createRelasiNode(adrDev d, adrCli c, string project) {
    adrRel R = new RelasiElm;
    R->dev = d;
    R->client = c;
    R->projectName = project;
    R->prev = nullptr;
    R->next = nullptr;
    return R;
}

void insertRelasi(RelasiList &L, adrRel R) {
    if (L.first == nullptr) {
        L.first = L.last = R;
    } else {
        L.last->next = R;
        R->prev = L.last;
        L.last = R;
    }
}

void deleteRelasi(RelasiList &L, adrRel R) {
    if (!R) return;

    if (R == L.first && R == L.last) {
        L.first = L.last = nullptr;
    } else if (R == L.first) {
        L.first = R->next;
        L.first->prev = nullptr;
    } else if (R == L.last) {
        L.last = R->prev;
        L.last->next = nullptr;
    } else {
        R->prev->next = R->next;
        R->next->prev = R->prev;
    }
    delete R;
}

void deleteRelasiByIds(RelasiList &L, string devID, string clientID) {
    adrRel R = findRelasiByIds(L, devID, clientID);
    deleteRelasi(L, R);
}

// ===== FIND =====
adrRel findRelasiByIds(RelasiList &L, string devID, string clientID) {
    adrRel r = L.first;
    while (r != nullptr) {
        if (r->dev->info.id == devID &&
            r->client->info.id == clientID) {
            return r;
        }
        r = r->next;
    }
    return nullptr;
}

bool clientHasDeveloper(RelasiList &L, string clientID) {
    adrRel r = L.first;
    while (r != nullptr) {
        if (r->client->info.id == clientID)
            return true;
        r = r->next;
    }
    return false;
}

// ===== SHOW =====
void showRelasiByDev(RelasiList &L, string devID) {
    adrRel r = L.first;
    cout << "Relasi Developer " << devID << ":\n";
    while (r != nullptr) {
        if (r->dev->info.id == devID) {
            cout << "- Client: " << r->client->info.name
                 << " | Project: " << r->projectName << endl;
        }
        r = r->next;
    }
}

void showRelasiByClient(RelasiList &L, string clientID) {
    adrRel r = L.first;
    cout << "Relasi Client " << clientID << ":\n";
    while (r != nullptr) {
        if (r->client->info.id == clientID) {
            cout << "- Developer: " << r->dev->info.name
                 << " | Project: " << r->projectName << endl;
        }
        r = r->next;
    }
}

void showAllRelasi(RelasiList &L) {
    adrRel r = L.first;
    cout << "=== SEMUA RELASI ===\n";
    while (r != nullptr) {
        cout << r->dev->info.name << " <--> "
             << r->client->info.name
             << " | Project: " << r->projectName << endl;
        r = r->next;
    }
}

// ===== COUNT =====
int countChildOfDev(RelasiList &L, string devID) {
    int count = 0;
    adrRel r = L.first;
    while (r != nullptr) {
        if (r->dev->info.id == devID)
            count++;
        r = r->next;
    }
    return count;
}

int countParentOfClient(RelasiList &L, string clientID) {
    int count = 0;
    adrRel r = L.first;
    while (r != nullptr) {
        if (r->client->info.id == clientID)
            count++;
        r = r->next;
    }
    return count;
}

int countClientWithoutParent(RelasiList &L, ClientList &CL) {
    int count = 0;
    adrCli c = CL.first;
    while (c != nullptr) {
        if (!clientHasDeveloper(L, c->info.id))
            count++;
        c = c->next;
    }
    return count;
}

int countDevWithoutChild(RelasiList &L, DevList &DL) {
    int count = 0;
    adrDev d = DL.first;
    while (d != nullptr) {
        if (countChildOfDev(L, d->info.id) == 0)
            count++;
        d = d->next;
    }
    return count;
}

// ===== EDIT =====
bool editRelasiChangeChild(RelasiList &L,
                           string devID,
                           string oldClientID,
                           string newClientID,
                           ClientList &CL) {
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
