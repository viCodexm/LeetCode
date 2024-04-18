class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int islands = 0, neighbors = 0;
        const int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                grid[i][j] ? islands++, neighbors += (i > 0 && grid[i - 1][j]) + (j > 0 && grid[i][j - 1]) : 0;

        return islands * 4 - neighbors * 2;
    }
};