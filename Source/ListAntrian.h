// ------------------------------------------------
// ListAntrian.h
//
// Implementasi kelas SimpulAntrian dan ListAntrian
//     (Aplikasi senarai berantai untuk antrian)
// ------------------------------------------------

#ifndef LISTANTRIAN_H
#define LISTANTRIAN_H

class SimpulAntrian
{
    public:
        char data;
        SimpulAntrian* berikut;

    // Konstruktor
    SimpulAntrian(char data);
};

class ListAntrian
{
    private:
        SimpulAntrian* pertama;
        SimpulAntrian* terakhir;
    public:
        ListAntrian();
        ~ListAntrian();
        void insert(char data);
        bool empty();
        char remove();
        void display();
};

#endif // LISTANTRIAN_H
