// ------------------------------------------------
// Binary.cpp
//
// Implementasi kelas BinarySearch
// ------------------------------------------------

#include <iostream>
#include <string>
#include "Binary.h"

using namespace std;

// -------------------------------------------------------
// Destruktor
// -------------------------------------------------------
BinarySearch::BinarySearch(int data[], int jumData)
{
    BinarySearch::jumData = jumData;
    BinarySearch::data.resize(jumData);
    for (int i = 0; i < jumData; i++)
    {
        BinarySearch::data[i] = data[i];
    }
}

// -------------------------------------------------------
// find() (bersifat public)
//
// Mencari data.
//    Nilai balik berupa indeks dalam vektor yang
//    menyatakan tempat data yang dicari sekiranya
//    data ditemukan. Nilai balik berupa -1 kalau data
//    tidak ditemukan
// -------------------------------------------------------
int BinarySearch::find(int dicari)
{
    int atas, bawah, tengah, posisi;
    bool ada;

    ada = false;
    bawah = 0;
    atas = jumData - 1;
    while (atas >= bawah)
    {
        tengah = (atas + bawah) / 2;
        if (dicari > data[tengah])
            bawah = tengah + 1;
        else if (dicari < data[tengah])
            atas = tengah - 1;
        else
        {
            ada = true;        // Ditemukan
            posisi = tengah;
            bawah = atas + 1;  // Mengakhiri pengulangan
        }
    }

    if (!ada)
        posisi = -1;

    return posisi;
}

// -------------------------------------------------------
// display() (bersifat public)
//
// Menampilkan data
// -------------------------------------------------------
void BinarySearch::display()
{
    for (unsigned int i = 0; i < jumData; i++)
        cout << data[i] << ' ';

    cout << endl;
}
