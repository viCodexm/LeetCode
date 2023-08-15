class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(0, nums, target);
        return count;
    }
    void dfs(int i, vector<int>& nums, int target) {
        if (i >= nums.size()) {
            count += !target;
            return;
        }
        dfs(i + 1, nums, target + nums[i]);
        dfs(i + 1, nums, target - nums[i]);
    }
};