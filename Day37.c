#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert
void insert(int x) {
    pq[size++] = x;
}

// Find index of minimum element
int findMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex])
            minIndex = i;
    }
    return minIndex;
}

// Delete (remove min)
void deleteMin() {
    int idx = findMinIndex();
    if (idx == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[idx]);

    // Shift elements
    for (int i = idx; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Peek (get min)
void peek() {
    int idx = findMinIndex();
    if (idx == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[idx]);
}

int main() {
    int n;
    scanf("%d", &n);

    char op[10];
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        }
        else if (strcmp(op, "delete") == 0) {
            deleteMin();
        }
        else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}