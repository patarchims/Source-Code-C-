// -------------------------------------------
// ListUrut.cpp
//
// Implementasi kelas SimpulData dan ListUrut
//     (Aplikasi untuk mengurutkan data)
// -------------------------------------------

#include <iostream>
#include <string>
#include "ListUrut.h"

using namespace std;

// -------------------------------------------
// Konstruktor
// -------------------------------------------
SimpulData::SimpulData(char data)
{
    // Konstruktor

    SimpulData::data = data;
    SimpulData::berikut = NULL;
}

// -------------------------------------------
// Konstruktor
// -------------------------------------------
ListUrut::ListUrut()
{
    ListUrut::pertama = NULL;
}

// -------------------------------------------
// Destruktor
// -------------------------------------------
ListUrut::~ListUrut()
{
    // Menghapus semua simpul
    SimpulData* penunjukHapus;
    while (pertama != NULL)
    {
        penunjukHapus = pertama;
        pertama = pertama->berikut;
        delete penunjukHapus;
    }
}

// -------------------------------------------
// insert() (Bersifat publik)
//
// Untuk menyisipkan data
// -------------------------------------------
void ListUrut::insert(char data)
{
    SimpulData* ptrBaru;

    ptrBaru = new SimpulData(data);
    ptrBaru->berikut = NULL;

    // Cari posisi untuk memasukkan data baru
    //   ke dalam senarai

    SimpulData* pendahulu = NULL;
    SimpulData* ptrSekarang = pertama;

    while ((ptrSekarang != NULL) &&
        (data > ptrSekarang->data))
    {
        cout << "Next" << endl;
        pendahulu = ptrSekarang;
        ptrSekarang = ptrSekarang->berikut;
    }

    if (pendahulu == NULL)
        pertama = ptrBaru;
    else
        pendahulu->berikut = ptrBaru;

    ptrBaru->berikut = ptrSekarang;
}

// --------------------------------------------
// empty() (bersifat publik)
//
// Menghasilkan nilai true kalau senarai kosong
// --------------------------------------------
bool ListUrut::empty()
{
    return pertama == NULL;
}

// -------------------------------------------
// remove() (bersifat publik)
//
// Menghapus sebuah data pada antrian
// -------------------------------------------
char ListUrut::remove()
{
    if (empty())
    {
        cout << "Senarai sudah kosong. " << endl;

        return 0;   // Karakter NULL menyatakan
                    // tumpukan sudah kosong
    }

    SimpulData* ptrData;
    char dataAntrian;

    ptrData = pertama;
    dataAntrian = pertama->data;
    pertama = pertama->berikut;
    delete ptrData;

    return dataAntrian;
}

// -------------------------------------------
// display() (Bersifat publik)
//
// Menampilkan isi senarai
// -------------------------------------------
void ListUrut::display()
{
    SimpulData* ptrData;

    ptrData = pertama;
    while (ptrData != NULL)
    {
        cout << ptrData->data << endl;
        ptrData = ptrData->berikut;
    }
}
