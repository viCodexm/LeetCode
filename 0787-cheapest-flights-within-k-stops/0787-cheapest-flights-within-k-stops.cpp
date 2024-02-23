struct tw {int to, weight;};
class Solution {
public:
    long long dfs(unordered_map<int, vector<tw>>& m, int prev, int goal, int k, vector<vector<int>>& dp) {
        if (prev == goal)
            return 0;
        if (k < 0)
            return INT_MAX;
        if (dp[prev][k] != -1)
            return dp[prev][k];
        long long ans = INT_MAX;
        for (tw& next : m[prev])
            ans = min(ans, 0LL + next.weight + dfs(m, next.to, goal, k - 1, dp));
        return dp[prev][k] = ans;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<tw>> m;
        for (vector<int>& fl : flights)
            m[fl[0]].push_back({ fl[1], fl[2] });
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        long long ans = dfs(m, src, dst, k, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};