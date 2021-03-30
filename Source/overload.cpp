#include <iostream>
#include <string>
using namespace std;

class ContohOverload
{
public:
    // Konstruktor
    ContohOverload(string str)
    {
        cout << "Konstruktor dengan string.\n"
             << "Argumen: " << str << endl;
    }

    ContohOverload(int bil)
    {
        cout << "Konstruktor dengan bilangan.\n"
             << "Argumen: " << bil << endl;
    }
};

int main()
{
    ContohOverload ovStr("Selamat belajar!");
    ContohOverload ovBil(123);

    return 0;
}
