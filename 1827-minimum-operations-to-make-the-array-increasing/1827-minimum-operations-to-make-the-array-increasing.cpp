class Solution {
public:
    int minOperations(vector<int>& nums) {
        int needNext = nums[0];
        int weGotTo = 0;
        for (auto& e : nums)
        {
            if (e < needNext)
            {
                weGotTo += needNext - e;
                e = needNext;
            }
            needNext = e + 1;
        }
        return weGotTo;
    }
};