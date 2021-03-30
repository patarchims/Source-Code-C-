// --------------------------------------------
// Contoh untuk menguji
//     pemrosesan postfix
// --------------------------------------------

#include <iostream>
#include <string>
#include "../postfix.h"

using namespace std;

int main()
{
    Postfix postfix;

    string stringInfix = "A+B*C";
    cout << stringInfix << " -> "
         << postfix.getResult(stringInfix) << endl;

    stringInfix = "(A+B)*C";
    cout << stringInfix << " -> "
         << postfix.getResult(stringInfix) << endl;

    stringInfix = "(A+B)*(C-D)";
    cout << stringInfix << " -> "
         << postfix.getResult(stringInfix) << endl;

    stringInfix = "A+B*C+(D-E)/F";
    cout << stringInfix << " -> "
         << postfix.getResult(stringInfix) << endl;

    stringInfix = "(A+B)*(C-D)/((X+Y)*(R-S))";
    cout << stringInfix << " -> "
         << postfix.getResult(stringInfix) << endl;

    stringInfix = "((A+B)*(C-D))^2/((X+Y)*(R-S))";
    cout << stringInfix << " -> "
         << postfix.getResult(stringInfix) << endl;

    // Tes evaluasi
    stringInfix = "(1+3)*(6-2)";
    cout << "Hasil ekspresi "
         <<  stringInfix << " = "
         << postfix.evalPostfix(
                postfix.getResult(stringInfix)) << endl;

    stringInfix = "((1+3)*(6-2)+4-2^3+7/2)%4";
    cout << "Hasil ekspresi via evalInfix" << endl;
    cout <<  stringInfix << " = "
         << postfix.evalInfix(stringInfix) << endl;

    cout << "Hasil ekspresi via evalPostfix" << endl;
    cout <<  stringInfix << " = "
         << postfix.evalPostfix(
                postfix.getResult(stringInfix)) << endl;

    return 0;
}
