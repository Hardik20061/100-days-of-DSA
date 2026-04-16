#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> adj[n];

    // Input adjacency list
    for (int i = 0; i < n; i++) {
        int k; // number of neighbors
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    int s; // starting vertex
    cin >> s;

    vector<bool> visited(n, false);

    dfs(s, adj, visited);

    return 0;
}