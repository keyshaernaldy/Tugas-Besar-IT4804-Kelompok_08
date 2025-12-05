#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
using namespace std;

struct Developer{
    string nama;
    Developer *next;
    Developer *prev;
};

struct Client{
    string nama;
    Client *next;
    Client *prev;
};

struct Relation{
    Developer *dev;
    Client *cli;
    string namaProject;
    Relation *next;
};
