#include <iostream>
#include "developer.h"
#include "client.h"
#include "relation.h"

using namespace std;

void menuUtama();
void menuClient(ClientList &CL, RelasiList &RL);
void menuDeveloper(DevList &DL, RelasiList &RL);
void menuRelasi(DevList &DL, ClientList &CL, RelasiList &RL);
void dataClientDevRel(DevList &DL, ClientList &CL, RelasiList &RL);

int main(){
    DevList DL;
    ClientList CL;
    RelasiList RL;

    createDevList(DL);
    createClientList(CL);
    createRelasiList(RL);
    dataClientDevRel(DL, CL, RL);

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
            cout << "Anda berhasil keluar dari program!"<< endl;
        }
        else {
            cout << "Pilihan tidak valid!"<< endl;
        }
    }
    return 0;
}

void dataClientDevRel(DevList &DL, ClientList &CL, RelasiList &RL) {
// Data dummy Developer
// 1 Dev bisa memegang > 1 client.
    Developer d1 = {"D01", "Keysha"};
    Developer d2 = {"D02", "Farida"};
    Developer d3 = {"D03", "Syafaat"};
    Developer d4 = {"D04", "Widi"};
    Developer d5 = {"D05", "Erna"};
    Developer d6 = {"D06", "Kusuma"};
    Developer d7 = {"D07", "Lubna"};
    Developer d8 = {"D08", "Dhea"};
    Developer d9 = {"D09", "Kaye"};

    insertDev(DL, createDevNode(d1));
    insertDev(DL, createDevNode(d2));
    insertDev(DL, createDevNode(d3));
    insertDev(DL, createDevNode(d4));
    insertDev(DL, createDevNode(d5));
    insertDev(DL, createDevNode(d6));
    insertDev(DL, createDevNode(d7));
    insertDev(DL, createDevNode(d8));
    insertDev(DL, createDevNode(d9));

//Data client
    Client c1 = {"C01", "Lazada"};
    Client c2 = {"C02", "Gojek"};
    Client c3 = {"C03", "PT.Keymazka"};
    Client c4 = {"C04", "PT.Sinar Bahagia"};
    Client c5 = {"C05", "Bank Indonesia"};
    Client c6 = {"C06", "CV.Jaya Abadi"};
    Client c7 = {"C07", "PT.Sosro"};
    Client c8 = {"C08", "CV.Surya Lestari"};
    Client c9 = {"C09", "PT.SOCO"};

    insertClient(CL, createClientNode(c1));
    insertClient(CL, createClientNode(c2));
    insertClient(CL, createClientNode(c3));
    insertClient(CL, createClientNode(c4));
    insertClient(CL, createClientNode(c5));
    insertClient(CL, createClientNode(c6));
    insertClient(CL, createClientNode(c7));
    insertClient(CL, createClientNode(c8));
    insertClient(CL, createClientNode(c9));

    adrDev dev1 = findDev(DL, "D01");
    adrDev dev2 = findDev(DL, "D02");
    adrDev dev3 = findDev(DL, "D03");
    adrDev dev4 = findDev(DL, "D04");
    adrDev dev5 = findDev(DL, "D05");
    adrDev dev6 = findDev(DL, "D06");
    adrDev dev7 = findDev(DL, "D07");
    adrDev dev8 = findDev(DL, "D08");
    adrDev dev9 = findDev(DL, "D09");

    adrCli cli1 = findClient(CL, "C01");
    adrCli cli2 = findClient(CL, "C02");
    adrCli cli3 = findClient(CL, "C03");
    adrCli cli4 = findClient(CL, "C04");
    adrCli cli5 = findClient(CL, "C05");
    adrCli cli6 = findClient(CL, "C06");
    adrCli cli7 = findClient(CL, "C07");
    adrCli cli8 = findClient(CL, "C08");
    adrCli cli9 = findClient(CL, "C09");

    // Keysha - Lazada:)
    if (dev1 && cli1){
        insertRelasi(RL, createRelasiElm(dev1, cli1, "Complaint Website"));
    }
    // Farida - Gojek;)
    if (dev2 && cli2){
        insertRelasi(RL, createRelasiElm(dev2, cli2, "Mobile App"));
    }
    // Syafaat - PT.Keymazka
    if(dev3 && cli3){
        insertRelasi(RL, createRelasiElm(dev3, cli3, "Sistem pencatatan RAB otomatis"));
    }
    // Widi - Sinar Bahagia
    if (dev4 && cli4){
        insertRelasi(RL, createRelasiElm(dev4, cli4, "Aplikasi Management Gudang"));
    }
    // Erna - Bank Indonesia
    if (dev5 && cli5){
        insertRelasi(RL, createRelasiElm(dev5, cli5, "Aplikasi Accounting"));
    }
    // Kusuma - PT. Jaya Abadi
    if(dev6 && cli6){
        insertRelasi(RL, createRelasiElm(dev6, cli6, "Website Sistem Monitoring Persediaan"));
    }
    // Lubna - PT.Sosro
     if(dev7 && cli7){
        insertRelasi(RL, createRelasiElm(dev7, cli7, "Absent Tracking Application"));
    }
}


void menuUtama() {
    cout<< endl<< "+-------------------------------+"<< endl;
    cout<< "|== SISTEM MANAGEMENT PROJECT ==|"<< endl;
    cout<< "+-------------------------------+"<< endl;
    cout<< "| 1. Menu Client                |"<< endl;
    cout<< "| 2. Menu Developer             |"<< endl;
    cout<< "| 3. Menu Project               |"<< endl;
    cout<< "| 0. Exit                       |"<< endl;
    cout<< "+===============================+"<< endl;
    cout<< "Pilih: ";
}

void menuClient(ClientList &CL, RelasiList &RL) {
    int pilih = -1;
    while (pilih != 0){
        cout<< endl<< "+-------------------------------+"<< endl;
        cout<< "|          MENU CLIENT          |"<< endl;
        cout<< "+-------------------------------+"<< endl;
        cout<< "|1. Masukan Client baru         |"<< endl;
        cout<< "|2. Hapus Client                |"<< endl;
        cout<< "|3. Temukan Client              |"<< endl;
        cout<< "|4. Show All Client             |"<< endl;
        cout<< "|5. Show Developer dari Client  |"<< endl;
        cout<< "|6. Show Client + Developer     |"<< endl;
        cout<< "|7. Count Jumlah Client         |"<< endl;
        cout<< "|8. Count Client tanpa Developer|"<< endl;
        cout<< "|0. Kembali                     |"<< endl;
        cout<< "+-------------------------------+"<< endl;
        cout<< "Pilih: ";
        cin>> pilih;
        cout<< endl;

        if (pilih == 1) {
            Client c;
            cout<< "ID Client (CXX): ";
            cin>> c.id;
            while (findClient(CL, c.id) != nullptr) {
            cout << "ID client sudah ada" << endl;
            cout<< "Silahkan masukan ID yang berbeda!"<< endl;
            cout<< "ID Client: ";
            cin>> c.id;
            }if(findClient(CL, c.id) == nullptr){
            cout<< "Nama      : ";
            cin>> c.name;
            insertClient(CL, createClientNode(c));
            cout<< "Data Client berhasil ditambahkan!"<< endl;
            }
        }
            else if (pilih == 2) {
                string id;

                if (CL.first == nullptr) {
                cout << "Tidak ada data client yang dapat dihapus" << endl;
                }
                else{
                    cout << "ID Client : ";
                    cin >> id;

                    adrCli p = findClient(CL, id);

                    if (p == nullptr) {
                    cout << "ID client tidak terdapat pada data, Masukan ID lain" << endl;
                    }else{
                    deleteRelasiByClient(RL, id);
                    deleteClientById(CL, id);

                    cout << "Data client berhasil dihapus" << endl;
                    }
                }
            }


        else if (pilih == 3) {
            string id;

            if (CL.first == nullptr) {
                cout << "Data client masih kosong" << endl;
            }
            else {
                cout << "ID Client : ";
                cin >> id;

                adrCli p = findClient(CL, id);

                if (p != nullptr) {
                    cout << "Client ditemukan" << endl;
                    cout << "ID   : " << p->info.id << endl;
                    cout << "Nama : " << p->info.name << endl;
                }
                else {
                    cout << "Client tidak ditemukan" << endl;
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
            cout<< "Jumlah client: "<< total<< endl;
        }

        else if (pilih == 8){
            if (CL.first == nullptr){
            cout << "Data client masih kosong" << endl;
            } else{
                showClientWithoutDeveloper(RL, CL);
            }
        }

    }
}


void menuDeveloper(DevList &DL, RelasiList &RL) {
    int pilih = -1;
    while (pilih != 0) {
        cout<< endl<< "+===============================+"<< endl;
        cout<< "|         MENU DEVELOPER        |"<< endl;
        cout<< "+===============================+"<< endl;
        cout<< "| 1. Insert Developer           +"<< endl;
        cout<< "| 2. Delete Developer           +"<< endl;
        cout<< "| 3. Find Developer             +"<< endl;
        cout<< "| 4. Show All Developer         +"<< endl;
        cout<< "| 5. Developer tanpa Client     +"<< endl;
        cout<< "| 0. Kembali                    +"<< endl;
        cout<< "+-------------------------------+"<< endl;
        cout<< "Pilih: ";
        cin>> pilih;
        cout<< endl;

        if (pilih == 1) {
            Developer d;
            cout<< "ID Developer : ";
            cin>> d.id;
            while(findDev(DL, d.id) != nullptr) {
            cout << "ID Developer sudah ada" << endl;
            cout<< "Silahkan masukan ID yang berbeda!"<< endl;
            cout<< "ID Client: ";
            cin>> d.id;
            }if(findDev(DL, d.id) == nullptr){
            cout << "Nama         : ";
            cin >> d.name;
            insertDev(DL, createDevNode(d));
            cout << "Developer berhasil ditambahkan!" << endl;

            }
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

        }else if (pilih == 3){
            string id;
            if (DL.first == nullptr) {
            cout << "Data developer kosong!" << endl;
        }else {
        cout<< "Masukan ID Developer : "; //gaboleh double
        cin>> id;
        adrDev P = findDev(DL, id);
        if (P != nullptr){
            cout<< "Developer ditemukan!"<< endl;
            cout<< endl<< "ID   : " << P->info.id<< endl;
            cout<< "Nama : " << P->info.name<< endl;
        }
        else {
            cout<< "Developer tidak ditemukan:(" << endl;
        }
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
            cout<< "Developer tanpa client: ";
            cout<< countDevWithoutChild(RL, DL)<< endl;
            showDevWithoutClient(RL, DL);
        }
    }
}

void menuRelasi(DevList &DL, ClientList &CL, RelasiList &RL) {
    int pilih = -1;
    while (pilih != 0) {
        cout<< "+==================================+"<< endl;
        cout<< "| ---  M E N U  P R O J E C T ---  |"<< endl;
        cout<< "+==================================+"<< endl;
        cout<< "| 1. Masukan project               |"<< endl;
        cout<< "| 2. Hapus project                 |"<< endl;
        cout<< "| 3. Tampilkan project by Developer|"<< endl;
        cout<< "| 4. Tampilkan project by Client   |"<< endl;
        cout<< "| 5. Tampilkan semua project       |"<< endl;
        cout<< "| 6. Edit Client                   |"<< endl;
        cout<< "| 7. Edit Developer                |"<< endl;
        cout<< "| 8. Cek project                   |"<< endl;
        cout<< "| 0. Kembali                       |"<< endl;
        cout<< "+==================================+"<< endl;
        cout<< "Pilih: ";
        cin>> pilih;
        cout<< endl;

        if (pilih == 1){
            string dID, cID, proj;
            cout<< "ID Developer : "; cin>> dID;
            cout<< "ID Client    : "; cin>> cID;
            cout<< "Nama Project : "; cin>> proj;

            adrDev d = findDev(DL, dID);
            adrCli c = findClient(CL, cID);

            if (d == nullptr){
                cout<< "Developer tidak ditemukan"<< endl;
            }else if (c == nullptr){
                cout<< "Client tidak ditemukan"<< endl;
            }else if (clientHasDeveloper(RL, cID)){
                cout<< "Client sudah punya developer"<< endl;
            }else {
                insertRelasi(RL, createRelasiElm(d, c, proj));
                cout<< "Project berhasil ditambahkan"<< endl;
            }
        }
        else if (pilih == 2){
            string dID, cID;
            cout << "ID Developer : "; cin >> dID;
            cout << "ID Client    : "; cin >> cID;
            adrDev d = findDev(DL, dID);
            if (d == nullptr){
                cout << "ID Developer/Client tidak terdaftar!, Masukan ID lain!" << endl;
                return;
            }
            adrCli c = findClient(CL, cID);
            if (c == nullptr){
                cout << "ID Developer/Client tidak terdaftar!, Masukan ID lain!" << endl;
                return;
            }
            if (findRelasiByIds(RL, dID, cID) == nullptr){
                cout << "Project tidak ditemukan!" << endl;
            } else{
                deleteRelasiByIds(RL, dID, cID);
                cout<< "Project berhasil dihapus!" << endl;
            }
}

        else if (pilih == 3){
            string id;
            cout<< "ID Developer : "; cin>> id;
            showRelasiByDev(RL, id);
        }
        else if (pilih == 4){
            string id;
            cout<< "ID Client : "; cin>> id;
            showRelasiByClient(RL, id);
        }
        else if (pilih == 5){
            showAllRelasi(RL);
        }
        else if (pilih == 6){
            string dID, oldC, newC;
            cout<< "ID Developer        : "; cin>> dID;
            cout<< "ID Client sebelum   : "; cin>> oldC;
            cout<< "New Client ID       : "; cin>> newC;
            if (editRelasiChangeChild(RL, dID, oldC, newC, CL))
                cout<< "Project berhasil diubah"<< endl;
            else
                cout<< "Gagal mengubah project"<< endl;
        }
        else if (pilih == 7){
            string cID, oldD, newD;
            cout<< "ID Client             : "; cin>> cID;
            cout<< "ID Developer sebelum  : "; cin>> oldD;
            cout<< "New Dev ID            : "; cin>> newD;
            if (editRelasiChangeParent(RL, cID, oldD, newD, DL))
                cout<< "Project berhasil diubah"<< endl;
            else
                cout<< "Gagal mengubah project"<< endl;
        }
        else if (pilih == 8) {
            string dID, cID;
            cout << "ID Developer : "; cin >> dID;
            cout << "ID Client    : "; cin >> cID;

            adrDev d = findDev(DL, dID);
            adrCli c = findClient(CL, cID);

            if (d == nullptr) {
                cout << "ID Developer tidak terdaftar" << endl;
            }
            else if (c == nullptr) {
                cout << "ID Client tidak terdaftar" << endl;
            }
            else {
                if (findRelasiByIds(RL, dID, cID)) {
                    cout << "Terdapat relasi" << endl;
                }
                else {
                    cout << "Tidak terdapat relasi" << endl;
                }
            }
        }

    }
}
