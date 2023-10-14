class Solution {
public:
    int dfs(int idx, int remain, const vector<int>& costs, const vector<int>& time, vector<vector<int>>& dp, const int &n) {
        if (remain <= 0)
            return 0;
        if (idx >= n)
            return 1e9;

        if (dp[idx][remain] != -1)
            return dp[idx][remain];

        const int paint = costs[idx] + dfs(idx + 1, remain - 1 - time[idx], costs, time, dp, n);
        const int dontPaint = dfs(idx + 1, remain, costs, time, dp, n);
        return dp[idx][remain] = min(paint, dontPaint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        const int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return dfs(0, n, cost, time, dp, n);
    }
};