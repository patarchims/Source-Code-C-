// --------------------------------------------
// ListGanda.h
//
// Implementasi kelas SimpulGanda dan ListGanda
//     (Aplikasi senarai berantai ganda)
// --------------------------------------------

#ifndef LISTGANDA_H
#define LISTGANDA_H

class SimpulGanda
{
    public:
        char data;
        SimpulGanda* berikut;
        SimpulGanda* sebelum;

    // Konstruktor
    SimpulGanda(char data);
};

class ListGanda
{
    private:
        SimpulGanda* pertama;
        SimpulGanda* terakhir;
    public:
        ListGanda();
        virtual ~ListGanda();
        void insertFirst(char data);
        void insertLast(char data);
        bool insertAfter(char kunci, char data);
        bool empty();
        char removeFirst();
        char removeLast();
        bool removeKey(char data);
        void displayForward();
        void displayBackward();
};

#endif // LISTGANDA_H
