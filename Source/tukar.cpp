#include <iostream>
using namespace std;

// Penukaran untuk tipe int
void tukar(int &x, int &y)
{
    int tmp;

    tmp = x;
    x = y;
    y = tmp;
}

// Penukaran untuk tipe double
void tukar(double &x, double &y)
{
    double tmp;

    tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int m = 5, n = 7;
    double x = 75.89, y = 12.34;

    cout << "m = " << m << " n = " << n << endl;
    tukar(m, n);
    cout << "m = " << m << " n = " << n << endl;

    cout << endl;

    cout << "x = " << x << " y = " << y << endl;
    tukar(x, y);
    cout << "x = " << x << " y = " << y << endl;

    return 0;
}
