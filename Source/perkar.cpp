#include <iostream>
#include <string>
using namespace std;

int main()
{

    string str = "Pasti bisa!";

    // Menampilkan per karakter
    for (int j = 0; j < str.length(); j++)
        cout << str.at(j) << endl;

    // Mengambil substring mulai indeks 6
    cout << str.substr(6, 4) << endl;

    return 0;
}
