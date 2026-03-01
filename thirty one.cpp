#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n;
    cin >> n;

    if (n <= 0) return 0;

    Node* head = NULL;
    Node* temp = NULL;
    Node* newNode = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make it circular
    temp->next = head;

    // Traversal
    Node* current = head;
    if (head != NULL) {
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
    }

    return 0;
}