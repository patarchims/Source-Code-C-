// ------------------------------------------
// Bagian untuk menguji tabel hash linear
// ------------------------------------------

#include <iostream>
#include "../HashLin.h"

using namespace std;

int main()
{
    // Buat tabel hash untuk 11 data
    HashLinear tabel(11);

    // Memasukkan data ke dalam tabel hash
    tabel.insert(12, "Andika");
    tabel.insert(13, "Ratna");
    tabel.insert(16, "Dewi");
    tabel.insert(17, "Ari Wardi");
    tabel.insert(20, "Karmila");

    cout << "Keadaan awal: " << endl;
    tabel.display();

    // Tes tabrakan hash
    tabel.insert(23, "Diana Riana");
    tabel.insert(45, "Shanti");
    tabel.insert(108, "Ahmad Dani");

    cout << "Setelah ditambah: " << endl;
    tabel.display();

    // Cari Data
    cout << "Nip 17: "
         << tabel.find(17) << endl;

    cout << "Nip 48: "
         << tabel.find(48) << endl;

    // Hapus data
    tabel.remove(17);

    cout << "Keadaan setelah NIP 17 dihapus: " << endl;
    tabel.display();

    return 0;
}
