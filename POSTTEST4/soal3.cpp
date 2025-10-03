#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

// Enqueue (tambah ke belakang antrian)
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    if (front == nullptr) { 
        // Queue kosong
        front = rear = newNode;
    } else {
        // Sambungkan ke rear lalu update rear
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue (ambil dari depan antrian)
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    Node* temp = front;
    string doc = temp->document;

    // Geser front
    front = front->next;
    if (front == nullptr) rear = nullptr; // jika kosong, rear ikut null

    delete temp;
    return doc;
}

// Proses semua dokumen dalam antrian
void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}
