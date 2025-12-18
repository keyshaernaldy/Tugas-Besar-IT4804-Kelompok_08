#ifndef CD_DEVELOPER_H_INCLUDED
#define CD_DEVELOPER_H_INCLUDED
#include<iostream>
#include<string>

// TIPE B - Parent = DLL

using namespace std;

typedef struct DevElm *adrDev;

struct Developer{
    string id;
    string name;
};

struct DevElm {
    Developer info;
    adrDev prev;
    adrDev next;
};

struct DevList {
    adrDev first;
    adrDev last;
};

void createDevList(DevList &L);
adrDev createDevNode(Developer &x);
void insertDev(DevList &L, adrDev P);
adrDev findDev(DevList L, const string &id);
void deleteDev(DevList &L, adrDev P);
void deleteDevById(DevList &L, const string &id);
void showAllDev(const DevList &L);
void deleteFirstDev(DevList &L);
void deleteLastDev(DevList &L);
void deleteAfterDev(DevList &L, adrDev P);

#endif // CD_DEVELOPER_H_INCLUDED
