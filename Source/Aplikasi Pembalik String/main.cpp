// ---------------------------------------
// Contoh untuk menguji senarai berantai
// ---------------------------------------

#include <iostream>
#include <string>
#include "..\LinkList.h"

using namespace std;

int main()
{
    LinkList senarai;

    string str = "Selamat belajar membalik string";
    for (unsigned int i = 0; i < str.length(); i++)
       senarai.insert(str[i]);

    cout << "Isi semula: " << str << endl;

    //  Tampilkan
    cout << "Hasil pembacaan dari senarai: ";
    senarai.display();

    return 0;
}
