// ------------------------------------------------
// Linear.cpp
//
// Implementasi kelas LinearSearch
//     (Aplikasi pencarian data secara linear)
// ------------------------------------------------

#include <iostream>
#include <string>
#include "Linear.h"

using namespace std;

// -------------------------------------------------------
// Destruktor
// -------------------------------------------------------
LinearSearch::LinearSearch(int data[], int jumData)
{
    LinearSearch::jumData = jumData;
    LinearSearch::data.resize(jumData);
    for (int i = 0; i < jumData; i++)
    {
        LinearSearch::data[i] = data[i];
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
int LinearSearch::find(int dicari)
{
    unsigned int posisi = -1;
    unsigned int j = 0;
    while (j < jumData)
    {
        if (data[j] == dicari)
        {
            posisi = j;
            break; // Akhiri while
        }

        j++;
    }

    return posisi;

}

// -------------------------------------------------------
// display() (bersifat public)
//
// Menampilkan data
// -------------------------------------------------------
void LinearSearch::display()
{
    for (unsigned int i = 0; i < jumData; i++)
        cout << data[i] << ' ';

    cout << endl;
}
