// ---------------------------------------
// LinkList.cpp
//
// Implementasi kelas Simpul dan LinkList
//     (Aplikasi untuk membalik string)
// ---------------------------------------

#include <iostream>
#include <string>
#include "LinkList.h"

using namespace std;

// ---------------------------------------
// Konstruktor
// ---------------------------------------
Simpul::Simpul(char data)
{
    Simpul::data = data;
    Simpul::berikut = NULL;
}

// ---------------------------------------
// Konstruktor
// ---------------------------------------
LinkList::LinkList()
{
    LinkList::pertama = NULL;
}

// ---------------------------------------
// Destruktor
// ---------------------------------------
LinkList::~LinkList()
{
    // Menghapus semua simpul
    Simpul* penunjukHapus;
    while (pertama != NULL)
    {
        penunjukHapus = pertama;
        pertama = pertama->berikut;
        delete penunjukHapus;
    }
}

// ---------------------------------------
// insert() (Bersifat publik)
//
// Untuk memasukkan data ke dalam senarai
// ---------------------------------------
void LinkList::insert(char data)
{
    Simpul* ptrBaru;

    ptrBaru = new Simpul(data);
    ptrBaru->berikut = pertama;
    pertama = ptrBaru;
}

// ---------------------------------------
// display() (Bersifat publik)
//
// Untuk menampilkan isi senarai
// ---------------------------------------
void LinkList::display()
{
    Simpul* penunjuk = pertama;
    while (penunjuk != NULL)
    {
        cout << penunjuk->data;
        penunjuk = penunjuk->berikut;
    }

    cout << endl; // Pindah baris
}
