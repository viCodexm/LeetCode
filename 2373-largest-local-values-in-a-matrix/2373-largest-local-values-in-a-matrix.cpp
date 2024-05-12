class Solution {
public:
    int square_max(vector<vector<int>>& grid, int x, int y) {
        int ans = 0;
        for (int i = -1; i < 2; ++i)
            for (int j = -1; j < 2; ++j)
                ans = std::max(ans, grid[x + i][y + j]);
        return ans;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size() - 2, vector<int>());
        for (int i = 1; i < grid.size() - 1; ++i)
            for (int j = 1; j < grid[0].size() - 1; ++j)
                ans[i - 1].push_back(square_max(grid, i, j));
        return ans;
    }
};