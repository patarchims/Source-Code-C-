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

    // Buat variabel dinamis berupa array dan
    //    atur agar ditunjuk oleh novel
    novel = new RekamanBuku[5];

    // Isi data melalui novel
    novel[0].judul = "Meriam Benteng Navarone";
    novel[0].pengarang = "Alistair McClean";
    novel[0].jumlah = 4;

    novel[1].judul = "Octopussy";
    novel[1].pengarang = "Ian Flemmings";
    novel[1].jumlah = 2;

    novel[2].judul = "Badai Pasti Berlalu";
    novel[2].pengarang = "Marga T.";
    novel[2].jumlah = 2;

    novel[3].judul = "Twilight";
    novel[3].pengarang = "Stephenie Meyer";
    novel[3].jumlah = 3;

    novel[4].judul = "Harry Potter Deadly Hallows";
    novel[4].pengarang = "JK Rowlings";
    novel[4].jumlah = 4;

    // Mengakses data melalui variabel pointer novel
    for (int j = 0; j < 5; j++)
    {
        cout << "Judul     : " << novel[j].judul << endl;
        cout << "Pengarang : " << novel[j].pengarang << endl;
        cout << "Jumlah    : " << novel[j].jumlah << endl;
        cout << endl;
    }

    // Bebaskan memori untuk variabel dinamis
    delete [] novel;

    return 0;
}
