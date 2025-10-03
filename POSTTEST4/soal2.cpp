// ## SOAL 2
// Buat fungsi yang memeriksa apakah sebuah string yang berisi tanda kurung (), {}, dan [] seimbang. Contohnya, "{[()]}" seimbang, tetapi "{[(])}" tidak. Gunakan implementasi Stack manual.
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
// // Anda bisa menggunakan fungsi push dan pop dari soal sebelumnya.
// bool areBracketsBalanced(string expr) {
//     Node* stackTop = nullptr;
//     // --- LENGKAPI DI SINI ---
//     // 1. Loop setiap karakter dalam `expr`.
//     // 2. Jika karakter adalah kurung buka '(', '{', '[', push ke stack.
//     // 3. Jika karakter adalah kurung tutup ')', '}', ']', cek:
//     //    a. Apakah stack kosong? Jika ya, return false.
//     //    b. Pop stack, lalu cek apakah kurung tutup cocok dengan kurung buka. Jika tidak, return false.
//     // 4. Setelah loop selesai, jika stack kosong, return true. Jika tidak, return false.
//     // --- LENGKAPI DI SINI ---
//     return false; // Placeholder
// }
// int main() {
//     string expr1 = "{[()]}";
//     cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
//     // Expected output: Seimbang
//     string expr2 = "{[(])}";
//     cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
//     return 0;
// }
// ```
// Hanya Info:
// Stack digunakan untuk menyimpan kurung buka. Setiap kali menemukan kurung tutup, kita memeriksa apakah kurung buka terakhir di stack adalah pasangannya.
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
    char val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) return false; // stack kosong

            char topChar = pop(stackTop);
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false; 
            }
        }
    }

    bool balanced = (stackTop == nullptr);

    while (stackTop != nullptr) pop(stackTop);
    return balanced;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " 
         << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    string expr2 = "{[(])}";
    cout << expr2 << " -> " 
         << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    string expr3 = "((()))[]{}";
    cout << expr3 << " -> " 
         << (areBracketsBalanced(expr3) ? "Seimbang" : "Tidak Seimbang") << endl;
    return 0;
}
