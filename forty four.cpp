#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue class
class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Enqueue operation
    void enqueue(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;

        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    // Dequeue operation
    void dequeue() {
        if (front == NULL) {
            cout << -1 << endl;
            return;
        }

        Node* temp = front;
        cout << front->data << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }
};

int main() {
    int N;
    cin >> N;

    Queue q;
    string op;
    int x;

    while (N--) {
        cin >> op;

        if (op == "enqueue") {
            cin >> x;
            q.enqueue(x);
        } 
        else if (op == "dequeue") {
            q.dequeue();
        }
    }

    return 0;
}