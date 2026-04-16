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

Node* buildTree(int preorder[], int inorder[], int start, int end, int &preIndex) {
    if (start > end)
        return NULL;

    // Create root node
    Node* root = new Node(preorder[preIndex++]);

    // If only one node
    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, root->data);

    // Build left and right subtree
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

void postorder(Node* root) {
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cin >> n;

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    int preIndex = 0;

    Node* root = buildTree(preorder, inorder, 0, n - 1, preIndex);

    postorder(root);

    return 0;
}