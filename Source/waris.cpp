#include <iostream>
#include <string>
using namespace std;

class Orang
{
private:
    string nama;
    string jenisKelamin;
public:
    // Konstruktor
    Orang(string nama, string jenisKelamin)
    {
        Orang::nama = nama;
        Orang::jenisKelamin = jenisKelamin;
    }

    void infoOrang(void)
    {
        cout << "Nama           : "
             << nama << endl;
        cout << "Jenis kelamin  : "
             << jenisKelamin << endl;
    }

    string perolehNama(void)
    {
        return nama;
    }

    string perolehKelamin(void)
    {
        return jenisKelamin;
    }
};

class Pegawai : Orang
{
private:
    string nip;
public:
    // Konstruktor
    Pegawai(string nip, string nama, string jenisKelamin) :
         Orang(nama, jenisKelamin)
    {
        Pegawai::nip = nip;
    }

    void infoPegawai(void)
    {
        cout << "Kelas Pegawai" << endl;
        cout << "NIP            : "
             << nip << endl;
        infoOrang();
    }
};

int main()
{
    Orang siX("Rian", "Pria");
    siX.infoOrang();

    cout << "---------------------" << endl;

    Pegawai sekretaris("12345", "Andhien", "Wanita");
    sekretaris.infoPegawai();

    return 0;
}
