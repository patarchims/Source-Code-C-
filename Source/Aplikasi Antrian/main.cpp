// ---------------------------------------
// Contoh untuk menguji senarai berantai
//    yang dipakai dalam antrian
// ---------------------------------------

#include <iostream>
#include "../ListAntrian.h"

using namespace std;

int main()
{
    ListAntrian antrian;

    antrian.insert('A');
    antrian.insert('B');
    antrian.insert('C');
    antrian.insert('D');

    cout << "Isi antrian semula:" << endl;
    antrian.display();

    char kar = antrian.remove();
    cout << "Data yang diambil dari antrian; "
         << kar << endl;
    cout << "Isi antrian setelah diambil satu data:"
         << endl;
    antrian.display();

    antrian.insert('X');
    antrian.insert('Y');
    cout << "Isi antrian setelah penambahan dua data:"
         << endl;
    antrian.display();
}
