class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int csize = cost.size();
        vector<int> dp(csize);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < csize; ++i)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        return min(dp[csize - 1], dp[csize - 2]);
    }
};