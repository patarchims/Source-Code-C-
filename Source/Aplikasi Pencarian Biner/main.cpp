// ------------------------------------------
// Bagian untuk menguji pencarian biner
// ------------------------------------------

#include <iostream>
#include "../Binary.h"

using namespace std;

int main()
{
    // Data harus urut
    int data[] = {3, 21, 34, 52, 54, 67, 68, 88, 89, 90};
    BinarySearch daftar(data, 10);

    cout << "Isi array: ";
    daftar.display();

    int dicari = 21;
    int posisi = daftar.find(dicari);
    if (posisi != -1)
        cout << "Data " << dicari
             << " ditemukan pada posisi : "
             << posisi << endl;
    else
        cout << "Data " << dicari
             << " tidak ditemukan." << endl;

    dicari = 77;
    posisi = daftar.find(dicari);
    if (posisi != -1)
        cout << "Data " << dicari
             << " ditemukan pada posisi : "
             << posisi << endl;
    else
        cout << "Data " << dicari
             << " tidak ditemukan." << endl;
    return 0;
}
