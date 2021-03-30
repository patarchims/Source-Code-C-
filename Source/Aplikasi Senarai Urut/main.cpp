// ---------------------------------------
// Contoh untuk menguji senarai berantai
//    dengan data urut
// ---------------------------------------

#include <iostream>
#include "../ListUrut.h"

using namespace std;

int main()
{
    ListUrut senarai;

    senarai.insert('A');
    senarai.insert('Z');
    senarai.insert('D');
    senarai.insert('M');
    senarai.insert('E');

    cout << "Isi setelah 5 data dimasukkan: " << endl;
    senarai.display();

    char kar = senarai.remove();
    cout << "Isi setelah diambil: " << kar << endl;
    senarai.display();

    senarai.insert('H');
    cout << "Setelah penambahan data H:" << endl;
    senarai.display();

    return 0;
}
