#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int postorder[], int start, int end, int &postIndex) {
    if (start > end)
        return NULL;

    // Create root from postorder
    Node* root = new Node(postorder[postIndex--]);

    // If single node
    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, root->data);

    // IMPORTANT: build right first
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

void preorder(Node* root) {
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cin >> n;

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    int postIndex = n - 1;

    Node* root = buildTree(inorder, postorder, 0, n - 1, postIndex);

    preorder(root);

    return 0;
}