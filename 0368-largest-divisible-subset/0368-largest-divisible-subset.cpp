class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> len(n, 1), prev(n, -1);

        int maxLen = 0, iMax = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] % nums[i] == 0 && len[j] < len[i] + 1) {
                    len[j] = len[i] + 1;
                    prev[j] = i;
                }
            }
            if (len[i] > maxLen) {
                maxLen = len[i];
                iMax = i;
            }
        }
        
        vector<int> ans;
        for (int j = iMax; j != -1; j = prev[j])
            ans.push_back(nums[j]);
        return ans;
    }
};