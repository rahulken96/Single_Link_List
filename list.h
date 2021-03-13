#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string>

#define nil NULL
#define info(p) p->info
#define next(p) p->next
#define first(l) l->first

using namespace std;

string nama,nim,kelas,barang;
int No_loker, b = 1,pilih,cari_loker;
bool stat;

typedef struct elmList *address;

struct Loker{
    int No_loker;
    string barang;
};

struct Penitip{
    string nama;
    string nim;
    string kelas;
    Loker no_loker;
};

struct elmList{ 
    Penitip info;
    address next;
};

struct List{
    address first;
}l;

void createList(List *l);
address alokasi (string nama, string nim, string kelas, Loker no_loker);
void insertFirst(List *l, address p);
void insertAfter(List *l, address elm, int cari_loker);
void insertLast(List *l, address p);
void DeleteFirst(List *l);
void DeleteLast(List *l);
void DeleteAfter(List *l, int cari_loker);
void viewList(List l);
void dealokasi(address p);
address Search(List l, int no_loker);
void UpdateData(List *l, address p, int cari_loker);
void pause(List l);
void tambah_data();
void update_input();
int Pilihan();
bool test(List l, int cari_loker);
bool cekloker(List l,int No_loker);
int inputloker(List l);


#endif
