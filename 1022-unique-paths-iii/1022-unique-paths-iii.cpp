typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
    vi dirs = {1, 0, -1, 0, 1};
    int uniquePathsIII(vvi& grid) {
        vvi vis(grid.size(), vi(grid[0].size(), -1));
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1)
                    return dfs(i, j, grid);
        return 0;
    }
    bool inside(int i, int j, vvi& grid) {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size();
    }
    int dfs(int i, int j, vvi& grid) {
        if (!inside(i, j, grid) || grid[i][j] == -1)
            return 0;
        if (grid[i][j] == 2) {
            for (auto& line : grid)
                for (int& elem : line)
                    if (elem == 0)
                        return 0;
            return 1;
        }
            
        int ans = 0;
        grid[i][j] = -1;
        for (int k = 0; k < 4; ++k)
            ans += dfs(i + dirs[k], j + dirs[k + 1], grid);
        grid[i][j] = 0;
        return ans;
    }
};