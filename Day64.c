#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int s, vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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

    int s;
    cin >> s;

    bfs(s, adj, n);

    return 0;
}