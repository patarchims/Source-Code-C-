// ------------------------------------------------
// MergeSort.cpp
//
// Implementasi kelas MergeSort
// ------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include "MergeSort.h"

using namespace std;

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
MergeSort::MergeSort(unsigned int ukuran)
{
    jumData = 0;
    ukuranMaksimum = ukuran;
    data.resize(ukuran);
}

// -------------------------------------------------------
// insert() (bersifat publik)
//
// Menambahkan data ke dalam vektor data
// -------------------------------------------------------
void MergeSort::insert(int data)
{
    if (jumData == ukuranMaksimum)
    {
        cout << "Kapasitas data sudah tercapai." << endl;
        cout << "Penambahan data " << data
             << " tidak dapat dilakukan." << endl;
        return;
    }

    MergeSort::data[jumData++] = data;
}

// -------------------------------------------------------
// reset() (bersifat publik)
//
// Mengosongkan data dalam vektor
// -------------------------------------------------------
void MergeSort::reset()
{
    jumData = 0;
}

// -------------------------------------------------------
// length() (bersifat publik)
//
// Memperoleh jumlah data
// -------------------------------------------------------
unsigned int MergeSort::length()
{
    return jumData;
}

// -------------------------------------------------------
// doMergeSort() (bersifat privat)
//
// Mengurutkan data dengan membagi data menjadi dua bagian
// -------------------------------------------------------
void MergeSort::doMergeSort(vector<int> tmp, int kiri, int kanan)
{
    // Kalau jumlah data hanya satu, tidak perlu pengurutan
    if (kiri == kanan)
        return;

    // Data dibagi dua dan masing-masing diurutkan
    int tengah = (kiri + kanan) / 2;
    doMergeSort(tmp, kiri, tengah);
    doMergeSort(tmp, tengah+1, kanan);
    merge(tmp, kiri, tengah+1, kanan);
}

// -------------------------------------------------------
// merge() (bersifat privat)
//
// Menggabungkan dua bagian yang telah diurutkan
// -------------------------------------------------------
void MergeSort::merge(vector<int> tmp, int posKiri,
                      int posKanan, int akhirKanan)
{
    int akhirKiri = posKanan - 1;
    int posTmp = posKiri;
    int jumElemen = akhirKanan - posKiri + 1;

    while ( (posKiri <= akhirKiri) and (posKanan <= akhirKanan) )
        if (data[posKiri] <= data[posKanan])
        {
            tmp[posTmp] = data[posKiri];
            posTmp++;
            posKiri++;
        }
        else
        {
            tmp[posTmp] = data[posKanan];
            posTmp++;
            posKanan++;
        }

    // Salin yang tersisa di bagian kiri
    while (posKiri <= akhirKiri)
    {
       tmp[posTmp] = data[posKiri];
        posTmp++;
        posKiri++;
    }

    // Salin yang tersisa di bagian kanan
    while (posKanan <= akhirKanan)
    {
        tmp[posTmp] = data[posKanan];
        posTmp++;
        posKanan++;
    }

    // Salin kembali isi tmp
    for (int j = 0;  j < jumElemen; j++)
    {
        data[akhirKanan] = tmp[akhirKanan];
        akhirKanan--;
    }
}

// -------------------------------------------------------
// sort() (bersifat publik)
//
// Mengurutkan data secara ascending
// -------------------------------------------------------
void MergeSort::sort()
{
    vector<int> tmp;
    tmp.resize(jumData);
    doMergeSort(tmp, 0, jumData-1);
}

// -------------------------------------------------------
// display() (bersifat public)
//
// Menampilkan data
// -------------------------------------------------------
void MergeSort::display()
{
    for (unsigned int i = 0; i < jumData; i++)
        cout << data[i] << ' ';

    cout << endl;
}
