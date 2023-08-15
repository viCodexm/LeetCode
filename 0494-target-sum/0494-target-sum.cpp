class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        return dfs(0, nums, target, dp);
    }
    int dfs(int i, vector<int>& nums, int target, map<pair<int, int>, int>& dp) {
        if (i >= nums.size())
            return !target;
        int sum = abs(target);
        auto it = dp.find({i, sum});
        if (it != dp.end())
            return it->second;
        
        return dp[{i, sum}] = dfs(i + 1, nums, target + nums[i], dp) + dfs(i + 1, nums, target - nums[i], dp);
    }
};