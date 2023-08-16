class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return dfs(0, 0, s, t, dp);
    }
    int dfs(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (j >= t.size())
            return 1;
        if (i >= s.size())
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int take = 0, skip = 0;
        if (s[i] == t[j])
            take = dfs(i + 1, j + 1, s, t, dp);
        
        skip = dfs(i + 1, j, s, t, dp);
        return dp[i][j] = take + skip;
    }
};