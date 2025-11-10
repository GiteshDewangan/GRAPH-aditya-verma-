#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Step 1: Direction arrays for 4 directions (up, down, left, right)
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int r, c;

    // Step 2: BFS function
    void bfs(int sr, int sc, int org_color, int color, vector<vector<int>>& image) {
        queue<pair<int, int>> q;
        q.push({sr, sc});   // start point
        image[sr][sc] = color;

        while (!q.empty()) {
            pair<int, int> f = q.front();
            q.pop();

            int i = f.first, j = f.second;

            // Visit all 4 directions
            for (int k = 0; k < 4; k++) {
                int ii = i + dx[k];
                int jj = j + dy[k];

                // Boundary & color check
                if (ii < 0 || jj < 0 || ii >= r || jj >= c || image[ii][jj] != org_color)
                    continue;

                q.push({ii, jj});
                image[ii][jj] = color;
            }
        }
    }

    // Step 3: Main flood fill function
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        r = image.size();
        c = image[0].size();
        int org_color = image[sr][sc];

        // If starting pixel already has same color
        if (org_color == color)
            return image;

        bfs(sr, sc, org_color, color, image);
        return image;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1, sc = 1, color = 2;

    vector<vector<int>> ans = sol.floodFill(image, sr, sc, color);

    for (auto row : ans) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}
