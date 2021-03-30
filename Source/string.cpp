#include <iostream>
#include <string>
using namespace std;

int main()
{

    string penyanyiJazz[5];

    penyanyiJazz[0] = "Rien Jamain";
    penyanyiJazz[1] = "Yopie Latul";
    penyanyiJazz[2] = "Nunung Wardiman";
    penyanyiJazz[3] = "Andhien";
    penyanyiJazz[4] = "Margie Siegers";

    for (int j = 0; j < 5; j++)
        cout << j+1 << ". "
             << penyanyiJazz[j] << endl;

    return 0;
}
