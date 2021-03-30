// ---------------------------------------------------------
// SelectionSort.cpp
//
// Implementasi kelas SelectionSort
//     (Aplikasi pengurutan data menggunakan Selection Sort)
// ---------------------------------------------------------

#include <iostream>
#include <string>
#include "SelectionSort.h"

using namespace std;

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
SelectionSort::SelectionSort(unsigned int ukuran)
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
void SelectionSort::insert(int data)
{
    if (jumData == ukuranMaksimum)
    {
        cout << "Kapasitas data sudah tercapai." << endl;
        cout << "Penambahan data " << data
             << " tidak dapat dilakukan." << endl;
        return;
    }

    SelectionSort::data[jumData++] = data;
}

// -------------------------------------------------------
// reset() (bersifat publik)
//
// Mengosongkan data dalam vektor
// -------------------------------------------------------
void SelectionSort::reset()
{
    jumData = 0;
}

// -------------------------------------------------------
// length() (bersifat publik)
//
// Memperoleh jumlah data
// -------------------------------------------------------
unsigned int SelectionSort::length()
{
    return jumData;
}

// -------------------------------------------------------
// sort() (bersifat publik)
//
// Mengurutkan data secara descending
// -------------------------------------------------------
void SelectionSort::sort()
{
    unsigned int posAwal, posMin, j;
    int tmp;

    for (posAwal = 0; posAwal < jumData-1; posAwal++)
    {
        posMin = posAwal;

	    // Cari data terkecil dan catat indeksnya
	    for (j = posAwal + 1; j < jumData; j++)
        {
	        if (data[posMin] > data[j])
	            posMin = j;
        }

	    // Kalau posAwal != posMin maka tukarkan elemen
	    if (posAwal != posMin)
        {
	        tmp = data[posAwal];
	        data[posAwal] = data[posMin];
	        data[posMin] = tmp;
        }
    }
}

// -------------------------------------------------------
// sortDesc() (bersifat publik)
//
// Mengurutkan data secara descending
// -------------------------------------------------------
void SelectionSort::sortDesc()
{
    unsigned int posAwal, posMak, j;
    int tmp;

    for (posAwal = 0; posAwal < jumData-1; posAwal++)
    {
        posMak = posAwal;

	    // Cari data terkecil dan catat indeksnya
	    for (j = posAwal + 1; j < jumData; j++)
        {
	        if (data[posMak] < data[j])
	            posMak = j;
        }

	    // Kalau posAwal != posMin maka tukarkan elemen
	    if (posAwal != posMak)
        {
	        tmp = data[posAwal];
	        data[posAwal] = data[posMak];
	        data[posMak] = tmp;
        }
    }
}

// -------------------------------------------------------
// display() (bersifat public)
//
// Menampilkan data
// -------------------------------------------------------
void SelectionSort::display()
{
    for (unsigned int i = 0; i < jumData; i++)
        cout << data[i] << ' ';

    cout << endl;
}
