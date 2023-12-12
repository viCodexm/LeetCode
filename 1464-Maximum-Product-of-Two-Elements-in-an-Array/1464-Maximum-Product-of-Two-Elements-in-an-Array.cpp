class Solution {
public:
    int maxProduct(vector<int>& nums) {
        partial_sort(nums.begin(), nums.begin() + 2, nums.end(), greater<int>());
        return (nums[0]-1)*(nums[1]-1);
    }
};
