// ---------------------------------------------------------
// SelectionSort.h
//
// Implementasi kelas SelectionSort
//     (Aplikasi pengurutan data menggunakan Selection Sort)
// ---------------------------------------------------------

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>

using namespace std;

class SelectionSort
{
    private:
        vector<int> data;            // Vektor untuk data
        unsigned int jumData;        // Jumlah data dalam vektor
        unsigned int ukuranMaksimum; // Ukuran maksimum jumlah data
    public:
        SelectionSort(unsigned int ukuran);
        void insert(int data);
        void reset();
        unsigned int length();
        void sort();
        void sortDesc();
        void display();
};

#endif // SELECTIONSORT_H
