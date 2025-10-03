// ## SOAL 1
// Buat sebuah fungsi yang menerima string dan mengembalikannya dalam keadaan terbalik. Anda harus menggunakan struktur data Stack yang diimplementasikan secara manual menggunakan singly linked list.
// Struktur Data:
// ```c++
// #include <iostream>
// #include <string>
// using namespace std;
// struct Node {
//     char data;
//     Node* next;
// };
// ```
// Lengkapi Fungsi berikut:
// ```c++
// // Fungsi Push dan Pop manual bisa dibuat di sini atau di dalam fungsi utama.
// // Disarankan untuk membuatnya terpisah agar lebih rapi.
// void push(Node*& top, char data) {
//     Node* newNode = new Node{data, top};
//     top = newNode;
// }
// char pop(Node*& top) {
//     if (top == nullptr) return '\0'; // Return null character jika stack kosong
//     Node* temp = top;
//     char poppedValue = temp->data;
//     top = top->next;
//     delete temp;
//     return poppedValue;
// }
// string reverseString(string s) {
//     Node* stackTop = nullptr;
//     string reversed = "";
//     // --- LENGKAPI DI SINI ---
//     // 1. Push setiap karakter dari string s ke dalam stack.
//     // 2. Pop setiap karakter dari stack dan tambahkan ke string `reversed`.
//     // --- LENGKAPI DI SINI ---
//     return reversed;
// }
// int main() {
//     string text = "Struktur Data";
//     cout << "Teks asli: " << text << endl;
//     cout << "Teks terbalik: " << reverseString(text) << endl; // Output: ataD rukurts
//     return 0;
// }
// ```
// Hanya Info:
// Karena sifat Stack adalah LIFO (Last-In, First-Out), karakter terakhir yang dimasukkan akan menjadi yang pertama kali dikeluarkan. Ini secara alami membalik urutan karakter.
// ---

#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0'; 
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    for (char c : s) {
        push(stackTop, c);
    }

   while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; 
    return 0;
}
