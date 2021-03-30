// ------------------------------------------------------
// BubbleSort.h
//
// Implementasi kelas BubbleSort
//     (Aplikasi pengurutan data menggunakan Bubble Sort)
// ------------------------------------------------------

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>

using namespace std;

class BubbleSort
{
    private:
        vector<int> data;   // Vektor untuk data
        unsigned int jumData;        // Jumlah data dalam vektor
        unsigned int ukuranMaksimum; // Ukuran maksimum jumlah data
    public:
        BubbleSort(unsigned int ukuran);
        void insert(int data);
        void reset();
        unsigned int length();
        void sort();
        void sortDesc();
        void display();
};

#endif // BUBBLESORT_H
