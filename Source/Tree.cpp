// ------------------------------------------------
// Tree.cpp
//
// Implementasi kelas SimpulPohon dan Pohon Biner
//     (Aplikasi BST)
// ------------------------------------------------

#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

// --------------------------------
// Konstruktor SimpulPohon
// --------------------------------

SimpulPohon::SimpulPohon(char data)
{
    SimpulPohon::data = data;
    SimpulPohon::induk = NULL;
    SimpulPohon::kiri = NULL;
    SimpulPohon::kanan = NULL;
}

// --------------------------------
// Konstruktor PohonBiner
// --------------------------------

PohonBiner::PohonBiner()
{
    PohonBiner::akar = NULL;
}

// --------------------------------
// Destruktor PohonBiner
// --------------------------------

PohonBiner::~PohonBiner()
{
    hapusSemuaSimpul(akar);
}
// -----------------------------------
// sisip (Bersifat privat)
//
// Untuk menyisipkan simpul ke pohon
// Nilai balik:
//   true  = Berhasil disisipkan
//   talse = Gagal karena data kembar
// -----------------------------------

bool PohonBiner::sisip(SimpulPohon* &ortu, SimpulPohon* ptrBaru)
{
    if (ptrBaru->data == ortu->data)
    {
        delete ptrBaru; // Hapus karena sudah ada
        return false;
    }
    else
        if (ptrBaru->data < ortu->data)
            if (ortu->kiri == NULL)
            {
                ortu->kiri = ptrBaru;
                ptrBaru->induk = ortu;
                return true;
            }
            else
                return sisip(ortu->kiri, ptrBaru);
        else // Berarti lebih dari
            if (ortu->kanan == NULL)
            {
                ortu->kanan = ptrBaru;
                ptrBaru->induk = ortu;
                return true;
            }
            else
                return sisip(ortu->kanan, ptrBaru);
}

// -----------------------------------
// sisip  (Bersifat publik)
//
// Untuk menyisipkan data ke pohon
// Nilai balik:
//   true  = Berhasil disisipkan
//   false = Gagal karena data kembar
// -----------------------------------
bool PohonBiner::sisip(char data)
{
    SimpulPohon* ptrBaru = new SimpulPohon(data);
    if (akar == NULL)
    {
        akar = ptrBaru;
        return true;
    }
    else
        return sisip(akar, ptrBaru);
}

// ------------------------------------------
// cari (Bersifat privat)
//
// Untuk mencari data data
// Nilai balik:
//    true: ketemu
//    false: tidak ketemu
// argumen Akar menyatakan akar dari subpohon
//    untuk pencarian
// ------------------------------------------

SimpulPohon* PohonBiner::cari(SimpulPohon* &akar, char data)
{
    if (akar == NULL)
        return NULL;
    else
        if (data == akar->data)
            return akar;
        else
            if (data < akar->data)
                return cari(akar->kiri, data);
            else
                return cari(akar->kanan, data);
}

// ------------------------------------------
// cari  (Bersifat publik)
//
// Menghasilkan :
//    true: kalau data ketemu
//    false: kalau tidak ketemu
// ------------------------------------------

bool PohonBiner::cari(char data)
{
    if (cari(akar, data) == NULL)
        return false;
    else
        return true;
}

// ------------------------------------------
// hapus   (Bersifat publik)
// Nilai balik:
//    false = Data tidak ketemu
//    true  = Data berhasil dihapus
// ------------------------------------------

bool PohonBiner::hapus(char data)
{
    SimpulPohon* simpulDihapus = cari(akar, data);
    if (simpulDihapus == NULL)
    {
        return true;
    }

    if (simpulDihapus->kanan == NULL)
        if (simpulDihapus->kiri == NULL)
        {
            // Simpul yang akan dihapus berkedudukan
            //   sebagai daun (tidak punya anak)
            if (simpulDihapus == akar)
                akar = NULL;
            else
                if (simpulDihapus->induk->kiri == simpulDihapus)
                    // Kalau yang dihapus adalah anak kiri ortunya
                    simpulDihapus->induk->kiri = NULL;
                else
                    // Kalau yang dihapus adalah anak kanan ortunya
                    simpulDihapus->induk->kanan = NULL;
        }
        else
        {
            // Simpul yang akan dihapus memiliki anak
            //   di sebelah kiri saja
            if (simpulDihapus == akar)
            {
                akar = simpulDihapus->kiri;
                akar->induk = NULL;
            }
            else
            {
                // Kalau bukan akar
                if (simpulDihapus->induk->kiri == simpulDihapus)
                {
                    // Merupakan anak kiri dari ortunya
                    simpulDihapus->induk->kiri = simpulDihapus->kiri;
                    simpulDihapus->kiri->induk = simpulDihapus->induk;
                }
                else
                {
                    // Merupakan anak kanan dari ortunya
                    simpulDihapus->induk->kanan = simpulDihapus->kiri;
                    simpulDihapus->kiri->induk = simpulDihapus->induk;
                }
            }
        }
        else
            if (simpulDihapus->kiri == NULL)
            {
                // Simpul yang akan dihapus
                //   mempunyai anak di sebelah kanan saja
                if (simpulDihapus == akar)
                {
                    akar = simpulDihapus->kanan;
                    akar->induk = NULL;
                }
                else  // Kalau bukan akar
                    if (simpulDihapus->induk->kiri == simpulDihapus)
                    {
                        // Simpul dihapus adalah anak kiri ortunya
                        simpulDihapus->induk->kiri = simpulDihapus->kanan;
                        simpulDihapus->kanan->induk = simpulDihapus->induk;
                    }
                    else
                    {
                        // Simpul dihapus adalah anak kanan ortunya
                        simpulDihapus->induk->kanan = simpulDihapus->kanan;
                        simpulDihapus->kanan->induk = simpulDihapus->induk;
                    }
            }
    else
    {
        // Simpul yang dihapus
        //   memiliki dua buah subpohon

        // -- Cari pengganti/suksesor simpul yang akan dihapus
        SimpulPohon* suksesor = simpulDihapus->kanan;
        while (suksesor->kiri != NULL)
             suksesor = suksesor->kiri;

        // -- Putuskan suksesor dari pohon
        if (suksesor->induk->kiri == suksesor)
        {
            // Suksesor sebagai anak kiri dari induknya
            suksesor->induk->kiri = suksesor->kanan;
            if (suksesor->kanan != NULL)
                suksesor->kanan->induk = suksesor->induk;
        }
        else
        {
            // Suksesor sebagai anak kanan dari induknya
            suksesor->induk->kanan = suksesor->kanan;
            if (suksesor->kanan != NULL)
                suksesor->kanan->induk = suksesor->induk;
        }

        // Data pada suksesor disalin ke
        //   simpul yang akan dihapus
        simpulDihapus->data = suksesor->data;

        // Ubah simpul yang ditunjuk oleh suksesor
        //   ke SimpulDihapus
        simpulDihapus = suksesor;
    }

    delete simpulDihapus;
    return true;
}

// ------------------------------------------
// InOrder (bersifat privat)
//
// Menampilkan data secara inorder
// ------------------------------------------

string PohonBiner::inOrder(SimpulPohon* ptrSimpul)
{
    string hasil = "";
    if (ptrSimpul != NULL)
    {
        if (ptrSimpul->kiri != NULL)
            hasil = hasil + inOrder(ptrSimpul->kiri);

        hasil = hasil + ptrSimpul->data;

        if (ptrSimpul->kanan != NULL)
            hasil = hasil + inOrder(ptrSimpul->kanan);
    }

    return hasil;
}

// ------------------------------------------
// InOrder (bersifat publik)
//
// Menampilkan data secara inorder
// ------------------------------------------

string PohonBiner::inOrder()
{
    return inOrder(akar);
}

// ------------------------------------------
// PreOrder (bersifat privat)
//
// Menampilkan data secara preorder
// ------------------------------------------

string PohonBiner::preOrder(SimpulPohon* ptrSimpul)
{
    string hasil = "";
    if (ptrSimpul != NULL)
    {
        hasil = hasil + ptrSimpul->data;
        if (ptrSimpul->kiri != NULL)
            hasil = hasil + preOrder(ptrSimpul->kiri);

      if (ptrSimpul->kanan != NULL)
        hasil = hasil + preOrder(ptrSimpul->kanan);
    }

    return hasil;
}

// ------------------------------------------
// PreOrder (bersifat publik)
//
// Menampilkan data secara preorder
// ------------------------------------------

string PohonBiner::preOrder()
{
   return preOrder(akar);
}

// ------------------------------------------
// PostOrder (bersifat privat)
//
// Menampilkan data secara postorder

string PohonBiner::postOrder(SimpulPohon* ptrSimpul)
{
    string hasil = "";
    if (ptrSimpul != NULL)
    {
        if (ptrSimpul->kiri != NULL)
        hasil = hasil + postOrder(ptrSimpul->kiri);

        if (ptrSimpul->kanan != NULL)
            hasil = hasil + postOrder(ptrSimpul->kanan);

        hasil = hasil + ptrSimpul->data;
    }

    return hasil;
}

// ------------------------------------------
// PostOrder (bersifat publik)
//
// Menampilkan data secara postorder
// ------------------------------------------

string PohonBiner::postOrder()
{
    return postOrder(akar);
}

// ------------------------------------------
// HapusSemuaSimpul (Bersifat privat)
//
// Untuk menghapus semua simpul
// ------------------------------------------

void PohonBiner::hapusSemuaSimpul(SimpulPohon* ptrSimpul)
{
    if (ptrSimpul != NULL)
    {
        hapusSemuaSimpul(ptrSimpul->kiri);
        hapusSemuaSimpul(ptrSimpul->kanan);

        delete ptrSimpul;
    }
}
