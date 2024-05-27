class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; ++i)
            freq[min(n, nums[i])]++;
        
        int numGreaterThanOrEqual = 0;
        for (int i = n; i >= 1; i--) {
            numGreaterThanOrEqual += freq[i];
            if (i == numGreaterThanOrEqual)
                return i;
        }
        
        return -1;
    }
};