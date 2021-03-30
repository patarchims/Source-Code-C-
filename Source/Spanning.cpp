// ------------------------------------------------
// Spanning.cpp
//
// Implementasi kelas SimpulAntrianBerprioritas,
//     AntrianBerprioritas, dan SpanningTree
// ------------------------------------------------

#include <iostream>
#include <string>
#include "Spanning.h"

using namespace std;

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
SimpulAntrianBerprioritas::SimpulAntrianBerprioritas(
                    int vertex1, int vertex2, double bobot)
{
    SimpulAntrianBerprioritas::vertex1 = vertex1;
    SimpulAntrianBerprioritas::vertex2 = vertex2;
    SimpulAntrianBerprioritas::bobot = bobot;
    berikut = NULL;
}

SimpulAntrianBerprioritas::SimpulAntrianBerprioritas(void)
{
    vertex1 = -1;
    vertex2 = -1;
    bobot = -1;
    berikut = NULL;
}

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
AntrianBerprioritas::AntrianBerprioritas(void)
{
    pertama = NULL;
}

// ---------------------------------------
// insert() (Bersifat publik)
//
// Menyisipkan data garis ke dalam senarai
//   dan menjamin data diurutkan
//   menurut bobot
// ---------------------------------------
void AntrianBerprioritas::insert(int vertex1, int vertex2, double bobot)
{
    // Buat simpul baru dan
    //   isikan data ke dalam simpul
    SimpulAntrianBerprioritas* ptrBaru;
    ptrBaru = new SimpulAntrianBerprioritas(vertex1,
                                     vertex2, bobot);

    // Cari posisi untuk memasukkan data baru
    //   ke dalam senarai
    SimpulAntrianBerprioritas* pendahulu = NULL;
    SimpulAntrianBerprioritas* ptrSekarang = pertama;
    while ((ptrSekarang != NULL) &&
        (bobot > ptrSekarang->bobot))
    {
        pendahulu = ptrSekarang;
        ptrSekarang = ptrSekarang->berikut;
    }

    if (pendahulu == NULL)
        pertama = ptrBaru;
    else
        pendahulu->berikut = ptrBaru;

    ptrBaru->berikut = ptrSekarang;
}

// --------------------------------------
// empty()
//
// Menghasilkan true kalau senarai kosong
//    atau false kalau tidak kosong
// --------------------------------------
bool AntrianBerprioritas::empty()
{
    return pertama == NULL;
}

// ---------------------------------
// remove() (Bersifat publik)
//
// Mengambil data pada simpul yang
//    ditunjuk oleh pertama
// ---------------------------------
SimpulAntrianBerprioritas AntrianBerprioritas::remove()
{
    if (empty())
    {
        cout << "Tumpukan sudah kosong" << endl;
        SimpulAntrianBerprioritas data(-1,-1,-1);
        data.berikut = NULL;

        return data;
    }

    SimpulAntrianBerprioritas data(pertama->vertex1,
                                   pertama->vertex2, pertama->bobot);
    data.berikut = NULL;
    SimpulAntrianBerprioritas* ptrData = pertama;
    pertama = pertama->berikut;
    delete ptrData;

    return data;
}

// -------------------------------------------------------
// Konstruktor
// -------------------------------------------------------
SpanningTree::SpanningTree(void)
{
    jumVertex = 0;
    tumpukan = new ListTumpukan;
}

// -------------------------------------
// find (bersifat privat)
//
// Menghasilkan posisi labelVertex
//    dalam array label
//    Nilai balik -1 berarti tidak ada
// -------------------------------------
int SpanningTree::find(char labelVertex)
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
void SpanningTree::insertVertex(char labelVertex)
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
void SpanningTree::insertEdge(char vertex1, char vertex2, double bobot)
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
    data[pos1][pos2] = bobot;
    data[pos2][pos1] = bobot;
}

// ----------------------------------
// mst() (Bersifat publik)
//
// Menghasilkan minimum spanning tree
//    Argumen Lintasan akan berisi
//    garis-garis dalam spanning tree
// ----------------------------------

double SpanningTree::mst()
{
    // Atur agar array induk bernilai 0
    int i, j;
    int induk[MAX_ELEMENTS];
    for (i = 0; i < jumVertex; i++)
      induk[i] = 0;

    // Buat objek antrian
    AntrianBerprioritas antrian = AntrianBerprioritas();

    // Masukkan semua garis ke dalam antrian
    for (i = 0; i < jumVertex; i++)
        for (j = 0; j < i; j++)
            if (data[i][j] > 0)
                antrian.insert(i, j, data[i][j]);

    // Proses untuk menghitung MST
    int  jumlahGaris = 0;
    double totalBobot = 0;

    SimpulAntrianBerprioritas simpul;
    SimpulAntrianBerprioritas pohon[MAX_ELEMENTS];
    while (jumlahGaris < jumVertex - 1)
    {
        simpul = antrian.remove();
        if (simpul.vertex1 == -1)
            break;   // Akhiri while kalau data habis

        int vertex1 = simpul.vertex1;
        int vertex2 = simpul.vertex2;
        double bobot = simpul.bobot;

        // Cari akar dari Vertex1
        int akarVertex1 = 0;
        while (vertex1 > 0)
        {
            akarVertex1 = vertex1;
            vertex1 = induk[vertex1];
        }

        // Cari akar dari Vertex2
        int akarVertex2 = 0;
        while (vertex2 > 0)
        {
            akarVertex2 = vertex2;
            vertex2 = induk[vertex2];
        }

        // Periksa nilai AkarVertex1 dan AkarVertex2
        if (akarVertex1 != akarVertex2)
        {
            pohon[jumlahGaris].vertex1 = simpul.vertex1;
            pohon[jumlahGaris].vertex2 = simpul.vertex2;
            pohon[jumlahGaris].bobot = simpul.bobot;
            totalBobot = totalBobot + simpul.bobot;

            jumlahGaris = jumlahGaris + 1;
        }
    }

    // Bentuk hasil spanning tree
    for (i = 0; i < jumlahGaris; i++)
        cout << label[pohon[i].vertex1]
             << " ke " << label[pohon[i].vertex2] << endl;

    return totalBobot;
}

