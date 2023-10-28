class Solution {
public:
    const int modulo = 1e9+7;
    int dfs(int len, int cur, int n, unordered_map<int, vector<int>>& dict, vector<vector<int>>& dp) {
        if (len >= n)
            return 1;

        if (dp[len][cur] != -1)
            return dp[len][cur];

        int ans = 0;
        for (int& dest : dict[cur])
            ans = (ans + dfs(len + 1, dest, n, dict, dp)) % modulo;

        return dp[len][cur] = ans;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n, vector<int>(5, -1));
        unordered_map<int, vector<int>> dict;
        dict[0] = { 1 };
        dict[1] = { 0, 2 };
        dict[2] = { 0, 1, 3, 4};
        dict[3] = { 2, 4 };
        dict[4] = { 0 };
        int ans = 0;
        for (int i = 0; i < 5; ++i)
            ans = (ans + dfs(0, i, n - 1, dict, dp)) % modulo;
        return ans;
    }
};