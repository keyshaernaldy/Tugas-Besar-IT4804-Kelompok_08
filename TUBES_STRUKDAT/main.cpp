#include <iostream>
#include "developer.h"
#include "client.h"
#include "relation.h"

using namespace std;

void menuUtama();
void menuClient(ClientList &CL, RelasiList &RL);
void menuDeveloper(DevList &DL, RelasiList &RL);
void menuRelasi(DevList &DL, ClientList &CL, RelasiList &RL);

int main() {
    DevList DL;
    ClientList CL;
    RelasiList RL;

    createDevList(DL);
    createClientList(CL);
    createRelasiList(RL);

    int pilih = -1;

    while (pilih != 0) {
        menuUtama();
        cin >> pilih;

        if (pilih == 1) {
            menuClient(CL, RL);
        }
        else if (pilih == 2) {
            menuDeveloper(DL, RL);
        }
        else if (pilih == 3) {
            menuRelasi(DL, CL, RL);
        }
        else if (pilih == 0) {
            cout << "Program selesai"<< endl;
        }
        else {
            cout << "Pilihan tidak valid!"<< endl;
        }
    }
    return 0;
}

void menuUtama() {
    cout<< endl<< "+-------------------------------+"<< endl;
    cout<< "|== SISTEM MANAGEMENT PROJECT ==|"<< endl;
    cout<< "+-------------------------------+"<< endl;
    cout<< "+ 1. Menu Client                +"<< endl;
    cout<< "+ 2. Menu Developer             +"<< endl;
    cout<< "+ 3. Menu Project               +"<< endl;
    cout<< "+ 0. Exit                       +"<< endl;
    cout<< "================================="<< endl;
    cout<< "Pilih: ";
}

void menuClient(ClientList &CL, RelasiList &RL) {
    int pilih = -1;
    while (pilih != 0){
        cout << "+-------------------------------+"<< endl;
        cout << "        MENU CLIENT         "<< endl;
        cout << "+-------------------------------+"<< endl;
        cout << "1. Insert Client"<< endl;
        cout << "2. Delete Client"<< endl;
        cout << "3. Find Client"<< endl;
        cout << "4. Show All Client"<< endl;
        cout << "5. Show Parent dari Client"<< endl;
        cout << "6. Show Client + Parent"<< endl;
        cout << "7. Count Jumlah Client"<< endl;
        cout << "8. Count Client tanpa Developer"<< endl;
        cout << "0. Kembali\n";
        cout << "---------------------------------"<< endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            Client c;
            cout << "ID Client : "; cin >> c.id;
            cout << "Nama      : "; cin >> c.name;
            insertClient(CL, createClientNode(c));
            cout<< "Data Client berhasil ditambahkan!"<< endl;
        }

        else if (pilih == 2) {
            string id;
            if(CL.first == nullptr){
                cout<< "Tidak ada data client yang dapat dihapus"<< endl;
            }else {
            cout<< "ID Client : ";
            cin >> id;
            deleteClientById(CL, id);
            cout<< "Data client berhasil dihapus";
            }
        }

        else if (pilih == 3) {
            string id;
            if(CL.first == nullptr){
                cout<< "Data client masih kosong"<< endl;
            }else if(CL.first != nullptr){
            cout << "ID Client : ";
            cin >> id;
                if (findClient(CL, id)){
                cout << "Client ditemukan"<< endl;
                }
                else{
                    cout << "Client tidak ditemukan"<< endl;
                }
            }
        }

        else if (pilih == 4) {
            showAllClient(CL);
        }

        else if (pilih == 5) {
            string id;
            cout << "ID Client : "; cin>> id;
            showRelasiByClient(RL, id);
        }

        else if (pilih == 6) {
            showAllRelasi(RL);
        }

        else if (pilih == 7) {
            int total = 0;
            adrCli c = CL.first;
            while (c != nullptr) {
                total++;
                c = c->next;
            }
            cout << "Jumlah client: "<< total<< endl;
        }

        else if (pilih == 8) {
            cout << "Client tanpa developer: "
                 << countClientWithoutParent(RL, CL)<< endl;
        }
    }
}


void menuDeveloper(DevList &DL, RelasiList &RL) {
    int pilih = -1;
    while (pilih != 0) {
        cout<< endl<< "+===============================+"<< endl;
        cout<< "|         MENU DEVELOPER        |"<< endl;
        cout<< "+===============================+"<< endl;
        cout<< "+ 1. Insert Developer           +"<< endl;
        cout<< "+ 2. Delete Developer           +"<< endl;
        cout<< "+ 3. Find Developer             +"<< endl;
        cout<< "+ 4. Show All Developer         +"<< endl;
        cout<< "+ 5. Developer tanpa Client     +"<< endl;
        cout<< "+ 0. Kembali                    +"<< endl;
        cout<< "--------------------------------+"<< endl;
        cout<< "Pilih: ";
        cin>> pilih;

        if (pilih == 1) {
            Developer d;
            cout<< "ID Developer : "; cin>> d.id;
            cout<< "Nama         : "; cin>> d.name;
            insertDev(DL, createDevNode(d));
            cout<< "Developer berhasil ditambahkan!"<< endl;
        }
        else if (pilih == 2) {
            string id;
            adrDev P;
            if (DL.first == nullptr){
                deleteDev(DL, P);
            }
            else{
            cout<< "ID Developer : ";
            cin>> id;
            deleteDevById(DL, id);
            }
        }
        else if (pilih == 3) {
            string id;
            if(DL.first == nullptr && DL.last == nullptr){
                cout<< "Data developer kosong!"<< endl;
            }
            else if (findDev(DL, id)){
                cout << "ID Developer : ";
                cin >> id;
                cout << "Developer ditemukan"<< endl;
            }
            else {cout << "Developer tidak ditemukan"<< endl;
            }
        }
        else if (pilih == 4) {
            if(DL.first == nullptr && DL.last == nullptr){
                cout<< "Tidak ada developer yang tersedia"<< endl;
            }else{
            showAllDev(DL);
            }
        }
        else if (pilih == 5) {
            cout << "Developer tanpa client: "
                 << countDevWithoutChild(RL, DL) << endl;
        }
    }
}

void menuRelasi(DevList &DL, ClientList &CL, RelasiList &RL) {
    int pilih = -1;
    while (pilih != 0) {
        system("cls");
        cout<< endl<< "--- M E N U  P R O J E C T ---"<< endl;
        cout<< "1. Insert Relasi"<< endl;
        cout<< "2. Delete Relasi"<< endl;
        cout<< "3. Show Relasi by Developer"<< endl;
        cout<< "4. Show Relasi by Client"<< endl;
        cout<< "5. Show All Relasi"<< endl;
        cout<< "6. Edit Relasi (Ganti Client)"<< endl;
        cout<< "7. Edit Relasi (Ganti Developer)"<< endl;
        cout<< "8. Cek Relasi Developer & Client"<< endl;
        cout<< "0. Kembali"<< endl;
        cout<< "Pilih: ";
        cin>> pilih;

        if (pilih == 1) {
            string dID, cID, proj;
            cout << "ID Developer : "; cin >> dID;
            cout << "ID Client    : "; cin >> cID;
            cout << "Project Name : "; cin >> proj;

            adrDev d = findDev(DL, dID);
            adrCli c = findClient(CL, cID);

            if (d && c && !clientHasDeveloper(RL, cID)) {
                insertRelasi(RL, createRelasiNode(d, c, proj));
                cout << "Relasi berhasil ditambahkan\n";
            } else {
                cout << "Relasi gagal\n";
            }
        }
        else if (pilih == 2) {
            string dID, cID;
            cout << "ID Developer : "; cin >> dID;
            cout << "ID Client    : "; cin >> cID;
            deleteRelasiByIds(RL, dID, cID);
        }
        else if (pilih == 3) {
            string id;
            cout << "ID Developer : "; cin >> id;
            showRelasiByDev(RL, id);
        }
        else if (pilih == 4) {
            string id;
            cout << "ID Client : "; cin >> id;
            showRelasiByClient(RL, id);
        }
        else if (pilih == 5) {
            showAllRelasi(RL);
        }
        else if (pilih == 6) {
            string dID, oldC, newC;
            cout << "ID Developer    : "; cin >> dID;
            cout << "Old Client ID   : "; cin >> oldC;
            cout << "New Client ID   : "; cin >> newC;
            if (editRelasiChangeChild(RL, dID, oldC, newC, CL))
                cout << "Relasi berhasil diubah\n";
            else
                cout << "Gagal mengubah relasi\n";
        }
        else if (pilih == 7) {
            string cID, oldD, newD;
            cout << "ID Client      : "; cin >> cID;
            cout << "Old Dev ID     : "; cin >> oldD;
            cout << "New Dev ID     : "; cin >> newD;
            if (editRelasiChangeParent(RL, cID, oldD, newD, DL))
                cout << "Relasi berhasil diubah\n";
            else
                cout << "Gagal mengubah relasi\n";
        }
        else if (pilih == 8){
            string dID, cID;
            cout << "ID Developer : "; cin >> dID;
            cout << "ID Client    : "; cin >> cID;

            if (findRelasiByIds(RL, dID, cID))
                cout << "Relasi ADA\n";
            else
                cout << "Relasi TIDAK ADA\n";
        }
    }
}
