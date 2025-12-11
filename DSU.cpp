#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;   // each node is its own parent
    }

    // Find with path compression
    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    // Union by rank
    void unionByRank(int a, int b) {
        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA != leaderB) {
            if (rank[leaderA] < rank[leaderB]) {
                parent[leaderA] = leaderB;
                rank[leaderB] += rank[leaderA];
            } else {
                parent[leaderB] = leaderA;
                rank[leaderA] += rank[leaderB];
            }
        }
    }
};
