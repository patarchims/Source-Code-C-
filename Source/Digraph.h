// ------------------------------------------------
// Digraph.h
//
// Berisi definisi kelas Digraph
//        (Graf Berarah Tanpa Bobot)
// ------------------------------------------------

#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <string>

using namespace std;

const int MAX_ELEMENTS = 50;

class Digraph
{
    private:
        double data[MAX_ELEMENTS][MAX_ELEMENTS];
        char label[MAX_ELEMENTS]; // Label vertex
        int jumVertex;            // Jumlah vertex

        int find(char labelVertex);
    public:
        Digraph(void);
        void insertVertex(char labelVertex);
        void deleteVertex(char labelVertex);
        void insertEdge(char vertex1, char vertex2);
        void deleteEdge(char vertex1, char vertex2);
        long int length();
        void display();
};

#endif // DIGRAPH_H
