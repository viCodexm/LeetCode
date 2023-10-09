class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return { binary_search(nums, target, true), binary_search(nums, target, false) };
    }
    int binary_search(vector<int>& nums, int& target, bool isSearchLeft) {
        int l = 0, r = nums.size() - 1, idx = -1;
        while (l <= r) {
            int mid = (r + l) / 2;
            if (nums[mid] > target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else {
                idx = mid;
                if (isSearchLeft)
                    r = mid - 1;
                else l = mid + 1;
            }
        }
        return idx;
    }
};