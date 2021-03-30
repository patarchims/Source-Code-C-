// ------------------------------------------------
// ShellSort.h
//
// Implementasi kelas ShellSort
//     untuk mengurutkan data dengan Shell Sort
// ------------------------------------------------

#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <vector>

using namespace std;

class ShellSort
{
    private:
        vector<int> data;            // Vektor untuk data
        unsigned int jumData;        // Jumlah data dalam vektor
        unsigned int ukuranMaksimum; // Ukuran maksimum jumlah data
    public:
        ShellSort(unsigned int ukuran);
        void insert(int data);
        void reset();
        unsigned int length();
        void sort();
        void sortDesc();
        void display();
};

#endif // SHELLSORT_H
