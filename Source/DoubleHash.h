// ------------------------------------------------
// DoubleHash.h
//
// Implementasi kelas DataHash dan DoubleHash
//     (Tabel hash dengan double hashing)
// ------------------------------------------------

#ifndef DOUBLEHASH_H
#define DOUBLEHASH_H

#include <string>
#include <vector>

using namespace std;

class DataHash
{
    public:
        int nip;
        string nama;

    // Konstruktor
    DataHash(int nip, string nama);
};

class DoubleHashing
{
    private:
        vector<DataHash*> data;   // Vektor untuk tabel hash
        int ukuranTabel;          // Ukuran data dalam vektor
        DataHash* ptrTerhapus;    // Menunjuk ke data yang dihapus
    public:
        DoubleHashing(int ukuran);
        ~DoubleHashing();
        int hashFunction1(int nip);
        int hashFunction2(int nip);
        void insert(int nip, string nama);
        string find(int nip);
        bool remove(int nip);
        void display();
};

#endif // DOUBLEHASH_H
