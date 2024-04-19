class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    absorb_island(grid, i, j, n, m);
                    count++;
                }
            }
        }
        return count;
    }
    void absorb_island(vector<vector<char>>& grid, int i, int j, int& n, int& m) {
        grid[i][j] = '0';
        if (i + 1 < n && grid[i + 1][j] == '1')
            absorb_island(grid, i + 1, j, n, m);
        if (j + 1 < m && grid[i][j + 1] == '1')
            absorb_island(grid, i, j + 1, n, m);

        if (i - 1 >= 0 && grid[i - 1][j] == '1')
            absorb_island(grid, i - 1, j, n, m);
        if (j - 1 >= 0 && grid[i][j - 1] == '1')
            absorb_island(grid, i, j - 1, n, m);
    }
};