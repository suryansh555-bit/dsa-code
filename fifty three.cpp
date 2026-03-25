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
    if (!root) return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// Find LCA in BST
Node* findLCA(Node* root, int p, int q) {
    if (!root) return NULL;

    if (p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    if (p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    return root; // split point = LCA
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

    int p, q;
    cin >> p >> q;

    Node* lca = findLCA(root, p, q);

    if (lca)
        cout << lca->data;

    return 0;
}