#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection (by value)
void findIntersection(struct Node* h1, struct Node* h2) {
    int n1 = getLength(h1);
    int n2 = getLength(h2);

    int diff = abs(n1 - n2);

    // Move pointer of longer list
    if (n1 > n2) {
        for (int i = 0; i < diff; i++)
            h1 = h1->next;
    } else {
        for (int i = 0; i < diff; i++)
            h2 = h2->next;
    }

    // Traverse together
    while (h1 != NULL && h2 != NULL) {
        if (h1->data == h2->data) {
            printf("%d", h1->data);
            return;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m, x;
    struct Node *list1 = NULL, *list2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }

    findIntersection(list1, list2);

    return 0;
}