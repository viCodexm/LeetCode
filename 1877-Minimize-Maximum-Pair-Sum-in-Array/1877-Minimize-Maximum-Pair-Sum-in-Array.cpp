class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        const int full_size = nums.size() - 1;
        const int size = nums.size() / 2;
        for (int i = 0; i < size; ++i)
            ans = max(ans, nums[i] + nums[full_size - i]);
        return ans;
    }
};
