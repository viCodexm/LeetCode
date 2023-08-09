class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (can_form_pairs(nums, mid, p))
                r = mid;
            else l = mid + 1;
        }
        return l;
    }
    bool can_form_pairs(vector<int>& nums, int mid, int p) {
        int total = 0;
        int k = 0;
        int n = nums.size();
        while (k + 1 < n && total < p)  {
            if (nums[k + 1] - nums[k] <= mid) {
                total++;
                k += 2;
            } else k++;
        }
        return total >= p;
    }
};