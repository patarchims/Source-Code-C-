#include <iostream>
#include <string>
#include "orang.h"

using namespace std;

Orang::Orang(string nama, string jenisKelamin)
{
    Orang::nama = nama;
    Orang::jenisKelamin = jenisKelamin;
}

void Orang::infoOrang(void)
{
    cout << "Nama           : "
         << Orang::nama << endl;
    cout << "Jenis kelamin  : "
         << jenisKelamin << endl;
}

string Orang::perolehNama(void)
{
    return Orang::nama;
}

string Orang::perolehKelamin(void)
{
    return Orang::jenisKelamin;
}
