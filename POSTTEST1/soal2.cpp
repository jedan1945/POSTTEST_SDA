#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matriks[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriks[i][j] = i + j + 1; 
        }
    }

    int jumlah = 0;
    for (int i = 0; i < N; i++) {
        jumlah += matriks[i][i];           
        jumlah += matriks[i][N - 1 - i];   
    }

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Jumlah diagonal utama + sekunder = " << jumlah << endl;

    return 0;
}
