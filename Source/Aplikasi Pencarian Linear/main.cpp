// ------------------------------------------
// Bagian untuk menguji pencarian linear
// ------------------------------------------

#include <iostream>
#include "../Linear.h"

using namespace std;

int main()
{
    int data[] = {54, 67, 89, 21, 3, 67, 88, 34, 90, 52};
    LinearSearch daftar(data, 10);

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
