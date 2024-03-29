class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        const int size = nums.size();
        for (int l = 0, r = 0; r < size; ++r) {
            k -= (nums[r] == max);
            while (!k)
                k += (nums[l++] == max);
            ans += l;
        }
        return ans;
    }
};