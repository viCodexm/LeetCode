class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            ans = min(ans, nums[mid]);
            if (nums[l] <= nums[r]) {
                if (nums[l] <= nums[mid])
                    r = mid - 1;
                else l = mid + 1;
            }
            else {
                if (nums[r] <= nums[mid])
                    l = mid + 1;
                else r = mid - 1;
            }
        }
        return ans;
    }
};