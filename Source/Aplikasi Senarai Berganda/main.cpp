// --------------------------------------------
// Contoh untuk menguji
//     senarai berantai ganda
// --------------------------------------------

#include <iostream>
#include "../ListGanda.h"

using namespace std;

int main()
{
    ListGanda senarai;
    senarai.insertFirst('A');
    senarai.insertFirst('B');
    senarai.insertFirst('C');
    senarai.insertFirst('D');
    senarai.insertFirst('E');
    senarai.displayForward();

    cout << "Penyisipan X dan Y: " << endl;
    senarai.insertLast('X');
    senarai.insertLast('Y');
    senarai.displayBackward();
    senarai.displayForward();

    char karakter = senarai.removeFirst();
    cout << "Karakter terkiri yang diambil: " << endl;
    senarai.displayForward();

    senarai.removeKey('C');
    cout << "Setelah C diambil:" << endl;
    senarai.displayForward();

    karakter = senarai.removeLast();
    cout << "Karakter terkanan yang diambil: " << endl;
    senarai.displayForward();

    cout << "Penyisipan setelah B: " << endl;
    senarai.insertAfter('B', 'M');
    senarai.displayForward();

    return 0;
}
