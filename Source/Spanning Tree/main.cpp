// ------------------------------------------
// Bagian untuk menguji Minimm Spanning Tree
// ------------------------------------------

#include <iostream>
#include "../Spanning.h"

using namespace std;

int main()
{
    SpanningTree graf;

    graf.insertVertex('A');
    graf.insertVertex('B');
    graf.insertVertex('C');
    graf.insertVertex('D');

    graf.insertEdge('A', 'B', 5);
    graf.insertEdge('A', 'C', 1);
    graf.insertEdge('A', 'D', 7);
    graf.insertEdge('B', 'D', 3);
    graf.insertEdge('D', 'C', 2);
    graf.insertEdge('B', 'C', 5);
    cout << "Minimum Spanning Tree: " << endl;
    double panjang = graf.mst();
    cout << "Panjang : " << panjang << endl;

    return 0;
}
