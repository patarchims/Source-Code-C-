#include <iostream>
#include <cstring>
using namespace std;

struct RekamanBuku
{
    char judul[35];
    char pengarang[25];
    int jumlah;
};

int main()
{
    struct RekamanBuku buku;
    strcpy(buku.judul, "Pascal");
    strcpy(buku.pengarang, "Abdul Kadir");
    buku.jumlah = 2;

    cout << "Judul     : " << buku.judul << endl;
    cout << "Pengarang : " << buku.pengarang << endl;
    cout << "Jumlah    : " << buku.jumlah << endl;

    return 0;
}
