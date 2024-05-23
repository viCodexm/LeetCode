class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        return countBeautifulSubsets(nums, k, 0, 0);
    }

private:
    int countBeautifulSubsets(vector<int>& nums, int difference, int index, int mask) {
        if (index == nums.size())
            return mask > 0;

        bool isBeautiful = true;

        for (int j = 0; j < index && isBeautiful; ++j)
            isBeautiful = !((1 << j) & mask) || abs(nums[j] - nums[index]) != difference;
            

        
        int skip = countBeautifulSubsets(nums, difference, index + 1, mask);
        int take = (!isBeautiful) ? 0 : countBeautifulSubsets(nums, difference, index + 1, mask + (1 << index));
        
        return skip + take;
    }
};