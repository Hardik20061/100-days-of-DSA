#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

// Display
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, op, val;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &val);
            push(val);
        } else if (op == 2) {
            pop();
        } else if (op == 3) {
            display();
        }
    }

    return 0;
}