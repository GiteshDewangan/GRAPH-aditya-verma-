class Solution {
public:
    // Step 1: DFS function
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, deque<int> &dq) {
        visited[node] = 1; // mark current node as visited
        
        for (int &nbr : adj[node]) {   // visit all neighbors
            if (!visited[nbr]) {
                dfs(nbr, visited, adj, dq);
            }
        }
        
        dq.push_front(node); // store node in front after visiting all neighbors
    }

    // Step 2: Topological Sort function
    vector<int> topologicalSort(vector<vector<int>> &adj) {
        int n = adj.size();          // total number of nodes
        vector<int> visited(n, 0);   // visited array
        deque<int> dq;               // to maintain topological order

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, dq); // perform DFS for each unvisited node
            }
        }

        // Step 3: Convert deque to vector
        vector<int> ans;
        for (int &x : dq) ans.push_back(x);

        return ans; // final topological order
    }
};
