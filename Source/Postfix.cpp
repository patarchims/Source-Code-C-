// -------------------------------------------
// Postfix.cpp
//
// Implementasi kelas Postfix
//     (Aplikasi pemrosesan postfix)
// -------------------------------------------

#include <iostream>
#include <string>
#include <cstdlib>  // Diperlukan untuk exit()

#include "ListTumpukan.h"
#include "Postfix.h"

using namespace std;

// -------------------------------------------
// Konstruktor
// -------------------------------------------
Postfix::Postfix()
{
    top = -1;      // Puncak stack untuk perhitungan ekspresi
}

// -------------------------------------------
// priority() (bersifat privat)
//
// Untuk menghitung prioritas operator.
//    Selain operator dianggap sama dengan nol
// -------------------------------------------
int Postfix::priority(char simbol)
{
    int nilai;

    switch (simbol)
    {
       case '(':  nilai = 1; break;
       case ')':  nilai = 2; break;
       case '+':
       case '-':  nilai = 3; break;
       case '*':
       case '/':
       case '%':  nilai = 4; break;
       case '^':  nilai = 5; break;
       default:   nilai = 0;
    }

    return nilai;
}

// -------------------------------------------
// push() (bersifat privat)
//
// Memasukkan bil ke stack yang dipakai
//    untuk menghitung ekspresi postfix
// -------------------------------------------
void Postfix::push(int bil)
{
    if (top == MAXSIZE)
    {
        cout << "Overflow";
        exit(1);  // Hentikan eksekusi
    }

    top = top + 1;
    stackOperand[top] = bil;

}

// -------------------------------------------
// pop() (bersifat privat)
//
// Untuk mengambil bilangan dari stack
//    penghitung ekspresi postfix
// -------------------------------------------
int Postfix::pop()
{
    if (top == -1)
    {
        cout << "Stack kosong" << endl;
        exit(1); // Hentikan eksekusi
    }

    int nilai = stackOperand[top];
    top = top - 1 ;
    return nilai;
}

// -------------------------------------------
// calculate() (bersifat privat)
//
// Menghitung ekspresi sesuai dengan operator
// -------------------------------------------
int Postfix::calculate(char oper, int operand1, int operand2)
{
    int hasil;

    switch(oper)
    {
        case '^' :
            hasil = 1;
            for (int i = 1; i <= operand2; i++)
                hasil = hasil * operand1;
            break;
        case '*' :
            hasil = operand1 * operand2;
            break;
        case '/' :
            hasil = operand1 / operand2;
            break;
        case '%' :
            hasil = operand1 % operand2;
            break;
        case '+' :
            hasil = operand1 + operand2;
            break;
        case '-' :
            hasil = operand1 - operand2;
            break;
    }

    return hasil;
}

// -------------------------------------------
// getResult() (bersifat publik)
//
// Menghitung ekspresi infix
// -------------------------------------------
string Postfix::getResult(string stringInfix)
{
    // Kosongkan stack
    while (!stack.empty())
      stack.pop();

    // Kosongkan hasil postfix
    string stringPostfix = "";

    // Tambahkan ) di akhir String infix
    stringInfix = stringInfix + ")";

    // Tumpuk ( ke stack
    stack.push('(');

    char karakter, simbol;
    for (unsigned int i = 0; i < stringInfix.length(); i++)
    {
        simbol = stringInfix[i];
        int prioritas = priority(simbol);
        switch(prioritas)
        {
            case 1: // Kalau simbol berupa (
                stack.push(simbol);
                break;
            case 2: // Kalau simbol berupa )
                karakter = stack.pop();
                while (karakter != '(')
                {
                    stringPostfix = stringPostfix + karakter;
                    karakter = stack.pop();
                };
                break;
            case 3: // Kalau simbol berupa + atau -
            case 4: // Kalau simbol berupa *, /, atau %
            case 5: // Kalau simbol berupa ^
                karakter = stack.pop();
                while (priority(karakter) >= prioritas)
                {
                    stringPostfix = stringPostfix + karakter;
                    karakter = stack.pop();
                }

                stack.push(karakter);
                stack.push(simbol);
                break;
            default: // Kalau berupa operand
               stringPostfix = stringPostfix + simbol;
        }
    }

    return stringPostfix;
}

// -------------------------------------------
// postfix() (bersifat publik)
//
// Untuk menghitung ekspresi postfix
// -------------------------------------------
int Postfix::evalPostfix(string stringPostfix)
{
    char karakter;
    char operand1, operand2;
    cout << "Postfix=" << stringPostfix << endl;
    for (int i = 0; i < stringPostfix.length(); i++)
    {
        karakter = stringPostfix[i];
        if ( (karakter >= '0') && (karakter <= '9') )
        {
            // Berarti operand
            push(karakter - '0');
        }
        else
        {
            // Berarti operator, maka lakukan perhitungan
            // dan hasilnya taruh ke stack
            operand2 = pop();
            operand1 = pop();
            int nilai = calculate(karakter, operand1, operand2);
            push(nilai);
        }
    }

    return pop(); // Ambil dari stack
}

// -------------------------------------------
// evalInfix() (bersifat publik)
//
// mengevaluasi infix
// -------------------------------------------
int Postfix::evalInfix(string stringInfix)
{
    string stringPostfix = getResult(stringInfix);
    return evalPostfix(stringPostfix);
}
