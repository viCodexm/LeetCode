class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int n = nums.size();
        int maxSum = nums[0];
        deque<pair<int, int>> dp;
        dp.push_back({0, maxSum});

        for (int i = 1; i < n; ++i) {
            if (i - dp.front().first > k)
                dp.pop_front();
            
            int current = nums[i];
            if (dp.front().second > 0)
                current += dp.front().second;
            maxSum = max(current, maxSum);

            while (!dp.empty() && dp.back().second < current)
                dp.pop_back();

            dp.push_back({i, current});
        }
        return maxSum;
    }
};