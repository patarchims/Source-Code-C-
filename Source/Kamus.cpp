// -------------------------------------------------------
// Kamus.cpp
//
// Implementasi kelas DataKamus, SortedDict, dan HashKamus
//     (Aplikasi kamus)
// -------------------------------------------------------

#include <iostream>
#include <string>
#include "Kamus.h"

using namespace std;

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
DataKamus::DataKamus(string kunci, string keterangan)
{
    DataKamus::kunci = kunci;
    DataKamus::keterangan = keterangan;
}

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
SortedDict::SortedDict()
{
    pertama = NULL;
}

// -------------------------------------------------------
// Destruktor
// -------------------------------------------------------
SortedDict::~SortedDict()
{
    removeAll();
}

// -------------------------------------------
// insert() (bersifat publik)
//
// Menyisipkan kunci dan keterangan ke dalam senarai
//   dan menjamin data diurutkan
// Nilai balik:
//   true: berarti berhasil menyisipkan simpul
//   false: ada kunci kembar
// -------------------------------------------
bool SortedDict::insert(string kunci, string keterangan)
{
    // Cari posisi untuk memasukkan data baru
    //   ke dalam senarai
    DataKamus* pendahulu = NULL;
    DataKamus* ptrSekarang = pertama;
    while ( (ptrSekarang != NULL) &&
           (kunci.compare(ptrSekarang->kunci) > 0) )
    {
        pendahulu = ptrSekarang;
        ptrSekarang = ptrSekarang->berikut;
    }

    if (ptrSekarang != NULL)
        if (kunci.compare(ptrSekarang->kunci) == 0)
        {
            // Berarti kunci sudah ada
            return false;
        }

    // Buat simpul baru dan
    //   isikan data ke dalam simpul
    DataKamus* ptrBaru = new DataKamus(kunci, keterangan);

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
// Menghapus simpul yang berisi kunci
// Nilai balik: true kalau berhasil
//              false kalau gagal
// ---------------------------------
bool SortedDict::remove(string kunci)
{
    DataKamus* pendahulu;

    bool ditemukan = find(pendahulu, kunci);
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
        DataKamus* posisiData = pendahulu->berikut;
        pendahulu->berikut = posisiData->berikut;
        delete posisiData;
    }

    return true;
}

// --------------------------------------------
// find()  (bersifat publik)
//
// Mencari kunci dalam senarai
// Nilai balik true kalau ketemu
//    dan pendahulu merujuk ke pendahulu simpul
//    yang dicari
// --------------------------------------------
bool SortedDict::find(DataKamus* &pendahulu, string kunci)
{
    pendahulu = NULL;
    DataKamus* ptrSekarang = pertama;
    bool ditemukan = false;
    while (ptrSekarang != NULL)
    {
        if (kunci.compare(ptrSekarang->kunci) == 0)
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
void SortedDict::display()
{
    DataKamus* ptrData = pertama;
    while (ptrData != NULL)
    {
        cout << ptrData->kunci << ' ';
        ptrData = ptrData->berikut;
    }

    cout << endl;
}

// -------------------------------------------
// removeAll() (publik)
//
// Menghapus semua simpul dalam senarai
// -------------------------------------------
void SortedDict::removeAll()
{
    DataKamus* ptrData;

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
HashKamus::HashKamus(int ukuran)
{
    ukuranTabel = ukuran;
    data.resize(ukuran);

    // Kosongkan tabel hash
    for (int i = 0; i < ukuran; i++)
        HashKamus::data[i] = new SortedDict;
}

// -------------------------------------------------------
// Destruktor
// -------------------------------------------------------
HashKamus::~HashKamus()
{
    for (int i = 0; i < ukuranTabel; i++)
        if (data[i] != NULL)
            data[i]->removeAll();
}

// -------------------------------------------------------
// hasFunction (bersifat publik)
//
// Menghasilkan alamat hash berdasarkan kunci (kunci)
// -------------------------------------------------------
int HashKamus::hashFunction(string kunci)
{
    long int nilai = 0;
    for (int i = 0; i < kunci.length(); i++)
        nilai = nilai * 16 + (kunci[i] - 31);

    if (nilai < 0)
        nilai = -nilai;

    return nilai % ukuranTabel;
}

// -------------------------------------------------------
// insert (bersifat publik)
//
// Untuk menyisipkan data ke tabel hash
// -------------------------------------------------------
void HashKamus::insert(string kunci, string keterangan)
{
    int alamatHash = hashFunction(kunci);
    data[alamatHash]->insert(kunci, keterangan);
}

// -------------------------------------------------------
// find() (bersifat public)
//
// Mencari data.
//    Nilai balik berupa data nama
// -------------------------------------------------------
string HashKamus::find(string kunci)
{
    DataKamus* pendahulu;
    int alamatHash = hashFunction(kunci);
    bool ditemukan = data[alamatHash]->find(pendahulu, kunci);

    if (ditemukan)
      if (pendahulu == NULL)
        return data[alamatHash]->pertama->keterangan;
      else
        return pendahulu->berikut->keterangan;
    else
      return "<tidak ditemukan>";
}

// --------------------------------------------
// remove (bersifat publik)
//
// Menghasilkan false kalau gagal menghapus kunci
//    dan true kalau data berhasil dihapus
// --------------------------------------------
bool HashKamus::remove(string kunci)
{
    int alamatHash = hashFunction(kunci);
    return data[alamatHash]->remove(kunci);
}

// --------------------------------------------
// display (bersifat publik)
//
// Menampilkan isi tabel hash
// --------------------------------------------
void HashKamus::display()
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
