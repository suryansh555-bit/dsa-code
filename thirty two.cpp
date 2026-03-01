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

    // Create linked list
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

    int k;
    cin >> k;

    // If only one node
    if (head->next == NULL) {
        cout << head->data;
        return 0;
    }

    // Find length and last node
    Node* last = head;
    int length = 1;
    while (last->next != NULL) {
        last = last->next;
        length++;
    }

    k = k % length;
    if (k == 0) {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        return 0;
    }

    // Make circular
    last->next = head;

    // Move to (length - k)th node
    Node* newTail = head;
    for (int i = 1; i < length - k; i++) {
        newTail = newTail->next;
    }

    // New head
    Node* newHead = newTail->next;

    // Break circular link
    newTail->next = NULL;

    // Print rotated list
    Node* curr = newHead;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }

    return 0;
}