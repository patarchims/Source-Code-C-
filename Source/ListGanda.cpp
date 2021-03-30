// --------------------------------------------
// ListGanda.cpp
//
// Implementasi kelas SimpulGanda dan ListGanda
//     (Aplikasi senarai berantai ganda)
// --------------------------------------------

#include <iostream>
#include <string>
#include "ListGanda.h"

using namespace std;

// -------------------------------------------
// Konstruktor
// -------------------------------------------
SimpulGanda::SimpulGanda(char data)
{
    // Konstruktor

    SimpulGanda::data = data;
    SimpulGanda::berikut = NULL;
    SimpulGanda::sebelum = NULL;
}

// -------------------------------------------
// Konstruktor
// -------------------------------------------
ListGanda::ListGanda()
{
    // Konstruktor
    ListGanda::pertama = NULL;
    ListGanda::terakhir = NULL;
}

// -------------------------------------------
// Destruktor
// -------------------------------------------
ListGanda::~ListGanda()
{
    // Destruktor

    // Menghapus semua simpul
    SimpulGanda* penunjukHapus;
    while (pertama != NULL)
    {
        penunjukHapus = pertama;
        pertama = pertama->berikut;
        delete penunjukHapus;
    }
}

// -------------------------------------------
// insertFirst() (Bersifat publik)
//
// Menyisipkan data ke dalam senarai
//   sehingga akan ditunjuk oleh pertama
// -------------------------------------------
void ListGanda::insertFirst(char data)
{
    // Buat simpul baru dan
    //   isikan Karakter ke dalam simpul
    SimpulGanda* ptrBaru = new SimpulGanda(data);

    // Atur penunjuk ke simpul
    if (empty())
        terakhir = ptrBaru;
    else
        pertama->sebelum = ptrBaru;

    ptrBaru->berikut = pertama;
    ptrBaru->sebelum = NULL;
    pertama = ptrBaru;
}

// -------------------------------------------
// insertLast() (Bersifat publik)
//
// Menyisipkan data ke akhir senarai
// -------------------------------------------
void ListGanda::insertLast(char data)
{
    // Buat simpul baru dan
    //   isikan karakter ke dalam simpul
    SimpulGanda* ptrBaru = new SimpulGanda(data);

    // Atur penunjuk ke simpul
    if (empty())
        pertama = ptrBaru;
    else
    {
        terakhir->berikut = ptrBaru;
        ptrBaru->sebelum = terakhir;
    }

    ptrBaru->berikut = NULL;
    terakhir = ptrBaru;
}

// -------------------------------------------
// insertAfter() (Bersifat publik)
//
// Menyisipkan data ke sesudah kunci kunci
// -------------------------------------------
bool ListGanda::insertAfter(char kunci, char data)
{
    char ditemukan = false;

    // Cari posisi Key
    SimpulGanda* ptrData = pertama;
    while (ptrData != NULL)
    {
        if (ptrData->data ==  kunci)
        {
            ditemukan = true;
            break;
        }

        ptrData = ptrData->berikut;
    }

    // Cek kalau tidak ditemukan
    if (! ditemukan)
    {
        return false;
    }

    // Buat simpul baru dan
    //   isikan data ke dalam simpul
    SimpulGanda* ptrBaru = new SimpulGanda(data);

    // Atur penunjuk ke simpul
    if (ptrData == terakhir)
    {
        ptrBaru->berikut = NULL;
        terakhir = ptrBaru;
    }
    else
    {
        ptrBaru->berikut = ptrData->berikut;
        ptrData->berikut->sebelum = ptrBaru;
    }

    ptrBaru->sebelum = ptrData;
    ptrData->berikut = ptrBaru;

    return true;
}

// -------------------------------------------
// empty() (Bersifat publik)
//
// Menghasilkan true kalau senarai kosong
//    atau false kalau tidak kosong
// -------------------------------------------
bool ListGanda::empty()
{
    return pertama == NULL;
}

// -------------------------------------------
// removeFirst() (Bersifat publik)
//
// Menghapus data pada simpul yang
//    ditunjuk oleh pertama
// -------------------------------------------
char ListGanda::removeFirst()
{
    if (empty())
    {
        cout << "Tumpukan sudah kosong" << endl;
        return 0;
    }

    char data = pertama->data;
    SimpulGanda* ptrData = pertama;
    if (pertama->berikut == NULL)
        terakhir = NULL;
    else
        pertama->berikut->sebelum = NULL;

    pertama = pertama->berikut;
    delete ptrData;

    return data;
}

// -------------------------------------------
// removeLast() (Bersifat publik)
//
// Menghapus data pada simpul yang
//    ditunjuk oleh terakhir
// -------------------------------------------
char ListGanda::removeLast()
{
    if (empty())
    {
        cout << "Tumpukan sudah kosong" << endl;
        return 0;
    }

    char data = terakhir->data;
    SimpulGanda* ptrData = terakhir;
    if (pertama->berikut == NULL)
        pertama = NULL;
    else
        terakhir->sebelum->berikut = NULL;

    terakhir = terakhir->sebelum;
    delete ptrData;

    return data;
}

// -------------------------------------------
// removeKey() (Bersifat publik)
//
// Menghapus simpul yang sesuai dengan kunci
// Hasil true kalau data dihapus
//       false kalau tak ada yang dihapus
// -------------------------------------------
bool ListGanda::removeKey(char data)
{
    SimpulGanda* ptrData = pertama;
    while (ptrData->data != data)
    {
        ptrData = ptrData->berikut;
        if (ptrData == NULL)
        {
           return false;
        }
    }

    if (ptrData == pertama)
        pertama = ptrData->berikut;
    else
        ptrData->sebelum->berikut = ptrData->berikut;

    if (ptrData == terakhir)
        terakhir = ptrData->sebelum;
    else
        ptrData->berikut->sebelum = ptrData->sebelum;

    delete ptrData;

    return true;
}

// -------------------------------------------
// displayForward() (Bersifat publik)
//
// Menampilkan isi senarai
//   dari pertama ke terakhir
// -------------------------------------------
void ListGanda::displayForward()
{
    cout << "Dari pertama ke terakhir: " << endl;
    SimpulGanda* ptrData = pertama;
    while (ptrData != NULL)
    {
      cout << ptrData->data;
      ptrData = ptrData->berikut;
    }

    cout << endl; // Pindah baris
}

// -------------------------------------------
// displayBackward() (Bersifat publik)
//
// Menampilkan isi senarai
//    dari terakhir ke pertama
// -------------------------------------------
void ListGanda::displayBackward()
{
    cout << "Dari terakhir ke pertama: " << endl;
    SimpulGanda* ptrData = terakhir;
    while (ptrData != NULL)
    {
      cout << ptrData->data;
      ptrData = ptrData->sebelum;
    }

    cout << endl; // Pindah baris
}
