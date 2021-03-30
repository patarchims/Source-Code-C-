// ---------------------------------------
// LinkList.h
//
// Implementasi kelas Simpul dan LinkList
//     (Aplikasi untuk membalik string)
// ---------------------------------------

#ifndef LINKLIST_H
#define LINKLIST_H

class Simpul
{
    public:
        char data;
        Simpul* berikut;

    // Konstruktor
    Simpul(char karakter);
};

class LinkList
{
    private:
        Simpul* pertama;
    public:
        LinkList();
        virtual ~LinkList();
        void insert(char data);
        void display();
};

#endif // LINKLIST_H
