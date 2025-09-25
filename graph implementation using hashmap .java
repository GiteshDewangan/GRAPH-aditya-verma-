#include <bits/stdc++.h>
using namespace std;

void print_graph(unordered_map<int, vector<int>> graph) {
    for (auto x : graph) {
        cout << "Node: " << x.first << ", Neighbors: ";
        for (int node : x.second) {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> edgelist = {
        {1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}
    };

    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < edgelist.size(); i++) {
        int a = edgelist[i][0];
        int b = edgelist[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    print_graph(graph);

    return 0;
}
