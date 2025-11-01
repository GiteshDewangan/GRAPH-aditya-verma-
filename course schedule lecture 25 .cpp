class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> ans;

        // Step 1: Build graph
        for (auto &edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }

        // Step 2: Calculate indegree of each node
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (graph[i].empty()) continue;
            for (int &x : graph[i]) {
                indegree[x]++;
            }
        }

        // Step 3: Push nodes with 0 indegree into queue
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Step 4: BFS (Kahn’s Algorithm)
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            ans.push_back(f);

            for (int &x : graph[f]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }

        // Step 5: If not all nodes are visited, cycle exists
        if (ans.size() != n) return {};

        return ans;
    }
};
