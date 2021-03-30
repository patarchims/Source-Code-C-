// ------------------------------------------------
// Dfs.h
//
// Berisi definisi kelas Dfs
//     (Penelusuran dengan DFS)
// ------------------------------------------------

#ifndef DFS_H
#define DFS_H

#include <string>
#include "ListTumpukan.h"

using namespace std;

const int MAX_ELEMENTS = 50;

class Dfs
{
    private:
        double data[MAX_ELEMENTS][MAX_ELEMENTS];
        char label[MAX_ELEMENTS]; // Label vertex
        int jumVertex;            // Jumlah vertex
        ListTumpukan* tumpukan;

        int find(char labelVertex);
    public:
        Dfs(void);
        void insertVertex(char labelVertex);
        void insertEdge(char vertex1, char vertex2);
        void display();
};

#endif // DFS_H
