#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1) {
        return; // overflow not required here
    }
    queue[++rear] = x;
}

// Display queue
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    display();

    return 0;
}