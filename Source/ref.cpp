#include <iostream>
using namespace std;

void tukar(int x, int y)
{
    int tmp;

    tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int m = 5, n = 7;

    cout << "m = " << m << " n = " << n << endl;
    tukar(m, n);
    cout << "m = " << m << " n = " << n << endl;

    return 0;
}
