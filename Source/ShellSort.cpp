// ------------------------------------------------
// ShellSort.cpp
//
// Implementasi kelas ShellSort
//     untuk mengurutkan data dengan Shell Sort
// ------------------------------------------------

#include <iostream>
#include <string>
#include "ShellSort.h"

using namespace std;

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
ShellSort::ShellSort(unsigned int ukuran)
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
void ShellSort::insert(int data)
{
    if (jumData == ukuranMaksimum)
    {
        cout << "Kapasitas data sudah tercapai." << endl;
        cout << "Penambahan data " << data
             << " tidak dapat dilakukan." << endl;
        return;
    }

    ShellSort::data[jumData++] = data;
}

// -------------------------------------------------------
// reset() (bersifat publik)
//
// Mengosongkan data dalam vektor
// -------------------------------------------------------
void ShellSort::reset()
{
    jumData = 0;
}

// -------------------------------------------------------
// length() (bersifat publik)
//
// Memperoleh jumlah data
// -------------------------------------------------------
unsigned int ShellSort::length()
{
    return jumData;
}

// -------------------------------------------------------
// sort() (bersifat publik)
//
// Mengurutkan data secara ascending
// -------------------------------------------------------
void ShellSort::sort()
{
    // Tentukan H sebagai gap
    unsigned int h = 1;
    while (h < jumData / 3)
        h = 3 * h + 1;

    // Proses sampai H = 1
    while (h > 0)
    {
        for (unsigned int luar = h; luar < jumData; luar++)
        {
            int tmp = data[luar];
            int dalam = luar;
            while ( (dalam > h - 1) &&
               (data[dalam-h] >= tmp) )
            {
                data[dalam] = data[dalam - h];
                dalam = dalam - h;
            }

            data[dalam] = tmp;
         } // for

         h = (h - 1) / 3;
    } // while
}

// -------------------------------------------------------
// sortDesc() (bersifat publik)
//
// Mengurutkan data secara descending
// -------------------------------------------------------
void ShellSort::sortDesc()
{
    // Tentukan H sebagai gap
    unsigned int h = 1;
    while (h < jumData / 3)
        h = 3 * h + 1;

    // Proses sampai H = 1
    while (h > 0)
    {
        for (unsigned int luar = h; luar < jumData; luar++)
        {
            int tmp = data[luar];
            int dalam = luar;
            while ( (dalam > h - 1) &&
               (data[dalam-h] <= tmp) )
            {
                data[dalam] = data[dalam - h];
                dalam = dalam - h;
            }

            data[dalam] = tmp;
         } // for

         h = (h - 1) / 3;
    } // while
}

// -------------------------------------------------------
// display() (bersifat public)
//
// Menampilkan data
// -------------------------------------------------------
void ShellSort::display()
{
    for (unsigned int i = 0; i < jumData; i++)
        cout << data[i] << ' ';

    cout << endl;
}
