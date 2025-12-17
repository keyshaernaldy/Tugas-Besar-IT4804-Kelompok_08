#include "relation.h"
#include "developer.h"
#include "client.h"
#include <iostream>
using namespace std;

// Farida Syafa – create list relasi
void createRelasiList(RelasiList &L) {
    L.first = L.last = nullptr;
}

// Keysha – create node relasi
adrRel createRelasiNode(adrDev d, adrCli c, const string &project) {
    adrRel R = new RelasiElm;
    R->dev = d;
    R->client = c;
    R->projectName = project;
    R->prev = nullptr;
    R->next = nullptr;
    return R;
}

// Farida Syafa – insert element relation
void insertRelasi(RelasiList &L, adrRel R) {
    if (L.first == nullptr) {
        L.first = L.last = R;
    } else {
        L.last->next = R;
        R->prev = L.last;
        L.last = R;
    }
}

// =====================================================
// =================== FIND =============================
// =====================================================

// Farida Syafa – find apakah parent dan child tertentu memiliki relasi
bool clientHasDeveloper(const RelasiList &L, const string &clientID) {
    adrRel r = L.first;
    while (r != nullptr) {
        if (r->client->info.id == clientID) {
            return true;
        }
        r = r->next;
    }
    return false;
}

// Keysha – find relasi berdasarkan ID dev & client
adrRel findRelasiByIds(const RelasiList &L,
                       const string &devID,
                       const string &clientID) {
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

// Farida Syafa – find relasi berdasarkan client
adrRel findRelasiByClient(const RelasiList &L, const string &clientID) {
    adrRel r = L.first;
    while (r != nullptr) {
        if (r->client->info.id == clientID) {
            return r;
        }
        r = r->next;
    }
    return nullptr;
}

// =====================================================
// =================== DELETE ===========================
// =====================================================

// Keysha – delete element relasi
void deleteRelasi(RelasiList &L, adrRel R) {
    if (R == nullptr) return;

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

// Keysha – delete relasi berdasarkan ID
void deleteRelasiByIds(RelasiList &L,
                       const string &devID,
                       const string &clientID) {
    adrRel r = findRelasiByIds(L, devID, clientID);
    deleteRelasi(L, r);
}

// =====================================================
// =================== SHOW =============================
// =====================================================

// Keysha – show data child dari parent tertentu
void showRelasiByDev(const RelasiList &L, const string &devID) {
    adrRel r = L.first;
    cout << "Relasi Developer " << devID << ":\n";
    while (r != nullptr) {
        if (r->dev->info.id == devID) {
            cout << "- Client: "
                 << r->client->info.name
                 << " | Project: "
                 << r->projectName << endl;
        }
        r = r->next;
    }
}

// Farida Syafa – show data parent dari child tertentu
void showRelasiByClient(const RelasiList &L, const string &clientID) {
    adrRel r = L.first;
    cout << "Relasi Client " << clientID << ":\n";
    while (r != nullptr) {
        if (r->client->info.id == clientID) {
            cout << "- Developer: "
                 << r->dev->info.name
                 << " | Project: "
                 << r->projectName << endl;
        }
        r = r->next;
    }
}

// Keysha – show semua relasi
void showAllRelasi(const RelasiList &L) {
    adrRel r = L.first;
    cout << "=== SEMUA RELASI ===\n";
    while (r != nullptr) {
        cout << r->dev->info.name
             << " <--> "
             << r->client->info.name
             << " | Project: "
             << r->projectName << endl;
        r = r->next;
    }
}

// =====================================================
// =================== COUNT ============================
// =====================================================

// Farida Syafa – count jumlah child milik parent tertentu
int countChildOfDev(const RelasiList &L, const string &devID) {
    int count = 0;
    adrRel r = L.first;
    while (r != nullptr) {
        if (r->dev->info.id == devID) count++;
        r = r->next;
    }
    return count;
}

// Keysha – count jumlah parent yang dimiliki child tertentu
int countParentOfClient(const RelasiList &L, const string &clientID) {
    int count = 0;
    adrRel r = L.first;
    while (r != nullptr) {
        if (r->client->info.id == clientID) count++;
        r = r->next;
    }
    return count;
}

// Farida Syafa – count child yang tidak punya parent
int countClientWithoutParent(const RelasiList &L, const ClientList &CL) {
    int count = 0;
    adrCli c = CL.first;
    while (c != nullptr) {
        if (!clientHasDeveloper(L, c->info.id)) count++;
        c = c->next;
    }
    return count;
}

// Keysha – count parent yang tidak punya child
int countDevWithoutChild(const RelasiList &L, const DevList &DL) {
    int count = 0;
    adrDev d = DL.first;
    while (d != nullptr) {
        if (countChildOfDev(L, d->info.id) == 0) count++;
        d = d->next;
    }
    return count;
}

// =====================================================
// =================== EDIT =============================
// =====================================================

// Keysha – edit relasi: ganti child
bool editRelasiChangeChild(RelasiList &L,
                           const string &devID,
                           const string &oldClientID,
                           const string &newClientID,
                           ClientList &CL){
    adrRel r = findRelasiByIds(L, devID, oldClientID);
    if (!r) {
        return false;
    }

    adrCli newClient = findClient(CL, newClientID);
    if (!newClient){
        return false;
    }
    if (clientHasDeveloper(L, newClientID)){
        return false;
    }
    r->client = newClient;
    return true;
}

// Keysha – edit relasi: ganti parent
bool editRelasiChangeParent(RelasiList &L,
                            const string &clientID,
                            const string &oldDevID,
                            const string &newDevID,
                            DevList &DL) {
    adrRel r = findRelasiByIds(L, oldDevID, clientID);
    if (!r) return false;

    adrDev newDev = findDev(DL, newDevID);
    if (!newDev) return false;

    r->dev = newDev;
    return true;
}
