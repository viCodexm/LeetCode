class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int size = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        const int len = nums.size();
        
        int min = size;
        int right = 0;
        for (int left = 0; left < len; ++left) {
            while (right < len && nums[right] < nums[left] + size)
                right++;
            
            min = std::min(min, size - (right - left));
        }
        return min;
    }
};