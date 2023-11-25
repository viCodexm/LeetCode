class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        const int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        
        vector<int> suffixSum(n);
        suffixSum[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suffixSum[i] = suffixSum[i + 1] + nums[i];

        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = nums[i] * i - prefixSum[i] + suffixSum[i] - nums[i] * (n-i-1);
        
        return ans;
    }
};
