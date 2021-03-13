#include "list.h"

void createList(List *l){
    first(l) = nil;
}

address alokasi (string nama, string nim, string kelas, Loker no_loker){
    address p = new elmList;
	p->info.nama = nama;
	p->info.nim = nim;
	p->info.kelas = kelas;
	p->info.no_loker.No_loker = No_loker;
    p->info.no_loker.barang = barang;

	next(p) = nil;
	return p;

}

void insertFirst(List *l, address p){
	next(p) = first(l);
	first(l) = p;
    p = nil;
}

void insertAfter(List *l, address elm, int cari_loker){
    if (first(l) != nil){
        address p = first(l);
        while(p != nil){
            if(cari_loker == p->info.no_loker.No_loker){
                elm->next = next(p);
                next(p) = elm;
                return;
            }
            p = next(p);
        }
    }
    else{
        insertFirst(l, elm);
    }
}

void insertLast(List *l, address p){
    if (first(l) == nil){
        insertFirst(l,p);
    }
    else{
        address p=first(l);
        while (next(p) != nil){
            p = next(p);
        }
        next(p) = p;
        p = nil;
    }
}

void DeleteFirst(List *l){
    if(first(l) != nil){
        address p = first(l);
        first(l) = next(p);
        next(p) = nil;

        dealokasi(p);
    }
    else{
        cout << "List sudah kosong!\n\n";
    }
    getch();
}

void DeleteLast(List *l){
    if(first(l) != nil){
        address p = first(l);
        if(next(p) == nil){
            DeleteFirst(l);
        }
        else{
            address q = p;
            p = q->next;
            while(next(p) != nil){
                q = p;
                p = q->next;
            }

            q->next = nil;
            dealokasi(p);
        }
    }
    else{
        cout << "List telahh kosong!\n";
        getch();
    }
}

void DeleteAfter(List *l, int cari_loker){
    if(first(l) != nil){
        address p = first(l);
        // int i = 1;
        while(p != nil){
            if (next(p) == nil){
                DeleteLast(l);
            }
            else{
                address q = next(p);
                next(p) = q->next;
                q->next = nil;
                dealokasi(q);
            }
        }
        p = next(p);
        // i++;
    }
    else{
        cout <<"List kosong!\n";
        getch();
    }
}

void viewList(List l){
    if(l.first == NULL){
        cout << "Data Masih Kosong!!";
    }
    address p = new elmList;
    p = l.first;
    while(p != nil){
		cout<< "No Loker : " << p->info.no_loker.No_loker
        <<"\nNama\t: " << p->info.nama << "\nNIM\t: " << p->info.nim
        << "\nKelas\t: " << p->info.kelas << "\nBarang\t: " << p->info.no_loker.barang
        << endl;
        p = next(p);
        // j++;
    }
    getch();
}

void dealokasi(address p){
    delete p;
    cout << "List sudah terhapus!\n";
}

address Search(List l, int cari_loker){
    address p = l.first;
    if(l.first != nil){
        while(p != nil && cari_loker != p->info.no_loker.No_loker){
            p = next(p);
        }
        if(p != nil){
            cout << "No Loker : " << p->info.no_loker.No_loker
            <<"\nNama\t: " << p->info.nama
            << "\nNIM\t: " << p->info.nim
            << "\nKelas\t: " << p->info.kelas
            << "\nBarang\t: " << p->info.no_loker.barang
            << endl;
            }
        else{
            cout <<"Data Tidak Ditemukan!!\n";
        }
    }
    else{
        cout <<"Data Tidak Ditemukan!!\n";
    }
}

void UpdateData(List *l, address elm, int cari_loker){
    address p = first(l);
    while(p != nil){
        if(cari_loker == p->info.no_loker.No_loker){
            p->info.nama = elm->info.nama;
            p->info.kelas = elm->info.kelas;
            p->info.nim = elm->info.nim;
            p->info.no_loker.barang = elm->info.no_loker.barang;
        }
        p = next(p);
    }
}


void tambah_data(){
    system("cls");
    do{
        cout<<"Loker : ";
        cin>>No_loker;
        stat = cekloker(l,No_loker);
    }while(stat == true);
    cout <<"Masukkan nama : "; cin >> nama ;
    cout <<"Msasukkan NIM : "; cin >> nim;
    cout <<"Masukkan Kelas : "; cin >> kelas;
    cout <<"Masukkan Barang : "; cin >> barang;
}

void update_input(){
    system("cls");
    cout <<"Masukkan nama : "; cin >> nama ;
    cout <<"Masukkan NIM : "; cin >> nim;
    cout <<"Masukkan Kelas : "; cin >> kelas;
    cout <<"Masukkan Barang : "; cin >> barang;
}

int Pilihan(){
    system("cls");
    cout<<"1.Tampilkan Data\n2.Tambah Data Awal\n3.Tambah ";
    cout<<"Data Setelah..\n4.Tambah Data Akhir\n5.Hapus Data Awal\n6.Hapus ";
    cout<<"Data Setelah..\n7.Hapus Data Akhir \n8.Cari Data\n9.Update Data\n";
    cout<<"10.Keluar Program\n\n";
    cout<<"Pilih : ";
    cin>>pilih;
    return pilih;
}

/*
    cout<<"1.Tanpilkan Data\n2.Tambah Data Di Awal\n3.Tambah ";
    cout<<"Data Di Akhir\n4.Delete Data\n5.Cari Data\n6.Hitung ";
    cout<<"Jumlah Data\n7.Tambah Data Setelah\n8.Update Data\n9.Keluar Program\n";
    cout<<"  Pilih : ";
*/

bool test(List l, int cari_loker){
    address p = l.first;
    while(p != nil){
            if(cari_loker == p->info.no_loker.No_loker){
                return true;
                break;
            }
        p = next(p);
    }
    return false;
}

bool cekloker(List l,int No_loker){
    address p = new elmList;
    p = l.first;
        while(p != nil){
            if(No_loker == p->info.no_loker.No_loker){
                return false;
                break;
            }
            else{
                return true;
                break;
            }
            p = next(p);
        }
}
