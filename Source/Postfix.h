// -------------------------------------------
// Postfix.h
//
// Implementasi kelas Postfix
//     (Aplikasi pemrosesan postfix)
// -------------------------------------------

#ifndef POSTFIX_H
#define POSTFIX_H

#define MAXSIZE 100

#include <string>
#include "ListTumpukan.h"

using namespace std;

class Postfix
{
    private:
        int stackOperand[MAXSIZE]; // stack operand
        int top;            // Puncak stackOperand
        ListTumpukan stack;
        int priority(char simbol);
        void push(int bil);
        int pop();
        int calculate(char oper, int operand1, int operand2);
    public:
        Postfix();
        string getResult(string stringInfix);
        int evalPostfix(string stringPostfix);
        int evalInfix(string stringInfix);
};

#endif // POSTFIX_H
