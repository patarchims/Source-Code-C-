// ------------------------------------------
// Contoh senarai berantai
// ------------------------------------------

#include <iostream>
#include <string>

using namespace std;

class Simpul
{
public:
    string kode;
    string nama;
    Simpul* berikut;

    // Konstruktor
    Simpul(string xkode, string xnama)
    {
        kode = xkode;
        nama = xnama;
        berikut = NULL;
    }

    void display()
    {
        cout << kode << " : "
             << nama << endl;
    }
};

class SenaraiBerantai
{
private:
    Simpul* pertama;
public:
    // Konstruktor
    SenaraiBerantai()
    {
        pertama = NULL;
    }

    // Destruktor
    ~SenaraiBerantai()
    {
        // Menghapus semua simpul
        Simpul* penunjukHapus;
        while (pertama != NULL)
        {
            penunjukHapus = pertama;
            pertama = pertama->berikut;
            delete penunjukHapus;
        }
    }

    // Memasukkan data ke senarai berantai
    //    Nilai balik tidak ada
    void insert(string kode, string nama)
    {
        Simpul* ptrBaru;

        ptrBaru = new Simpul(kode, nama);
        ptrBaru->berikut = pertama;
        pertama = ptrBaru;
    }

    // Mencari data
    //    Nilai balik berupa true kalau yang dicari ketemu
    //    Dalam hal ini, pendahulu merupakan simpul yang
    //    terletak di depan simpul yang dicari
    bool find(Simpul* &pendahulu, Simpul* &posisiData, string x)
    {
        posisiData = pertama;
        pendahulu = NULL;
        bool ditemukan = false;
        while (posisiData != NULL)
        {
            string kode = posisiData->kode;
            if (kode.compare(x) == 0)
            {
                ditemukan = true;
                break; // Keluar dari while
            }

            pendahulu = posisiData;
            posisiData = posisiData->berikut;
        }

        return ditemukan;
    }

    // Mencari data
    //    Nilai balik berupa NULL kalau yang dicari tdadk ketemu
    Simpul* find(string x)
    {
        Simpul* pendahulu;
        Simpul* posisiData;
        bool ditemukan = find(pendahulu, posisiData, x);
        if (! ditemukan)
            return NULL;
        else
            return posisiData;
    }

    // Menghapus simpul yang berisi kode x
    //     Nilai balik berupa :
    //        - true kalau data berhasil dihapus
    //        - false kalau data tidak ada
    bool remove(string x)
    {
        Simpul* pendahulu;
        Simpul* posisiData;
        bool ditemukan = find(pendahulu, posisiData, x);
        if (! ditemukan)
        {
            cout << "Data yang akan dihapus tidak ditemukan."
                 << endl;
            return false;
        }

        if (pendahulu == NULL)
        {
            // Data yang dihapus ditunjuk oleh pertama
            pertama = pertama->berikut;
            delete posisiData;
        }
        else
        {
            // Data yang dihapus tidak ditunjuk oleh pertama
            pendahulu->berikut = posisiData->berikut;
            delete posisiData;
        }
    }

    // Menampilkan data
    void display(void)
    {
        cout << "Isi senarai berantai:" << endl;

        Simpul* penunjuk = pertama;
        while (penunjuk != NULL)
        {
            penunjuk->display();
            penunjuk = penunjuk->berikut;
        }
    }
};

int main()
{
    SenaraiBerantai senarai;

    // Masukkan 5 buah nama
    senarai.insert("AMN", "Aminudin");
    senarai.insert("ZAS", "Zaskia");
    senarai.insert("RIN", "Rina Melati");
    senarai.insert("FAR", "Farhan");
    senarai.insert("AGN", "Agnes Monica");

    cout << "Keadaan awal:" << endl;
    senarai.display();

    senarai.remove("RIN");

    cout << endl;
    cout << "Setelah RIN dihapus:" << endl;
    senarai.display();

    // Cari RIN
    string dicari = "RIN";
    cout << endl;
    cout << "Pencarian " << dicari << endl;
    Simpul* posisiData =  senarai.find(dicari);
    if (posisiData == NULL)
       cout << dicari << " tidak ditemukan." << endl;
    else
    {
        cout << "Hasil pencarian:" << endl;
        posisiData->display();
    }

    // Cari FAR
    dicari = "FAR";
    cout << endl;
    cout << "Pencarian " << dicari << endl;
    posisiData =  senarai.find(dicari);
    if (posisiData == NULL)
       cout << dicari << " tidak ditemukan." << endl;
    else
    {
        cout << "Hasil pencarian:" << endl;
        posisiData->display();
    }

    return 0;
}
