#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Tumpukan
{
private:
    vector<string> tumpukan;
    int puncak;
public:
    // Konstruktor
    Tumpukan(int ukuran) : puncak(-1)
    {
        tumpukan.resize(ukuran);  // Ukuran vector
    }

    // Memasukkan data ke tumpukan
    //    Nilai balik berupa false
    //    kalau tumpukan sudah penuh
    bool push(string data)
    {
        // Periksa kalau tumpukan penuh
        if (puncak == (tumpukan.size()-1))
            return false;

        // Masukkan data ke tumpukan
        puncak++;
        tumpukan[puncak] = data;
    }

    string pop(void)
    {
        if (! empty())
            return tumpukan[puncak--];
        else
            return "";  // String kosong menyatakan
        // tumpukan sudah habis
    }

    bool empty(void)
    {
        return (puncak == -1);
    }
};

int main()
{
    int ukuran = 10;
    Tumpukan stack(ukuran); // Buat objek

    // Masukkan 5 buah nama
    stack.push("Aminudin");
    stack.push("Zaskia");
    stack.push("Rina Melati");
    stack.push("Farhan");
    stack.push("Agnes Monica");

    // Kosongkan isi tumpukan dan tampilkan
    while (! stack.empty())
    {
        string nama = stack.pop();
        cout << nama << endl;
    }

    return 0;
}
