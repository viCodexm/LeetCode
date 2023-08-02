class Solution {
public:
    vector<int> dirs = {1, 0, -1, 0, 1};
    bool inside(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    bool dfs(int i, int j, int level, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if (i == grid.size() - 1 && j == grid.size() - 1)
            return true;
        if (vis[i][j])
            return false;

        vis[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int di = i + dirs[k];
            int dj = j + dirs[k + 1];
            if (inside(di, dj, grid.size()) && !vis[di][dj] && grid[di][dj] <= level)
                if (dfs(di, dj, level, grid, vis))
                    return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = max(grid[0][0], grid[n - 1][n - 1]);
        int r = n * n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if (dfs(0, 0, mid, grid, vis))
                r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};