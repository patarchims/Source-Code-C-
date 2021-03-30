// ------------------------------------------------------
// HashChain.h
//
// Implementasi kelas DataHash, SortedList, dan HashChain
//     (Tabel hash dengan Hash Chaining)
// ------------------------------------------------------

#ifndef HASHCHAIN_H
#define HASHCHAIN_H

#include <string>
#include <vector>

using namespace std;

class DataHash
{
    public:
        int nip;
        string nama;
        DataHash* berikut;

    // Konstruktor
    DataHash(int nip, string nama);
};

class SortedList
{
    public:
        DataHash* pertama;
    public:
        SortedList();
        ~SortedList();
        bool insert(int nip, string nama);
        bool remove(int nip);
        bool find(DataHash* &pendahulu, int nip);
        void display();
        void removeAll();
};

class HashChain
{
    private:
        vector<SortedList*> data; // Vektor untuk tabel hash
        int ukuranTabel;          // Ukuran data dalam vektor
    public:
        HashChain(int ukuran);
        ~HashChain();
        int hashFunction(int nip);
        void insert(int nip, string nama);
        string find(int nip);
        bool remove(int nip);
        void display();
};

#endif // HASHCHAIN_H
