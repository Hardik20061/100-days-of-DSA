#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack node
struct Node {
    int data;
    struct Node* next;
};

// Push
struct Node* push(struct Node* top, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    return newNode;
}

// Pop
struct Node* pop(struct Node* top, int* val) {
    if (top == NULL) return NULL;

    struct Node* temp = top;
    *val = temp->data;
    top = temp->next;
    free(temp);
    return top;
}

// Evaluate postfix
int evaluate(char expr[]) {
    struct Node* top = NULL;
    int i = 0;

    while (expr[i] != '\0') {

        // Skip spaces
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        // If digit
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            top = push(top, num);
        }
        // Operator
        else {
            int val1, val2;
            top = pop(top, &val1);
            top = pop(top, &val2);

            int result;
            switch (expr[i]) {
                case '+': result = val2 + val1; break;
                case '-': result = val2 - val1; break;
                case '*': result = val2 * val1; break;
                case '/': result = val2 / val1; break;
            }

            top = push(top, result);
            i++;
        }
    }

    int finalResult;
    top = pop(top, &finalResult);
    return finalResult;
}

int main() {
    char expr[100];

    fgets(expr, sizeof(expr), stdin);

    int result = evaluate(expr);

    printf("%d", result);

    return 0;
}