// ------------------------------------------------
// ShellSort.cpp
//
// Implementasi kelas QuickSort
//     untuk mengurutkan data dengan Quicksort
// ------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include "QuickSort.h"

using namespace std;

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
QuickSort::QuickSort(unsigned int ukuran)
{
    jumData = 0;
    ukuranMaksimum =  ukuran;
    data.resize(ukuran);
}

// -------------------------------------------------------
// insert() (bersifat publik)
//
// Menambahkan data ke dalam vektor data
// -------------------------------------------------------
void QuickSort::insert(int data)
{
    if (jumData == ukuranMaksimum)
    {
        cout << "Kapasitas data sudah tercapai." << endl;
        cout << "Penambahan data " << data
             << " tidak dapat dilakukan." << endl;
        return;
    }

    QuickSort::data[jumData++] = data;
}

// -------------------------------------------------------
// reset() (bersifat publik)
//
// Mengosongkan data dalam vektor
// -------------------------------------------------------
void QuickSort::reset()
{
    jumData = 0;
}

// -------------------------------------------------------
// length() (bersifat publik)
//
// Memperoleh jumlah data
// -------------------------------------------------------
unsigned int QuickSort::length()
{
    return jumData;
}

// -------------------------------------------------------
// sort() (bersifat publik)
//
// Mengurutkan data secara ascending
// -------------------------------------------------------
void QuickSort::sort()
{
    qsort(0, jumData-1);
}

// -------------------------------------------------------
// display() (bersifat public)
//
// Menampilkan data
// -------------------------------------------------------
void QuickSort::display()
{
    for (unsigned int i = 0; i < jumData; i++)
        cout << data[i] << ' ';

    cout << endl;
}

// -------------------------------------------------------
// partitionData()  (bersifat privat)
//
// Melakukan partisi terhadap data
//     Nilai balik berupa pivot
// -------------------------------------------------------
int QuickSort::partitionData(int kiri, int kanan)
{
    int pivot = data[kanan];
    int i = kiri - 1;
    for (int j = kiri; j < kanan; j++)
    {
        if (data[j] <= pivot)
        {
            i++;
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }

    int tmp = data[i+1];
    data[i+1] = data[kanan];
    data[kanan] = tmp;

    return i + 1;
}

// -------------------------------------------------------
// qsort() (bersifat privat)
//
// Mengurutkan data menggunakan QuickSort
// -------------------------------------------------------
void QuickSort::qsort(int kiri, int kanan)
{
    int pivot;

    if (kiri < kanan)
    {
        pivot = partitionData(kiri, kanan);
        qsort(kiri, pivot - 1);
        qsort(pivot + 1, kanan);
    }
}

