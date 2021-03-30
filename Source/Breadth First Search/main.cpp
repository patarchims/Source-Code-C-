// ------------------------------------------
// Bagian untuk menguji BFS
// ------------------------------------------

#include <iostream>
#include "../Bfs.h"

using namespace std;

int main()
{
    Bfs graf;

    graf.insertVertex('A');
    graf.insertVertex('B');
    graf.insertVertex('C');
    graf.insertVertex('D');
    graf.insertVertex('E');
    graf.insertVertex('F');
    graf.insertVertex('G');
    graf.insertVertex('H');
    graf.insertVertex('I');
    graf.insertVertex('J');

    graf.insertEdge('A', 'B');
    graf.insertEdge('A', 'C');
    graf.insertEdge('B', 'D');
    graf.insertEdge('B', 'E');
    graf.insertEdge('C', 'F');
    graf.insertEdge('C', 'G');
    graf.insertEdge('D', 'H');
    graf.insertEdge('E', 'H');
    graf.insertEdge('F', 'I');
    graf.insertEdge('G', 'I');
    graf.insertEdge('H', 'J');
    graf.insertEdge('I', 'J');

    cout << "graf: " << endl;
    graf.display();

    return 0;
}
