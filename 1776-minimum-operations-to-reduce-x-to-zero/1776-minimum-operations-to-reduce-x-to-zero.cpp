class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), -x);
        if (target < 0)
            return -1;
        
        int n = nums.size(), sum = 0, ans = INT_MIN;
        for (int l = 0, r = 0; r < n; ++r) {
            sum += nums[r];
            while (sum > target)
                sum -= nums[l++];

            if (sum == target)
                ans = max(ans, r - l + 1);
        }
        return (ans == INT_MIN) ? -1 : n - ans;
    }
};