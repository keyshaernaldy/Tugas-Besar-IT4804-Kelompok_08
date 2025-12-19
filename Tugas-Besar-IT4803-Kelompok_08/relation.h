#ifndef RELATION_H
#define RELATION_H

#include <string>
#include "developer.h"
#include "client.h"

using namespace std;

typedef struct RelasiElm *adrRel;

struct RelasiElm {
    adrDev dev;
    adrCli client;
    string projectName;
    adrRel prev;
    adrRel next;
};

struct RelasiList {
    adrRel first;
    adrRel last;
};


void createRelasiList(RelasiList &L);
adrRel createRelasiElm(adrDev d, adrCli c, string project);
void insertRelasi(RelasiList &L, adrRel R);
void deleteRelasi(RelasiList &L, adrRel R);
void deleteRelasiByIds(RelasiList &L, string devID, string clientID);
void deleteRelasiByClient(RelasiList &RL, string cID);
adrRel findRelasiByIds(RelasiList &L, string devID, string clientID);
bool clientHasDeveloper(RelasiList &L, string clientID);
void showRelasiByDev(RelasiList &L, string devID);
void showRelasiByClient(RelasiList &L, string clientID);
void showAllRelasi(RelasiList &L);
void showDevWithoutClient(RelasiList &RL, DevList &DL);
void showClientWithoutDeveloper(RelasiList RL, ClientList CL);
int countChildOfDev(RelasiList &L, string devID);
int countParentOfClient(RelasiList &L, string clientID);
int countClientWithoutParent(RelasiList &L, ClientList &CL);
int countDevWithoutChild(RelasiList &L, DevList &DL);
bool developerHasClient(RelasiList RL, string devID);


bool editRelasiChangeChild(RelasiList &L,
                           string devID,
                           string oldClientID,
                           string newClientID,
                           ClientList &CL); // Keysha

bool editRelasiChangeParent(RelasiList &L,
                            string clientID,
                            string oldDevID,
                            string newDevID,
                            DevList &DL); // Keysha

#endif
