class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {

        int v = dist.size();

        for(int k = 0; k < v; k++) {
            for(int i = 0; i < v; i++) {
                for(int j = 0; j < v; j++) {

                    // If any required path is infinite, skip
                    if(dist[i][k] == 1e8 || dist[k][j] == 1e8)
                        continue;

                    int dist_through_k = dist[i][k] + dist[k][j];

                    // Update shortest distance
                    if(dist_through_k < dist[i][j]) {
                        dist[i][j] = dist_through_k;
                    }

                }
            }
        }
    }
};
