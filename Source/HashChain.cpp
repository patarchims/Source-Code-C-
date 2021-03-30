// ------------------------------------------------------
// HashChain.cpp
//
// Implementasi kelas DataHash, SortedList, dan HashChain
//     (Tabel hash dengan Hash Chaining)
// ------------------------------------------------------

#include <iostream>
#include <string>
#include "HashChain.h"

using namespace std;

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
DataHash::DataHash(int nip, string nama)
{
    DataHash::nip = nip;
    DataHash::nama = nama;
}

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
SortedList::SortedList()
{
    pertama = NULL;
}

// -------------------------------------------------------
// Destruktor
// -------------------------------------------------------
SortedList::~SortedList()
{
    removeAll();
}

// -------------------------------------------
// insert() (bersifat publik)
//
// Menyisipkan Nip dan Nama ke dalam senarai
//   dan menjamin data diurutkan
// Nilai balik:
//   True: berarti berhasil menyisipkan simpul
//   False: ada Nip kembar
// -------------------------------------------
bool SortedList::insert(int nip, string nama)
{
    // Cari posisi untuk memasukkan data baru
    //   ke dalam senarai
    DataHash* pendahulu = NULL;
    DataHash* ptrSekarang = pertama;
    while ( (ptrSekarang != NULL) &&
        (nip > ptrSekarang->nip) )
    {
        pendahulu = ptrSekarang;
        ptrSekarang = ptrSekarang->berikut;
    }

    if (ptrSekarang != NULL)
        if (ptrSekarang->nip == nip)
        {
            // Berarti Nip sudah ada
            return false;
        }

    // Buat simpul baru dan
    //   isikan data ke dalam simpul
    DataHash* ptrBaru = new DataHash(nip, nama);

    // Letakkan ke dalam senarai
    if (pendahulu == NULL)
        pertama = ptrBaru;
    else
        pendahulu->berikut = ptrBaru;

    ptrBaru->berikut = ptrSekarang;

    return true;
}

// ---------------------------------
// remove() (bersifat publik)
//
// Menghapus simpul yang berisi Nip
// Nilai balik: true kalau berhasil
//              false kalau gagal
// ---------------------------------
bool SortedList::remove(int nip)
{
    DataHash* pendahulu;

    bool ditemukan = find(pendahulu, nip);
    if (! ditemukan)
    {
        cout << "Data tidak ada" << endl;
        return false;
    }

    if (pendahulu == NULL)
    {
        // Data yang dihapus ditunjuk oleh pertama
        pendahulu = pertama;
        pertama = pertama->berikut;
        delete pendahulu;
    }
    else
    {
        // Yang dihapus tidak ditunjuk Pertama
        DataHash* posisiData = pendahulu->berikut;
        pendahulu->berikut = posisiData->berikut;
        delete posisiData;
    }

    return true;
}

// --------------------------------------------
// find()  (bersifat publik)
//
// Mencari NIP dalam senarai
// Nilai balik true kalau ketemu
//    dan pendahulu merujuk ke pendahulu simpul
//    yang dicari
// --------------------------------------------
bool SortedList::find(DataHash* &pendahulu, int nip)
{
    pendahulu = NULL;
    DataHash* ptrSekarang = pertama;
    bool ditemukan = false;
    while (ptrSekarang != NULL)
    {
        if (ptrSekarang->nip == nip)
        {
            ditemukan = true;
            break;
        }

        pendahulu = ptrSekarang;
        ptrSekarang = ptrSekarang->berikut;
    }

    return ditemukan;
}

// ---------------------------------
// display()  (bersifat publik)
//
// Menampilkan isi senarai
// ---------------------------------
void SortedList::display()
{
    DataHash* ptrData = pertama;
    while (ptrData != NULL)
    {
        cout << ptrData->nip << ' ';
        ptrData = ptrData->berikut;
    }

    cout << endl;
}

// -------------------------------------------
// removeAll() (publik)
//
// Menghapus semua simpul dalam senarai
// -------------------------------------------
void SortedList::removeAll()
{
    DataHash* ptrData;

    while (pertama != NULL)
    {
        ptrData = pertama;
        pertama = pertama->berikut;

        delete ptrData;
    }
}

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
HashChain::HashChain(int ukuran)
{
    ukuranTabel = ukuran;
    data.resize(ukuran);

    // Kosongkan tabel hash
    for (int i = 0; i < ukuran; i++)
        HashChain::data[i] = new SortedList;
}

// -------------------------------------------------------
// Destruktor
// -------------------------------------------------------
HashChain::~HashChain()
{
    for (int i = 0; i < ukuranTabel; i++)
        if (data[i] != NULL)
            data[i]->removeAll();
}

// -------------------------------------------------------
// hasFunction (bersifat publik)
//
// Menghasilkan alamat hash berdasarkan kunci (nip)
// -------------------------------------------------------
int HashChain::hashFunction(int nip)
{
    return nip % ukuranTabel;
}

// -------------------------------------------------------
// insert (bersifat publik)
//
// Untuk menyisipkan data ke tabel hash
// -------------------------------------------------------
void HashChain::insert(int nip, string nama)
{
    int alamatHash = hashFunction(nip);
    data[alamatHash]->insert(nip, nama);
}

// -------------------------------------------------------
// find() (bersifat public)
//
// Mencari data.
//    Nilai balik berupa data nama
// -------------------------------------------------------
string HashChain::find(int nip)
{
    DataHash* pendahulu;
    int alamatHash = hashFunction(nip);
    bool ditemukan = data[alamatHash]->find(pendahulu, nip);

    if (ditemukan)
      if (pendahulu == NULL)
        return data[alamatHash]->pertama->nama;
      else
        return pendahulu->berikut->nama;
    else
      return "<tidak ditemukan>";
}

// --------------------------------------------
// remove (bersifat publik)
//
// Menghasilkan false kalau gagal menghapus Nip
//    dan true kalau data berhasil dihapus
// --------------------------------------------
bool HashChain::remove(int nip)
{
    int alamatHash = hashFunction(nip);
    return data[alamatHash]->remove(nip);
}

// --------------------------------------------
// display (bersifat publik)
//
// Menampilkan isi tabel hash
// --------------------------------------------
void HashChain::display()
{
    for (int i=0; i < ukuranTabel; i++)
    {
        if (data[i] == NULL)
            cout << i << ": (Kosong) " << endl;
        else
        {
            cout << i << ": ";
            data[i]->display();
        }
    }
}
