#include <bits/stdc++.h>
using namespace std;

// This function prints the adjacency matrix in a user-friendly format
void print_graph(vector<vector<int>> adjacencyMatrix) {
    for (int i = 1; i < 5; i++) {
        cout << "Node: " << i << ", Neighbors: ";
        for (int j = 1; j < 5; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    // The edge list represents connections between nodes
    vector<vector<int>> edgelist = {
        {1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}
    };

    // Initialize the adjacency matrix with 0s. The size is 5x5 for 4 nodes
    // to make indexing easier (nodes 1-4).
    vector<vector<int>> adjacencyMatrix(5, vector<int>(5, 0));

    // Iterate through the edge list to populate the adjacency matrix
    for (int i = 0; i < edgelist.size(); i++) {
        // Since it's an undirected graph, connections go both ways
        int a = edgelist[i][0];
        int b = edgelist[i][1];
        adjacencyMatrix[a][b] = 1;
        adjacencyMatrix[b][a] = 1;
    }

    // Print the final graph representation
    print_graph(adjacencyMatrix);

    return 0;
}
