class Solution {
public:
    bool bfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &parent) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (int nbr : adj[f]) {
                if (!visited[nbr]) {
                    visited[nbr] = 1;
                    parent[nbr] = f;
                    q.push(nbr);
                } else if (parent[f] != nbr) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0), parent(V, -1);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfs(i, adj, visited, parent)) {
                    return true;
                }
            }
        }
        return false;
    }
};
