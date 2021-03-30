// ------------------------------------------------
// UGraph.cpp
//
// Implementasi kelas UGraph
//     (Graf Tak berarah)
// ------------------------------------------------

#include <iostream>
#include <string>
#include "UGraph.h"

using namespace std;

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
UGraph::UGraph(void)
{
    jumVertex = 0;
}

// -------------------------------------
// find (bersifat privat)
//
// Menghasilkan posisi labelVertex
//    dalam array label
//    Nilai balik -1 berarti tidak ada
// -------------------------------------
int UGraph::find(char labelVertex)
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
void UGraph::insertVertex(char labelVertex)
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

// ----------------------------------
// deleteVertex() (bersifat publik)
//
// Menghapus vertex labelVertex
// ----------------------------------
void UGraph::deleteVertex(char labelVertex)
{
    // Batalkan kalau memang tidak ada vertex lagi
    if (jumVertex == 0)
    {
        cout << "Tak ada vertex" << endl;
        return;
    }

    // Kalau label tidak ada batalkan
    int pos = find(labelVertex);
    if (pos == -1)
    {
        cout << "Tak ada vertex" << endl;
        return;
    }

    // Lakukan penggeseran
    if (pos < jumVertex)
    {
        // Hapus baris
        for (int j = pos; j < jumVertex-1; j++)
        {
            // Geser pada data
            for (int k = 0; k < jumVertex; k++)
                data[j][k] = data[j+1][k];

            // Geser pada label
            label[j] = label[j+1];
        }

        // Hapus kolom
        for (int j = pos; j < jumVertex-1; j++)
        {
            // Geser pada data
            for (int k = 0; k < jumVertex; k++)
                data[k][j] = data[k][j+1];
        }
    }

    jumVertex--;  // Jumlah vertex diturunkan sebesar satu
}

// ---------------------------------
// insertEdge() (bersifat publik)
//
// Menyisipkan garis
// ---------------------------------
void UGraph::insertEdge(char vertex1, char vertex2)
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

// ---------------------------------
// deleteEdge (bersifat publik)
//
// Menghapus garis
// ---------------------------------
void UGraph::deleteEdge(char vertex1, char vertex2)
{
        // --- Periksa keberadaan Vertex1 dan Vertex2
    int pos1 = find(vertex1);
    int pos2 = find(vertex2);
    if ( (pos1 == -1) || (pos2 == -1) )
    {

        cout << "Ada vertex yang tidak dikenal" << endl;
        return;
    }

    if (data[pos1][pos2] == 0)
    {
        cout << vertex1 << " dan " << vertex2
             << " tak punya garis" << endl;
        return;
    }

    // Hapus garis
    data[pos1][pos2] = 0;
    data[pos2][pos1] = 0;
}

// ---------------------------------
// length() (bersifat publik)
//
// Memberi nilai balik berupa
//    jumlah vertex
// ---------------------------------
long int UGraph::length()
{
    return jumVertex;
}

void UGraph::display()
{
    for (int j = 0; j < jumVertex; j++)
        for (int k = 0; k <= j; k++)
            if (data[j][k] == 1)
               cout << label[j] << "-"
                    << label[k] << "  ";

    cout << endl;
}
