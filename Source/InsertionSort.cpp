// ------------------------------------------------
// InsertionSort.cpp
//
// Implementasi kelas InsertionSort
// ------------------------------------------------

#include <iostream>
#include <string>
#include "InsertionSort.h"

using namespace std;

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
InsertionSort::InsertionSort(unsigned int ukuran)
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
void InsertionSort::insert(int data)
{
    if (jumData == ukuranMaksimum)
    {
        cout << "Kapasitas data sudah tercapai." << endl;
        cout << "Penambahan data " << data
             << " tidak dapat dilakukan." << endl;
        return;
    }

    InsertionSort::data[jumData++] = data;
}

// -------------------------------------------------------
// reset() (bersifat publik)
//
// Mengosongkan data dalam vektor
// -------------------------------------------------------
void InsertionSort::reset()
{
    jumData = 0;
}

// -------------------------------------------------------
// length() (bersifat publik)
//
// Memperoleh jumlah data
// -------------------------------------------------------
unsigned int InsertionSort::length()
{
    return jumData;
}

// -------------------------------------------------------
// sort() (bersifat publik)
//
// Mengurutkan data secara ascending
// -------------------------------------------------------
void InsertionSort::sort()
{
    unsigned int j, k;
    int tmp;

	for (j = 1; j < jumData; j++)
    {

        tmp = data[j];
        k = j;

	    // Sisipkan data ke  vektor dengan indeks 0 s/d K-1
	    while ( (k > 0) && (data[k-1] > tmp) )
        {
	        data[k] = data[k-1];
	        k--;
        }

        data[k] = tmp;
    }
}

// -------------------------------------------------------
// sortDesc() (bersifat publik)
//
// Mengurutkan data secara descending
// -------------------------------------------------------
void InsertionSort::sortDesc()
{
    unsigned int j, k;
    int tmp;

	for (j = 1; j < jumData; j++)
    {
        tmp = data[j];
        k = j;

	    // Sisipkan data ke  vektor dengan indeks 0 s/d K-1
	    while ( (k > 0) && (data[k-1] <= tmp) )
        {
	        data[k] = data[k-1];
	        k--;
        }

        data[k] = tmp;
    }
}

// -------------------------------------------------------
// display() (bersifat public)
//
// Menampilkan data
// -------------------------------------------------------
void InsertionSort::display()
{
    for (unsigned int i = 0; i < jumData; i++)
        cout << data[i] << ' ';

    cout << endl;
}
