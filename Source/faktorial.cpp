#include <iostream>
using namespace std;

long faktorial(int m)
{
    if (m == 0)
        return 1;
    else
        return m * faktorial(m - 1);
}

int main()
{
    int n = 3;
    cout << n << "! = "
         << faktorial(n) << endl;

    n = 6;
    cout << n << "! = "
         << faktorial(n) << endl;

    return 0;
}
