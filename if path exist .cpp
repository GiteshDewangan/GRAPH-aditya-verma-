#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& graph) {
        visited[node] = 1;

        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, graph);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> visited(n, 0);

        dfs(source, visited, graph);

        return visited[destination];
    }
};
