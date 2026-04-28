#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int V;                      // number of vertices
int adj[MAX][MAX];          // adjacency matrix
int visited[MAX];           // visited array
int stack[MAX];             // stack to store result
int top = -1;

// DFS function
void topoSortUtil(int v) {
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            topoSortUtil(i);
        }
    }

    // push vertex to stack after visiting neighbors
    stack[++top] = v;
}

// Topological Sort function
void topoSort() {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topoSortUtil(i);
        }
    }

    // print in reverse order
    printf("Topological Order: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topoSort();
    return 0;
}