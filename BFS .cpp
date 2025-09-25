#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

void bfs(int source, unordered_map<int, vector<int>>& graph, int n) {
    queue<int> q;
    vector<int> visited(n + 1, 0);

    q.push(source);
    visited[source] = 1;

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        cout << f << " ";
        
        for (int nbr : graph[f]) {
            if (visited[nbr] == 0) {
                visited[nbr] = 1;
                q.push(nbr);
            }
        }
    }
}

int main() {
    vector<vector<int>> edgeList = {
        {0, 1}, {1, 4}, {1, 2}, {2, 3}
    };
    
    int n = 5;

    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < edgeList.size(); ++i) {
        int u = edgeList[i][0];
        int v = edgeList[i][1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int source = 0;
    cout << "BFS Order: ";
    bfs(source, graph, n);
    cout << endl;

    return 0;
}
