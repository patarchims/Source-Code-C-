// ------------------------------------------
// Bagian untuk menguji pengurutan data
//        menggunakan Shell Sort
// ------------------------------------------

#include <iostream>
#include "../ShellSort.h"

using namespace std;

int main()
{
    ShellSort daftar(10);

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

    daftar.sortDesc();
    cout << "Descending: ";
    daftar.display();

    return 0;
}
