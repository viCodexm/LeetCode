class Solution {
public:
    const int modulo = 1e9+7;
    int dfs(int curNum, int movesLeft, unordered_map<int, vector<int>>& dict, vector<vector<int>>& dp) {
        if (!movesLeft)
            return 1;
        if (dp[curNum][movesLeft] != -1)
            return dp[curNum][movesLeft];
        
        int ans = 0;
        for (auto& nei : dict[curNum])
            ans = (ans + dfs(nei, movesLeft - 1, dict, dp)) % modulo;
        
        return dp[curNum][movesLeft] = ans;
    }
    int knightDialer(int n) {
        unordered_map<int, vector<int>> dict = {
            {0, {4, 6}},
            {1, {6, 8}}, {2, {7, 9}}, {3, {4, 8}},
            {4, {3, 9, 0}}, {6, {1, 7, 0}},
            {7, {2, 6}}, {8, {1, 3}}, {9, {4, 2}},
        };
        vector<vector<int>> dp(10, vector<int>(n + 1, -1));
        int ans = 0;
        for (int i = 0; i < 10; ++i)
            ans = (ans + dfs(i, n - 1, dict, dp)) % modulo;
        return ans;
    }
};
