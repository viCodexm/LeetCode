class Solution {
public:
    vector<int> dirs = {1, 0, -1, 0, 1};
    bool inside(int dx, int max) {
        return 0 <= dx && dx < max;
    }
    bool dfs(int i, int j, int prevI, int prevJ, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        char cur = grid[i][j];
        for (int k = 0; k < 4; ++k) {
            int di = i + dirs[k];
            int dj = j + dirs[k + 1];
            
            if (!inside(di, n) || !inside(dj, m) || grid[di][dj] != cur)
                continue;

            if (vis[di][dj])
                if (di != prevI && dj != prevJ)
                    return true;
            
            if (!vis[di][dj])
                if (dfs(di, dj, i, j, n, m, grid, vis))
                    return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && dfs(i, j, -1, -1, n, m, grid, vis))
                    return true;
            }
        return false;
    }
};