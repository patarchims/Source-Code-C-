#include <iostream>
using namespace std;

template <class T> void tukar(T &x, T &y)
{
    T tmp;

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
