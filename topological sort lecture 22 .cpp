class Solution {
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> indegree(n, 0);
        vector<int> ans;

        // Getting nodes' indegree
        for (int i = 0; i < n; i++) {
            for (int x : adj[i]) {
                indegree[x]++;
            }
        }

        // Getting the start points
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS loop
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            ans.push_back(f);

            for (int x : adj[f]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }

        return ans;
    }
};
