#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Directions → up, right, down, left
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // DFS to mark connected land as visited
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1')
            return;

        // Mark current land as visited
        grid[i][j] = '2';

        // Visit 4 connected directions
        for (int k = 0; k < 4; k++) {
            int ii = i + dx[k];
            int jj = j + dy[k];
            dfs(grid, ii, jj);
        }
    }

    // Main function
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt++;  // found one island
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands: " << sol.numIslands(grid) << endl;
    return 0;
}
