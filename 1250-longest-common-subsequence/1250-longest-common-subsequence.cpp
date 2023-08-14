class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return dfs(0, 0, text1, text2, dp);
    }
    int dfs(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i >= s1.size() || j >= s2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = 1 + dfs(i + 1, j + 1, s1, s2, dp);

        return dp[i][j] = max(dfs(i + 1, j, s1, s2, dp), dfs(i, j + 1, s1, s2, dp));
    }
};