// --------------------------------------------------
// LinkTumpukan.h
//
// Implementasi kelas SimpulTumpukan dan ListTumpukan
//     (Aplikasi untuk membalik string)
// --------------------------------------------------

#ifndef LISTTUMPUKAN_H
#define LISTTUMPUKAN_H

class SimpulTumpukan
{
    public:
        char data;
        SimpulTumpukan* berikut;

    // Konstruktor
    SimpulTumpukan(char data);
};

class ListTumpukan
{
    private:
        SimpulTumpukan* puncak;
    public:
        ListTumpukan();
        virtual ~ListTumpukan();
        void push(char data);
        bool empty();
        char pop();
};

#endif // LISTTUMPUKAN_H
