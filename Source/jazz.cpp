#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    char penyanyiJazz[5][30];

    strcpy(penyanyiJazz[0], "Rien Jamain");
    strcpy(penyanyiJazz[1], "Yopie Latul");
    strcpy(penyanyiJazz[2], "Nunung Wardiman");
    strcpy(penyanyiJazz[3], "Andhien");
    strcpy(penyanyiJazz[4], "Margie Siegers");

    for (int j = 0; j < 5; j++)
        cout << j+1 << ". "
             << penyanyiJazz[j] << endl;

    return 0;
}
