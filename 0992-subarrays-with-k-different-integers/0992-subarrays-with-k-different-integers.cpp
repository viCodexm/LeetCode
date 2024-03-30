class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindowAtMost(nums, k) - slidingWindowAtMost(nums, k - 1);
    }
    int slidingWindowAtMost(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> dict;
        const int size = nums.size();
        for (int l = 0, r = 0; r < size; ++r) {
            dict[nums[r]]++;
            while (dict.size() > k) {
                dict[nums[l]]--;
                if (dict[nums[l]] == 0)
                    dict.erase(nums[l]);
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};