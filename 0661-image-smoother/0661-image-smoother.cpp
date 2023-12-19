class Solution {
public:
    bool inside(int x, int y, int n, int m) {
        return 0 <= x && x < n && 0 <= y && y < m;
    }
    void calc_nei(vector<vector<int>>& img, int x, int y, vector<vector<int>>& ans, int n, int m) {
        int sum = 0, count = 0;
        for (int i = -1; i <= 1; ++i)
            for (int j = -1; j <= 1; ++j) {
                const int dx = x + i, dy = y + j;
                if (inside(dx, dy, n, m)) {
                    sum += img[dx][dy];
                    count++;
                }
            }
        
        ans[x][y] = sum / count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const int n = img.size();
        const int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                calc_nei(img, i, j, ans, n, m);
        return ans;
    }
};