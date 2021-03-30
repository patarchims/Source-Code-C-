// ---------------------------------------
// Contoh untuk menguji Senarai berantai
//     yang dipakai sebagai tumpukan
// ---------------------------------------

#include <iostream>
#include "../ListTumpukan.h"

using namespace std;

int main()
{
    ListTumpukan tumpukan;

    tumpukan.push('A');
    tumpukan.push('B');
    tumpukan.push('C');
    tumpukan.push('D');

    // Ambil isi tumpukan
    cout << "Isi tumpukan dari atas  ke bawah:" << endl;

    char karakter;
    while (! tumpukan.empty())
    {
        karakter = tumpukan.pop();
        cout << karakter << endl;
    }

    return 0;
}
