// ------------------------------------------------
// ListAntrian.h
//
// Implementasi kelas SimpulAntrian dan ListAntrian
//     (Aplikasi senarai berantai untuk antrian)
// ------------------------------------------------

#include <iostream>
#include <string>
#include "ListAntrian.h"

using namespace std;

// ------------------------------------
// Konstruktor
// ------------------------------------
SimpulAntrian::SimpulAntrian(char data)
{
    SimpulAntrian::data = data;
    SimpulAntrian::berikut = NULL;
}

// ------------------------------------
// Konstruktor
// ------------------------------------
ListAntrian::ListAntrian()
{
    ListAntrian::pertama = NULL;
    ListAntrian::terakhir = NULL;
}

// ------------------------------------
// Destruktor
// ------------------------------------
ListAntrian::~ListAntrian()
{
    // Menghapus semua simpul
    SimpulAntrian* penunjukHapus;
    while (pertama != NULL)
    {
        penunjukHapus = pertama;
        pertama = pertama->berikut;
        delete penunjukHapus;
    }
}

// ------------------------------------
// insert() (Bersifat publik)
//
// Untuk menyisipkan data
// ------------------------------------
void ListAntrian::insert(char data)
{
    SimpulAntrian* ptrBaru;

    ptrBaru = new SimpulAntrian(data);
    ptrBaru->berikut = NULL;

    if (empty())
      pertama = ptrBaru;
    else
      terakhir->berikut = ptrBaru;

    terakhir = ptrBaru;
}

// ------------------------------------
// empty() (bersifat publik)
//
// Memberikan nilai balik berupa true
//     kalau antrian kosong
// ------------------------------------
bool ListAntrian::empty()
{
    return pertama == NULL;
}

// ------------------------------------
// remove() (bersifat publik)
//
// Mengeluarkan satu yang antri
//     Nilai balik berupa karakter
//     yang dikeluarkan dari antrian
// ------------------------------------
char ListAntrian::remove()
{
    if (empty())
    {
        cout << "Antrian sudah kosong. " << endl;

        return 0;   // Karakter NULL menyatakan
                    // tumpukan sudah kosong
    }

    SimpulAntrian* ptrData;
    char dataAntrian;

    ptrData = pertama;
    dataAntrian = pertama->data;
    pertama = pertama->berikut;
    delete ptrData;

    return dataAntrian;
}

// ------------------------------------
// display() (bersifat publik)
//
// Menampilkan isi antrian
// ------------------------------------
void ListAntrian::display()
{
    SimpulAntrian* ptrData;

    ptrData = pertama;
    while (ptrData != NULL)
    {
        cout << ptrData->data << endl;
        ptrData = ptrData->berikut;
    }
}
