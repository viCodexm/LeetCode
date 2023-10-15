const int modulo = 1e9+7;
class Solution {
public:
    int dfs(int idx, int stepsLeft, vector<vector<int>>& dp) {
        if (idx < 0 || idx >= dp.size())
            return 0;
        if (!stepsLeft)
            return (idx == 0);
        
        if (dp[idx][stepsLeft] != -1)
            return dp[idx][stepsLeft] % modulo;
        
        return dp[idx][stepsLeft] = (
            (dfs(idx - 1, stepsLeft - 1, dp) + dfs(idx, stepsLeft - 1, dp)) % modulo
             + dfs(idx + 1, stepsLeft - 1, dp)
        ) % modulo;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(min(arrLen, steps), vector<int>(steps + 1, -1));
        return dfs(0, steps, dp);
    }
};