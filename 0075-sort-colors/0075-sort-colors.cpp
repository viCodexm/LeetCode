class Solution {
public:
    void sortColors(vector<int>& nums) {
        int end = nums.size() - 1;
        for (int i = 0; i < end; ++i) {
            while (nums[end] == 2 && end > 0)
                end--;
            if (nums[i] == 2 && i < end) swap(nums[i], nums[end]);
        }
        if (nums[end] == 2) end--;
        for (int i = 0; i < end; ++i) {
            while (nums[end] == 1 && end > 0)
                end--;
            if (nums[i] == 1 && i < end) swap(nums[i], nums[end]);
        }
    }
};