// ------------------------------------------
// Bagian untuk menguji pengurutan data
//        menggunakan Bubble Sort
// ------------------------------------------

#include <iostream>
#include "../BubbleSort.h"

using namespace std;

int main()
{
    BubbleSort daftar(10);

    daftar.insert(15);
    daftar.insert(255);
    daftar.insert(150);
    daftar.insert(13);
    daftar.insert(1);
    daftar.insert(44);
    daftar.insert(45);
    daftar.insert(65);
    daftar.insert(73);
    daftar.insert(81);
    daftar.insert(99);

    cout << "Data Asli: ";
    daftar.display();

    daftar.sort();
    cout << "Ascending: ";
    daftar.display();

    daftar.sortDesc();
    cout << "Descending: ";
    daftar.display();

    return 0;
}
