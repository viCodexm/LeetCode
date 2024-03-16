class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> dict;
        dict[0] = -1;
        int max = 0, count = 0;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            count += nums[i] ? 1 : -1;
            auto it = dict.find(count);
            if (it != dict.end())
                max = std::max(max, i - it->second);
            else dict[count] = i;
        }
        return max;
    }
};