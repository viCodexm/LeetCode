class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, up = 0;
        const int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1])
                up++;
            ans += up;
        }
        return ans;
    }
};
