class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int n = nums.size();
        int l = k, r = k;
        int ans = nums[k];
        int min = nums[k];
        while (l > 0 || r < n - 1) {
            if (l == 0)
                r++;
            else if (r == n - 1)
                l--;
            else if (nums[l - 1] < nums[r + 1])
                r++;
            else l--;
            min = std::min({min, nums[l], nums[r]});
            ans = std::max(ans, min * (r - l + 1));
        }
        return ans;
    }
};