// ------------------------------------------------
// DoubleHash.cpp
//
// Implementasi kelas DataHash dan doubleHashing
//      (Tabel hash dengan double hashing)
// ------------------------------------------------

#include <iostream>
#include <string>
#include "DoubleHash.h"

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
DoubleHashing::DoubleHashing(int ukuran)
{
    ukuranTabel = ukuran;
    data.resize(ukuran);

    // Kosongkan tabel hash
    for (int i = 0; i < ukuran; i++)
    {
        DoubleHashing::data[i] = NULL;
    }

    // Tandai NIP dengan -1 untuk menyatakan terhapus
    ptrTerhapus = new DataHash(-1, "");
}

// -------------------------------------------------------
// Destruktor
// -------------------------------------------------------
DoubleHashing::~DoubleHashing()
{
    for (int i = 0; i < ukuranTabel; i++)
    {
        if (data[i] != NULL)
            if (data[i]->nip != -1)
                delete data[i];
    }

    delete ptrTerhapus;
}

// -------------------------------------------------------
// hasFunction1 (bersifat publik)
//
// Menghasilkan alamat hash berdasarkan kunci (nip)
// -------------------------------------------------------
int DoubleHashing::hashFunction1(int nip)
{
    return nip % ukuranTabel;
}

// ---------------------------------------------
// hashFunction2() (bersifat publik)
//
// Menghasilkan langkah untuk penambahan atau
//    pencarian data
//    Nilai balik selalu lebih besar daripada 0
// ---------------------------------------------
int DoubleHashing::hashFunction2(int nip)
{
    return 1 + (nip % 5);
}
// -------------------------------------------------------
// insert (bersifat publik)
//
// Untuk menyisipkan data ke tabel hash
// -------------------------------------------------------
void DoubleHashing::insert(int nip, string nama)
{
    int alamatHash = hashFunction1(nip);
    int langkah = hashFunction2(nip);
    int i = 0;
    while ((data[alamatHash] != NULL) &&
          (data[alamatHash]->nip != -1))
    {
        if (i > ukuranTabel)
            break;  // Keluar kalau sudah penuh

        // Peroleh alamat berikutnya
        alamatHash = (alamatHash + langkah) % ukuranTabel;
        i++;  // Untuk menghitung sampai penuh
    }

    if (i < ukuranTabel)
        data[alamatHash] = new DataHash(nip, nama);
}

// -------------------------------------------------------
// find() (bersifat public)
//
// Mencari data.
//    Nilai balik berupa data nama
// -------------------------------------------------------
string DoubleHashing::find(int nip)
{
    int alamatHash = hashFunction1(nip);
    int langkah = hashFunction2(nip);
    int i = 1;
    while (data[alamatHash] != NULL)
    {
        if (i > ukuranTabel)
            break;  // Keluar kalau semua sudah dicek

        // Cek nilai nip sama dengan nip yang dicari
        if (data[alamatHash]->nip == nip)
            break; // Keluar while

        // Peroleh alamat berikutnya
        alamatHash = (alamatHash + langkah) % ukuranTabel;
        i++;
    }

    if ((i <= ukuranTabel) &&
       (data[alamatHash] != NULL))
        return data[alamatHash]->nama;
    else
        return "<Tidak ditemukan>"; // Kalau tidak ditemukan
}

// --------------------------------------------
// remove (bersifat publik)
//
// Menghasilkan false kalau gagal menghapus Nip
//    dan true kalau data berhasil dihapus
// --------------------------------------------
bool DoubleHashing::remove(int nip)
{
    int alamatHash = hashFunction1(nip);
    int langkah = hashFunction2(nip);
    int i = 1;
    while (data[alamatHash] != NULL)
    {
        if (i > ukuranTabel)
            break;  // Keluar kalau semua sudah dicek

        // Cek nilai field Nip sama dengan Nip
        if (data[alamatHash]->nip == nip)
        {
            // Bebaskan memori yang digunakan
            //    untuk menyimpan data
            delete data[alamatHash];

            // Alihkan ke pointer yang menyatakan
            //    data terhapus
            data[alamatHash] = ptrTerhapus;
            break; // Keluar while
        }

        // Peroleh alamat berikutnya
        alamatHash = (alamatHash + langkah) % ukuranTabel;
        i++;  // Untuk menghitung sampai semua
    }

    if ((i < ukuranTabel) &&
       (data[alamatHash] != NULL))
        return true;
    else
        return false; // gagal menghapus
}

// --------------------------------------------
// display (bersifat publik)
//
// Menampilkan isi tabel hash
// --------------------------------------------
void DoubleHashing::display()
{
    for (int i=0; i < ukuranTabel; i++)
    {
        if (data[i] == NULL)
            cout << i << ": (Kosong) " << endl;
        else
            if (data[i]->nip == -1)
                cout << i << ": (Terhapus) " << endl;
            else
                cout << i << ": "
                     << data[i]->nip << "-"
                     << data[i]->nama << endl;
    }
}
