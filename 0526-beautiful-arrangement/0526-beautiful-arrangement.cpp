class Solution {
public:
    int countArrangement(int n) {
        vector<int> nums(n);
        for (int i = 1; i <= n; ++i)
            nums[i - 1] = i;

        return dfs(0, 1, n, nums);
    }
    int dfs(int mask, int i, int n, vector<int>& nums) {
        int count = 0;
        if (mask == (1 << n) - 1)
            return 1;

        for (int j = 0; j < n; ++j) {
            int pick = 1 << j;
            if (!(mask & pick) && (nums[j] % i == 0 || i % nums[j] == 0))
                count += dfs(mask | pick, i + 1, n, nums);
        }
        return count;
    }
};