// -------------------------------------------------------
// Kamus.h
//
// Implementasi kelas DataKamus, SortedDict, dan HashKamus
//     (Aplikasi kamus)
// -------------------------------------------------------

#ifndef KAMUS_H
#define KAMUS_H

#include <string>
#include <vector>

using namespace std;

class DataKamus
{
    public:
        string kunci;
        string keterangan;
        DataKamus* berikut;

    // Konstruktor
    DataKamus(string kunci, string keterangan);
};

class SortedDict
{
    public:
        DataKamus* pertama;
    public:
        SortedDict();
        ~SortedDict();
        bool insert(string kunci, string keterangan);
        bool remove(string kunci);
        bool find(DataKamus* &pendahulu, string kunci);
        void display();
        void removeAll();
};

class HashKamus
{
    private:
        vector<SortedDict*> data; // Vektor untuk tabel hash
        int ukuranTabel;          // Ukuran data dalam vektor
    public:
        HashKamus(int ukuran);
        ~HashKamus();
        int hashFunction(string kunci);
        void insert(string kunci, string keterangan);
        string find(string kunci);
        bool remove(string kunci);
        void display();
};

#endif // KAMUS_H
