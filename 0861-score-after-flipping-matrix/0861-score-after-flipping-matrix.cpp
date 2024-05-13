class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        int score = (n << m - 1);

        for (int j = 1; j < m; ++j) {
            int bitsets = 0;
            for (int i = 0; i < n; ++i)
                bitsets += (grid[i][j] ^ !grid[i][0]);

            score += ((max(bitsets, n - bitsets)) << m - 1 - j);
        }
        return score;
    }
};