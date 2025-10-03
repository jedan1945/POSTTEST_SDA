#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

// Fungsi untuk menambahkan node secara terurut (ascending)
void sortedInsert(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    // Jika list kosong
    if (!head) {
        head = newNode;
        head->next = head->prev = head; // circular
        return;
    }

    Node* temp = head;

    // Jika nilai lebih kecil dari head → sisip sebelum head
    if (value < head->data) {
        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;

        head = newNode; // update head
        return;
    }

    // Cari posisi untuk sisip (antara dua node)
    while (temp->next != head && temp->next->data < value) {
        temp = temp->next;
    }

    // Sisip setelah temp
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

// Print list dari depan
void printList() {
    if (!head) {
        cout << "List kosong\n";
        return;
    }

    cout << "Isi Circular DLL (dari depan): ";
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Print list dari belakang
void printListReverse() {
    if (!head) {
        cout << "List kosong\n";
        return;
    }

    cout << "Isi Circular DLL (dari belakang): ";
    Node* temp = head->prev; // mulai dari tail
    Node* stop = temp;
    do {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != stop);
    cout << endl;
}

int main() {
    // Contoh penggunaan
    sortedInsert(30);
    sortedInsert(10);
    sortedInsert(20);
    sortedInsert(25);
    sortedInsert(5);

    printList();
    printListReverse();

    return 0;
}
