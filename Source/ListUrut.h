// -------------------------------------------
// ListUrut.h
//
// Implementasi kelas SimpulData dan ListUrut
//     (Aplikasi untuk mengurutkan data)
// -------------------------------------------

#ifndef LISTURUT_H
#define LISTURUT_H

class SimpulData
{
    public:
        char data;
        SimpulData* berikut;

    // Konstruktor
    SimpulData(char data);
};

class ListUrut
{
    private:
        SimpulData* pertama;
    public:
        ListUrut();
        virtual ~ListUrut();
        void insert(char data);
        bool empty();
        char remove();
        void display();
};

#endif // LISTURUT_H
