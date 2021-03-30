#include <iostream>
#include <string>
using namespace std;

struct RekamanBuku
{
    string judul;
    string pengarang;
    int jumlah;
};

int main()
{
    struct RekamanBuku *novel;

    // Buat variabel dinamis dan
    //    atur agar ditunjuk oleh novel
    novel = new RekamanBuku;

    // Isi data melalui novel
    novel->judul = "Meriam Benteng Navarone";
    novel->pengarang = "Alistair McClean";
    novel->jumlah = 4;

    // Mengakses data melalui variabel pointer novel
    cout << "Judul     : " << novel->judul << endl;
    cout << "Pengarang : " << novel->pengarang << endl;
    cout << "Jumlah    : " << novel->jumlah << endl;

    // Bebaskan memori untuk variabel dinamis
    delete novel;

    return 0;
}
