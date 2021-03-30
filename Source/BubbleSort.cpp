// ------------------------------------------------------
// BubbleSort.cpp
//
// Implementasi kelas BubbleSort
//     (Aplikasi pengurutan data menggunakan Bubble Sort)
// ------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include "BubbleSort.h"

using namespace std;

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
BubbleSort::BubbleSort(unsigned int ukuran)
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
void BubbleSort::insert(int data)
{
    if (jumData == ukuranMaksimum)
    {
        cout << "Kapasitas data sudah tercapai." << endl;
        cout << "Penambahan data " << data
             << " tidak dapat dilakukan." << endl;
        return;
    }

    BubbleSort::data[jumData++] = data;
}

// -------------------------------------------------------
// reset() (bersifat publik)
//
// Mengosongkan data dalam vektor
// -------------------------------------------------------
void BubbleSort::reset()
{
    jumData = 0;
}

// -------------------------------------------------------
// length() (bersifat publik)
//
// Memperoleh jumlah data
// -------------------------------------------------------
unsigned int BubbleSort::length()
{
    return jumData;
}

// -------------------------------------------------------
// sort() (bersifat publik)
//
// Mengurutkan data secara ascending
// -------------------------------------------------------
void BubbleSort::sort()
{
    unsigned int tahap, j;
    int tmp;
    for (tahap = 1; tahap < jumData; tahap++)
    {
        for (j = 0; j < jumData - tahap; j++)
            if (data[j] > data[j+1])
            {
                // Tukarkan
                tmp = data[j];
                data[j] = data[j+1];
                 data[j+1] = tmp;
            }
    }
}

// -------------------------------------------------------
// sortDesc() (bersifat publik)
//
// Mengurutkan data secara descending
// -------------------------------------------------------
void BubbleSort::sortDesc()
{
    unsigned int tahap, j;
    int tmp;
    for (tahap = 1; tahap < jumData; tahap++)
    {
        for (j = 0; j < jumData - tahap; j++)
            if (data[j] < data[j+1])
            {
                // Tukarkan
                tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
    }
}

// -------------------------------------------------------
// display() (bersifat public)
//
// Menampilkan data
// -------------------------------------------------------
void BubbleSort::display()
{
    for (unsigned int i = 0; i < jumData; i++)
        cout << data[i] << ' ';

    cout << endl;
}
