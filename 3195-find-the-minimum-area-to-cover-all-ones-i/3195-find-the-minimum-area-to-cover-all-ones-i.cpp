class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int imin = 1000, jmin = 1000;
        int imax = -1, jmax = -1;
        const int n = grid.size();
        const int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                imin = min(imin, i);
                imax = max(imax, i);
                jmin = min(jmin, j);
                jmax = max(jmax, j);
            }
        }
        return (imax - imin + 1) * (jmax - jmin + 1);
    }
};