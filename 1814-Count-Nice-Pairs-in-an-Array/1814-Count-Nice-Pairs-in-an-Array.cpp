class Solution {
public:
    const int modulo = 1e9+7;
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, long long> dict;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            dict[nums[i] - stoi(s)]++;
        }
        long long count = 0;
        for (auto& [key, val] : dict)
            count = (count + (val * (val - 1) / 2) % modulo) % modulo;
        return count;
    }
};
