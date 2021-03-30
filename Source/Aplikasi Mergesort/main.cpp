// ------------------------------------------
// Bagian untuk menguji pengurutan data
//        menggunakan Mergesort
// ------------------------------------------

#include <iostream>
#include "../MergeSort.h"

using namespace std;

int main()
{
    MergeSort daftar(10);

    daftar.insert(15);
    daftar.insert(98);
    daftar.insert(75);
    daftar.insert(13);
    daftar.insert(1);
    daftar.insert(44);
    daftar.insert(45);
    daftar.insert(65);
    daftar.insert(73);
    daftar.insert(81);

    cout << "Data Asli: ";
    daftar.display();

    daftar.sort();
    cout << "Ascending: ";
    daftar.display();

    return 0;
}
