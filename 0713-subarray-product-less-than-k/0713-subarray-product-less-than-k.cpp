class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;
        int ans = 0, prod = 1;
        const int size = nums.size();
        for (int l = 0, r = 0; r < size; ++r) {
            prod *= nums[r];
            while (prod >= k)
                prod /= nums[l++];
            ans += r - l + 1;
        }
        return ans;
    }
};