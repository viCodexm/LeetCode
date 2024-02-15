class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long prevElemSum = 0, ans = -1;
        for (int num : nums) {
            if (num < prevElemSum)
                ans = num + prevElemSum;
            prevElemSum += num;
        }
        return ans;
    }
};