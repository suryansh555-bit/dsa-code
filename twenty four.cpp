#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* temp = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;

        Node* newNode = createNode(value);

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    Node* current = head;
    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}