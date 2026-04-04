#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue pair (node + horizontal distance)
struct Pair {
    struct Node* node;
    int hd;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* current = queue[front++];

        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i >= n) break;

        if (arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Pair queue[1000];
    int front = 0, rear = 0;

    int hd[1000], val[1000];
    int size = 0;

    queue[rear++] = (struct Pair){root, 0};

    int minHD = 0, maxHD = 0;

    // BFS traversal
    while (front < rear) {
        struct Pair temp = queue[front++];
        struct Node* curr = temp.node;
        int h = temp.hd;

        hd[size] = h;
        val[size] = curr->data;
        size++;

        if (h < minHD) minHD = h;
        if (h > maxHD) maxHD = h;

        if (curr->left)
            queue[rear++] = (struct Pair){curr->left, h - 1};

        if (curr->right)
            queue[rear++] = (struct Pair){curr->right, h + 1};
    }

    // Print vertical order
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < size; j++) {
            if (hd[j] == i)
                printf("%d ", val[j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}