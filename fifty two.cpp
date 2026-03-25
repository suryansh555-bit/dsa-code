#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert into BST
Node* insertBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int N;
    cin >> N;

    Node* root = NULL;

    // Build BST
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        root = insertBST(root, x);
    }

    int val;
    cin >> val;

    // Insert new value
    root = insertBST(root, val);

    // Print inorder
    inorder(root);

    return 0;
}