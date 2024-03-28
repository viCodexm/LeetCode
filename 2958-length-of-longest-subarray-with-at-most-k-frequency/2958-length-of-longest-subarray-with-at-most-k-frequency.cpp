class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> dict;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            dict[nums[r]]++;
            auto& it = dict[nums[r]];
            while (it > k && l <= r)
                dict[nums[l++]]--;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};