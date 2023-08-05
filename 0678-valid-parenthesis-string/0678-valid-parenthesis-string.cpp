class Solution {
public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), INT_MAX));
        return dfs(s, 0, 0, dp);
    }
    bool dfs(string& s, int i, int open, vector<vector<int>>& dp) {
        if (i >= s.size())
            return open == 0;

        if (open < 0)
            return false;
        if (dp[i][open] != INT_MAX)
            return dp[i][open];

        if (s[i] == '(')
            return dp[i][open] = dfs(s, i + 1, open + 1, dp);
        if (s[i] == ')')
            return dp[i][open] = dfs(s, i + 1, open - 1, dp);
        if (s[i] == '*')
            return dp[i][open] = dfs(s, i + 1, open + 1, dp) || dfs(s, i + 1, open - 1, dp) || dfs(s, i + 1, open, dp);
        
        return dp[i][open] = false;
    }
};