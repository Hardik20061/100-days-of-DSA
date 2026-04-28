def is_cyclic_util(v, adj, visited, recStack):
    visited[v] = True
    recStack[v] = True

    for neighbor in adj[v]:
        # If not visited, recurse
        if not visited[neighbor]:
            if is_cyclic_util(neighbor, adj, visited, recStack):
                return True
        # If neighbor is in recursion stack → cycle
        elif recStack[neighbor]:
            return True

    # Remove node from recursion stack
    recStack[v] = False
    return False


def is_cyclic(V, adj):
    visited = [False] * V
    recStack = [False] * V

    for node in range(V):
        if not visited[node]:
            if is_cyclic_util(node, adj, visited, recStack):
                return True

    return False


# Example usage
V = 4
adj = [
    [1],    # 0 → 1
    [2],    # 1 → 2
    [3],    # 2 → 3
    [1]     # 3 → 1 (cycle)
]

if is_cyclic(V, adj):
    print("YES")
else:
    print("NO")