#include <iostream>
#include <string>
using namespace std;

class Mobil
{
private:
    string tipe;
public:
    // Konstruktor
    Mobil(string tipe)
    {
        Buku::tipe = tipe;
        cout << "Konstruktor mobil. Tipe: "
             << Mobil::tipe << endl;
    }

    // Destruktor
    ~Mobil()
    {
        cout << "Destruktor mobil. Tipe: "
             << tipe << endl;
    }
    void perolehInfo(void)
    {
        cout << "Info Mobil. Tipe: " << tipe << endl;
    }
};

int main()
{
    Mobil mobilKota("Honda Jazz");
    Mobil mpv("Mitsubishi Delica");

    mobilKota.perolehInfo();
    mpv.perolehInfo();

    return 0;
}
