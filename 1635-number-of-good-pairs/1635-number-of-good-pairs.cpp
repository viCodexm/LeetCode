class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int good = 0;
        const int size = nums.size();
        for (int i = 0; i < size; ++i)
            for (int j = i + 1; j < size; ++j)
                good += (nums[i] == nums[j]);
        return good;
    }
};