// ------------------------------------------
// Bagian untuk menguji BST
// ------------------------------------------

#include <iostream>
#include "../Tree.h"

using namespace std;

int main()
{
    PohonBiner pohon;

    string dataNama = "KEBUNMAIYA";

    // Memasukkan karakter-karakter yang ada
    //   di dataNama ke Pohon
    for (unsigned int i = 0; i < dataNama.length(); i++)
    {
        if (pohon.sisip(dataNama[i]) == false)
            cout << "Data " << dataNama[i]
                 << " sudah ada" << endl;
        else
            cout << "Data " << dataNama[i]
                 << " disimpan" << endl;
    }

    cout << "InOrder: "
         << pohon.inOrder() << endl;

    cout << "PreOrder: "
         << pohon.preOrder() << endl;

    cout << "PostOrder: "
         << pohon.postOrder() << endl;

    // Menghapus A, N dan K
    pohon.hapus('A');
    pohon.hapus('N');
    pohon.hapus('K');

    cout << "Setelah A, N dan K dihapus: " << endl
         << "PreOrder: "
         << pohon.preOrder() << endl;

    return 0;
}
