class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3)
            return true;
        
        bool dec = true;
        for (int i = 1; i < n; ++i)
            if (nums[i - 1] < nums[i]) {
                dec = false;
                break;
            }
        if (dec)
            return true;

        bool inc = true;
        for (int i = 1; i < n; ++i)
            if (nums[i - 1] > nums[i]) {
                inc = false;
                break;
            }
        if (inc)
            return true;
        return false;
    }
};