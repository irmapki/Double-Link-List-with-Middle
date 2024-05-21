#include <iostream>
using namespace std;

// deklarasi double linked list
struct DataUser{
  string nama, username, email, password;
  DataUser *sebelumnya;
  DataUser *selanjutnya;
};

DataUser *kepala, *ekor, *saat_ini, *nodeBaru, *hapus, *setelahNode;

// Buat Double Linked List
void buatDoubleLinkedList( string data[4] ){
  kepala = new DataUser();
  kepala->nama = data[0];
  kepala->username = data[1];
  kepala->email = data[2];
  kepala->password = data[3];
  kepala->sebelumnya = NULL;
  kepala->selanjutnya = NULL;
  ekor = kepala;
}

// hitung Double Linked List
int hitungDoubleLinkedList()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    saat_ini = kepala;
    int jumlah = 0;
    while( saat_ini != NULL ){
      jumlah++;      
      // pindah
      saat_ini = saat_ini->selanjutnya;
    }
    return jumlah;
  }
}

// Tambah Awal
void tambahAwal( string data[4] ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    nodeBaru = new DataUser();
    nodeBaru->nama = data[0];
    nodeBaru->username = data[1];
    nodeBaru->email = data[2];
    nodeBaru->password = data[3];
    nodeBaru->sebelumnya = NULL;
    nodeBaru->selanjutnya = kepala;
    kepala->sebelumnya = nodeBaru;
    kepala = nodeBaru;
  }
}

// Tambah Akhir
void tambahAkhir( string data[4] ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    nodeBaru = new DataUser();
    nodeBaru->nama = data[0];
    nodeBaru->username = data[1];
    nodeBaru->email = data[2];
    nodeBaru->password = data[3];
    nodeBaru->sebelumnya = ekor;
    nodeBaru->selanjutnya = NULL;
    ekor->selanjutnya = nodeBaru;
    ekor = nodeBaru;
  }
}

// Tambah Tengah
void tambahTengah( string data[4], int posisi ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{

    if( posisi == 1 ){
      cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
    }else if( posisi < 1 || posisi > hitungDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!!" << endl;
    }else{
      nodeBaru = new DataUser();
      nodeBaru->nama = data[0];
      nodeBaru->username = data[1];
      nodeBaru->email = data[2];
      nodeBaru->password = data[3];

      // traversing
      saat_ini = kepala;
      int nomor = 1;
      while( nomor <  posisi - 1){
        saat_ini = saat_ini->selanjutnya;
        nomor++;
      }

      setelahNode = saat_ini->selanjutnya;
      nodeBaru->sebelumnya = saat_ini;
      nodeBaru->selanjutnya = setelahNode;
      saat_ini->selanjutnya = nodeBaru;
      setelahNode->sebelumnya = nodeBaru;
    }

  }
}

// hapus Awal
void hapusAwal()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    hapus = kepala;
    kepala = kepala->selanjutnya;
    kepala->sebelumnya = NULL;
    delete hapus;
  }
}

// hapus Akhir
void hapusAkhir()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    hapus = ekor;
    ekor = ekor->sebelumnya;
    ekor->selanjutnya = NULL;
    delete hapus;
  }
}

// hapus Tengah
void hapusTengah(int posisi){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    if( posisi == 1 || posisi == hitungDoubleLinkedList() ){
      cout << "Posisi bukan posisi tegah!!" << endl;
    }else if( posisi < 1 || posisi > hitungDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!" << endl;
    }else{
      int nomor = 1;
      saat_ini = kepala;
      while( nomor < posisi - 1 ){
        saat_ini = saat_ini->selanjutnya;
        nomor++;
      }
      hapus = saat_ini->selanjutnya;
      setelahNode = hapus->selanjutnya;
      saat_ini->selanjutnya = setelahNode;
      setelahNode->sebelumnya = saat_ini;
      delete hapus;
    }
  }
}

// Cetak Double Linked List
void cetakDoubleLinkedList()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cout << "Jumlah Data : " << hitungDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    saat_ini = kepala;
    while( saat_ini != NULL ){
      // cetak
      cout << "Nama User : " << saat_ini->nama << endl;
      cout << "Username User : " << saat_ini->username << endl;
      cout << "Email User : " << saat_ini->email << endl;
      cout << "Password User : " << saat_ini->password << "\n" << endl;
      // pindah
      saat_ini = saat_ini->selanjutnya;
    }
  }
}

int main(){

  string newData[4] = {"Irma Fatimatuz Zahro", "jimet", "irmakayang@gmail.com", "tahu_uap"};
  buatDoubleLinkedList(newData);

  cetakDoubleLinkedList();

  string data2[4] = {"Muhammad Diluc", "dilucxx", "dilukgemsing@gmail.com", "dilucgantenglovvv"};

  tambahAwal( data2 );

  cetakDoubleLinkedList();

  string data3[4] = {"Pace Mace", "pacmac", "sayapapua@gmail.com", "yppa"};

  tambahAkhir( data3 );

  cetakDoubleLinkedList();

  string data4[4] = {"Nur sagiri", "sagri", "akuloli@gmail.com", "sgr"};
  tambahTengah(data4, 3);

  cetakDoubleLinkedList();

  hapusTengah(2);

  cetakDoubleLinkedList();


}