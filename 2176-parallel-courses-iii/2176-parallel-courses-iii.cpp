class Solution {
public:
    int dfs(int cur, vector<vector<int>>& dict, vector<int>& time, vector<int>& dp) {
        if (dict[cur].empty())
            return time[cur];

        if (dp[cur] != -1)
            return dp[cur];
        
        int ans = 0;
        for (int& next : dict[cur])
            ans = max(ans, dfs(next, dict, time, dp));
        return dp[cur] = time[cur] + ans;
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> dict(n, vector<int>(0, 0));
        for (vector<int>& v : relations)
            dict[v[0] - 1].push_back(v[1] - 1);

        vector<int> dp(n, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, dfs(i, dict, time, dp));

        return ans;
    }
};