#include <iostream>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item *next;
    Item *prev;
};

Item *head = nullptr;
Item *tail = nullptr;

int JUMLAH_AWAL = 1;
int POSISI_SISIP = 1;

void setPersonalisasiNIM(string nim) {
    if (nim.size() >= 2) {
        JUMLAH_AWAL = stoi(nim.substr(nim.size() - 2));
        if (JUMLAH_AWAL == 0) JUMLAH_AWAL = 1;
    }
    if (nim.size() >= 1) {
        int lastDigit = nim[nim.size() - 1] - '0';
        POSISI_SISIP = lastDigit + 1;
    }
}

void tambahItem(string nama, string tipe) {
    Item *baru = new Item{nama, JUMLAH_AWAL, tipe, nullptr, tail};
    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan (jumlah " << JUMLAH_AWAL << ")\n";
}

void sisipItem(string nama, string tipe) {
    Item *baru = new Item{nama, JUMLAH_AWAL, tipe, nullptr, nullptr};
    if (head == nullptr || POSISI_SISIP <= 1) {
        baru->next = head;
        if (head != nullptr) head->prev = baru;
        head = baru;
        if (tail == nullptr) tail = baru;
        cout << "Item \"" << nama << "\" disisipkan di awal.\n";
        return;
    }

    Item *temp = head;
    int hitung = 1;
    while (temp->next != nullptr && hitung < POSISI_SISIP - 1) {
        temp = temp->next;
        hitung++;
    }
    baru->next = temp->next;
    baru->prev = temp;
    if (temp->next != nullptr) temp->next->prev = baru;
    else tail = baru;
    temp->next = baru;

    cout << "Item \"" << nama << "\" berhasil disisipkan di posisi " << POSISI_SISIP << "\n";
}

void hapusItemTerakhir() {
    if (tail == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "Item \"" << tail->namaItem << "\" dihapus.\n";
    Item *hapus = tail;
    tail = tail->prev;
    if (tail != nullptr) tail->next = nullptr;
    else head = nullptr;
    delete hapus;
}

void gunakanItem(string nama) {
    Item *temp = head;
    while (temp != nullptr && temp->namaItem != nama) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Item \"" << nama << "\" tidak ditemukan!\n";
        return;
    }
    temp->jumlah--;
    cout << "Item \"" << nama << "\" digunakan. Sisa: " << temp->jumlah << "\n";
    if (temp->jumlah <= 0) {
        cout << "Item \"" << nama << "\" habis dan dihapus dari inventory.\n";
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        else tail = temp->prev;
        delete temp;
    }
}

void tampilkanInventory() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "\n=== INVENTORY (DARI DEPAN) ===\n";
    Item *temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->namaItem << " (" << temp->tipe << ") - Jumlah: " << temp->jumlah << "\n";
        temp = temp->next;
    }
    cout << "=============================\n";
}

void tampilkanDariBelakang() {
    if (tail == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "\n=== INVENTORY (DARI BELAKANG) ===\n";
    Item *temp = tail;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->namaItem << " (" << temp->tipe << ") - Jumlah: " << temp->jumlah << "\n";
        temp = temp->prev;
    }
    cout << "===============================\n";
}

void cariDetail(string nama) {
    Item *temp = head;
    while (temp != nullptr && temp->namaItem != nama) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Item \"" << nama << "\" tidak ditemukan.\n";
    } else {
        cout << "\n--- DETAIL ITEM ---\n";
        cout << "Nama   : " << temp->namaItem << "\n";
        cout << "Tipe   : " << temp->tipe << "\n";
        cout << "Jumlah : " << temp->jumlah << "\n";
        cout << "-------------------\n";
    }
}

int main() {
    string namaUser, nimUser;
    cout << "Masukkan Nama: ";
    getline(cin, namaUser);
    cout << "Masukkan NIM: ";
    getline(cin, nimUser);

    setPersonalisasiNIM(nimUser);

    int pilihan;
    do {
        cout << "\n+---------------------------------------------------+\n";
        cout << "|                          link's bag               |\n";
        cout << "|        [ " << namaUser << " - " << nimUser << " ]\n";
        cout << "+---------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                               |\n";
        cout << "| 2. Sisipkan Item                                  |\n";
        cout << "| 3. Hapus Item Terakhir                            |\n";
        cout << "| 4. Gunakan Item                                   |\n";
        cout << "| 5. Tampilkan Inventory (depan)                    |\n";
        cout << "| 6. Tampilkan Inventory (belakang)                 |\n";
        cout << "| 7. Cari Detail Item                               |\n";
        cout << "| 0. Keluar                                         |\n";
        cout << "+---------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        string nama, tipe;
        switch (pilihan) {
            case 1:
                cout << "Nama Item: "; getline(cin, nama);
                cout << "Tipe Item: "; getline(cin, tipe);
                tambahItem(nama, tipe); break;
            case 2:
                cout << "Nama Item: "; getline(cin, nama);
                cout << "Tipe Item: "; getline(cin, tipe);
                sisipItem(nama, tipe); break;
            case 3:
                hapusItemTerakhir(); break;
            case 4:
                cout << "Masukkan nama item yang ingin digunakan: ";
                getline(cin, nama);
                gunakanItem(nama); break;
            case 5:
                tampilkanInventory(); break;
            case 6:
                tampilkanDariBelakang(); break;
            case 7:
                cout << "Masukkan nama item: "; getline(cin, nama);
                cariDetail(nama); break;
            case 0:
                cout << "Keluar dari program...\n"; break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
