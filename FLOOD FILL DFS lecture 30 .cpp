class Solution {
public:
    int dx[4] = {0, 0, 1, -1};  // directions for row movement
    int dy[4] = {1, -1, 0, 0};  // directions for column movement
    int r, c;

    void dfs(int i, int j, int org_color, int color, vector<vector<int>>& image) {
        // base case
        if (i < 0 || j < 0 || i >= r || j >= c || image[i][j] != org_color)
            return;

        image[i][j] = color; // fill color

        // call dfs in 4 directions
        for (int k = 0; k < 4; k++) {
            int ii = i + dx[k];
            int jj = j + dy[k];
            dfs(ii, jj, org_color, color, image);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        r = image.size();
        c = image[0].size();
        int org_color = image[sr][sc];  // store original color

        if (org_color == color) 
            return image;  // no change needed

        dfs(sr, sc, org_color, color, image);
        return image;
    }
};
