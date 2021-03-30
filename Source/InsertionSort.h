// ------------------------------------------------
// InsertionSort.h
//
// Implementasi kelas InsertionSort
// ------------------------------------------------

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>

using namespace std;

class InsertionSort
{
    private:
        vector<int> data;            // Vektor untuk data
        unsigned int jumData;        // Jumlah data dalam vektor
        unsigned int ukuranMaksimum; // Ukuran maksimum jumlah data
    public:
        InsertionSort(unsigned int ukuran);
        void insert(int data);
        void reset();
        unsigned int length();
        void sort();
        void sortDesc();
        void display();
};

#endif // INSERTIONSORT_H
