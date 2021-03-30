// ------------------------------------------------
// Binary.h
//
// Implementasi kelas BinarySearch
// ------------------------------------------------

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <vector>

using namespace std;

class BinarySearch
{
    private:
        vector<int> data;            // Vektor untuk data
        unsigned int jumData;        // Jumlah data dalam vektor
    public:
        BinarySearch(int data[], int ukuran);
        int find(int dicari);
        void display();
};

#endif // BINARYSEARCH_H
