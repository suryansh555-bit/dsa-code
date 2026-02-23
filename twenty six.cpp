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

// Function to merge two sorted lists
Node* mergeLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* head = NULL;
    Node* tail = NULL;

    // Initialize head
    if (head1->data <= head2->data) {
        head = tail = head1;
        head1 = head1->next;
    } else {
        head = tail = head2;
        head2 = head2->next;
    }

    // Merge remaining nodes
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (head1)
        tail->next = head1;
    else
        tail->next = head2;

    return head;
}

int main() {
    int n, m;
    cin >> n;

    Node* head1 = NULL;
    Node* temp1 = NULL;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = createNode(val);

        if(!head1) head1 = temp1 = newNode;
        else {
            temp1->next = newNode;
            temp1 = newNode;
        }
    }

    cin >> m;

    Node* head2 = NULL;
    Node* temp2 = NULL;

    for(int i = 0; i < m; i++) {
        int val;
        cin >> val;
        Node* newNode = createNode(val);

        if(!head2) head2 = temp2 = newNode;
        else {
            temp2->next = newNode;
            temp2 = newNode;
        }
    }

    Node* mergedHead = mergeLists(head1, head2);

    // Print merged list]
    while(mergedHead) {
        cout << mergedHead->data << " ";
        mergedHead = mergedHead->next;
    }

    return 0;
}