#include <iostream>
using namespace std;

int main() {
    int A[3][3][4];
    int nilai = 2;

    
    for (int lapis = 0; lapis < 3; lapis++) {
        for (int baris = 0; baris < 3; baris++) {
            for (int kolom = 0; kolom < 4; kolom++) {
                A[lapis][baris][kolom] = nilai;
                nilai += 2;
            }
        }
    }

    
    for (int lapis = 0; lapis < 3; lapis++) {
        cout << "Lapis " << lapis + 1 << endl;

        for (int baris = 0; baris < 3; baris++) {
            for (int kolom = 0; kolom < 4; kolom++) {
                cout << A[lapis][baris][kolom] << "\t";
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}