#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

/*
 * Fungsi ini menerima referensi ke pointer head.
 * Head dan tail akan di-update setelah penukaran.
 */
void exchangeHeadAndTail(Node *&head_ref) {
    if (head_ref == nullptr || head_ref->next == head_ref) {
        // kosong atau hanya 1 node
        return;
    }

    Node* head = head_ref;
    Node* tail = head_ref->prev;

    // Jika hanya ada 2 node
    if (head->next == tail && tail->next == head) {
        head_ref = tail; // cukup tukar head
        return;
    }

    Node* headNext = head->next;
    Node* tailPrev = tail->prev;

    // Hubungkan tail dengan headNext
    tail->next = headNext;
    headNext->prev = tail;

    // Hubungkan head dengan tailPrev
    head->prev = tailPrev;
    tailPrev->next = head;

    // Hubungkan tail dan head (melingkar)
    tail->prev = head;
    head->next = tail;

    // Update head_ref jadi tail
    head_ref = tail;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }
    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node *head = nullptr;

    // Buat list:
