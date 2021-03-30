// ---------------------------------------------
// Bagian untuk menguji berbagai pengurutan data
// ---------------------------------------------

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>
#include "../BubbleSort.h"
#include "../SelectionSort.h"
#include "../InsertionSort.h"

using namespace std;

void timeval_diff(struct timeval *selisih,
                       struct timeval *waktu_akhir,
                       struct timeval *waktu_awal)
// Digunakan untuk menghitung selisih waktu
//    (waktu_awal dan waktu_akhir )
// selisih berisi selisih kedua waktu
{
    struct timeval temp_diff;
    if(selisih == NULL)
    {
        selisih =& temp_diff;
    }

    selisih->tv_sec = waktu_akhir->tv_sec -
                      waktu_awal->tv_sec ;
    selisih->tv_usec = waktu_akhir->tv_usec -
                       waktu_awal->tv_usec;

    // Hitung detik dan mikrodetik
    while(selisih->tv_usec < 0)
    {
        selisih->tv_usec += 1000000;
        selisih->tv_sec -= 1;
    }
}

int main()
{
    const long JUMDATA = 100000L; // 100.000 data

    struct timeval mulai;
    struct timeval akhir;
    struct timeval interval;

    int data_asli[JUMDATA];
    int data[JUMDATA];
    long j;

    cout << "Pembandingan kinerja pengurutan data\n";

    // Biji pembangkit random diisi dengan waktu sekarang
    //    supaya benar-benar acak
    srand( time(NULL) );

    // Bangkitkan bilangan random
    for (j = 0; j < JUMDATA; j++)
        // Buat data antara 1 sampai dengan 20000
        data[j] = rand() % 20000 + 1;

    // Pengurutan dengan bubble sort
    BubbleSort bubble(JUMDATA);
    for (j = 0; j < JUMDATA; j++)
        bubble.insert(data[j]);
    gettimeofday(&mulai,NULL);
    bubble.sort();
    gettimeofday(&akhir,NULL);
    timeval_diff(&interval,&akhir, &mulai);

    cout << "Waktu untuk bubble sort: " <<
         interval.tv_sec << " detik " <<
         interval.tv_usec << " mikrodetik" << endl;

    // Pengurutan dengan selection sort
    SelectionSort seleksi(JUMDATA);
    for (j = 0; j < JUMDATA; j++)
        seleksi.insert(data[j]);
    gettimeofday(&mulai,NULL);
    seleksi.sort();
    gettimeofday(&akhir,NULL);
    timeval_diff(&interval,&akhir, &mulai);

    cout << "Waktu untuk selection sort: " <<
         interval.tv_sec << " detik " <<
         interval.tv_usec << " mikrodetik" << endl;

    // Pengurutan dengan insertion sort
    InsertionSort insersi(JUMDATA);
    for (j = 0; j < JUMDATA; j++)
        insersi.insert(data[j]);
    gettimeofday(&mulai,NULL);
    bubble.sort();
    gettimeofday(&akhir,NULL);
    timeval_diff(&interval,&akhir, &mulai);

    cout << "Waktu untuk insertion sort: " <<
         interval.tv_sec << " detik " <<
         interval.tv_usec << " mikrodetik" << endl;

    return 0;
}
