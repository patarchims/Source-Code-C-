// ------------------------------------------------
// Bfs.cpp
//
// Implementasi kelas Bfs
//     (Penelusuran dengan BFS)
// ------------------------------------------------

#include <iostream>
#include <string>
#include "Bfs.h"

using namespace std;

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
Bfs::Bfs(void)
{
    jumVertex = 0;
    antrian = new ListAntrian;
}

// -------------------------------------
// find (bersifat privat)
//
// Menghasilkan posisi labelVertex
//    dalam array label
//    Nilai balik -1 berarti tidak ada
// -------------------------------------
int Bfs::find(char labelVertex)
{
    for (int j = 0; j < jumVertex; j++)
        if (label[j] == labelVertex)
        {
            return j;
        }

    return -1; // data tidak ditemukan
}

// ----------------------------------
// insertVertex (bersifat publik)
//
// Menyisipkan vertex baru dan
//    diberi label berupa labelVertex
// ----------------------------------
void Bfs::insertVertex(char labelVertex)
{
    if (jumVertex == MAX_ELEMENTS-1)
    {
        cout << "Array sudah penuh" << endl;
        return;
    }

    // --- Apa label sudah ada?
    if (find(labelVertex) > -1)
    {
        cout << "Label " << labelVertex << " sudah ada" << endl;
        return;
    }

    // Nolkan pada jumVertex
    for (int j = 0; j <= jumVertex; j++)
    {
        data[j][jumVertex] = 0;
        data[jumVertex][j] = 0;
    }

    // Tambahkan label
    label[jumVertex] = labelVertex;

    // Catat jumlah vertex sekarang
    jumVertex++;
}

// ---------------------------------
// insertEdge() (bersifat publik)
//
// Menyisipkan garis
// ---------------------------------
void Bfs::insertEdge(char vertex1, char vertex2)
{
    // --- Periksa keberadaan Vertex1 dan Vertex2
    int pos1 = find(vertex1);
    int pos2 = find(vertex2);
    if ( (pos1 == -1) || (pos2 == -1) )
    {
        cout << "Ada vertex yang tidak dikenal" << endl;
        return;
    }

    // --- Sisipkan ke array
    data[pos1][pos2] = 1;
    data[pos2][pos1] = 1;
}

void Bfs::display()
{
    // Kosongkan Antrian
    while (!antrian->empty())
        antrian->remove();

    // Tandai seluruh simpul dengan tanda belum dikunjungi
    char simpulDikunjungi[MAX_ELEMENTS];
    for (int j = 0; j < jumVertex; j++)
        simpulDikunjungi[j] = 'x';

    // Masukkan simpul pertama ke Antrian
    antrian->insert(label[0]);

    // Tandai bahwa simpul tsb telah dikunjungi
    simpulDikunjungi[0] = 'v';

    // Proses untuk semua simpul
    while (!antrian->empty())
    {
        // Ambil sebuah data dari Antrian
        char dataAntrian = antrian->remove();

        // Tambahkan ke hasil Bfs
        cout << dataAntrian;

        // Masukkan tetangganya yang belum dikunjungi
        // ke dalam Antrian dan kemudian tandai
        // simpul tersebut sudah dikunjungi
        int posisi = find(dataAntrian);
        for (int j = 1; j< jumVertex; j++)
            if (data[posisi][j] == 1)
                if (simpulDikunjungi[j] == 'x')
                {
                    antrian->insert(label[j]);
                    simpulDikunjungi[j] = 'v';
                }
    }
}

