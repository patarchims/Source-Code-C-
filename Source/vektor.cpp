#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ArrayData
{
private:
    vector<string> kota;
    int jumKota;
public:
    // Konstruktor
    ArrayData(int ukuran) : jumKota(0)
    {
        kota.resize(ukuran);  // Ukuran vector bisa ditentukan
                              // sewaktu program dijalankan
    }

    // Pilih tindakan pada menu
    int pilihMenu()
    {
        char pilihan;

        do
        {
            cout << "Menu:" << endl;
            cout << "1. Tambah data" << endl;
            cout << "2. Hapus data" << endl;
            cout << "3. Tampilkan data" << endl;
            cout << "4. Selesai" << endl;
            cout << "Pilihan (1, 2, 3, atau 4 dan tekan Enter): ";
            cin >> pilihan;
        }
        while (pilihan < '1' || pilihan > '4');

        return pilihan;
    }

    // Menampilkan isi array
    void tampilkanData(void)
    {
        cout << "Isi array: " ;

        for (int j = 0; j < jumKota; j++)
        {
            cout << kota[j];

            if (j != (jumKota-1))
                cout << " - ";  // Beri pemisah antarkota
        }

        cout << endl; // Pindah baris
    }

    // Menambahkan data
    bool tambahData(string kotaBaru)
    {
        if (jumKota == kota.size())
        {
            cout << "Array sudah penuh" << endl;
            return false;      // Gagal menambahkan kota
        }

        // Cari posisi penyisipan
        int posisi = -1;
        for (int j = 0; j < jumKota; j++)
            if (kotaBaru.compare(kota[j]) < 0)
            {
                posisi = j;
                break;
            }

        if (posisi == -1)
        {
            // Sisipkan di belakang
            kota[jumKota] = kotaBaru;
            jumKota = jumKota + 1;
        }
        else // Kalau posisi tidak sama dengan -1
        {
            // Sisipkan pada posisi
            // a. Geser dulu
            for (int j = jumKota-1; j >= posisi; j--)
                kota[j + 1] = kota[j];

            // b. Sisipkan
            kota[posisi] = kotaBaru;
            jumKota = jumKota + 1;
        }

        return true;
    }

    // Menghapus data
    bool hapusData(string kotaX)
    {
        // Cari posisi penghapusan
        int posisi = -1;
        for (int j = 0; j < jumKota; j++)
        {
            if (kotaX.compare(kota[j]) == 0)  //  kalau sama
            {
                posisi = j;
                break;
            }
        }

        // Kalau tidak ditemukan
        if (posisi == -1)
        {
            return false; // Gagal menghapus karena data tdk ada
        }

        // Penghapusan kota
        if (posisi == (jumKota-1))
        {
            // Hapus di bagian akhir
            jumKota = jumKota - 1;
        }
        else // Kalau posisi tidak sama
             // dengan yang terakhir
        {
            // Geser ke atas untuk menghapus
            for (int j = posisi+1; j < jumKota; j++)
                kota[j - 1] = kota[j];
            jumKota = jumKota - 1;
        }

        return true;
    }
};

int main()
{
    int pilihan;      // Pilihan tindakan
    string kotaX;     // Kota yang akan dihapus atau ditambahkan

    int ukuran = 10;
    ArrayData kota(ukuran); // Buat objek

    // Sisipkan 3 kota. Pastikan kota dalam keadaan urut
    kota.tambahData("Medan");
    kota.tambahData("Pontianak");
    kota.tambahData("Surabaya");
    kota.tampilkanData();

    // Proses interaksi dengan pemakai
    do
    {
        pilihan = kota.pilihMenu();
        switch (pilihan)
        {
        case '1':
            cout << "Penambahan data. Kota: ";
            cin >> kotaX;
            if (!kota.tambahData(kotaX))
                cout << "Gagal menambah data. Wadah penuh"
                     << endl;
            break;
        case '2':
            cout << "Penghapusan data. Kota: ";
            cin >> kotaX;
            if (!kota.hapusData(kotaX))
                cout << "Data yang akan dihapus tidak ditemukan"
                     << endl;
            break;
        case '3':
            kota.tampilkanData();
        }
    }
    while (pilihan != '4');

    return 0;
}
