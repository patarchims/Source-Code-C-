// --------------------------------------------------
// LinkTumpukan.cpp
//
// Implementasi kelas SimpulTumpukan dan ListTumpukan
//     (Aplikasi untuk membalik string)
// --------------------------------------------------

#include <iostream>
#include <string>
#include "ListTumpukan.h"

using namespace std;

// ----------------------------------------
// Konstruktor
// ----------------------------------------
SimpulTumpukan::SimpulTumpukan(char data)
{
    SimpulTumpukan::data = data;
    SimpulTumpukan::berikut = NULL;
}

ListTumpukan::ListTumpukan()
{
    ListTumpukan::puncak = NULL;
}

// ----------------------------------------
// Destruktor
// ----------------------------------------
ListTumpukan::~ListTumpukan()
{
    // Menghapus semua simpul
    SimpulTumpukan* penunjukHapus;
    while (puncak != NULL)
    {
        penunjukHapus = puncak;
        puncak = puncak->berikut;
        delete penunjukHapus;
    }
}

// ----------------------------------------
// push()  (Bersifat publik)
//
// Untuk memasukkan data ke dalam tumpukan
// ----------------------------------------
void ListTumpukan::push(char data)
{
    SimpulTumpukan* ptrBaru;

    ptrBaru = new SimpulTumpukan(data);
    ptrBaru->berikut = puncak;
    puncak = ptrBaru;
}

// ----------------------------------------
// empty() (Bersifat publik)
//
// Menghasilkan true kalau tumpukan dalam
//     keadaan kosong
// ----------------------------------------
bool ListTumpukan::empty()
{
    return puncak == NULL;
}

// ----------------------------------------
// pop() (Bersifat publik)
//
// Mengambil sebuah nilai dari tumpukan
// ----------------------------------------

char ListTumpukan::pop()
{
    if (empty())
    {
        cout << "Tumpukan sudah kosong. "
             << "Tidak bisa diambil lagi" << endl;
        return 0;   // Karakter NULL menyatakan
                    // tumpukan sudah kosong
    }

    SimpulTumpukan* ptrData;
    char data;

    ptrData = puncak;
    data = puncak->data;
    puncak = puncak->berikut;
    delete ptrData;

    return data;
}


