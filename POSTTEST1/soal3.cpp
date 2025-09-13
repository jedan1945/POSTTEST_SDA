#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int N = 5;
    Mahasiswa mhs[N];

    for (int i = 0; i < N; i++) {
        cout << "Masukkan data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "IPK: ";
        cin >> mhs[i].ipk;
    }

    int idxTertinggi = 0;
    for (int i = 1; i < N; i++) {
        if (mhs[i].ipk > mhs[idxTertinggi].ipk) {
            idxTertinggi = i;
        }
    }

    cout << "\nMahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama: " << mhs[idxTertinggi].nama << endl;
    cout << "NIM : " << mhs[idxTertinggi].nim << endl;
    cout << "IPK : " << mhs[idxTertinggi].ipk << endl;

    return 0;
}
