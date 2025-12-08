class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // Min-heap : {dist, x, y}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        pq.push({0, 0, 0});  
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int effort = curr[0];
            int x = curr[1];
            int y = curr[2];

            // If already found a better path
            if (effort > dist[x][y]) continue;

            // If reached target
            if (x == n - 1 && y == m - 1) return effort;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                int nextEffort = max(
                    effort,
                    abs(heights[x][y] - heights[nx][ny])
                );

                if (nextEffort < dist[nx][ny]) {
                    dist[nx][ny] = nextEffort;
                    pq.push({nextEffort, nx, ny});
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};
