// ------------------------------------------------
// Tree.h
//
// Implementasi kelas SimpulPohon dan Biner
//     (Aplikasi BST)
// ------------------------------------------------

#ifndef TREE_H
#define TREE_H

#include <string>

using namespace std;

class SimpulPohon
{
    public:
        char data;
        SimpulPohon* induk;
        SimpulPohon* kiri;
        SimpulPohon* kanan;
    // Konstruktor
    SimpulPohon(char karakter);
};

class PohonBiner
{
    private:
        SimpulPohon* akar;
        bool sisip(SimpulPohon* &ortu, SimpulPohon* ptrBaru);
        SimpulPohon* cari(SimpulPohon* &akar, char data);
        string inOrder(SimpulPohon* ptrSimpul);
        string preOrder(SimpulPohon* ptrSimpul);
        string postOrder(SimpulPohon* ptrSimpul);
        void hapusSemuaSimpul(SimpulPohon* ptrSimpul);

    public:
        PohonBiner();
        ~PohonBiner();
        bool sisip(char data);
        bool cari(char data);
        bool hapus(char data);
        string inOrder();
        string preOrder();
        string postOrder();
};

#endif // TREE_H
