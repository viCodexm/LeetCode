class Solution {
public:
    int ans = 0;
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return dfs(nums, target, dp);
    }
    int dfs(vector<int>& nums, int target, vector<int>& dp) {
        if (target < 0)
            return false;
        if (target == 0)
            return true;
        
        if (dp[target] != -1)
            return dp[target];
        
        dp[target] = 0;
        for (int& x : nums)
            dp[target] += dfs(nums, target - x, dp);
        
        return dp[target];
    }
};