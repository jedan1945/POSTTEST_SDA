#include <iostream>
using namespace std;

// Node / struct untuk linked list
struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item *next;
};

Item *head = nullptr;  // awal linked list

// Variabel personalisasi (diambil dari NIM user)
int JUMLAH_AWAL = 1;
int POSISI_SISIP = 1;

// Ambil 2 digit terakhir dan 1 digit terakhir dari NIM user
void setPersonalisasiNIM(string nim) {
    if (nim.size() >= 2) {
        // dua digit terakhir
        JUMLAH_AWAL = stoi(nim.substr(nim.size() - 2));
        if (JUMLAH_AWAL == 0) JUMLAH_AWAL = 1; // minimal 1
    }
    if (nim.size() >= 1) {
        // satu digit terakhir
        int lastDigit = nim[nim.size() - 1] - '0';
        POSISI_SISIP = lastDigit + 1;
    }
}

// Tambah item di akhir (addLast)
void tambahItem(string nama, string tipe) {
    Item *baru = new Item{nama, JUMLAH_AWAL, tipe, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Item *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan dengan jumlah " << JUMLAH_AWAL << endl;
}

// Sisip item di posisi tertentu (addMiddle)
void sisipItem(string nama, string tipe) {
    Item *baru = new Item{nama, JUMLAH_AWAL, tipe, nullptr};
    if (head == nullptr || POSISI_SISIP <= 1) {
        baru->next = head;
        head = baru;
        return;
    }

    Item *temp = head;
    int hitung = 1;
    while (temp->next != nullptr && hitung < POSISI_SISIP - 1) {
        temp = temp->next;
        hitung++;
    }
    baru->next = temp->next;
    temp->next = baru;

    cout << "Item \"" << nama << "\" berhasil disisipkan di posisi " << POSISI_SISIP << endl;
}

// Hapus item terakhir (deleteLast)
void hapusItemTerakhir() {
    if (head == nullptr) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    if (head->next == nullptr) {
        cout << "Item \"" << head->namaItem << "\" dihapus." << endl;
        delete head;
        head = nullptr;
        return;
    }

    Item *temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    cout << "Item \"" << temp->next->namaItem << "\" dihapus." << endl;
    delete temp->next;
    temp->next = nullptr;
}

// Gunakan item
void gunakanItem(string nama) {
    Item *temp = head;
    Item *prev = nullptr;

    while (temp != nullptr && temp->namaItem != nama) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item \"" << nama << "\" tidak ditemukan!" << endl;
        return;
    }

    temp->jumlah--;
    cout << "Item \"" << nama << "\" digunakan. Sisa: " << temp->jumlah << endl;

    if (temp->jumlah <= 0) {
        cout << "Item \"" << nama << "\" habis dan dihapus dari inventory." << endl;
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
}

// Tampilkan inventory
void tampilkanInventory() {
    if (head == nullptr) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    cout << "\n=== INVENTORY ===" << endl;
    Item *temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->namaItem
             << " (" << temp->tipe << ") - Jumlah: " << temp->jumlah << endl;
        temp = temp->next;
    }
    cout << "=================\n" << endl;
}

int main() {
    string namaUser, nimUser;
    cout << "Masukkan Nama: ";
    getline(cin, namaUser);
    cout << "Masukkan NIM: ";
    getline(cin, nimUser);

    setPersonalisasiNIM(nimUser); // set jumlah & posisi dari NIM user

    int pilihan;
    do {
        cout << "\n+---------------------------------------------------+\n";
        cout << "|                     link's bag                    |\n";
        cout << "|        [ " << namaUser << " - " << nimUser << " ]\n";
        cout << "+---------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                               |\n";
        cout << "| 2. Sisipkan Item                                  |\n";
        cout << "| 3. Hapus Item Terakhir                            |\n";
        cout << "| 4. Gunakan Item                                   |\n";
        cout << "| 5. Tampilkan Inventory                            |\n";
        cout << "| 0. Keluar                                         |\n";
        cout << "+---------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        string nama, tipe;
        switch (pilihan) {
            case 1:
                cout << "Nama Item: ";
                getline(cin, nama);
                cout << "Tipe Item: ";
                getline(cin, tipe);
                tambahItem(nama, tipe);
                break;
            case 2:
                cout << "Nama Item: ";
                getline(cin, nama);
                cout << "Tipe Item: ";
                getline(cin, tipe);
                sisipItem(nama, tipe);
                break;
            case 3:
                hapusItemTerakhir();
                break;
            case 4:
                cout << "Masukkan nama item yang ingin digunakan: ";
                getline(cin, nama);
                gunakanItem(nama);
                break;
            case 5:
                tampilkanInventory();
                break;
            case 0:
                cout << "Keluar dari program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
