// --------------------------
// Bagian untuk menguji kamus
// --------------------------

#include <iostream>
#include "../kamus.h"

using namespace std;

int main()
{
    // Buat tabel hash untuk 11 data
    HashKamus tabelHash(11);

    // Memasukkan data ke dalam tabel hash
    tabelHash.insert("Kucing", "Cat");
    tabelHash.insert("Pelangi", "Rainbow");
    tabelHash.insert("Mobil", "Car");
    tabelHash.insert("Tanaman", "Plant");
    tabelHash.insert("Teman", "Friend");
    tabelHash.insert("Kota", "City");
    tabelHash.insert("Burung dara", "Pigeon");
    tabelHash.insert("Api", "Fire");
    tabelHash.insert("Batu", "Stone");

    cout << "Keadaan awal: " << endl;
    tabelHash.display();

    // Cari Data
    cout << "Mobil: " << tabelHash.find("Mobil") << endl;

    cout << "Burung dara: "
         << tabelHash.find("Burung dara") << endl;

    cout << "Kuda: " << tabelHash.find("Kuda") << endl;

    // Hapus data
    tabelHash.remove("Mobil");

    cout << "Keadaan setelah Mobil dihapus: " << endl;
    tabelHash.display();

    return 0;
}
