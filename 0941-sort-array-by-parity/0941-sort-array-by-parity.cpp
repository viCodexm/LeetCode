class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& left, const int& right) {
            return !(left & 1) && (right & 1);
        });
        return nums;
    }
};