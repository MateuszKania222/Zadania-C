#include <iostream>
using namespace std;

// Struktura węzła
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Implementacja kolejki dwukierunkowej
class Deque {
private:
    Node* front;
    Node* rear;
public:
    Deque() : front(nullptr), rear(nullptr) {}

    // Dodawanie na początek
    void enqueueFront(int value) {
        Node* newNode = new Node(value);
        if (!front) {
            front = rear = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Dodawanie na koniec
    void enqueueBack(int value) {
        Node* newNode = new Node(value);
        if (!rear) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    // Usuwanie z początku
    void dequeueFront() {
        if (!front) return;
        Node* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else rear = nullptr;
        delete temp;
    }

    // Usuwanie z końca
    void dequeueBack() {
        if (!rear) return;
        Node* temp = rear;
        rear = rear->prev;
        if (rear) rear->next = nullptr;
        else front = nullptr;
        delete temp;
    }

    // Wyświetlanie kolejki
    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Testowanie kolejki dwukierunkowej
int main() {
    Deque dq;
    dq.enqueueBack(10);
    dq.enqueueBack(20);
    dq.enqueueFront(5);
    dq.display(); // 5 10 20
    dq.dequeueFront();
    dq.display(); // 10 20
    dq.dequeueBack();
    dq.display(); // 10
    return 0;
}
