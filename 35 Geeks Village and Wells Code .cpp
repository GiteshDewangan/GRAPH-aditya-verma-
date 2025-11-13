class Solution {
public:
    vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c) {
        vector<vector<int>> result(n, vector<int>(m, 0));
        vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;

        // Initialize queue with all wells (multiple sources)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == 'W') {
                    q.push({i, j});
                }
            }
        }

        int counter = 1;

        // BFS traversal
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                pair<int, int> p = q.front();
                q.pop();

                int row = p.first;
                int col = p.second;

                for (auto dir : direction) {
                    int new_row = row + dir.first;
                    int new_col = col + dir.second;

                    if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
                        (c[new_row][new_col] == 'H' || c[new_row][new_col] == '.')) {

                        if (c[new_row][new_col] == 'H') {
                            result[new_row][new_col] = 2 * counter;
                        }

                        c[new_row][new_col] = 'V'; // Mark as visited
                        q.push({new_row, new_col});
                    }
                }
            }
            counter++;
        }

        // Update result for houses not reached
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == 'H' && result[i][j] == 0) {
                    result[i][j] = -1;
                }
            }
        }

        return result;
    }
};
