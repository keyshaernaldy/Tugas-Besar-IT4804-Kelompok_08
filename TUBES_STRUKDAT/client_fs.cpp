#include "main.h"

void createListClient(Client *&first) {
    first = nullptr;
}

void createNewClient(string nama, Client *&newClient) {
    newClient = new Client;
    newClient->nama = nama;
    newClient->next = nullptr;
    newClient->prev = nullptr;
}

void insertFirstClient(Client *&first, Client *newClient) {
    if (first == nullptr) {
        newClient->next = nullptr;
        newClient->prev = nullptr;
        first = newClient;
    } 
    else {
        newClient->next = first;
        first->prev = newClient;
        newClient->prev = nullptr;
        first = newClient;
    }
}

void insertAfterClient(Client *prec, Client *newClient) {
    if (prec == nullptr) {
        cout << "Predecessor (node acuan) tidak boleh NULL." << endl;
        return;
    }
    
    if (prec->next != nullptr) {
        newClient->next = prec->next; 
        prec->next->prev = newClient; 
    } 
    prec->next = newClient;
    newClient->prev = prec;
}

void insertLastClient(Client *&first, Client *newClient) {
    if (first == nullptr) {
        insertFirstClient(first, newClient);
        return;
    }
    Client *last = first;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newClient;
    newClient->prev = last;
}

void deleteFirstClient(Client *&first) {
    if (first == nullptr) {
        cout << "List kosong, tidak ada Client yang bisa dihapus." << endl;
        return;
    }
    Client *deletedNode = first;
    if (first->next == nullptr) {
        first = nullptr;
    } 
    else {
        first = first->next; 
        first->prev = nullptr; 
    }
    
    delete deletedNode;
    cout << "Client pertama berhasil dihapus." << endl;
}

void deleteAfterClient(Client *prec) {
    if (prec == nullptr || prec->next == nullptr) {
        cout << "Tidak ada node setelah predecessor untuk dihapus." << endl;
        return;
    }
    Client *deletedNode = prec->next;
    if (deletedNode->next == nullptr) {
        prec->next = nullptr;
    } 
    else {
        deletedNode->next->prev = prec;
        prec->next = deletedNode->next;
    }
    deletedNode->prev = nullptr;
    deletedNode->next = nullptr;
    delete deletedNode;
    cout << "Node Client setelah predecessor berhasil dihapus." << endl;
}

void deleteLastClient(Client *&first) {
    if (first == nullptr) {
        cout << "List kosong, tidak ada yang dihapus." << endl;
        return;
    }
    if (first->next == nullptr) {
        deleteFirstClient(first);
        return;
    }
    Client *last = first;
    while (last->next != nullptr) {
        last = last->next;
    }
    Client *beforeLast = last->prev;
    beforeLast->next = nullptr;
    delete last;
    cout << "Client terakhir berhasil dihapus." << endl;
}

void printListClient(Client *first) {
    if (first == nullptr) {
        cout << "List Client kosong." << endl;
        return;
    }

    Client *current = first;
    cout << "--- LIST CLIENT (Doubly Linked List) ---" << endl;
    int count = 1;
    while (current != nullptr) {
        cout << count << ". Nama: " << current->nama << endl;
        current = current->next;
        count++;
    }
    cout << "------------------------------------------" << endl;
}


