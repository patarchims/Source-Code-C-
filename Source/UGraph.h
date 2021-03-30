// ------------------------------------------------
// UGraph.h
//
// Berisi definisi kelas UGraph
//     (Graf Tak Berarah)
// ------------------------------------------------

#ifndef UGRAPH_H
#define UGRAPH_H

#include <string>

using namespace std;

const int MAX_ELEMENTS = 50;

class UGraph
{
    private:
        double data[MAX_ELEMENTS][MAX_ELEMENTS];
        char label[MAX_ELEMENTS]; // Label vertex
        int jumVertex;            // Jumlah vertex

        int find(char labelVertex);
    public:
        UGraph(void);
        void insertVertex(char labelVertex);
        void deleteVertex(char labelVertex);
        void insertEdge(char vertex1, char vertex2);
        void deleteEdge(char vertex1, char vertex2);
        long int length();
        void display();
};

#endif // UGRAPH_H
