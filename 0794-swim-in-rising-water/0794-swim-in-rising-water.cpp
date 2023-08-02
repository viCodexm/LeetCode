class Solution {
public:
    vector<int> dirs = {1, 0, -1, 0, 1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        dfs(0, 0, grid, dp);
        return dp[n - 1][n - 1];
    }
    bool inside(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        for (int k = 0; k < 4; ++k) {
            int di = i + dirs[k];
            int dj = j + dirs[k + 1];

            if (inside(di, dj, grid.size()) && dp[di][dj] > max(dp[i][j], grid[di][dj])) {
                dp[di][dj] = max(dp[i][j], grid[di][dj]);
                dfs(di, dj, grid, dp);
            }
        }
    }
};