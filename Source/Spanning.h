// ------------------------------------------------
// Spanning.h
//
// Berisi definisi kelas SimpulAntrianBerprioritas,
//     AntrianBerprioritas, dan SpanningTree
// ------------------------------------------------

#ifndef SPANNING_H
#define SPANNING_H

#include <string>
#include "ListTumpukan.h"

using namespace std;

const int MAX_ELEMENTS = 50;

class SimpulAntrianBerprioritas
{
    public:
        int vertex1;
        int vertex2;
        double bobot;
        SimpulAntrianBerprioritas* berikut;
        SimpulAntrianBerprioritas(int vertex1, int vertex2, double bobot);
        SimpulAntrianBerprioritas(void);
};

class AntrianBerprioritas
{
    private:
        SimpulAntrianBerprioritas* pertama;
    public:
        AntrianBerprioritas(void);
        void insert(int vertex1, int vertex2, double bobot);
        bool empty();
        SimpulAntrianBerprioritas remove();
};

class SpanningTree
{
    private:
        double data[MAX_ELEMENTS][MAX_ELEMENTS];
        char label[MAX_ELEMENTS]; // Label vertex
        int jumVertex;            // Jumlah vertex
        ListTumpukan* tumpukan;

        int find(char labelVertex);
    public:
        SpanningTree(void);
        void insertVertex(char labelVertex);
        void insertEdge(char vertex1, char vertex2, double bobot);
        double mst();
};

#endif // SPANNING_H
