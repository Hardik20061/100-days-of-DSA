#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if ((rear + 1) % MAX == front) {
        return; // overflow not required here
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = x;
}

// Dequeue
void dequeue() {
    if (front == -1) {
        return; // underflow not required here
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if (front == -1) return;

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // Enqueue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Dequeue operations
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // Display result
    display();

    return 0;
}