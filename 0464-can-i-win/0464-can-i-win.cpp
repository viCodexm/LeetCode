class Solution {
public:
    bool canIWin(int m, int t) {
        vector<int> dp(1 << m, -1);
        return (m * (m + 1) / 2 < t) ? false : win(0, 0, m, t, dp);
    }
    bool win(int mask, int score, int m, int t, vector<int>& dp) {
        if (dp[mask] != -1)
            return dp[mask];
        
        for (int i = 0; i < m; ++i) {
            int pick = 1 << i;
            if (!(mask & pick) && ((score + i + 1 >= t || !win((mask | pick), score + i + 1, m, t, dp))))
                return dp[mask] = 1;
        }
        return dp[mask] = 0;
    }
};