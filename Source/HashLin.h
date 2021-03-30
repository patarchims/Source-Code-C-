// ------------------------------------------------
// HashLin.h
//
// Implementasi kelas DataHash dan HashLinear
//     (Tabel hash linear)
// ------------------------------------------------

#ifndef HASHLINEAR_H
#define HASHLINEAR_H

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

class HashLinear
{
    private:
        vector<DataHash*> data;   // Vektor untuk tabel hash
        int ukuranTabel;          // Ukuran data dalam vektor
        DataHash* ptrTerhapus;    // Menunjuk ke data yang dihapus
    public:
        HashLinear(int ukuran);
        ~HashLinear();
        int hashFunction(int nip);
        void insert(int nip, string nama);
        string find(int nip);
        bool remove(int nip);
        void display();
};

#endif // HASHLINEAR_H
