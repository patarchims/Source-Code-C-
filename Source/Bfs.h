// ------------------------------------------------
// Bfs.h
//
// Berisi definisi kelas Bfs
//     (Penelusuran dengan BFS)
// ------------------------------------------------

#ifndef BFS_H
#define BFS_H

#include <string>
#include "ListAntrian.h"

using namespace std;

const int MAX_ELEMENTS = 50;

class Bfs
{
    private:
        double data[MAX_ELEMENTS][MAX_ELEMENTS];
        char label[MAX_ELEMENTS]; // Label vertex
        int jumVertex;            // Jumlah vertex
        ListAntrian* antrian;

        int find(char labelVertex);
    public:
        Bfs(void);
        void insertVertex(char labelVertex);
        void insertEdge(char vertex1, char vertex2);
        void display();
};

#endif // BFS_H
