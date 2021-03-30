#include <iostream>
using namespace std;

int main()
{
    int nilai[5];

    // Mengisi elemen larik
    nilai[0] = 75;
    nilai[1] = 80;
    nilai[2] = 77;
    nilai[3] = 90;
    nilai[4] = 75;

    // Menampilkan semua elemen
    for (int i = 0; i < 5; i++)
        cout << "Isi elemen dengan indeks "
             << i << " : " << nilai[i] << endl;

    return 0;
}
