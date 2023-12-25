class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return s.empty() ? 0 : dfs(s, 0, s.size(), dp);
    }
    int dfs(string& s, int i, int n, vector<int>& dp) {
        if (i == n)
            return 1;
        if (s[i] == '0')
            return dp[i] = 0;
        if (dp[i] != -1)
            return dp[i];

        dp[i] = dfs(s, i + 1, n, dp);
        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
            dp[i] += dfs(s, i + 2, n, dp);
        return dp[i];
    }
};