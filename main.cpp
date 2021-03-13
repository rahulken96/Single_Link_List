#include "fungsi.cpp"

int main(){
    List l;
    Penitip e;
    address p;
    createList(&l);

    while(true){
        pilih = Pilihan();
        switch (pilih){
        case 1 : 
            system("cls");
            viewList(l);
            break;
        
        case 2 : 
            system("cls");
            if (b>10){
                cout << "*** Data telah penuh! ***\n";
                getch();
            }
            else{
                tambah_data();
                p = alokasi(nama,nim,kelas,{No_loker, barang});
                insertFirst(&l,p);
            }
            b++;
            break;
        
        case 3 :
            system("cls");
            if (b>10){
                cout << "*** Data telah penuh! ***\n";
                getch();
            }
            else{
                cout<<"No.Loker Tujuan  : ";
                cin>>cari_loker;
                stat=test(l, cari_loker);
                if( stat == false){
                    cout<<"No.Loker Tidak Ditmukan !!!\n";
                    getch();
                }
                else{
                    tambah_data();
                    p = alokasi(nama,nim,kelas,{No_loker, barang});
                    insertAfter(&l,p,cari_loker);
                }
            }
            b++;
            break;
            
        case 4 :
            system("cls");
            if (b>10){
                cout << "*** Data telah penuh! ***\n";
                getch();
            }
            else{
                tambah_data();
                p = alokasi(nama,nim,kelas,{No_loker, barang});
                insertLast(&l,p);
            }
            b++;
            break;
            
        case 5 :
            system("cls");
            DeleteFirst(&l);
            break;
        
        case 6 :
            system("cls");
            cout<<"No.Loker Tujuan  : ";
            cin>>cari_loker;
            stat=test(l, cari_loker);
            if( stat == false){
                cout<<"No.Loker Tidak Ditmukan !!!\n";
                getch();
            }
            else{
                DeleteAfter(&l,cari_loker);
            }
            break;

        case 7 :
            system("cls");
            DeleteLast(&l);
            break;

        case 8 :
            system("cls");
            cout<<"No.Loker Tujuan  : ";
            cin>>cari_loker;
            Search(l,cari_loker);
            getch();
            break;

        case 9 :
            system("cls");
            cout<<"No.Loker Tujuan  : ";
            cin>>cari_loker;
            stat=test(l, cari_loker);
            if( stat == false){
                cout<<"No.Loker Tidak Ditmukan !!!\n";
                getch();
            }
            else{
                update_input();
                p = alokasi(nama,nim,kelas,{No_loker, barang});
                UpdateData(&l,p,cari_loker);
            }
            break;

        case 10 :
            system("cls");
            return 0;
            break;

        default:
            break;
        }  
    }

    cin.get();
    return 0;
}
