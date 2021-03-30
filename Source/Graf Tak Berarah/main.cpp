// ------------------------------------------
// Bagian untuk menguji Graf Tak Berarah
// ------------------------------------------

#include <iostream>
#include "../UGraph.h"

using namespace std;

int main()
{
    UGraph graf;

    graf.insertVertex('A');
    graf.insertVertex('B');
    graf.insertVertex('C');
    graf.insertVertex('D');
    graf.insertVertex('E');
    graf.insertVertex('F');

    graf.insertEdge('A', 'D');
    graf.insertEdge('A', 'B');
    graf.insertEdge('B', 'D');
    graf.insertEdge('D', 'C');
    graf.insertEdge('B', 'C');
    graf.insertEdge('C', 'E');
    graf.insertEdge('E', 'F');
    graf.insertEdge('F', 'F');

    cout << "Graph: " << endl;
    graf.display();

    graf.deleteEdge('E', 'F');
    cout << "Setelah E-F dihapus: " << endl;
    graf.display();

    graf.deleteVertex('A');
    cout << "Setelah vertex A dihapus: " << endl;

    graf.display();

    cout << "Jumlah vertex sekarang: "
         << graf.length() << endl;

    return 0;
}
