// ------------------------------------------------
// MergeSort.h
//
// Implementasi kelas MergeSort
// ------------------------------------------------

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

using namespace std;

class MergeSort
{
    private:
        vector<int> data;            // Vektor untuk data
        unsigned int jumData;        // Jumlah data dalam vektor
        unsigned int ukuranMaksimum; // Ukuran maksimum jumlah data

        void doMergeSort(vector<int> tmp, int kiri, int kanan);
        void merge(vector<int> tmp, int posKiri, int posKanan, int akhirKanan);
    public:
        MergeSort(unsigned int ukuran);
        void insert(int data);
        void reset();
        unsigned int length();
        void sort();
        void display();
};

#endif // MERGESORT_H
