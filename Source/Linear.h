// ------------------------------------------------
// Linear.h
//
// Implementasi kelas LinearSearch
//     (Aplikasi pencarian data secara linear)
// ------------------------------------------------

#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <vector>

using namespace std;

class LinearSearch
{
    private:
        vector<int> data;            // Vektor untuk data
        unsigned int jumData;        // Jumlah data dalam vektor
    public:
        LinearSearch(int data[], int ukuran);
        int find(int dicari);
        void display();
};

#endif // LINEARSEARCH_H
