class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minId = -1, maxId = -1;
        const int size = nums.size();
        for (int l = 0, r = 0; r < size; ++r) {
            int cur = nums[r];
            if (cur < minK || cur > maxK) {
                l = r + 1;
                continue;
            }
            if (cur == maxK) maxId = r;
            if (cur == minK) minId = r;
            ans += max(0, min(maxId, minId) - l + 1);
        }
        return ans;
    }
};