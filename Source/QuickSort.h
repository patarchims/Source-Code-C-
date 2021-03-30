// ------------------------------------------------
// ShellSort.h
//
// Implementasi kelas QuickSort
//     untuk mengurutkan data dengan Quicksort
// ------------------------------------------------

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

using namespace std;

class QuickSort
{
    private:
        vector<int> data;            // Vektor untuk data
        unsigned int jumData;        // Jumlah data dalam vektor
        unsigned int ukuranMaksimum; // Ukuran maksimum jumlah data
        int partitionData(int kiri, int kanan);
        void qsort(int kiri, int kanan);
    public:
        QuickSort(unsigned int ukuran);
        void insert(int data);
        void reset();
        unsigned int length();
        void sort();
        void sortDesc();
        void display();
};

#endif // QUICKSORT_H
