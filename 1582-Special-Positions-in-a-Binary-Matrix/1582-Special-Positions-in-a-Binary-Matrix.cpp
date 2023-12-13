class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        const int n = mat.size();
        const int m = mat[0].size();
        vector<int> rows(n, 0), cols(m, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (mat[i][j]) {
                    rows[i]++;
                    cols[j]++;
                }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans += mat[i][j] && rows[i] == 1 && cols[j] == 1;
        return ans;
    }
};
